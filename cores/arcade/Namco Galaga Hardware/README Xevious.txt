-- Xevious by Namco MiST port
--
-- Create ROM file from the MRA file using the MRA utility.
--  Example: mra -z /path/to/mame/roms Xevious.mra
-- Copy the ROM files to the root of the SD Card
-- Copy the RBF files to the SD Card
--
-- MRA utility: https://github.com/sebdel/mra-tools-c/
--
-- Based on:
---------------------------------------------------------------------------------
-- Xevious by Dar (darfpga@aol.fr) (01 May 2017)
-- http://darfpga.blogspot.fr
--
--  Terasic board DE2-35 or MAX10 DE10 Lite
--
-- Modified for external SDRAM controller as ROM storage for MiST by Slingshot 
--
--------------------------------------------------------------------------------
-- gen_ram.vhd & io_ps2_keyboard
-------------------------------- 
-- Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
-- http://www.syntiac.com/fpga64.html
---------------------------------------------------------------------------------
-- T80/T80se - Version : 0247
-----------------------------
-- Z80 compatible microprocessor core
-- Copyright (c) 2001-2002 Daniel Wallner (jesus@opencores.org)
---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------
--  MAX10 DE10 Lite Top version 0.2 : (01/05/2017)
--
--     add digital audio out sgtl5000 support with teensy audio shield on top of
--     arduino usb host shield
--
--  MAX10 DE10 Lite Top version 0.1 : (14/04/2017)
--
--    add usb host max3421e support with arduino shield
--
--     BEWARE : arduino shield has to be modified (see instruction on my blog)
--
--  Keyboard PS/2 available at gpio pins 
--  Beware voltage translation for PS2 keyboard connection : do it at your own risk
--  Don't do this by yourself if you have no electronic skill, you may damage the board
--
--  Sound PWM output available at gpio pins     
--
--  USB keyboard or joystick available (with arduino shield)
--  See more explanation in file xevious_de10_lite.vhd
--
--  No external SRAM required, Use internal RAM for xevious_cpu_gfx_8bits.vhd 
--
---------------------------------------------------------------------------------
--
--  Video 15KHz is OK, 
--
--  This is not VGA, you have to use a TV set with SCART plug
--
--    SCART(TV) pin  - signal -  VGA(DE10) pin
--               15  -  red   -  1          
--               11  - green  -  2
--                7  -  blue  -  3  
--           5,9,13  -  gnd   -  5,6,7
--   (comp. sync)20  - csync  -  13 (HS)   
--  (fast commut)16  - commut -  14 (VS)
--            17,18  -  gnd   -  8,10 
--
---------------------------------------------------------------------------------
--
-- XEVIOUS VHDL VERSION
--
-- Todo : replace cs51xx rough emulation 
--
-- Version 0.3 -- 28/02/2017
--             Fixed cs54xx audio 2 (mb88 JMP instruction fixed)
--
-- Version 0.2 -- 26/02/2017 -- 
--             Replace cs50xx rough emulation by mb88 processor
--             mb88.vhd : tstR and tbit fixed
--
-- Version 0.1 -- 15/02/2017 -- 
--	       Add ship explosion with mb88 processor
---------------------------------------------------------------------------------
--  Features :
--   TV 15KHz mode only (atm)
--   Cocktail mode : todo 
--   Replace cs51xx with true mb88 processor : todo
--
--   Sound ok, Ship explode ok with true mb88 processor

--  Use with MAME roms from xevious.zip
--
--  Use make_xevious_proms.bat to build vhd file and bin from binaries

--  IMPORTANT -- for DE2-35 SRAM have to be loaded with rom data before loading 
--    xevious_de2.sof   
--
--    Use DE2 Control Panel to load xevious_cpu_gfx_16bits.bin to DE2 SRAM
--
--    1) Switch ON DE2
--    2) Launch QuartusII and program DE2 with "DE2_USB_API.sof"
--    3) Launch DE2 control panel
--       a) Menu Open -> Open USB port 0
--       b) (Test connexion) Tab PS2 & 7-SEG : select '3' on HEX7 and click on SET, digit on DE2 should diplay '3'
--       c) Tab SRAM / frame Sequential Write : check box 'File length'. Click on Write a file to SRAM and choose xevious_cpu_gfx_16bits.bin
--       d) wait for compete write
--       e) (check write) frame Random Access : click Read (Adress 0), rData should display '3E3E'
--       f) VERY IMPORTANT : Menu Open -> Close USB port
--    DO NOT SWITCH OFF DE2 or you will need to reload SRAM
--    4) go back to QuartusII and program DE2 with "xevious_de2.sof"

