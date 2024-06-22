Midway MCR3 MiST port

Common controls:
ESC - coin for all players
5,6,7,8 - coin for player 1,2,3,4 (MAME compatible)
F1,F2,F3 (or 1,2,3) - player 1,2,3,4 start
Controller 1 and 2 can be substitued with MAME-keys

Supported games:

Sarge
=====
Controls:
Player 1: joystick 1 and joystick 2 (two sticks mode), joystick1 only(one stick mode)
Player 2: joystick 3 and joystick 4 (two sticks mode), joystick2 only(one stick mode)

Max RPM
=======
Controls:
Gear : Button1/Button2
Steering: Left/Right
Throttle/Brake: Up/Down

Rampage
=======
Normal controls for maximum of 3 players.

Power Drive
===========
3 players support 
Buttons 1,2 - Gas
Button  3   - Wheelie
Button  4   - Shift

Demolition Derby
================
4 players support
Gas: Button 1
Brake: Button 2
Steering: Left/Right

Tapper, Timber
==============
Normal controls for maximum of 2 players

Discs of Tron
=============

                             Joy/keyboard   MAME key
        Forward         :     Up
        Backward        :     Down
        Left            :     Left
        Right           :     Right
        Coin            :     ESC             5,6
        1 Player        :     F1               1
        2 Player        :     F2               2
        Fire            :     Button A       LCtrl
        Block           :     Button B       LAlt
        Aim Left        :     Button X,L      Z,C
        Aim Right       :     Button Y,R      X,V
        Aim Up          :     Button C       Space
        Aim Down        :     Button D       LShift

Usage:
======

Create ROM and ARC files from MAME ROM zip files using the mra utility and the MRA files.
Example: mra -A -z /path/to/mame/roms Rampage.mra
Copy the RBF and the ARC files to the same folder.
Copy the ROM files to the root of the SD Card.

MRA utilty: https://github.com/sebdel/mra-tools-c

Some games are storing settings/high scores in a non-volatile RAM. It can be saved to
the SD Card with the "Save NVRAM" option in the OSD menu. It'll be restored when
the core is loaded next time.

