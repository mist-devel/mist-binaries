---------------------------------------------------------------------------------
-- 
-- Arcade: Burger Time for MiST by Gehstock
-- 18 December 2017
-- 
---------------------------------------------------------------------------------
-- Copyright (c) DAR - Dez 2017
-- https://sourceforge.net/projects/darfpga/files/Software%20VHDL/burger_time/
---------------------------------------------------------------------------------
-- 
-- Only controls are rotated on VGA output.
-- 
-- 
-- Keyboard inputs :
--
--   ESC         : Coin
--   F1          : Start 1 player
--   F2          : Start 2 players
--   SPACE       : Pepper
--   LALT	 : 
--   ARROW KEYS  : Movement
--
-- Joystick support.
-- 
---------------------------------------------------------------------------------

---------------------------------------------------------------------------------
-- Burger Time by Dar (darfpga@aol.fr) (27/12/2017)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------
-- gen_ram.vhd & io_ps2_keyboard
-------------------------------- 
-- Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
-- http://www.syntiac.com/fpga64.html
---------------------------------------------------------------------------------
-- T65(b) core.Ver 301 by MikeJ March 2005
-- Latest version from www.fpgaarcade.com (original www.opencores.org)
---------------------------------------------------------------------------------
-- YM2149 (AY-3-8910)
-- Copyright (c) MikeJ - Jan 2005
---------------------------------------------------------------------------------
-- Use burger_time_de10_lite.sdc to compile (Timequest constraints)
-- /!\
-- Don't forget to set device configuration mode with memory initialization 
--  (Assignments/Device/Pin options/Configuration mode)
---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
--
-- Main features :
--  PS2 keyboard input @gpio pins 35/34 (beware voltage translation/protection) 
--  Audio pwm output   @gpio pins 1/3 (beware voltage translation/protection) 
--
-- Uses 1 pll for 12MHz generation from 50MHz
--
-- Board key :
--   0 : reset game
--
-- Keyboard players inputs :
--
--   F3 : Add coin
--   F2 : Start 2 players
--   F1 : Start 1 player
--   SPACE       : pepper 
--   RIGHT arrow : move right
--   LEFT  arrow : move left
--   UP    arrow : move up 
--   DOWN  arrow : move down
--
-- Other details : see burger_time.vhd
-- For USB inputs and SGT5000 audio output see my other project: xevious_de10_lite
---------------------------------------------------------------------------------
-- Use burger_time_de10_lite.sdc to compile (Timequest constraints)
-- /!\
-- Don't forget to set device configuration mode with memory initialization 
--  (Assignments/Device/Pin options/Configuration mode)
---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
--  Features :
--   TV 15KHz mode only (atm)
--   Coctail mode ok
--   Sound ok
--   No external RAM/SDRAM required

--  Use with MAME roms from btime.zip
--
--  Use make_burger_time_proms.bat to build vhd file from binaries

--  Burger Time Hardware caracteristics :
--
--  VIDEO : 1x6502@750kHz CPU accessing its program rom, working ram,
--    foreground and sprite data ram, I/O, sound board register and trigger.
--	16Kx8bits program rom
--       2Kb8bits working ram
--
--    One char 8x8 tile map 32x30 + sprites data
--      1Kx8bits + 1Kx2bits
--      3x8Kx8bits graphics rom 3bits/pixel
--      8 colors with ram palette
--
--    8 sprites 16*16 with priorities and flip H/V
--      use char graphics rom and colors
--
--    Char/sprites 8 colors among 256 colors
--      8bits 3red/3green/2blue
--
--    Sprites buffer rams 3x256bits  
--
--    Background static tile map with scroll
--      2K*8bits tile map rom
--      3x2K*8bits graphics rom 3bits/pixel
--      8 colors with ram palette
--      16x16 tiles
--
--  SOUND : 1x6502@500kHz CPU accessing its program rom, working ram, 2x-AY3-8910,
--      command registers, triggers.
--      2Kx8bits working ram
--      4Kx8bits program rom
--
--      1xAY-3-8910
--        3 sound channels
--      1xAY-3-8910
--        3 sound channels 
--
--      Pass band active filter on channel A of AY#2
--
+----------------------------------------------------------------------------------+
; Fitter Summary                                                                   ;
+------------------------------------+---------------------------------------------+
; Fitter Status                      ; Successful - Wed Dec 27 10:02:23 2017       ;
; Quartus Prime Version              ; 16.1.0 Build 196 10/24/2016 SJ Lite Edition ;
; Revision Name                      ; burger_time_de10_lite                       ;
; Top-level Entity Name              ; burger_time_de10_lite                       ;
; Family                             ; MAX 10                                      ;
; Device                             ; 10M50DAF484C6GES                            ;
; Timing Models                      ; Preliminary                                 ;
; Total logic elements               ; 3,540 / 49,760 ( 7 % )                      ;
;     Total combinational functions  ; 3,382 / 49,760 ( 7 % )                      ;
;     Dedicated logic registers      ; 1,090 / 49,760 ( 2 % )                      ;
; Total registers                    ; 1090                                        ;
; Total pins                         ; 105 / 360 ( 29 % )                          ;
; Total virtual pins                 ; 0                                           ;
; Total memory bits                  ; 465,792 / 1,677,312 ( 28 % )                ;
; Embedded Multiplier 9-bit elements ; 0 / 288 ( 0 % )                             ;
; Total PLLs                         ; 1 / 4 ( 25 % )                              ;
; UFM blocks                         ; 0 / 1 ( 0 % )                               ;
; ADC blocks                         ; 0 / 2 ( 0 % )                               ;
+------------------------------------+---------------------------------------------+