--    Explanation : Xevious make use of large amount of data (prom). All these data could not fit into DE2-35 FPGA. 
--    I choose to put all 3 CPUs program, foreground graphics, background graphics and sprite graphics data
--    to external memory. This lead to 68Ko of data. As DE2-35 use a 16bits width SRAM since and DE2 control panel doesn't allow
--    to load 8bits width data all data have been duplicated on both 8bits LSB and 8bits MSB. So xevious_cpu_gfx_16bits.bin 
--    is 136Ko.

--		For other boards one have to consider that the external data are accessed with a 18Mhz multiplexed addressing scheme. So
--    external device have to have a 55ns max access time. Of course big enough FPGA may directly implement these data bank without
--    requiring external device. It is to notice that 55ns will be not so easy to reach with Flash or SDRAM memories.    

--  Xevious Hardware caracteristics :
--
--    3xZ80 CPU accessing each own program rom and shared ram/devices
--      16Ko program for CPU1
--      8Ko program for CPU2
--      4Ko program for CPU3
--
--    One char tile map 64x28 (called foreground/fg) 
--      1 colors/64sets among 128 colors
--      4Ko ram (code + attr/color), 4Ko rom graphics, 8pixels of 1bits/byte 
--      Horizontal scrolling (horizontal for TV scan = vertical for upright cabinet) 
--      full emulation in vhdl

--    One background tile map 64x28 (called background/bg) 
--      4 colors/128sets among 128 colors
--      4Ko ram (code + attr/color), 8Ko rom graphics, 8pixels of 2bits/ 2bytes 
--      Horizontal/Vertical scrolling 
--      full emulation in vhdl
--
--    64 sprites with priorities, flip H/V, 2x size H/V, 
--      8 colors/64sets among 128 colors.
--      24Ko rom graphics, 4pixels of 3bits / 1.5byte
--      4 colors/64sets among 128 colors.
--      8Ko rom graphics, 4pixels of 2bits / byte
--      full emulation in vhdl (improved capabilities : more sprites/scanline)
--
--    Char/sprites color palette 128 colors among 4096
--      12bits 4red/4green/4blue
--      full emulation in vhdl
--
--    Terrain data
--      8Ko + 4Ko + 4Ko rom
--
--    Namco 06XX for 51/54XX control 
--      simplified emulation in vhdl
--
--    Namco 50XX for protection management 
--      true mb88 processor ok

--    Namco 51XX for coin/credit management 
--      simplified emulation in vhdl : 1coin/1credit, 1 or 2 players start
--
--    Namco 54XX for sound effects 
--      true mb88 processor ok
--
--    Namco sound waveform and frequency synthetizer
--      full original emulation in vhdl
--
--    Namco such as address generator, H/V counters and shift registers
--      full emulation in vhdl from what I think they should do.
--
--    Working ram : 2Kx8bits + 3x2Kx8bits + 2x4Kox8bits (all shared)
--    Sprites ram : 1 scan line delay flip/flop 512x4bits  
--    Sound registers ram : 2x16x4bits
--    Sound sequencer rom : 256x4bits (3 sequential 4 bits adders)
--    Sound wavetable rom : 256x4bits 8 waveform of 32 samples of 4bits/level  
---------------------------------------------------------------------------------

---------------------------------------------------------------------------------
-- DE2-35 Top level for Xevious by Dar (darfpga@aol.fr) (January 2017)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
-- Educational use only
-- Do not redistribute synthetized file with roms
-- Do not redistribute roms whatever the form
-- Use at your own risk
---------------------------------------------------------------------------------
--
-- Main features :
--  PS2 keyboard input
--  Wm8731 sound output
--  68Ko external SRAM (136Ko for 16bits width)
--
-- Uses 1 pll for 18MHz and 11MHz generation from 50MHz
--
-- Board key :
--      0 : reset
--
-- Keyboard inputs :
--   F3 : Add coin
--   F2 : Start 2 players
--   F1 : Start 1 player
--   SPACE       : Fire  
--   RIGHT arrow : Move right 
--   LEFT  arrow : Move left
--   UP    arrow : Move up 
--   DOWN  arrow : Move down
--   CTRL        : Launch bomb        
--
-- Dip switch and other details : see xevious.vhd

---------------------------------------------------------------------------------

+--------------------------------------------------------------------------------------+
; Fitter Summary                                                                       ;
+------------------------------------+-------------------------------------------------+
Fitter Status                      : Successful - Fri Apr 14 21:57:50 2017
Quartus II 64-Bit Version          : 13.0.1 Build 232 06/12/2013 SP 1 SJ Web Edition
Revision Name                      : xevious_de2
Top-level Entity Name              : xevious_de2
Family                             : Cyclone II
Device                             : EP2C35F672C6
Timing Models                      : Final
Total logic elements               : 10,744 / 33,216 ( 32 % )
    Total combinational functions  : 9,815 / 33,216 ( 30 % )
    Dedicated logic registers      : 3,054 / 33,216 ( 9 % )
