Namco Super Pacman Hardware to Mist FPGA by Slingshot and Jotego

-- Usage:
-- - Create ROM and ARC files from the MRA files in the meta directory
--   using the MRA utility.
--   Example: mra -A -z /path/to/mame/roms Motos.mra
-- - Copy the ROM files to the root of the SD Card
-- - Copy the RBF and ARC files to the same folder on the SD Card
--
-- MRA utility: https://github.com/sebdel/mra-tools-c/
--
--
---------------------------------------------------------------------------------
-- 
-- Arcade: The Tower of Druaga  port to MiSTer by MiSTer-X
-- 25 September 2019
-- 
---------------------------------------------------------------------------------
-- FPGA Druaga for XILINX Spartan-3
--------------------------------------
-- Copyright (c) 2007 MiSTer-X
---------------------------------------------------------------------------------
-- Cycle-Accurate 6809 Core
-- Revision 1.0 - 13th August 2016
---------------------------------------------------
-- Copyright (c) 2016, Greg Miller
---------------------------------------------------------------------------------
-- 
-- 
-- Keyboard inputs :
--
--   F2          : Coin + Start 2 players
--   F1          : Coin + Start 1 player
--   UP,DOWN,LEFT,RIGHT arrows : Movements
--   SPACE       : Trig1
--   CTRL        : Trig2
--
-- MAME/IPAC/JPAC Style Keyboard inputs:
--   5           : Coin 1
--   6           : Coin 2
--   1           : Start 1 Player
--   2           : Start 2 Players
--   R,F,D,G     : Player 2 Movements
--   A           : Player 2 Trig1
--   S           : Player 2 Trig2
--
-- Joystick support.
-- 
-- 
-- FIXED: Video timing.
--
---------------------------------------------------------------------------------

                                *** Attention ***

ROM is not included. In order to use this arcade, you need to provide a correct ROM file.

Find this zip file somewhere. You need to find the file exactly as required.
Do not rename other zip files even if they also represent the same game - they are not compatible!
The name of zip is taken from M.A.M.E. project, so you can get more info about
hashes and contained files there.

To generate the ROM using Windows:
1) Copy the zip into "releases" directory
2) Execute bat file - it will show the name of zip file containing required files.
3) Put required zip into the same directory and execute the bat again.
4) If everything will go without errors or warnings, then you will get the a.*.rom file.
5) Copy generated a.*.rom into root of SD card along with the Arcade-*.rbf file

To generate the ROM using Linux/MacOS:
1) Copy the zip into "releases" directory
2) Execute build_rom.sh
3) Copy generated a.*.rom into root of SD card along with the Arcade-*.rbf file

To generate the ROM using MiSTer:
1) scp "releases" directory along with the zip file onto MiSTer:/media/fat/
2) Using OSD execute build_rom.sh
3) Copy generated a.*.rom into root of SD card along with the Arcade-*.rbf file

