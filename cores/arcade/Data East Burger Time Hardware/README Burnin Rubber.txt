---------------------------------------------------------------------------------
-- 
-- Arcade: Burnin' Rubber for MiST by Gehstock
-- 18 December 2017
-- 
---------------------------------------------------------------------------------
-- Copyright (c) DAR - Dez 2017
-- https://sourceforge.net/projects/darfpga/files/Software%20VHDL/burnin_rubber/
---------------------------------------------------------------------------------
-- 
-- Only controls and OSD are rotated on VGA output.
-- 
-- 
-- Keyboard inputs :
--
--   ESC         : Coin
--   F1          : Start 1 player
--   F2          : Start 2 players
--   SPACE       : Turbo
--   LALT	 : Turbo
--   ARROW KEYS  : Movement
--
-- Joystick support.
-- 
---------------------------------------------------------------------------------



---------------------------------------------------------------------------------
-- burnin rubber by Dar (darfpga@aol.fr) (05/12/2017)
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
-- Use burnin_rubber_de10_lite.sdc to compile (Timequest constraints)
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
--   SPACE       : Jump 
--   RIGHT arrow : move right
--   LEFT  arrow : move left
--   UP    arrow : accelerate 
--   DOWN  arrow : slow down
--
-- Other details : see burnin_rubber.vhd
-- For USB inputs and SGT5000 audio output see my other project: xevious_de10_lite
---------------------------------------------------------------------------------
-- Use burnin_rubber_de10_lite.sdc to compile (Timequest constraints)
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

--  Use with MAME roms from rbubber.zip
--
--  Use make_burnin_rubber_proms.bat to build vhd file from binaries

--  Burnin' Rubber Hardware caracteristics :
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
--    Background tile map with scroll 0-511 pixels
--      1K*4bits ram
--      4K*8bits + 4K*4bits graphics rom 3bits/pixel
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
; Fitter Status                      ; Successful - Fri Dec 22 17:53:19 2017       ;
; Quartus Prime Version              ; 16.1.0 Build 196 10/24/2016 SJ Lite Edition ;
; Revision Name                      ; burnin_rubber_de10_lite                     ;
; Top-level Entity Name              ; burnin_rubber_de10_lite                     ;
; Family                             ; MAX 10                                      ;
; Device                             ; 10M50DAF484C6GES                            ;
; Timing Models                      ; Preliminary                                 ;
; Total logic elements               ; 3,565 / 49,760 ( 7 % )                      ;
;     Total combinational functions  ; 3,392 / 49,760 ( 7 % )                      ;
;     Dedicated logic registers      ; 1,099 / 49,760 ( 2 % )                      ;
; Total registers                    ; 1099                                        ;
; Total pins                         ; 105 / 360 ( 29 % )                          ;
; Total virtual pins                 ; 0                                           ;
; Total memory bits                  ; 433,024 / 1,677,312 ( 26 % )                ;
; Embedded Multiplier 9-bit elements ; 0 / 288 ( 0 % )                             ;
; Total PLLs                         ; 1 / 4 ( 25 % )                              ;
; UFM blocks                         ; 0 / 1 ( 0 % )                               ;
; ADC blocks                         ; 0 / 2 ( 0 % )                               ;
+------------------------------------+---------------------------------------------+

---------------
VHDL File list 
---------------

max10_pll_12M.vhd                    Pll 12MHz and 14 MHz from 50MHz altera mf

rtl_dar/burnin_rubber_de10_lite.vhd  Top level for de10_lite board

rtl_dar/burnin_rubber.vhd            Main video board logic
rtl_dar/burnin_rubber _sound.vhd     Main sound board logic

rtl_mikej/YM2149_linmix_sep.vhd      Copyright (c) MikeJ - Jan 2005

t65/T65.vhd                          Copyright (c) MikeJ - Jan 2005t65/T65_Pack.vhdt65/T65_MCode.vhdt65/T65_ALU.vhd
rtl_dar/kbd_joystick.vhd           Keyboard key to player/coin input
rtl_dar/io_ps2_keyboard.vhd        Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
rtl_dar/gen_ram.vhd                Generic RAM (Peter Wendrich + DAR Modification)
rtl_dar/decodeur_7_seg.vhd         7 segments display decoder

burnin_rubber_prog.vhd             Burnin' rubber video board PROMs
fg_sp_graphx_3.vhd
fg_sp_graphx_2.vhd
fg_sp_graphx_1.vhd
bg_graphx_2.vhd
bg_graphx_1.vhd

burnin_rubber_sound_prog.vhd       Burnin' rubber sound board PROM

----------------------
Quartus project files
----------------------
de10_lite/burnin_rubber_de10_lite.sdc    Timequest constraints file
de10_lite/burnin_rubber__de10_lite.qsf   de10_lite settings (files,pins...) 
de10_lite/burnin_rubber__de10_lite.qpf   de10_lite project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 8 ROMs binary files from brubber.zip (MAME)

brubber.12c,brubber.12d
bnj4e
bnj4f
bnj4h
bnj10e
bnj10f
bnj6c

------
Tools 
------
You need to build vhdl files from the binary file :
 - Unzip the roms file in the tools/burnin_rubber_unzip directory
 - Double click (execute) the script tools/make_burnin_rubber_proms.bat to get the following files

burnin_rubber_prog.vhd            : brubber.12c,brubber.12d
fg_sp_graphx_1.vhd                : bnj4e
fg_sp_graphx_2.vhd                : bnj4f
fg_sp_graphx_3.vhd                : bnj4h
bg_graphx_1.vhd                   : bnj10e
bg_graphx_2.vhd                   : bnj10f
burnin_rubber_prog_sound_prog.vhd : bnj6c

*DO NOT REDISTRIBUTE THESE FILES*

VHDL files are needed to compile and include roms into the project 

The script make_burnin_rubber_proms.bat uses make_vhdl_prom executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c is also delivered.

---------------------------------
Compiling for de10_lite
---------------------------------
You can build the project with ROM image embeded in the sof file.
*DO NOT REDISTRIBUTE THESE FILES*

3 steps

 - put the VHDL ROM files (.vhd) into the rtl_dar directory
 - build burnin_rubber_de10_lite
 - program burnin_rubber_de10_lite.sof

------------------------
------------------------
End of file
------------------------
