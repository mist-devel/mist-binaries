-- Zaxxon (Super Zaxxon, Future Spy) port to MiST
--
-- Usage:
-- Create .ROM and ARC files from MAME ROM zip files using the mra utility and the mra files.
-- Example: mra -A -z /path/to/mame/roms Zaxxon.mra
-- Copy the resulting ROM and ARC files to the root of the SD Card, next to the Zaxxon.rbf.
--
-- MRA utilty: https://github.com/sebdel/mra-tools-c
--
---------------------------------------------------------------------------------
-- DE10_lite Top level for Zaxxon by Dar (darfpga@aol.fr) (23/11/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------
-- Use zaxxon_de10_lite.sdc to compile (Timequest constraints)
-- /!\
-- Don't forget to set device configuration mode with memory initialization 
--  (Assignments/Device/Pin options/Configuration mode)
---------------------------------------------------------------------------------
--
-- release rev 00 : initial release
--  (23/11/2019)
---------------------------------------------------------------------------------
--
-- Main features :
--  PS2 keyboard input @gpio pins 35/34 (beware voltage translation/protection) 
--  Audio pwm output   @gpio pins 1/3 (beware voltage translation/protection) 
--
--  Video         : TV 15kHz
--  Cocktail mode : Yes
--  Sound         : No (atm)
-- 
-- For hardware schematic see my other project : NES
--
-- Uses 1 pll 24MHz from 50MHz
--
-- Board key :
--   0 : reset game
--
-- Keyboard players inputs :
--
--   F1 : Add coin
--   F2 : Start 1 player
--   F3 : Start 2 players

--   SPACE       : fire
--   RIGHT arrow : move right
--   LEFT  arrow : move left
--   UP    arrow : move up
--   DOWN  arrow : move down
--
--   F4 : flip screen (additional feature)
--   F5 : Service mode ?! (not tested)
--   F7 : uprigth/cocktail mode (required reset)

--
-- Other details : see zaxxon.vhd
-- For USB inputs and SGT5000 audio output see my other project: xevious_de10_lite
---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
-- Zaxxon by Dar (darfpga@aol.fr) (23/11/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
--
-- release rev 00 : initial release
--  (23/11/2019)
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
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------

--  Features :
--   Video        : TV 15kHz
--   Coctail mode : Yes
--   Sound        : No (atm)

--  Use with MAME roms from zaxxon.zip
--
--  Use make_zaxxon_proms.bat to build vhd file from binaries
--  (CRC list included)

--  Zaxxon (Gremlin/SEGA) Hardware caracteristics :
--
--  VIDEO : 1xZ80@3MHz CPU accessing its program rom, working ram,
--    sprite data ram, I/O, sound board register and trigger.
--		  20Kx8bits program rom
--
--    3 graphic layers
--
--    One char map 32x28 tiles 
--      2x2Kx8bits graphics rom 2bits/pixel
--      static layout color rom 16 color/tile
--
--    One diagonal scrolling background map 8x8 tiles
--      4x8Kx8bits tile map rom (10 bits code + 4bits color)
--      3x8Kx8bits graphics rom 3bits/pixel
--
--    32 sprites, up to 8/scanline 32x32pixels with flip H/V
--      6bits code + 2 bits flip h/v, 5 bits color 
--      3x8Kx8bits graphics rom 3bits/pixel
--      
--    general palette 256 colors 3red 3green 2blue 
--       char 2bits/tile +  4bits color set/tile + 1bits global set
--       background 3bits/tile + 4 bits color set/tile + 1bits global set
--       sprites   3bits/sprite + 5 bits color set/sprite
--
--    Working ram : 4Kx8bits
--    char ram    : 1Kx8bits code, (+ static layout color rom)
--    sprites ram : 256x8bits + 32x9bits intermediate buffer + 256x8bits line buffer
--

--  SOUND : see zaxxon_sound_board.vhd

---------------------------------------------------------------------------------
--  Schematics remarks : IC board 834-0214 and 834-0257 or 834-0211
--  some details are missing or seems to be wrong:
--     - sprite buffer addresses flip control seems to be incomplete
--       (fliping adresses both at read and write is useless !)
--     - diagonal scrolling seems to be incomplete (BCK on U52 pin 4 where from ?)
--     - 834-0211 sheet 6 of 9 : 74ls161 U26 at C-5 no ouput used !
--     - 834-0211 sheet 7 of 9 : /128H, 128H and 256H dont agree with U21 Qc/Qd 
--       output ! 
--
--  tips :
--     Background tiles scrolls over H (and V) but map rom output are latched
--     at fixed Hcnt position (4H^). Graphics rom ouput latch is scrolled over H.
--
--     During visible area (hcnt(8) = 1) sprite data are transfered from sp_ram
--     to sp_online_ram. Only sprites visible on (next) line are transfered. So
--     64 sprites are defined in sp_ram and only 8 can be transfered to 
--     sp_online_ram. 
--
--     During line fly back (hcnt(8) = 0) sp_online_ram is read and sprite
--     graphics feed line buffer. Line buffer is then read starting from
--     visible line.
--
--     Sprite data transfer is done at pixel rate : each sprite is 4 bytes data.
--     Visible area allows 64 sprites x 4 data (256 pixels) to be read, only 8
--     sprites (the ones on next line) are transfered.
--
--     Line buffer feed is done at twice pixel rate : 8 sprites x 32 pixels / 2
--     (256/2 = 128 pixels = fly back area length).
--
--     sp_online_ram is 9 bits wide. 9th bits is set during tranfer for actual 
--     sprites data written. 9th bit is reset during fly back area after data
--     are read. So 9th bits are all set to 0s at start of next transfer.
--
--     When feeding line buffer sprites graphic data are written only of no 
--     graphics have been written previouly for that line. Line buffer pixels are
--     set to 0s after each pixel read during visible area. Thus line buffer is 
--     fully cleared at start of next feeding.
--
--     Global screen flip is fully managed at hardware level. This allow to 
--     easily add an external flip screen feature.

+----------------------------------------------------------------------------------+
; Fitter Summary                                                                   ;
+------------------------------------+---------------------------------------------+
; Fitter Status                      ; Successful - Fri Nov 29 21:07:56 2019       ;
; Quartus Prime Version              ; 18.1.0 Build 625 09/12/2018 SJ Lite Edition ;
; Revision Name                      ; zaxxon_de10_lite                            ;
; Top-level Entity Name              ; zaxxon_de10_lite                            ;
; Family                             ; MAX 10                                      ;
; Device                             ; 10M50DAF484C6GES                            ;
; Timing Models                      ; Preliminary                                 ;
; Total logic elements               ; 2,754 / 49,760 ( 6 % )                      ;
;     Total combinational functions  ; 2,646 / 49,760 ( 5 % )                      ;
;     Dedicated logic registers      ; 653 / 49,760 ( 1 % )                        ;
; Total registers                    ; 653                                         ;
; Total pins                         ; 105 / 360 ( 29 % )                          ;
; Total virtual pins                 ; 0                                           ;
; Total memory bits                  ; 867,616 / 1,677,312 ( 52 % )                ;
; Embedded Multiplier 9-bit elements ; 0 / 288 ( 0 % )                             ;
; Total PLLs                         ; 1 / 4 ( 25 % )                              ;
; UFM blocks                         ; 0 / 1 ( 0 % )                               ;
; ADC blocks                         ; 0 / 2 ( 0 % )                               ;
+------------------------------------+---------------------------------------------+

---------------
VHDL File list 
---------------

de10_lite/max10_pll_24M.vhd        Pll 24MHz from 50MHz altera mf

rtl_dar/zaxxon_de10_lite.vhd         Top level for de10_lite board
rtl_dar/zaxxon.vhd                   Main CPU and video boards logic

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

rtl_dar/proms/zaxxon_cpu.vhd         CPU board PROMS
rtl_dar/proms/zaxxon_char_bits_2.vhd
rtl_dar/proms/zaxxon_char_bits_1.vhd
rtl_dar/proms/zaxxon_char_color.vhd
rtl_dar/proms/zaxxon_palette.vhd

rtl_dar/proms/zaxxon_map_2.vhd       Video board PROMS
rtl_dar/proms/zaxxon_map_1.vhd       
rtl_dar/proms/zaxxon_sp_bits_3.vhd
rtl_dar/proms/zaxxon_sp_bits_2.vhd
rtl_dar/proms/zaxxon_sp_bits_1.vhd
rtl_dar/proms/zaxxon_bg_bits_3.vhd
rtl_dar/proms/zaxxon_bg_bits_2.vhd
rtl_dar/proms/zaxxon_bg_bits_1.vhd

----------------------
Quartus project files
----------------------
de10_lite/zaxxon_de10_lite.sdc   Timequest constraints file
de10_lite/zaxxon_de10_lite.qsf   de10_lite settings (files,pins...) 
de10_lite/zaxxon_de10_lite.qpf   de10_lite project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 17 ROMs binary files from zaxxon.zip (MAME)

zaxxon_rom3d.u27  CRC 6e2b4a30
zaxxon_rom2d.u28  CRC 1c9ea398
zaxxon_rom1d.u29  CRC 1c123ef9
zaxxon_rom14.u68  CRC 07bf8c52
zaxxon_rom15.u69  CRC c215edcb
zaxxon_rom6.u113  CRC 6e07bb68
zaxxon_rom5.u112  CRC 0a5bce6a
zaxxon_rom4.u111  CRC a5bf1465
zaxxon_rom11.u77  CRC eaf0dd4b
zaxxon_rom12.u78  CRC 1c5369c7
zaxxon_rom13.u79  CRC ab4e8a9a
zaxxon_rom8.u91   CRC 28d65063
zaxxon_rom7.u90   CRC 6284c200
zaxxon_rom10.u93  CRC a95e61fd
zaxxon_rom9.u92   CRC 7e42691f
mro16.u76         CRC 6cc6695b (or zaxxon.u98)
zaxxon.u72        CRC deaa21f7

------
Tools 
------
You need to build vhdl files from the binary file :
 - Unzip the roms file in the tools/zaxxon_unzip directory
 - Double click (execute) the script tools/make_zaxxon_proms.bat to get the following 13 files

zaxxon_cpu.vhd
zaxxon_char_bits_1.vhd
zaxxon_char_bits_2.vhd
zaxxon_bg_bits_1.vhd
zaxxon_bg_bits_2.vhd
zaxxon_bg_bits_3.vhd
zaxxon_sp_bits_1.vhd
zaxxon_sp_bits_2.vhd
zaxxon_sp_bits_3.vhd
zaxxon_map_1.vhd
zaxxon_map_2.vhd
zaxxon_palette.vhd
zaxxon_char_color.vhd

*DO NOT REDISTRIBUTE THESE FILES*

VHDL files are needed to compile and include roms into the project 

The script make_tron_proms.bat uses make_vhdl_prom executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c is also delivered.

---------------------------------
Compiling for de10_lite
---------------------------------
You can build the project with ROM image embeded in the sof file.
*DO NOT REDISTRIBUTE THESE FILES*

3 steps

 - put the VHDL ROM files (.vhd) into the rtl_dar/proms directory
 - build zaxxon_de10_lite
 - program zaxxon_de10_lite.sof

------------------------
------------------------
End of file
------------------------
