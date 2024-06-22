---------------------------------------------------------------------------------
-- Galaga Midway by Dar (darfpga@aol.fr)
-- http://darfpga.blogspot.fr
---------------------------------------------------------------------------------
-- Galaga releases
--
-- Release 0.3 - 06/05/2018 - Dar
--    add cs54XX mb88 explosion sound ship 
--
-- Release 0.2 - 06/11/2017 - Dar
--    fixes twice bullets on single shot => add edge detection en fire
--
-- Release 0.1 - 04 November 2017 - Dar
--	fixes 2 ships bullets bug (swap 2xH/2xV command bits)
--      add top level for DE10_lite
--
-- Release 0.0 - 29 December 2016 - Dar
--	initial release (DE2 only)
--
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

--  Features :
--   TV 15KHz mode only (atm)
--   Coctail mode ok
--   Sound ok, Ship explode missing (custom chip 0x54XX todo)
--   Starfield from MAME information  

--  Use with MAME roms from galagamw.zip
--
--  Use make_galaga_proms.bat to build vhd file from binaries

--   galaga_cpu1.vhd   : 3200a.bin, 3300b.bin, 3400c.bin,3500d.bin, 
--   galaga_cpu2.vhd   : 3600e.bin
--   galaga_cpu3.vhd   : 3700g.bin
--   bg_graphx.vhd     : 2600j.bin
--   sp_graphx.vhd     : 2800l.bin, 2700k.bin
--   rgb.vhd           : prom-5.5n
--   bg_palette.vhd    : prom-4.2n
--   sp_palette.vhd    : prom-3.1c
--   sound_seq.vhd     : prom-2.5c
--   sound_samples.vhd : prom-1.1d

--  Galaga Hardware caracteristics :
--
--    3xZ80 CPU accessing each own program rom and shared ram/devices
--
--    One char tile map 32x28 (called background/bg although being front of other layers) 
--      3 colors/64sets among 16 colors
--      1Ko ram, 4Ko rom graphics, 4pixels of 2bits/byte 
--      full emulation in vhdl
--
--    64 sprites with priorities, flip H/V, 2x size H/V, 
--      3 colors/64sets among 16 colors (different of char colors).
--      8Ko rom graphics, 4pixels of 2bits/byte
--      full emulation in vhdl (improved capabilities : more sprites/scanline)
--
--    Namco 05XX Starfield 
--      4 sets, 63 stars/set, 2 set displayed at one time for blinking   
--      6bits colors: 2red/2green/2blue
--      full emulation in vhdl (from MAME information)
--
--    Char/sprites color palette 2x16 colors among 256 colors
--      8bits 3red/3green/2blue
--      full emulation in vhdl
--
--    Namco 06XX for 51/54XX control 
--      simplified emulation in vhdl
--
--    Namco 51XX for coin/credit management 
--      simplified emulation in vhdl : 1coin/1credit, 1 or 2 players start
--
--    Namco 54XX for sound effects 
--      mb88 ok
--
--    Namco sound waveform and frequency synthetizer
--      full original emulation in vhdl
--
--    Namco 00XX,04XX,02XX,07XX,08XX address generator, H/V counters and shift registers
--      full emulation in vhdl from what I think they should do.
--
--    Working ram : 3x1Kx8bits shared
--    Sprites ram : 1 scan line delay flip/flop 512x4bits  
--    Sound registers ram : 2x16x4bits
--    Sound sequencer rom : 256x4bits (3 sequential 4 bits adders)
--    Sound wavetable rom : 256x4bits 8 waveform of 32 samples of 4bits/level  
---------------------------------------------------------------------------------

---------------------------------------------------------------------------------
-- DE2-35 Top level for Galaga Midway by Dar (darfpga@aol.fr)
-- http://darfpga.blogspot.fr
--
-- Main features :
--  PS2 keyboard input
--  Wm8731 sound output
--  NO board SRAM/Flash used
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
--   SPACE       : Fire player 1 & 2
--   RIGHT arrow : Move right player 1 & 2
--   LEFT arrow  : Move left player 1 & 2
--
-- Dip switch and other details : see galaga.vhd

---------------------------------------------------------------------------------
---------------
VHDL File list 
---------------