Total registers                    : 3054
Total pins                         : 88 / 475 ( 19 % )
Total virtual pins                 : 0
Total memory bits                  : 295,936 / 483,840 ( 61 % )
Embedded Multiplier 9-bit elements : 0 / 70 ( 0 % )
Total PLLs                         : 1 / 4 ( 25 % )
+--------------------------------------------------------------------------------------+
; Fitter Summary                                                                       ;
+------------------------------------+-------------------------------------------------+
Fitter Status                      : Successful - Fri Apr 14 22:11:20 2017
Quartus Prime Version              : 16.1.0 Build 196 10/24/2016 SJ Lite Edition
Revision Name                      : xevious_de10_lite
Top-level Entity Name              : xevious_de10_lite
Family                             : MAX 10
Device                             : 10M50DAF484C6GES
Timing Models                      : Preliminary
Total logic elements               : 11,849 / 49,760 ( 24 % )
    Total combinational functions  : 10,942 / 49,760 ( 22 % )
    Dedicated logic registers      : 3,256 / 49,760 ( 7 % )
Total registers                    : 3256
Total pins                         : 137 / 360 ( 38 % )
Total virtual pins                 : 0
Total memory bits                  : 852,992 / 1,677,312 ( 51 % )
Embedded Multiplier 9-bit elements : 0 / 288 ( 0 % )
Total PLLs                         : 1 / 4 ( 25 % )
UFM blocks                         : 0 / 1 ( 0 % )
ADC blocks                         : 0 / 2 ( 0 % )
+------------------------------------+-------------------------------------------------+

---------------
VHDL File list 
---------------

rtl_dar/xevious_de2.vhd          Top level for de2 board 
rtl_dar/xevious.vhd              Main logic

rtl_dar/pll50_to_11_and_18.vhd   PLL 11MHz and 18 MHz from 50MHz alt. mf (DE2-CycloneII)
rtl_dar/gen_video.vhd            Video genertor H/V counter, blanking and syncs

rtl_dar/sound_machine.vhd        Namco sound waveform/frequency synthetizer
rtl_dar/mb88.vhd                 mb88 fujitsu 4bits microprocessor

rtl_dar/sp_palette_msb.vhd       sprites color LUT msb 3bits 64sets => 64 colors    PROM
rtl_dar/sp_palette_lsb.vhd       sprites color LUT lsb 3bits 64sets => 64 colors    PROM
rtl_dar/red.vhd                  128 colors 4bits palette red                       PROM
rtl_dar/green.vhd                128 colors 4bits palette green                     PROM
rtl_dar/blue.vhd                 128 colors 4bits palette blue                      PROM
rtl_dar/bg_palette_msb.vhd       background color LUT msb 2bits 64sets => 64 colors PROM
rtl_dar/bg_palette_lsb.vhd       background color LUT lsb 2bits 64sets => 64 colors PROM
rtl_dar/terrain_2c.vhd           terrain map                 PROM
rtl_dar/terrain_2b.vhd           terrain map                 PROM
rtl_dar/terrain_2a.vhd           terrain map                 PROM
rtl_dar/sound_seq.vhd            Sound slice adder sequencer PROM
rtl_dar/sound_samples.vhd        Sound wavetable             PROM
rtl_dar/cs54xx_prog.vhd          Namco custom chip 54xx pgm  PROM

rtl_dar/gen_ram.vhd              Generic RAM (Peter Wendrich + DAR Modification)

wm_8731_dac.vhd                  DE1/DE2 audio dac

io_ps2_keyboard.vhd              Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
kbd_joystick.vhd                 Keyboard key to player/coin input

xevious_de10_lite.vhd            Top level for de10 lite

decodeur_7_seg.vhd               7 segments decoder (for usb report display)
usb_report_pkg.vhd               usb report buffer
usb_keyboard_decoder.vhd         usb keyboard report to game input 
usb_joystick_decoder.vhd         usb joystick report to game input
usb_host_max3421e.vhd            usb host for max3421e controler

max10_pll_18M_11M.vhd            PLL 11MHz and 18 MHz from 50MHz alt. mf (DE10_lite-MAX10)

rtl_T80/T80se.vhd                T80 Copyright (c) 2001-2002 Daniel Wallner (jesus@opencores.org)
rtl_T80/T80_Reg.vhd
rtl_T80/T80_Pack.vhd
rtl_T80/T80_MCode.vhd
rtl_T80/T80_ALU.vhd
rtl_T80/T80.vhd


----------------------
Quartus project files
----------------------
de2/xevious_de2.qsf               de2 settings (files,pins...) 
de2/xevious_de2.qpf               de2 project
(CycloneII support : maximum release Quartus 13.1)

de10_lite/xevious_de10_lite.qsf   de10_lite settings (files,pins...) 
de10_lite/xevious_de10_lite.qpf   de10_lite project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 29 ROMs binary files from xevious.zip 
(MAME xevious)

