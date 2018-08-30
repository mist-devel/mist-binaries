BBC Micro for MIST
==================

This is a port of Mike Sterlings great [BBC Micro on FPGA](http://www.mike-stirling.com/retro-fpga/bbc-micro-on-an-fpga/) with major changes by Stephen Leary and David Banks. 

SD card
-------

This core includes os1.2, basic2 and MMFS. It implements a
MMBEEB (SD card to user port) compatible interface
and can use it to load software from SD card. The limitations of the original
MMFS still apply and e.g. the SD card needs to be FAT16/FAT32 (without partitions)
formatted and the 'beeb.mmb' file needs to be written first to the SD card before anything else.
Also the size limit of the file system is 8 GB. However you can make an image file, called bbc.vhd,
"format" this image to FAT16, and copy the 'beeb.mmb' into this image. This way you can simply
put the bbc.vhd file to the root of the SD card, next to the core.

One such file can be found at [here](http://stardot.org.uk/files/mmb/higgy_mmbeeb-v1.0.zip).

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

The BREAK key maps to the PrintScr key. BREAK is effectively the reset button.

Joysticks
---------

Two analog joysticks are supported on ADC channels 1-4. Digital joysticks
are mapped to max/min values.

Games
-----
New to the BBC? Here's a selection of the best games to try: Arcadians, Chuckie Egg, Elite, Monsters, Planetoid, Snapper.

History
-------

* [bbc_180823.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/bbc_180823.rbf)
  - Replaced the CPU and the VIA from hoglet67's (David Banks) repo
  - Changed sd_card and user_io's async clock usage (inspiration from Sorgelig's mist_io)
  - Changed SMMC rom to MMFS, so an SDHC card with FAT32 (up to 8GB) can be used, too. However it's more convenient to copy the BEEB.MMB to a FAT image called bbc.vhd, and copy this to the SD card's root folder.

* [bbc_170227.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/old/bbc_170227.rbf)
  - Fix broken sound.

* [bbc_170226.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/old/bbc_170226.rbf)
  - Planetoid, Snapper etc now work (m6522 related games).
  - Fix SHIFT and CONTROL pausing games.
  - m6522 improvements and clock improvements.

* [bbc_170221.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/old/bbc_170221.rbf)
  - RGB 15khz OSD and dull colours fixes. 
  - Castle Quest works.

* [bbc_151009.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/old/bbc_151009.rbf)
  - Auto boot option

* [bbc_151006.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/old/bbc_151006.rbf)
  - CPU running at 2 MHz
  - Swapped joysticks

* [bbc_151005.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/bbc/old/bbc_151005.rbf)
  - Joystick support
