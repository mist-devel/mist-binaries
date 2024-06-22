-- Crater Raider MiST port
--
-- Usage:
-- Create ROM file from MRA file and MAME crater.zip file using the MRA utility
-- Copy the ROM and the RBF to the SD Card
-- Example: mra -z /path/to/mame/roms "Crater Raider.mra"
-- MRA utility: https://github.com/sebdel/mra-tools-c
--
---------------------------------------------------------------------------------
-- DE10_lite Top level for Crater Raider (Midway MCR) by Dar (darfpga@aol.fr) (06/12/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
--
-- release rev 00 : initial release
--  (06/12/2019)
--
--   fit de10_lite OK : 
--     - use sdram loader to load sprites data first then load spy hunter core

---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------
-- Use spy_hunter_de10_lite.sdc to compile (Timequest constraints)
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
--  Sound         : OK - missing Chip/cheap squeak deluxe board
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
--   F3 : toggle lamp text display on screen
--   F4 : Demo sound
--   F5 : Separate audio
--   F7 : Service mode
--   F8 : 15kHz interlaced / 31 kHz progressive

--   F2     : toggle hi/low gear shift
--   SPACE  : oil
--   f key  : missile
--   g key  : van
--   t key  : smoke
--   v key  : gun

--   RIGHT arrow : turn right side (auto center when released)
--   LEFT  arrow : tirn left side (auto center when released)
--   UP    arrow : gas increase
--   DOWN  arrow : gas decrease
--
-- Other details : see timber.vhd
-- For USB inputs and SGT5000 audio output see my other project: xevious_de10_lite
---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
-- Spy hunter by Dar (darfpga@aol.fr) (06/12/2019)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
--
-- release rev 00 : initial release
--  (06/12/2019)
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
--   Sound        : OK - missing cheap/chip squeak deluxe board

--  Use with MAME roms from spyhunt.zip
--
--  Use make_spyhunt_proms.bat to build vhd file from binaries
--  (CRC list included)

--  Spy hunter (midway mcr) Hardware caracteristics :
--
--  VIDEO : 1xZ80@3MHz CPU accessing its program rom, working ram,
--    sprite data ram, I/O, sound board register and trigger.
--		  56Kx8bits program rom
--
--    One char tile map 30x32 tiles of 8x8 pixels 
--      1x4Kx8bits graphics rom 2bits/pixel single hard wired color set 

--    One scroling background tile map 16x64 tile of 8x32 pixels
--      2x16Kx8bits graphics rom 4bits/pixel single color set
--      rbg programmable ram palette 64 (16 for background) colors 9bits : 3red 3green 3blue
--
--    128 sprites, up to ~30/line, 32x32 with flip H/V
--      4x32Kx8bits graphics rom 4bits/pixel single color set
--      rbg programmable ram palette 64 (16 for sprites) colors 9bits : 3red 3green 3blue 
--
--    Working ram : 2Kx8bits
--    video char ram  : 1Kx8bits
--    video background ram  : 2Kx8bits
--    Sprites ram : 512x8bits + 512x8bits cache buffer

--    Sprites line buffer rams (graphics and colors) : 1 scan line delay flip/flop 2x256x8bits
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

+----------------------------------------------------------------------------------+
; Fitter Summary                                                                   ;
+------------------------------------+---------------------------------------------+
; Fitter Status                      ; Successful - Fri Dec 13 19:55:32 2019       ;
; Quartus Prime Version              ; 18.1.0 Build 625 09/12/2018 SJ Lite Edition ;
; Revision Name                      ; spy_hunter_de10_lite                        ;
; Top-level Entity Name              ; spy_hunter_de10_lite                        ;
; Family                             ; MAX 10                                      ;
; Device                             ; 10M50DAF484C6GES                            ;
; Timing Models                      ; Preliminary                                 ;
; Total logic elements               ; 7,259 / 49,760 ( 15 % )                     ;
;     Total combinational functions  ; 6,938 / 49,760 ( 14 % )                     ;
;     Dedicated logic registers      ; 1,984 / 49,760 ( 4 % )                      ;
; Total registers                    ; 2000                                        ;
; Total pins                         ; 160 / 360 ( 44 % )                          ;
; Total virtual pins                 ; 0                                           ;
; Total memory bits                  ; 881,216 / 1,677,312 ( 53 % )  <--  WITH SDRAM SPRITE DATA LOADER
; Embedded Multiplier 9-bit elements ; 0 / 288 ( 0 % )                             ;
; Total PLLs                         ; 1 / 4 ( 25 % )                              ;
; UFM blocks                         ; 0 / 1 ( 0 % )                               ;
; ADC blocks                         ; 0 / 2 ( 0 % )                               ;
+------------------------------------+---------------------------------------------+
---------------
VHDL File list 
---------------
de10_lite/max10_pll_120M.vhd        Pll 120MHz and 40MHz from 50MHz altera mf 

rtl_dar/spy_hunter_de10_lite.vhd    Top level for de10_lite board
rtl_dar/spy_hunter.vhd              Main CPU and video boards logic
rtl_dar/spy_hunter_sound_board.vhd  Main sound board logic
rtl_dar/ctc_controler.vhd           Z80-CTC controler 
rtl_dar/ctc_counter.vhd             Z80-CTC counter
rtl_dar/sdram.sv                    specific sdram interface 8bits write / 8x16bits burst read

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
rtl_dar/cmos_ram.vhd               ram that can be initialized store setup

rtl_dar/proms/spy_hunter_cpu.vhd        CPU board PROMS
rtl_dar/proms/spy_hunter_bg_bits_2.vhd
rtl_dar/proms/spy_hunter_bg_bits_1.vhd
rtl_dar/proms/spy_hunter_ch_bits.vhd

rtl_dar/proms/spy_hunter_sp_bits_1.vhd  Video board PROMS (to be used with sdram loader)
rtl_dar/proms/spy_hunter_sp_bits_2.vhd     
rtl_dar/proms/spy_hunter_sp_bits_3.vhd     
rtl_dar/proms/spy_hunter_sp_bits_4.vhd     

rtl_dar/proms/spy_hunter_sound_cpu.vhd  Sound board PROMS
rtl_dar/proms/midssio_82s123.vhd

----------------------
Quartus project files
----------------------
de10_lite/spy_hunter_de10_lite.sdc   Timequest constraints file
de10_lite/spy_hunter_de10_lite.qsf   de10_lite settings (files,pins...) 
de10_lite/spy_hunter_de10_lite.qpf   de10_lite project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 19 ROMs binary files from spyhunt.zip and midssio.zip(MAME)

spy-hunter_cpu_pg0_2-9-84.6d      CRC 1721b88f
spy-hunter_cpu_pg1_2-9-84.7d      CRC 909d044f
spy-hunter_cpu_pg2_2-9-84.8d      CRC afeeb8bd
spy-hunter_cpu_pg3_2-9-84.9d      CRC 5e744381
spy-hunter_cpu_pg4_2-9-84.10d     CRC a3033c15
spy-hunter_cpu_pg5_2-9-84.11d     CRC 88aa1e99
spy-hunter_cpu_alpha-n_11-18-83   CRC 936dc87f
spy-hunter_cpu_bg0_11-18-83.3a    CRC dea34fed
spy-hunter_cpu_bg1_11-18-83.4a    CRC 8f64525f
spy-hunter_cpu_bg2_11-18-83.5a    CRC ba0fd626
spy-hunter_cpu_bg3_11-18-83.6a    CRC 7b482d61
spy-hunter_video_1fg_11-18-83.a7  CRC 9fe286ec
spy-hunter_video_0fg_11-18-83.a8  CRC 292c5466
spy-hunter_video_3fg_11-18-83.a5  CRC b894934d
spy-hunter_video_2fg_11-18-83.a6  CRC 62c8bfa5
spy-hunter_video_5fg_11-18-83.a3  CRC 2d9fbcec
spy-hunter_video_4fg_11-18-83.a4  CRC 7ca4941b
spy-hunter_video_7fg_11-18-83.a1  CRC 940fe17e
spy-hunter_video_6fg_11-18-83.a2  CRC 8cb8a066
spy-hunter_snd_0_sd_11-18-83.a7   CRC c95cf31e
spy-hunter_snd_1_sd_11-18-83.a8   CRC 12aaa48e

midssio_82s123.12d CRC e1281ee9

------
Tools 
------
You need to build vhdl files from the binary file :
 - Unzip the roms file in the tools/spy_hunter_unzip directory
 - Double click (execute) the script tools/make_spy_hunter_proms.bat to get the following 10 files

spy_hunter_cpu.vhd
spy_hunter_sound_cpu.vhd
spy_hunter_ch_bits.vhd
spy_hunter_bg_bits_1.vhd
spy_hunter_bg_bits_2.vhd 
spy_hunter_sp_bits_1.vhd -- use sdram loader to load spy_hunter_sp_bits_1/2/3/4.vhd before loading spy_hunter core.
spy_hunter_sp_bits_2.vhd
spy_hunter_sp_bits_3.vhd
spy_hunter_sp_bits_4.vhd
midssio_82s123.vhd


*DO NOT REDISTRIBUTE THESE FILES*

VHDL files are needed to compile and include roms into the project 

The script make_spy_hunter_proms.bat uses make_vhdl_prom executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c is also delivered.

---------------------------------
Compiling for de10_lite
---------------------------------
You can build the project with ROM image embeded in the sof file.
*DO NOT REDISTRIBUTE THESE FILES*

Use the following project assignements for both sdram loader and spy_hunter core

 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_cke
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_clk
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_cs_n
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_ldqm
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_ras_n
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_udqm
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_we_n
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_addr
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_ba
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_cas_n
 set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to dram_dq
 set_instance_assignment -name FAST_INPUT_REGISTER ON -to dram_dq
 set_instance_assignment -name FAST_OUTPUT_ENABLE_REGISTER ON -to dram_dq


2 steps for sdram loader (sprites graphics)

 - put the VHDL ROM files (spy_hunter_sp_bit_1/2/3/4.vhd) into the rtl_dar/proms directory
 - build sdram_loader_de10_lite

4 steps for core

 - put the VHDL ROM files (.vhd) into the rtl_dar/proms directory
 - build spy_hunter_de10_lite

 - program sdram_loader_de10_lite.sof (first step) (press key1 bouton to start/restart loader program)
 - program spy_hunter_de10_lite.sof   (next step without power OFF de10_lite board) 

------------------------
------------------------
End of file
------------------------
