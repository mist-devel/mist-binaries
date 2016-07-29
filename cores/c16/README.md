C16 for MiST
------------

This is the MiST port of Istvan Hegedus' FPGATED project. Find the
original project at https://hackaday.io/project/11460-fpgated

The source code of the modified version is available at 
https://github.com/mist-devel/mist-board/tree/master/cores/c16

Usage
-----

Copy the latest core version onto a SD card and rename it to core.rbf

Alternate kernals/NTSC
----------------------

By default the core will boot the built-in PAL kernal which will run
the C16 in PAL video mode. Thus your screen needs to support 50Hz PAL
timing. In order to get an NTSC setup you need to place a c16 NTSC
kernal on the SD card and rename to C16.ROM. This kernal will then be
uploaded into the core on boot time and replace the built-in PAL
kernal. This can also be used to run the kernal version of the diag264
roms.

Loading and running programs
----------------------------

You probably also want to put some games in c16/plus4 PRG format onto
the SD card, preferably into a c16 subdirectory. Once the c16 has
booted use F12 to open the on screen display (OSD), select "Load PRG"
and the PRG you want to load. The screen will flicker for a fraction
for a second while the program is being loaded directly into the C16
ram. 

Afterwards type "RUN" to run the game.

Using a SCART TV
----------------

The C16 core supported the MiST ability to disable the built-in VGA
scandoubler. Using the [appropriate cable](https://github.com/mist-devel/mist-board/wiki/ScartCable) the C16 core can thus drive a standard SCART TV.
