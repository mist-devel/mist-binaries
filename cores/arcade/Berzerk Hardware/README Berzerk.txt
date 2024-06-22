Berzerk Port to MiST




-------------------------------------------------
-- Berzerk FPGA by Dar - (darfpga@aol.fr)
-- http://darfpga.blogspot.fr
-------------------------------------------------
-- Berzerk releases
--
-- Release 0.0 - 07/07/2018 - Dar
-------------------------------------------------
Educational use only
Do not redistribute synthetized file with roms
Do not redistribute roms whatever the form
Use at your own risk
--------------------------------------------------------------------
make sure to use berzerk.zip roms 
--------------------------------------------------------------------
--
-- Main features :
--  PS2 keyboard input @gpio pins 35/34 (beware voltage translation/protection) 
--  Audio pwm output   @gpio pins 1/3 (beware voltage translation/protection) 
--
-- Uses 1 pll for 10MHz generation from 50MHz
--
-- Board key :
--   0 : reset game
--
-- Board switch :
--	  1 : tv 15Khz mode / VGA 640x480 mode
--
-- Keyboard players inputs :
--
--   F3 : Add coin
--   F2 : Start 2 players
--   F1 : Start 1 player
--   SPACE       : fire
--   RIGHT arrow : move right
--   LEFT  arrow : move left
--   UP    arrow : move up 
--   DOWN  arrow : move down
--
-- Sound effects : OK
-- Speech synthesis : todo 
--
---------------
VHDL File list 
---------------

max10_pll_10M.vhd       Pll 10MHz from 50MHz altera mf

berzerk_de10_lite.vhd   Top level for de10-lite board
berzerk.vhd             Main logic
berzerk_sound_fx.vhd    Music logic
berzerk_program1.vhd
berzerk_program2.vhd

video_gen.vhd           Video scheduler, syncs (h,v and composite)
line_doubler.vhd        Line doubler 15kHz -> 31kHz VGA

kbd_joystick.vhd        Keyboard key to player/coin input

T80se.vhd               T80 release 304  
T80_Reg.vhd
T80_Pack.vhd
T80_MCode.vhd
T80_ALU.vhd
T80.vhd

io_ps2_keyboard.vhd     Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
gen_ram.vhd

decodeur_7_seg.vhd      for debug

----------------------
Quartus project files
----------------------
de10_lite/berzerk_de10_lite.qsf   de10_lite settings (files,pins,...)
de10_lite/berzerk_de10_lite.qpf   de10_lite project
de10_lite/berzerk_de10_lite.sdc   timequest constraints


+----------------------------------------------------------------------------------+
; Fitter Summary                                                                   ;
+------------------------------------+---------------------------------------------+
; Fitter Status                      ; Successful - Sat Jul 07 07:38:44 2018       ;
; Quartus Prime Version              ; 16.1.0 Build 196 10/24/2016 SJ Lite Edition ;
; Revision Name                      ; berzerk_de10_lite                           ;
; Top-level Entity Name              ; berzerk_de10_lite                           ;
; Family                             ; MAX 10                                      ;
; Device                             ; 10M50DAF484C6GES                            ;
; Timing Models                      ; Preliminary                                 ;
; Total logic elements               ; 3,277 / 49,760 ( 7 % )                      ;
;     Total combinational functions  ; 3,043 / 49,760 ( 6 % )                      ;
;     Dedicated logic registers      ; 886 / 49,760 ( 2 % )                        ;
; Total registers                    ; 886                                         ;
; Total pins                         ; 121 / 360 ( 34 % )                          ;
; Total virtual pins                 ; 0                                           ;
; Total memory bits                  ; 241,664 / 1,677,312 ( 14 % )                ;
; Embedded Multiplier 9-bit elements ; 0 / 288 ( 0 % )                             ;
; Total PLLs                         ; 1 / 4 ( 25 % )                              ;
; UFM blocks                         ; 0 / 1 ( 0 % )                               ;
; ADC blocks                         ; 0 / 2 ( 0 % )                               ;
+------------------------------------+---------------------------------------------+
-----------------------------
Required ROMs (Not included)
-----------------------------

You need the following 8 ROMs from berzerk.zip 

berzerk_rc31_1c.rom0.1c CRC(ca566dbc) SHA1(fae2647f12f1cd82826db61b53b116a5e0c9f995)
berzerk_rc31_1d.rom1.1d CRC(7ba69fde) SHA1(69af170c4a39a3494dcd180737e5c87b455f9203)
berzerk_rc31_3d.rom2.3d CRC(a1d5248b) SHA1(a0b7842f6a5f86c16d80d78e7012c78b3ea11d1d)
berzerk_rc31_5d.rom3.5d CRC(fcaefa95) SHA1(07f849aa39f1e3db938187ffde4a46a588156ddc)
berzerk_rc31_6d.rom4.6d CRC(1e35b9a0) SHA1(5a5e549ec0e4803ab2d1eac6b3e7171aedf28244)
berzerk_rc31_5c.rom5.5c CRC(c8c665e5) SHA1(e9eca4b119549e0061384abf52327c14b0d56624)
berzerk_r_vo_1c.1c      CRC(2cfe825d) SHA1(f12fed8712f20fa8213f606c4049a8144bfea42e)
berzerk_r_vo_2c.2c      CRC(d2b6324e) SHA1(20a6611ad6ec19409ac138bdae7bdfaeab6c47cf)

------
Tools 
------
You need to build vhdl ROM image files from the binary file :
 - Unzip the roms file in the tools/berzerk_unzip directory
 - Double click (execute) the script tools/berzerk_unzip/make_berzerk_proms.bat to get the following files

berzerk_program1.vhd
berzerk_program2.vhd

*DO NOT REDISTRIBUTE THESE FILES*

The script make_berzerk_proms uses make_vhdl_prom and and duplicate_byte executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c and and duplicate_byte.c is also delivered.

---------------------------------
Compiling for de10_lite
---------------------------------
You can rebuild the project with ROM image embeded in the sof file. DO NOT REDISTRIBUTE THESE FILES.
4 steps

 - put the VHDL rom files into the project directory
 - rebuild berzerk_de10_lite
 - program berzerk_de10_lite.sof into the fpga 

------------------------
End of file
------------------------