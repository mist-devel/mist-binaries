---------------------------------------------------------------------------------
--
-- Arcade: Midway MCR1 (Kick/man, Solar Fox, Draw Poker)
-- Based on Kickman by Dar port to MiST by Gehstock
-- 3 November 2019
--
-- 15kHz interlaced/VGA
--
-- Generic controls:
-- ESC/5/6 - coin
-- 1,2     - start 1,2 players
--
-- Draw Poker controls:
-- Button A (LCtrl) - Stand
-- Button B (LAlt)  - Cancel
-- Button C (Space) - Deal
-- Z,X,C,V,B        - Hold
--
-- Usage:
-- Create ROM and ARC files from MAME ROM zip files using the mra utility and the MRA files.
-- Example: mra -A -z /path/to/mame/roms Kick.mra
-- Copy the RBF and the ARC files to the same folder.
-- Copy the ROM files to the root of the SD Card.
--
-- MRA utilty: https://github.com/sebdel/mra-tools-c
--
---------------------------------------------------------------------------------
-- DE10_lite Top level for Kick (Midway MCR) by Dar (darfpga@aol.fr) (19/10/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------
-- Use kick_de10_lite.sdc to compile (Timequest constraints)
-- /!\
-- Don't forget to set device configuration mode with memory initialization 
--  (Assignments/Device/Pin options/Configuration mode)
---------------------------------------------------------------------------------
--
-- Main features :
--  PS2 keyboard input @gpio pins 35/34 (beware voltage translation/protection) 
--  Audio pwm output   @gpio pins 1/3 (beware voltage translation/protection) 
--
--  Video         : 31Khz/60Hz
--  Cocktail mode : NO
--  Sound         : OK
-- 
-- For hardware schematic see my other project : NES
--
-- Uses 1 pll 40MHz from 50MHz to make 20MHz and 8Mhz 
--
-- Board key :
--   0 : reset game
--
-- Keyboard players inputs :
--
--   F3 : Add coin
--   F2 : Start 2 players
--   F1 : Start 1 player
--   SPACE       : move faster
--   RIGHT arrow : move right
--   LEFT  arrow : move left
--   UP    arrow : toggle service mode ON/OFF
--   DOWN  arrow : kick 
--
-- Other details : see kick.vhd
-- For USB inputs and SGT5000 audio output see my other project: xevious_de10_lite

---------------------------------------------------------------------------------
-- Kick by Dar (darfpga@aol.fr) (19/10/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
-- gen_ram.vhd & io_ps2_keyboard
-------------------------------- 
-- Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
-- http://www.syntiac.com/fpga64.html
---------------------------------------------------------------------------------
-- T80/T80se - Version : 304
-----------------------------
-- Z80 compatible microprocessor core
-- Copyright (c) 2001-2002 Daniel Wallner (jesus@opencores.org)
---------------------------------------------------------------------------------
-- YM2149 (AY-3-8910)
-- Copyright (c) MikeJ - Jan 2005
---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------

--  Features :
--   Video        : 31Khz/60Hz
--   Coctail mode : NO
--   Sound        : OK

--  Use with MAME roms from kick.zip and midssio.zip
--
--  Use make_kick_proms.bat to build vhd file from binaries
--  (CRC list included)

--  Kick/Kickman (Midway mcr) Hardware caracteristics :
--
--  VIDEO : 1xZ80@3MHz CPU accessing its program rom, working ram,
--    sprite data ram, I/O, sound board register and trigger.
--		  24Kx8bits program rom
--
--    One char/background tile map 30x32
--      2x4Kx8bits graphics rom 4bits/pixel
--      rbg programmable ram palette 16 colors 12bits : 4red 4green 4blue
--
--    128 sprites, up to ~15/line, 32x32 with flip H/V
--      4x4Kx8bits graphics rom 4bits/pixel
--      rbg programmable ram palette 16 colors 12bits : 4red 4green 4blue 
--
--    Working ram : 2Kx8bits
--    video (char/background) ram  : 1Kx8bits
--    Sprites ram : 512x8bits + 512x8bits cache buffer

--    Sprites line buffer rams : 1 scan line delay flip/flop 2x256x8bits
--
--  SOUND : see Kick_sound_board.vhd

---------------------------------------------------------------------------------
--  Schematics remarks :
--
--		Display is 512x480 pixels  (video 635x525 lines @ 20MHz )

--       635/20e6  = 31.75us per line  (31.750KHz)
--       31.75*525 = 16.67ms per frame (59.99Hz)
--        
--    Original video is interlaced 240 display lines per 1/2 frame
--
--       H0 and V0 are not use for background => each bg tile is 16x16 pixel but 
--			background graphics is 2x2 pixels defintion.
--
--			Sprite are 32x32 pixels with 1x1 pixel definition, 16 lines for odd 1/2
--       frame and 16 lines for even 2/2 frame thanks to V8 on sprite rom ROMAD2
--       (look at 74ls86 G1 pin 9 on video genration board schematics)
--
--    *H and V stand for Horizontal en Vertical counter (Hcnt, Vcnt in VHDL code)
--
--    /!\ For VHDL port interlaced video mode is replaced with progressive video 
--        mode.
--
--    Sprite data are stored first by cpu into a 'cache' buffer (staging ram at
--    K6/L6) this buffer is read and write for cpu. After visible display, cache
--    buffer (512x8) is moved to actual sprite ram buffer (512x8). Actual sprite
--    buffer is access by transfer address counter during 2 scanlines after 
--    visible area and only by sprite machine during visible area.
--
--    Thus cpu can read and update sprites position during entire frame except
--    during 2 lines.
-- 
--    Sprite data are organised (as seen by cpu F000-F1FF) into 128 * 4bytes.
--    bytes #1 : Vertical position
--    bytes #2 : code and attribute
--    bytes #3 : Horizontal position
--    bytes #4 : not used
--
--    Athough 1x1 pixel defintion sprite position horizontal/vertical is made on
--    on a 2x2 grid (due to only 8bits for position data)
--
--    Z80-CTC : interruption ar managed by CTC chip. ONly channel 3 is trigered
--    by hardware signal line 493. channel 0 to 2 are in timer mode. Schematic 
--    show zc/to of channel 0 connected to clk/trg of channel 1. This seems to be
--    unsued for that (Kick) game. 
--
--     CPU programs 4 interuptions : (Vector D0)
--
--     IT ch 3 : triggered by line 493  : once per frame : start @00D8
--               set timer ch0 to launch interrupt around line 20
--               set timer ch1 to launch interrupt around line 240
--
--     IT ch 0 : triggered by timer ch 0  : once per frame : start @017E
--               stop timer 0
--
--     IT ch 1 : triggered by timer ch 1  : once per frame : start @0192
--               stop timer 1
--
--     IT ch 2 : trigged by timer ch 2 : once every ~105 scanlines : start @04E1
--               read angle decoder
--
--    Z80-CTC VHDL port keep separated interrupt controler and each counter so 
--    one can use them on its own. Priority daisy-chain is not done (not used in
--    that game). clock polarity selection is not done since it has no meaning
--    with digital clock/enable (e.g cpu_ena signal) method.
--
--    Angle (spin) decoder : Original design is a simple Up/Down 4 bits counter.
--    Replacement is proposed in kick_de10_lite.vhd as a 10bits counter allowing
--    more stable speed. It make use of CTC zc_to channel 2 signal to avoid
--    aliasing problems. Despite speed selection (faster/slower) is available 
--    from keyboard key it hardly simulate a real spinner.
--
--    Ressource : input clock 40MHz is chosen to allow easy making of 20MHz for
--    pixel clock and 8MHz signal for amplitude modulation circuit of ssio board
--    
--
--  TODO :
--    Working ram could be initialized to set initial difficulty level and
--    initial bases (live) number. Otherwise one can set it up by using service
--    menu at each power up.
--
+----------------------------------------------------------------------------------+
; Fitter Summary                                                                   ;
+------------------------------------+---------------------------------------------+
; Fitter Status                      ; Successful - Sat Nov 02 22:31:20 2019       ;
; Quartus Prime Version              ; 18.1.0 Build 625 09/12/2018 SJ Lite Edition ;
; Revision Name                      ; kick_de10_lite                              ;
; Top-level Entity Name              ; kick_de10_lite                              ;
; Family                             ; MAX 10                                      ;
; Device                             ; 10M50DAF484C6GES                            ;
; Timing Models                      ; Preliminary                                 ;
; Total logic elements               ; 7,125 / 49,760 ( 14 % )                     ;
;     Total combinational functions  ; 6,705 / 49,760 ( 13 % )                     ;
;     Dedicated logic registers      ; 2,068 / 49,760 ( 4 % )                      ;
; Total registers                    ; 2068                                        ;
; Total pins                         ; 105 / 360 ( 29 % )                          ;
; Total virtual pins                 ; 0                                           ;
; Total memory bits                  ; 700,416 / 1,677,312 ( 42 % )                ;
; Embedded Multiplier 9-bit elements ; 0 / 288 ( 0 % )                             ;
; Total PLLs                         ; 1 / 4 ( 25 % )                              ;
; UFM blocks                         ; 0 / 1 ( 0 % )                               ;
; ADC blocks                         ; 0 / 2 ( 0 % )                               ;
+------------------------------------+---------------------------------------------+

---------------
VHDL File list 
---------------

de10_lite/max10_pll_40M.vhd        Pll 40MHz from 50MHz altera mf

rtl_dar/kick_de10_lite.vhd         Top level for de10_lite board
rtl_dar/kick.vhd                   Main CPU and video boards logic
rtl_dar/kick_sound_board.vhd       Main sound board logic
rtl_dar/ctc_controler.vhd          Z80-CTC controler 
rtl_dar/ctc_counter.vhd            Z80-CTC counter

rtl_mikej/YM2149_linmix.vhd        Copyright (c) MikeJ - Jan 2005

rtl_T80_304/T80se.vhdT80               Copyright (c) 2001-2002 Daniel Wallner (jesus@opencores.org)
rtl_T80_304/T80_Reg.vhd
rtl_T80_304/T80_Pack.vhd
rtl_T80_304/T80_MCode.vhd
rtl_T80_304/T80_ALU.vhd
rtl_T80_304/T80.vhd

rtl_dar/kbd_joystick.vhd           Keyboard key to player/coin input
rtl_dar/io_ps2_keyboard.vhd        Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
rtl_dar/gen_ram.vhd                Generic RAM (Peter Wendrich + DAR Modification)
rtl_dar/decodeur_7_seg.vhd         7 segments display decoder

rtl_dar/proms/kick_cpu.vhd         CPU board PROMS
rtl_dar/proms/kick_bg_bits_2.vhd
rtl_dar/proms/kick_bg_bits_1.vhd

rtl_dar/proms/kick_sp_bits_4.vhd   Video board PROMS
rtl_dar/proms/kick_sp_bits_3.vhd
rtl_dar/proms/kick_sp_bits_2.vhd
rtl_dar/proms/kick_sp_bits_1.vhd

rtl_dar/proms/kick_sound_cpu.vhd   Sound board PROMS
rtl_dar/proms/midssio_82s123.vhd

----------------------
Quartus project files
----------------------
de10_lite/kick_de10_lite.sdc   Timequest constraints file
de10_lite/kick_de10_lite.qsf   de10_lite settings (files,pins...) 
de10_lite/kick_de10_lite.qpf   de10_lite project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 17 ROMs binary files from kick.zip and midssio.zip(MAME)

1200a-v2.b3  CRC 65924917
1300b-v2.b4  CRC 27929f52
1400c-v2.b5  CRC 69107ce6
1500d-v2.d4  CRC 04a23aa1
1600e-v2.d5  CRC 1d2834c0
1700f-v2.d6  CRC ddf84ce1
1800g-v2.g4  CRC b4d120f3
1900h-v2.g5  CRC c3ba4893

2600a-v2.1e  CRC 2c5d6b55
2700b-v2.1d  CRC 565ea97d
2800c-v2.1b  CRC f3be56a1
2900d-v2.1a  CRC 77da795e

4200-a.a7          CRC 9e35c02e
4300-b.a8          CRC ca2b7c28
4400-c.a9          CRC d1901551
4500-d.a10         CRC d36ddcdc
midssio_82s123.12d CRC e1281ee9

------
Tools 
------
You need to build vhdl files from the binary file :
 - Unzip the roms file in the tools/kick_unzip directory
 - Double click (execute) the script tools/make_kick_proms.bat to get the following 9 files

kick_cpu.vhd
kick_bg_bits_2.vhd
kick_bg_bits_1.vhd
kick_sp_bits_4.vhd
kick_sp_bits_3.vhd
kick_sp_bits_2.vhd
kick_sp_bits_1.vhd
kick_sound_cpu.vhd
midssio_82s123.vhd

*DO NOT REDISTRIBUTE THESE FILES*

VHDL files are needed to compile and include roms into the project 

The script make_kick_proms.bat uses make_vhdl_prom executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c is also delivered.

---------------------------------
Compiling for de10_lite
---------------------------------
You can build the project with ROM image embeded in the sof file.
*DO NOT REDISTRIBUTE THESE FILES*

3 steps

 - put the VHDL ROM files (.vhd) into the rtl_dar/proms directory
 - build kick_de10_lite
 - program kick_de10_lite.sof

------------------------
------------------------
End of file
------------------------