---------------
VHDL File list 
---------------

max10_pll_12M.vhd                    Pll 12MHz and 14 MHz from 50MHz altera mf

rtl_dar/burger_time_de10_lite.vhd    Top level for de10_lite board 

rtl_dar/burger_time.vhd              Main video board logic
rtl_dar/burger_time_sound.vhd        Main sound board logic

rtl_mikej/YM2149_linmix_sep.vhd      Copyright (c) MikeJ - Jan 2005

t65/T65.vhd                        Copyright (c) MikeJ - Jan 2005t65/T65_Pack.vhdt65/T65_MCode.vhdt65/T65_ALU.vhd
rtl_dar/kbd_joystick.vhd           Keyboard key to player/coin input
rtl_dar/io_ps2_keyboard.vhd        Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
rtl_dar/gen_ram.vhd                Generic RAM (Peter Wendrich + DAR Modification)
rtl_dar/decodeur_7_seg.vhd         7 segments display decoder

burger_time_prog.vhd             Burger Time video board PROMs
fg_sp_graphx_3.vhd
fg_sp_graphx_2.vhd
fg_sp_graphx_1.vhd
bg_map.vhd
bg_graphx_3.vhd
bg_graphx_2.vhd
bg_graphx_1.vhd

burger_time_sound_prog.vhd       Burger Time sound board PROM

----------------------
Quartus project files
----------------------
de10_lite/burger_time_de10_lite.sdc   Timequest constraints file
de10_lite/burger_time_de10_lite.qsf   de10_lite settings (files,pins...) 
de10_lite/burger_time_de10_lite.qpf   de10_lite project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 15 ROMs binary files from btime.zip (MAME)

aa04.9b,  aa06.13b, aa05.10b, aa07.15b 
aa12.7k,  ab13.9k
ab10.10k, ab11.12k 
aa8.13k,  ab9.15k
ab00.1b
ab01.3b
ab02.4b
ab03.6b
ab14.12h

------
Tools 
------
You need to build vhdl files from the binary file :
 - Unzip the roms file in the tools/burger_time_unzip directory
 - Double click (execute) the script tools/make_burger_time_proms.bat to get the following files

burger_time_prog.vhd       : aa04.9b + aa06.13b + aa05.10b + aa07.15b 
fg_sp_graphx_1.vhd         : aa12.7k  + ab13.9k
fg_sp_graphx_2.vhd         : ab10.10k + ab11.12k 
fg_sp_graphx_3.vhd         : aa8.13k  + ab9.15k
bg_graphx_1.vhd            : ab00.1b 
bg_graphx_2.vhd            : ab01.3b 
bg_graphx_3.vhd            : ab02.4b 
bg_map.vhd                 : ab03.6b 
burger_time_sound_prog.vhd : ab14.12h

*DO NOT REDISTRIBUTE THESE FILES*

VHDL files are needed to compile and include roms into the project 

The script make_burger_time_proms.bat uses make_vhdl_prom executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c is also delivered.

---------------------------------
Compiling for de10_lite
---------------------------------
You can build the project with ROM image embeded in the sof file.
*DO NOT REDISTRIBUTE THESE FILES*

3 steps

 - put the VHDL ROM files (.vhd) into the rtl_dar directory
 - build burger_time_de10_lite
 - program burger_time_de10_lite.sof

------------------------
------------------------
End of file
------------------------