rtl_dar/galaga_de2.vhd          Top level for de2 board 
rtl_dar/galaga.vhd              Main logic

rtl_dar/pll50_to_11_and_18.vhd  PLL 11MHz and 18 MHz from 50MHz altera mf
rtl_dar/gen_video.vhd           Video genertor H/V counter, blanking and syncs

rtl_dar/stars.vhd               Starfield 4 star set list
rtl_dar/stars_machine.vhd	Starfield machine for one set	
rtl_dar/sound_machine.vhd	Namco sound waveform/frequency synthetizer
rtl_dar/mb88.vhd                mb88 fujitsu 4bits microprocessor

rtl_dar/galaga_cpu1.vhd         CPU1 program    PROM 
rtl_dar/galaga_cpu2.vhd         CPU2 program    PROM
rtl_dar/galaga_cpu3.vhd         CPU3 program    PROM
rtl_dar/sound_samples.vhd       Sound wavetable PROM
rtl_dar/sound_seq.vhd           Sound slice adder sequencer                 PROM
rtl_dar/rgb.vhd                 32 colors 8bits palette (3r/3g/2b)          PROM
rtl_dar/bg_graphx.vhd           Background (char) graphix 2bits/pixel (4Ko) PROM
rtl_dar/bg_palette.vhd          2bits 64sets => 16 colors char LUT          PROM
rtl_dar/sp_graphx.vhd           Sprites graphix 2bits/pixel (8Ko)           PROM
rtl_dar/sp_palette.vhd          2bits 64sets => 16 colors sprites LUT       PROM 
rtl_dar/cs54xx_prog.vhd         Namco custom chip 54xx pgm                  PROM

rtl_dar/gen_ram.vhd             Generic RAM (Peter Wendrich + DAR Modification)

wm_8731_dac.vhd                 DE1/DE2 audio dac

io_ps2_keyboard.vhd             Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)
kbd_joystick.vhd                Keyboard key to player/coin input

rtl_T80/T80se.vhd               T80 Copyright (c) 2001-2002 Daniel Wallner (jesus@opencores.org)
rtl_T80/T80_Reg.vhd
rtl_T80/T80_Pack.vhd
rtl_T80/T80_MCode.vhd
rtl_T80/T80_ALU.vhd
rtl_T80/T80.vhd

----------------------
Quartus project files
----------------------
de2/galaga_de2.qsf             de2 settings (files,pins...) 
de2/galaga_de2.qpf             de2 project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 15 ROMs binary files from galagamw.zip 
(MAME Galaga - Midway set 1)

--   galaga_cpu1.vhd   : 3200a.bin, 3300b.bin, 3400c.bin,3500d.bin, 
--   galaga_cpu2.vhd   : 3600e.bin
--   galaga_cpu3.vhd   : 3700g.bin
--   bg_graphx.vhd     : 2600j.bin
--   sp_graphx.vhd     : 2800l.bin, 2700k.bin
--   rgb.vhd           : prom-5.5n
--   bg_palette.vhd    : prom-4.2n
--   sp_palette.vhd    : prom-3.1c
--   sound_seq.vhd     : prom-2.5c
--   sound_samples.vhd : prom-1.1d
--   cs54xx_prog.vhd   : 54xx.bin  
------
Tools 
------
You need to build vhdl files from the binary file :
 - Unzip the roms file in the tools/galaga_unzip directory
 - Double click (execute) the script tools/make_galaga_proms.bat to get the following files

  galaga_cpu1.vhd 
  galaga_cpu2.vhd
  galaga_cpu3.vhd
  bg_graphx.vhd
  sp_graphx.vhd
  rgb.vhd
  bg_palette.vhd
  sp_palette.vhd
  sound_seq.vhd
  sound_samples.vhd
  cs54xx_prog.vhd 

*DO NOT REDISTRIBUTE THESE FILES*

VHDL files are needed to compile and include roms into the project 

The script make_galaga_proms.bat uses make_vhdl_prom executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c is also delivered.

---------------------------------
Compiling for de2
---------------------------------
You can build the project with ROM image embeded in the sof file. DO NOT REDISTRIBUTE THESE FILES.
3 steps

 - put the VHDL ROM files (.vhd) into the project directory
 - build galag_de2
 - program galaga_de2.sof

------------------------
------------------------
End of file
------------------------
