BBC Micro for MIST
==================

This is a port of Mike Sterlings great [BBC Micro on FPGA](http://www.mike-stirling.com/retro-fpga/bbc-micro-on-an-fpga/) with major changes by Stephen Leary. 

SD card
-------

This core includes os1.2, basic2 and SuperMMC. It implements a
[MMBEEB](http://swhs.home.xs4all.nl/bbc/mmbeeb/) compatible interface
and can use it to load software from SD card. The limitations of the original
mmbeed still apply and e.g. the SD card needs to be FAT16 formatted and the
'beeb.mmb' file needs to be written first to the SD card before anything else.

One such file can be found at [here](http://www.retrocomputers.eu/bbc/).

If using the beeb.mmb file, once the BBC is booted type "*MENU" to start
the menu. You can also set it to start automatically by setting "Auto boot"
in the OSD.

This core supports VGA and RGB 15khz. Use the setting in mist.ini
or hold down the middle button to switch between the two modes.

Sideways ROM/RAM
----------------

A 16k ROM image can be uploaded to Sideways ROM slot 10 using the OSD. 
An OSD option allows to map BASIC and SuperMMC from slots 12 and 14 (hi)
down to slots 0 and 2 (low) giving the uploaded ROM and the RAM banks 
priorty over SuperMMC and BASIC.

Four RAM banks are present in slots 4,5,6 and 7.

Keyboard
--------

The BREAK key maps to the PrintScr key.

Joysticks
---------

Two analog joysticks are supported on ADC channels 1-4. Digital joysticks
are mapped to max/min values.

History
-------

* [bbc_170227.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/bbc_170227.rbf)
  - Fix broken sound.

* [bbc_170226.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/bbc_170226.rbf)
  - Planetoid, Snapper etc now work (m6522 related games).
  - Fix SHIFT and CONTROL pausing games.
  - m6522 improvements and clock improvements.

* [bbc_170221.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/bbc_170221.rbf)
  - RGB 15khz OSD and dull colours fixes. 
  - Castle Quest works.

* [bbc_151009.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/bbc_151009.rbf)
  - Auto boot option

* [bbc_151006.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/old/bbc_151006.rbf)
  - CPU running at 2 MHz
  - Swapped joysticks

* [bbc_151005.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/old/bbc_151005.rbf)
  - Joystick support