xvi_1.3p    , xvi_2.3m    , xvi_3.2m    , xvi_4.2l    , xvi_5.3f    , xvi_6.3j    , xvi_7.2c  ,
xvi_12.3b   , xvi_13.3c   , xvi_14.3d   , xvi_15.4m   , xvi_17.4p   , xvi_16.4n   , xvi_18.4r ,
xvi_9.2a    , xvi_10.2b   , xvi_11.2c   , xvi_8bpr.6a , xvi_9bpr.6d , xvi10bpr.6e ,  
xvi_7bpr.4h , xvi_6bpr.4f , xvi_4bpr.3l , xvi_5bpr.3m , xvi_1bpr.5n , xvi_2bpr.7n .
50xx.bin    , 51xx.bin    , 54xx.bin   

------
Tools 
------
You need to build vhdl/bin files from the binary file :
 - Unzip the roms file in the tools/xevious_unzip_win64/roms directory  (or win32 or linux)
 - Double click (execute) the script tools/make_xevious_proms.bat to get the following files

The following 15 files will be converted to vhld (rom) files.
(bpr files are 4bits width prom, vhdl files are 8bits width, compiler will optimize to the right size automaticaly)

xvi_9.2a      =>  terrain_2a.vhd
xvi_10.2b     =>  terrain_2b.vhd
xvi_11.2c     =>  terrain_2c.vhd

xvi_8bpr.6a   =>  red.vhd
xvi_9bpr.6d   =>  green.vhd
xvi10bpr.6e   =>  blue.vhd

xvi_7bpr.4h   =>  bg_palette_lsb.vhd
xvi_6bpr.4f   =>  bg_palette_msb.vhd

xvi_4bpr.3l   =>  sp_palette_lsb.vhd
xvi_5bpr.3m   =>  sp_palette_msb.vhd

xvi_1bpr.5n   =>  sound_seq.vhd
xvi_2bpr.7n   =>  sound_samples.vhd

50xx.bin      =>  cs50xx_prog.vhd
51xx.bin      =>  cs51xx_prog.vhd (N.U. atm)
54xx.bin      =>  cs54xx_prog.vhd 

The following 14 files will produce "xevious_cpu_gfx_8bits.bin" and "xevious_cpu_gfx_16bits.bin" 

xvi_1.3p ,   xvi_2.3m ,   xvi_3.2m ,   xvi_4.2l,    xvi_5.3f ,   xvi_6.3j,   xvi_7.2c,
xvi_12.3b,   xvi_13.3c,   xvi_14.3d,   xvi_15.4m,   xvi_17.4p,   xvi_16.4n,  xvi_18.4r,

"xevious_cpu_gfx_8bits.bin"  has to be used if your board has  8bits width SRAM
"xevious_cpu_gfx_16bits.bin" has to be used if your board has 16bits width SRAM (DE2-35)

*DO NOT REDISTRIBUTE ANY OF THESE FILES*

VHDL files are needed to compile and include roms into the project 

The script make_xevious_proms.bat uses make_vhdl_prom and duplicate_byte executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c and duplicate_byte.c is also delivered.

---------------------------------
Compiling for de2
---------------------------------
You can build the project with ROM image embeded in the sof file. DO NOT REDISTRIBUTE THESE FILES.
3 steps

 - put the VHDL ROM files (.vhd) into the project directory
 - build xevious_de2
 - load DE2 SRAM with "xevious_cpu_gfx_16bits.bin" by using DE2 control panel software (see begining of this readme file)
 - then program xevious_de2.sof

----------------------------
Big enough FPGA (~100Ko RAM)
(Already done for de10_lite)
----------------------------
You can easily mofidy make_xevious_prom.bat to produce xevious_cpu_gfx_8bits.vhld from xevious_cpu_gfx_8bits.bin.
*DO NOT REDISTRIBUTE ANY OF THESE FILES*

Remove SRAM external link.
Add and use this new entity in your own board to top level file as shown here after:

architecture struct of xevious_xxboardxx is

 signal clock_18n  : std_logic;
 ...
 signal rom_bus_addr : std_logic_vector(16 downto 0);
 signal rom_bus_do   : std_logic_vector(7 downto 0);
 ...

begin
...
clock_18n <= not clock_18;
...
xevious : entity work.xevious
port map(
 ... 
 rom_bus_addr_o => rom_bus_addr,
 rom_bus_do     => rom_bus_do,
 ... 
);

xevious_cpu_gfx_rom : entity work.xevious_cpu_gfx_8bits
port map(
 clk  => clock_18n,
 addr => rom_bus_addr,
 data => rom_bus_do
);
...
end struct;

*DO NOT REDISTRIBUTE FILES CONTAINING ROM DATA WHATEVER THE FORM* 

------------------------
End of file
------------------------
