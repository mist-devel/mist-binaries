This the MiST port of FPGAmstrad project
----------------------------------------

Please read the cores [Wiki](http://github.com/mist-devel/mist-board/wiki/CoreDocAmstrad) page for more details.

Quick stat
----------

Copy the latest [core](https://github.com/mist-devel/mist-binaries/raw/master/cores/amstrad/amstrad_151013_r004.7.2.rbf) onto an FAT32 formatted SD card and rename it to `core.rbf`.

Then copy at least the following ROM files into the root directory of your SD card:
  - [AMSDOS.e07](https://github.com/mist-devel/mist-binaries/raw/master/cores/amstrad/ROMs/AMSDOS.e07)
  - [BASIC1-1.e00](https://github.com/mist-devel/mist-binaries/raw/master/cores/amstrad/ROMs/BASIC1-1.e00)
  - [OS6128.eZZ](https://github.com/mist-devel/mist-binaries/raw/master/cores/amstrad/ROMs/OS6128.eZZ)

Insert the SD card into your MIST and reboot. After a few seconds you should be presented the familiar Amstrad basic screen.

Now you can copy a dsk image like e.g. the [AST-EQUINOX demo](http://cpcrulez.fr/Scene_Demos/index.php?download=YqXJmarLlrvj292Im7vl&p=Scene_Demos) onto your SD card and boot the MIST with this. On the main screen open the OSD with F12 and choose the "AST-Equinox.dsk" disk image.

The enter:
 `cat`
to list the contents of the disk is listed.

Or just type
 `run"EQUINOX`
to load and run the demo.

Have fun :)
