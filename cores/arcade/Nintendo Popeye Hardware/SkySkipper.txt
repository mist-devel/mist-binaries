---------------------------------------------------------------------------------
-- DE10_lite Top level for Sky Skipper by Dar (darfpga@aol.fr) (26/12/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
--
-- release rev 00 : initial release
--  (26/12/2019)
--
---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------
-- Use popeye_de10_lite.sdc to compile (Timequest constraints)
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

--   F7 : Service mode
--   F8 : 15kHz interlaced / 31 kHz progressive

--   SPACE  : punch

--   RIGHT arrow : move right
--   LEFT  arrow : move left
--   UP    arrow : up stairs
--   DOWN  arrow : down stairs
--
-- Other details : see popeye.vhd
-- For USB inputs and SGT5000 audio output see my other project: xevious_de10_lite
---------------------------------------------------------------------------------

---------------------------------------------------------------------------------
-- Popeye by Dar (darfpga@aol.fr) (26/12/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
--
-- release rev 00 : initial release
--  (26/12/2019)
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
--   Video        : VGA 31kHz/60Hz progressive and TV 15kHz interlaced
--   Coctail mode : NO
--   Sound        : OK

--  Use with MAME roms from popeye.zip & popeyeu.zip
--
--  Use make_popeye_proms.bat to build vhd file from binaries
--  (CRC list included)

--  Popeye Hardware caracteristics : TODO
--
---------------------------------------------------------------------------------
--  Schematics remarks :
--
--  Display is 512x448 pixels  (video 640 pixels x 256 interlaced lines @ 10.08MHz )

--       640/10.08e6  = 63.49us per line  (15.750KHz)
--       63.49*256 = 16.254ms per frame (61.52Hz)
--        
---------------------------------------------------------------------------------
+----------------------------------------------------------------------------------+
; Fitter Summary                                                                   ;
+------------------------------------+---------------------------------------------+
; Fitter Status                      ; Successful - Mon Dec 30 10:06:20 2019       ;
; Quartus Prime Version              ; 18.1.0 Build 625 09/12/2018 SJ Lite Edition ;
; Revision Name                      ; popeye_de10_lite                            ;
; Top-level Entity Name              ; popeye_de10_lite                            ;
; Family                             ; MAX 10                                      ;
; Device                             ; 10M50DAF484C6GES                            ;
; Timing Models                      ; Preliminary                                 ;
; Total logic elements               ; 3,354 / 49,760 ( 7 % )                      ;
;     Total combinational functions  ; 3,247 / 49,760 ( 7 % )                      ;
;     Dedicated logic registers      ; 865 / 49,760 ( 2 % )                        ;
; Total registers                    ; 865                                         ;
; Total pins                         ; 121 / 360 ( 34 % )                          ;
; Total virtual pins                 ; 0                                           ;
; Total memory bits                  ; 613,888 / 1,677,312 ( 37 % )                ;
; Embedded Multiplier 9-bit elements ; 0 / 288 ( 0 % )                             ;
; Total PLLs                         ; 1 / 4 ( 25 % )                              ;
; UFM blocks                         ; 0 / 1 ( 0 % )                               ;
; ADC blocks                         ; 0 / 2 ( 0 % )                               ;
+------------------------------------+---------------------------------------------+
