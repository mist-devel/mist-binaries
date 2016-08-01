C16 for MiST
------------

This is the MiST port of [Istvan Hegedus' FPGATED project](https://hackaday.io/project/11460-fpgated).

The source code of the modified version is available [in the mist-board repository](https://github.com/mist-devel/mist-board/tree/master/cores/c16).

Usage
-----

Copy the latest core version onto a SD card and rename it to ```core.rbf```.

Alternate kernals/NTSC
----------------------

By default the core will boot the built-in PAL kernal which will run
the C16 in PAL video mode. Thus your screen needs to support 50Hz PAL
timing. In order to get a NTSC setup you need to place a c16 NTSC
kernal on the SD card and rename to ```C16.ROM```. This kernal will then be
uploaded into the core on boot time and replace the built-in PAL
kernal. This can also be used to run the kernal version of the diag264
roms.

Loading and running programs
----------------------------

You probably also want to put some games in c16/plus4 PRG format onto
the SD card, preferably into a c16 subdirectory. Once the c16 has
booted use F12 to open the on screen display (OSD), select ```Load PRG```
and the PRG you want to load. The screen will flicker for a fraction
for a second while the program is being loaded directly into the C16
ram. 

Afterwards type ```RUN``` to run the game.

Using the 1541 floppy
---------------------

You can also load from floppy images in D64 format using the built-in
1541. Use ```Mount D64``` from the OSD to insert a floppy disk image
in D64 format. The simply use the regular C16 methods to access the 
floppy disk. In most cases ```LOAD "*",8``` and a subsequent ```RUN```
will be what you want.

Using a SCART TV
----------------

The C16 core supports the MiST's ability to disable the built-in VGA
scandoubler. Using the [appropriate cable](https://github.com/mist-devel/mist-board/wiki/ScartCable) the C16 core can thus drive a standard SCART TV.

History
-------

* [c16_160801-2.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/c16_160801-2.rbf)
  - C1541 floppy disk implementation (read only)

* [c16_160801.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_160801.rbf)
  - OSD option to switch between 16k and 64k

* [c16_160729.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_160729.rbf)
  - Initial release
