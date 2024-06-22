-- Satan's Hollow/Tron/Wacko/Kozmik Krooz'r/Two Tigers/Domino Man Arcade
-- Based on Dar's Satan's Hollow VHDL code
-- Interlaced 15kHz/31kHz VGA
--
-- Controls: joystick, mouse, standard MAME keys
-- Coin: ESC, 5, 6
-- Start: F1, F2, 1, 2

-- Tron: Joystick 1 for movement, Joystick 2 (MAME keys: D, G) or Buttons B and C for turret
-- Wacko: control Captain Krooz'r with the mouse, shoot with the joystick
-- Kozmik Krooz'r: use the mouse for movement and shoot, rotate the turret with the joystick

-- Create ROM and ARC files from MAME ROM zip files using the mra utility and the MRA files.
-- Copy the RBF and the ARC files to the same folder.
-- Example: mra -A -z /path/to/mame/roms Tron.mra
-- Copy the ROM files to the root of the SD Card.
--
-- MRA utilty: https://github.com/sebdel/mra-tools-c
--
-- Some games are storing settings/high scores in a non-volatile RAM. It can be saved to
-- the SD Card with the "Save NVRAM" option in the OSD menu. It'll be restored when
-- the core is loaded next time.
--
---------------------------------------------------------------------------------
-- DE10_lite Top level for Satan Hollow (Midway MCR) by Dar (darfpga@aol.fr) (19/10/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
--
-- release rev 02 : add TV 15kHz mode
--  (22/11/2019)    use merged sprite 8bits roms (make it easier to externalize)
--  
--  release 01 : improve ssio read input (fix mirror addressing)
--               improve memory access (fix mirror addressing)
--
--  release 00 : initial release
---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------
-- Use satan_hollow_de10_lite.sdc to compile (Timequest constraints)
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
--   F1 : Add coin
--   F2 : Start 1 player
--   F3 : Start 2 players
--   F5 : Sevice mode ON/OFF
--   SPACE       : fire
--   RIGHT arrow : move right
--   LEFT  arrow : move left
--   UP    arrow : shield 
--
-- Other details : see satans_hollow.vhd
-- For USB inputs and SGT5000 audio output see my other project: xevious_de10_lite
---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
-- Satans Hollow by Dar (darfpga@aol.fr) (09/11/2019)
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
--
-- release rev 02 : add TV 15kHz mode
--  (22/11/2019)    use merged sprite 8bits roms (make it easier to externalize)
--
-- release rev 01 : improve ssio read input (fix mirror addressing)
--                  improve memory access (fix mirror addressing)
--
-- release rev 00 : initial release
--
---------------------------------------------------------------------------------
--  Features :
--   Video        : 31Khz/60Hz
--   Coctail mode : NO
--   Sound        : OK

--  Use with MAME roms from shollow.zip
--
--  Use make_satans_hollow_proms.bat to build vhd file from binaries
--  (CRC list included)

--  Satans hollow (midway mcr) Hardware caracteristics :
--
--  VIDEO : 1xZ80@3MHz CPU accessing its program rom, working ram,
--    sprite data ram, I/O, sound board register and trigger.
--		  48Kx8bits program rom
--
--    One char/background tile map 30x32
--      2x8Kx8bits graphics rom 4bits/pixel
--      rbg programmable ram palette 64 colors 9bits : 3red 3green 3blue
--
--    128 sprites, up to ~15/line, 32x32 with flip H/V
--      4x8Kx8bits graphics rom 4bits/pixel
--      rbg programmable ram palette 64 colors 9bits : 3red 3green 3blue 
--
--    Working ram : 2Kx8bits
--    video (char/background) ram  : 2Kx8bits
--    Sprites ram : 512x8bits + 512x8bits cache buffer

--    Sprites line buffer rams : 1 scan line delay flip/flop 2x256x8bits
--
--  SOUND : see satans_hollow_sound_board.vhd

---------------------------------------------------------------------------------
--  Schematics remarks :
--
--    Display is 512x480 pixels  (video 635x525 lines @ 20MHz )

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
--    Real hardware uses background ram access after each 1/2 frame (~line 240
--    and 480). In these areas cpu can access ram since scanlines are out of
--    visible display. In progessive mode there are video access around lines 240.
--    These accesses will create video artfacts aound mid display. In VHDL code
--    ram access is muliplexed between cpu and scanlines by using hcnt(0) in
--    order to avoid these artefacts.
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
--		Athough 1x1 pixel defintion sprite position horizontal/vertical is made on
--    on a 2x2 grid (due to only 8bits for position data)
--
--    Z80-CTC : interruption ar managed by CTC chip. ONly channel 3 is trigered
--    by hardware signal line 493. channel 0 to 2 are in timer mode. Schematic 
--    show zc/to of channel 0 connected to clk/trg of channel 1. This seems to be
--    unsued for that (Kick) game. 
--
--    Z80-CTC VHDL port keep separated interrupt controler and each counter so 
--    one can use them on its own. Priority daisy-chain is not done (not used in
--    that game). clock polarity selection is not done since it has no meaning
--    with digital clock/enable (e.g cpu_ena signal) method.
--
--    Ressource : input clock 40MHz is chosen to allow easy making of 20MHz for
--    pixel clock and 8MHz signal for amplitude modulation circuit of ssio board
--
--  TODO :
--    Working ram could be initialized to set initial difficulty level and
--    initial bases (live) number. Otherwise one can set it up by using service
--    menu at each power up.
--

+----------------------------------------------------------------------------------+
; Fitter Summary                                                                   ;
+------------------------------------+---------------------------------------------+
; Fitter Status                      ; Successful - Wed Nov 13 19:50:34 2019       ;
; Quartus Prime Version              ; 18.1.0 Build 625 09/12/2018 SJ Lite Edition ;
; Revision Name                      ; satans_hollow_de10_lite                     ;
; Top-level Entity Name              ; satans_hollow_de10_lite                     ;
; Family                             ; MAX 10                                      ;
; Device                             ; 10M50DAF484C6GES                            ;
; Timing Models                      ; Preliminary                                 ;
; Total logic elements               ; 6,545 / 49,760 ( 13 % )                     ;
;     Total combinational functions  ; 6,307 / 49,760 ( 13 % )                     ;
;     Dedicated logic registers      ; 1,671 / 49,760 ( 3 % )                      ;
; Total registers                    ; 1671                                        ;
; Total pins                         ; 105 / 360 ( 29 % )                          ;
; Total virtual pins                 ; 0                                           ;
; Total memory bits                  ; 938,560 / 1,677,312 ( 56 % )                ;
; Embedded Multiplier 9-bit elements ; 0 / 288 ( 0 % )                             ;
; Total PLLs                         ; 1 / 4 ( 25 % )                              ;
; UFM blocks                         ; 0 / 1 ( 0 % )                               ;
; ADC blocks                         ; 0 / 2 ( 0 % )                               ;
+------------------------------------+---------------------------------------------+


---------------
VHDL File list 
---------------

de10_lite/max10_pll_40M.vhd        Pll 40MHz from 50MHz altera mf

rtl_dar/satans_hollow_de10_lite.vhd    Top level for de10_lite board
rtl_dar/satans_hollow.vhd              Main CPU and video boards logic
rtl_dar/satans_hollow_sound_board.vhd  Main sound board logic
rtl_dar/ctc_controler.vhd              Z80-CTC controler 
rtl_dar/ctc_counter.vhd                Z80-CTC counter

rtl_mikej/YM2149_linmix.vhd        Copyright (c) MikeJ - Jan 2005

rtl_T80_304/T80se.vhdT80           Copyright (c) 2001-2002 Daniel Wallner (jesus@opencores.org)
rtl_T80_304/T80_Reg.vhd
rtl_T80_304/T80_Pack.vhd
rtl_T80_304/T80_MCode.vhd
rtl_T80_304/T80_ALU.vhd
rtl_T80_304/T80.vhd

rtl_dar/kbd_joystick.vhd           Keyboard key to player/coin input
rtl_dar/io_ps2_keyboard.vhd        Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
rtl_dar/gen_ram.vhd                Generic RAM (Peter Wendrich + DAR Modification)
rtl_dar/decodeur_7_seg.vhd         7 segments display decoder

rtl_dar/proms/satans_hollow_cpu.vhd         CPU board PROMS
rtl_dar/proms/satans_hollow_bg_bits_2.vhd
rtl_dar/proms/satans_hollow_bg_bits_1.vhd

rtl_dar/proms/satans_hollow_sp_bits.vhd     Video board PROMS

rtl_dar/proms/satans_hollow_sound_cpu.vhd   Sound board PROMS
rtl_dar/proms/midssio_82s123.vhd

----------------------
Quartus project files
----------------------
de10_lite/satans_hollow_de10_lite.sdc   Timequest constraints file
de10_lite/satans_hollow_de10_lite.qsf   de10_lite settings (files,pins...) 
de10_lite/satans_hollow_de10_lite.qpf   de10_lite project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 16 ROMs binary files from satans_hollow.zip and midssio.zip(MAME)

sh-pro.00 CRC 95e2b800
sh-pro.01 CRC b99f6ff8
sh-pro.02 CRC 1202c7b2
sh-pro.03 CRC 0a64afb9
sh-pro.04 CRC 22fa9175
sh-pro.05 CRC 1716e2bb

sh-snd.01 CRC 55a297cc
sh-snd.02 CRC 46fc31f6
sh-snd.03 CRC b1f4a6a8

sh-bg.00  CRC 3e2b333c
sh-bg.01  CRC d1d70cc4

sh-fg.00  CRC 33f4554e
sh-fg.01  CRC ba1a38b4
sh-fg.02  CRC 6b57f6da
sh-fg.03  CRC 37ea9d07

midssio_82s123.12d CRC e1281ee9

------
Tools 
------
You need to build vhdl files from the binary file :
 - Unzip the roms file in the tools/satans_hollow_unzip directory
 - Double click (execute) the script tools/make_satans_hollow_proms.bat to get the following 6 files

satans_hollow_cpu.vhd
satans_hollow_sound_cpu.vhd
satans_hollow_bg_bits_1.vhd
satans_hollow_bg_bits_2.vhd 
satans_hollow_sp_bits.vhd

make_vhdl_prom midssio_82s123.12d midssio_82s123.vhd


*DO NOT REDISTRIBUTE THESE FILES*

VHDL files are needed to compile and include roms into the project 

The script make_satans_hollow_proms.bat uses make_vhdl_prom executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c is also delivered.

---------------------------------
Compiling for de10_lite
---------------------------------
You can build the project with ROM image embeded in the sof file.
*DO NOT REDISTRIBUTE THESE FILES*

3 steps

 - put the VHDL ROM files (.vhd) into the rtl_dar/proms directory
 - build satans_hollow_de10_lite
 - program satans_hollow_de10_lite.sof

------------------------
------------------------
End of file
------------------------