Based on Darfpga's work:
---------------------------------------------------------------------------------
-- DE10_lite Top level for Timber (Midway MCR) by Dar (darfpga@aol.fr) (22/11/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------

--
-- release rev 00 : initial release
--  (22/11/2019)
--
--   /!\ /!\ cannot fit de10_lite : Full size sprite rom required more room or
--           sdram usage (TO DO)
--
---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------
-- Use timber_de10_lite.sdc to compile (Timequest constraints)
-- /!\
-- Don't forget to set device configuration mode with memory initialization 
--  (Assignments/Device/Pin options/Configuration mode)
---------------------------------------------------------------------------------
--
-- Main features :
--  PS2 keyboard input @gpio pins 35/34 (beware voltage translation/protection) 
--  Audio pwm output   @gpio pins 1/3 (beware voltage translation/protection) 
--
--  Video         : VGA 31kHz/60Hz progressive and TV 15kHz interlaced
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
--   F4 : Demo sound
--   F5 : Separate audio
--   F7 : Service mode
--   F8 : 15kHz interlaced / 31 kHz progressive

--   SPACE       : bouton 1
--   v key       : bouton 2
--   RIGHT arrow : move right
--   LEFT  arrow : move left
--   UP    arrow : move up
--   DOWN  arrow : move down
--
-- Other details : see timber.vhd
-- For USB inputs and SGT5000 audio output see my other project: xevious_de10_lite
---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
-- Timber by Dar (darfpga@aol.fr) (22/11/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
--
-- release rev 00 : initial release
--  (22/11/2019)
--
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
--   Video        : VGA 31Khz/60Hz progressive and TV 15kHz interlaced
--   Coctail mode : NO
--   Sound        : OK

--  Use with MAME roms from timber.zip
--
--  Use make_timber_proms.bat to build vhd file from binaries
--  (CRC list included)

--  Timber (midway mcr) Hardware caracteristics :
--
--  VIDEO : 1xZ80@3MHz CPU accessing its program rom, working ram,
--    sprite data ram, I/O, sound board register and trigger.
--		  56Kx8bits program rom
--
--    One char/background tile map 30x32
--      2x8Kx8bits graphics rom 4bits/pixel + 2 bit color set
--      rbg programmable ram palette 64 colors 9bits : 3red 3green 3blue
--
--    128 sprites, up to ~30/line, 32x32 with flip H/V
--      4x32Kx8bits graphics rom 4bits/pixel + 2 bit color set
--      rbg programmable ram palette 64 colors 9bits : 3red 3green 3blue 
--
--    Working ram : 2Kx8bits
--    video (char/background) ram  : 2Kx8bits
--    Sprites ram : 512x8bits + 512x8bits cache buffer

--    Sprites line buffer rams (graphics and colors) : 1 scan line delay flip/flop 2x256x16bits
--
--  SOUND : see tron_sound_board.vhd

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
---------------------------------------------------------------------------------

 /!\ /!\ HALF SIZE SPRITE ROM  /!\ /!\

Full size sprite rom would required more room or external ram

+----------------------------------------------------------------------------------+
; Fitter Summary                                                                   ;
+------------------------------------+---------------------------------------------+
; Fitter Status                      ; Successful - Fri Nov 22 17:33:36 2019       ;
; Quartus Prime Version              ; 18.1.0 Build 625 09/12/2018 SJ Lite Edition ;
; Revision Name                      ; timber_de10_lite                            ;
; Top-level Entity Name              ; timber_de10_lite                            ;
; Family                             ; MAX 10                                      ;
; Device                             ; 10M50DAF484C6GES                            ;
; Timing Models                      ; Preliminary                                 ;
; Total logic elements               ; 6,779 / 49,760 ( 14 % )                     ;
;     Total combinational functions  ; 6,540 / 49,760 ( 13 % )                     ;
;     Dedicated logic registers      ; 1,724 / 49,760 ( 3 % )                      ;
; Total registers                    ; 1724                                        ;
; Total pins                         ; 105 / 360 ( 29 % )                          ;
; Total virtual pins                 ; 0                                           ;
; Total memory bits                  ; 1,399,360 / 1,677,312 ( 83 % )  <--  WITH HALF SIZE SPRITE ROM ONLY
; Embedded Multiplier 9-bit elements ; 0 / 288 ( 0 % )                             ;
; Total PLLs                         ; 1 / 4 ( 25 % )                              ;
; UFM blocks                         ; 0 / 1 ( 0 % )                               ;
; ADC blocks                         ; 0 / 2 ( 0 % )                               ;
+------------------------------------+---------------------------------------------+

---------------
VHDL File list 
---------------

de10_lite/max10_pll_40M.vhd        Pll 40MHz from 50MHz altera mf 

rtl_dar/timber_de10_lite.vhd       Top level for de10_lite board
rtl_dar/timber.vhd                 Main CPU and video boards logic
rtl_dar/timber_sound_board.vhd     Main sound board logic
rtl_dar/ctc_controler.vhd          Z80-CTC controler 
rtl_dar/ctc_counter.vhd            Z80-CTC counter

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

rtl_dar/proms/timber_cpu.vhd         CPU board PROMS
rtl_dar/proms/timber_bg_bits_2.vhd
rtl_dar/proms/timber_bg_bits_1.vhd

rtl_dar/proms/timber_sp_bits.vhd     Video board PROMS

rtl_dar/proms/timber_sound_cpu.vhd   Sound board PROMS
rtl_dar/proms/midssio_82s123.vhd

----------------------
Quartus project files
----------------------
de10_lite/timber_de10_lite.sdc   Timequest constraints file
de10_lite/timber_de10_lite.qsf   de10_lite settings (files,pins...) 
de10_lite/timber_de10_lite.qpf   de10_lite project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 18 ROMs binary files from timber.zip and midssio.zip(MAME)

timpg0.bin  CRC 377032ab
timpg1.bin  CRC fd772836
timpg2.bin  CRC 632989f9
timpg3.bin  CRC dae8a0dc

tima7.bin   CRC c615dc3e
tima8.bin   CRC 83841c87
tima9.bin   CRC 22bcdcd3

timbg1.bin  CRC b1cb2651
timbg0.bin  CRC 2ae352c4

timfg1.bin  CRC 81de4a73
timfg0.bin  CRC 7f3a4f59
timfg3.bin  CRC 37c03272
timfg2.bin  CRC e2c2885c
timfg5.bin  CRC eb636216
timfg4.bin  CRC b7105eb7
timfg7.bin  CRC d9c27475
timfg6.bin  CRC 244778e8

midssio_82s123.12d CRC e1281ee9

------
Tools 
------
You need to build vhdl files from the binary file :
 - Unzip the roms file in the tools/timber_unzip directory
 - Double click (execute) the script tools/make_timber_proms.bat to get the following 6 files

timber_cpu.vhd
timber_sound_cpu.vhd
timber_bg_bits_1.vhd
timber_bg_bits_2.vhd 
timber_sp_bits.vhd
midssio_82s123.vhd


*DO NOT REDISTRIBUTE THESE FILES*

VHDL files are needed to compile and include roms into the project 

The script make_timber_proms.bat uses make_vhdl_prom executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c is also delivered.

---------------------------------
Compiling for de10_lite
---------------------------------
You can build the project with ROM image embeded in the sof file.
*DO NOT REDISTRIBUTE THESE FILES*

3 steps

 - put the VHDL ROM files (.vhd) into the rtl_dar/proms directory
 - build timber_de10_lite
 - program timber_de10_lite.sof

------------------------
------------------------
End of file
------------------------
