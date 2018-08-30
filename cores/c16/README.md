C16 for MiST
------------

This is the MiST port of [Istvan Hegedus' FPGATED project](https://hackaday.io/project/11460-fpgated).

The source code of the modified version is available [in the mist-board repository](https://github.com/mist-devel/mist-board/tree/master/cores/c16).

Usage
-----

Copy the latest core version onto a SD card and rename it to ```core.rbf```.

Alternate kernals/NTSC
----------------------

There are two versions of the core built, one for PAL and one for NTSC systems.
They contain the appropriate kernal versions, so no need to load it separately.
However you can replace the kernal (e.g. with the diag264 roms) by putting it
to the SD Card and rename it to ```C16.ROM```.

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

* [c16_180830_PAL.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/c16_180830_PAL.rbf),
  [c16_180830_NTSC.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/c16_180830_NTSC.rbf)
  - Updated C1541 to a read-write version
  - Updated the CPU to an improved version of the T65 (both the machine and C1541)

* [c16_160811.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_160811.rbf)
  - Fixed C1541 disk image change detection

* [c16_160801-2.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_160801-2.rbf)
  - C1541 floppy disk implementation (read only)

* [c16_160801.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_160801.rbf)
  - OSD option to switch between 16k and 64k

* [c16_160729.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_160729.rbf)
  - Initial release
