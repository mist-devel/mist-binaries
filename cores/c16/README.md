C16 for MiST
------------

This is the MiST port of [Istvan Hegedus' FPGATED project](https://hackaday.io/project/11460-fpgated).

The source code of the modified version is available [in the mist-board repository](https://github.com/mist-devel/mist-board/tree/master/cores/c16).

Usage
-----

Copy the latest core version onto a SD card and rename it to ```core.rbf```.

Alternative ROMs
----------------

It's possible to replace one or all of the three ROMs (C1541, Kernal and Basic) by
putting them in a file on the SD Card and name it to ```C16.ROM```. The format is
C1541 + Kernal + Basic, 16k each. Partially replacing ROMs are allowed, e.g. just
changeing the 1541's ROM to JiffyDOS, you need only a 16k ```C16.ROM``` with the
appropriate JiffyDOS version.

PAL/NTSC version
----------------

The TED chip can switch PAL/NTSC modes on the fly. The Kernal sets the
appropriate register, so with changing the Kernal ROM, it is possible to switch
the video standard. The default is PAL mode.
You can load a new Kernal from the OSD menu, or permamently replace it
with alternative versions with the method described above.

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

SID extension
-------------

Selectable SID versions are in the OSD menu. Enabling one of them maps
the SID to the FD40-FD5F and FE80-FE9F addresses.

Using a SCART TV
----------------

The C16 core supports the MiST's ability to disable the built-in VGA
scandoubler. Using the [appropriate cable](https://github.com/mist-devel/mist-board/wiki/ScartCable) the C16 core can thus drive a standard SCART TV.
You can use [component output](https://github.com/mist-devel/mist-board/wiki/YPbPr_Cable), too.

History
-------

* [c16_190502.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/c16_190502.rbf)
  - TAP file playback
  - SID extension

* [c16_190214.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_190214.rbf)
  - One core version for PAL/NTSC
  - Loadable Kernal ROM from the OSD menu
  - Disk change detection fix
  - Bigger OSD on VGA

* [c16_180905_PAL.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_180905_PAL.rbf),
  [c16_180905_NTSC.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_180905_NTSC.rbf)
  - Updates and bug fixes to C1541 makes it work with every tested fastloader without timing hacks
  - Fixed PRG loader
  - All ROMs are replaceable

* [c16_180830_PAL.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_180830_PAL.rbf),
  [c16_180830_NTSC.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/c16/old/c16_180830_NTSC.rbf)
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
