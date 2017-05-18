This is a port of fpgagen - Genesis/Megadrive core to additional platform(s)
MiST, Turbo Chameleon 64, Altera/Terasic DE2 board

The core shall be considered a work in progress as there are multiple issues:
1. Sprite flickering on heavy scenes, or on large sprites
2. No LFO modulation of the FM sound
3. Rom file formats supported are .bin and .gen, no support for .smd files
4. The design does not fit on the Altera/Terasic DE1 board anymore

==== Installing the core ====
If you are not buidling the core, copy the following files to the root of your sdcard:
fpgagen.rbf
Config_VGA/FPGAGEN.CFG, or Config_TV/FPGAGEN.CFG (for 15 kHz video)

Then rename the file fpgagen.rbf to core.rbf

==== Building and installing the core ====
The project depends on submodules, so you need to type in the following commands after checkout.

cd fpgagen
git submodule init
git submodule update

Then load the Quartus II project file, and build:
fpgagen/syn/mist/fpgagen.qpf

When you have built the core, copy the following files to the root of your sdcard:
fpgagen/syn/mist/fpgagen.rbf
fpgagen/Configs/VGA/FPGAGEN.CFG, or fpgagen/Configs/TV/FPGAGEN.CFG (for 15 kHz video)

Then rename the file fpgagen.rbf to core.rbf

================================================================================
fpgagen - a SEGA Megadrive/Genesis clone in a FPGA.
Copyright (c) 2010-2013 Gregory Estrade (greg@torlus.com)
All rights reserved

fpgagen is an attempt to clone the SEGA Megadrive/Genesis console in a FPGA.
It is currently advanced enough to run many games.

================================================================================
In order to run this project you will need :
- A Terasic/Altera DE1 board.
- A VGA monitor.
- DE1 CD-ROM contents. (http://www.terasic.com/downloads/cd-rom/de1/)
- Altera Quartus II 9.1 Web Edition.
- (optional) ModelSim-Altera 6.5b Starter Edition.

First, the FPGA EEPROM should be programmed with the demonstration design
"DE1_USB_API.sof". It should be the case if you've never re-programmed it.
That will allow you to use the "DE1 Control Panel" software.

Power on your DE1 board, make it sure it is connected thru USB to your computer.
Run the "DE1_Control_Panel.exe" program.
Click on "Open", select "Open USB Port 0".
Select the "FLASH" tab, and click on "Chip Erase".
Check "File Length", then click on "Write a File to FLASH".
Choose a Genesis ROM (.bin or .gen file formats are supported, .smd files need 
to be converted to .bin, with SMD2BIN for instance).
Once the write operation is done, close the "DE1 Control Panel".

If you downloaded the programming file, run the Quartus Programmer
("quartus_pgmw.exe" located in "<altera root directory>\91\quartus\bin").
Select the "gen_top.cdf" file, click on "Start", and you're done!

If you want to build the project from its source, open the Quartus II software 
and select the "gen_top.qpf" project.

Notes : 
- Be sure to always perform a "Chip Erase" before programming a new ROM.
- I don't know if it's due to my own setup, but I've found that the flash write
  operation is not very reliable, as I often get a byte off when I try to read
  back the flash. For some games it doesn't matter (if you're lucky enough, and
  that the write error occurs in a data section, and not a code section).
  Some games however perform a self-consistency check, and won't run at all.
  Only workaround so far : erase and re-program the flash until it succeeds.

A 3-button pad is mapped to the board's switches and buttons.
Here is a description of the controls :
- KEY0 : Start
- KEY1 : C
- KEY2 : B
- KEY3 : A
- SW9 : Up
- SW8 : Down
- SW7 : Left
- SW6 : Right
SW0 performs a Hard-Reset operation.

================================================================================
What this project currently provides :
- 68000 code execution, using the TG68 core, written by Tobias Gubener.
- Z80 code execution, using the T80 core, written by Daniel Wallner.
- Video Display Processor core with integrated scandoubler for VGA output.
- Genesis "glue logic".

What it lacks :
- Any kind of sound support.
  The only part of the soundchips I've written is the timer logic of the FM chip.
  I've done this only to ensure that it won't prevent some Z80 code to run.
- Interlaced modes and Shadow/Highlight features of the VDP.

Other issues :
- Some games run quite well, but for some reason, others don't. 
  For instance, Golden Axe doesn't work properly, from the early beginning.
  However, some games that look more advanced, like Thunder Force III and IV,
  work quite well.
- The VDP needs some rework, so expect some graphical glitches.
- The flash erase/programming phase is tedious, someday I'll replace it with a 
  bootloader that will read ROMs from a SD card.
- A small expansion board to connect Genesis pads to the board would be nice, 
  instead of using switchs and push buttons...

================================================================================
Special thanks and greetings to :
- Charles MacDonald. 
  His documentation work, the source code for his Genesis Plus emulator, and 
  various chat sessions we had, have been very helpful.
- Tobias Gubener and Daniel Wallner, for their CPU cores.
- Kunihiko Ohnaka, for his EMSX project.
  It has been very helpful, especially for the SDRAM controller. 
- Pascal Bosquet, for providing me his Rick Dangerous port source code, among
  other stuff.
- People on IRC@EFNet : #gbadevfr and #utopiasoft.
- People of the SpritesMind.Net forum.
  This forum's threads contain very valuable information on Genesis emulation.

================================================================================
Gregory Estrade (Torlus) - 2010/07/14
greg@torlus.com
