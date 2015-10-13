Plus Too for the MiST board
===========================

This is a port of the [Plus Too project](http://www.bigmessowires.com/plus-too/) to the MiST board.

Usage
-----

- Copy the core onto a sd card naming it core.rbf for auto boot
- Copy the a Mac Plus rom onto the SD card under the name plus_too.rom
- Copy a disk image in Plus Too format (e.g. Disk608-800K.bin) onto the SD card

Boot the MIST. After a few seconds the floppy disk icon should
appear. Open the on screen display using the F12 key and select the
disk image. The upload of the disk image will take a few seconds after
which Plus Too is being reset. Plus Too will then boot into the MacOS
desktop.

The green texts at the screens bottom are debug information of the
original Plus Too project.

The necessary rom and disk images can be found in the original (Plus
Too project archive)[http://www.bigmessowires.com/plustoo.zip].

State
-----

The MiST Plus Too port is in the same state as the original Plus
Too. It's thus unfinished. Basically only the mouse is working as well
as a read only floppy. 

Some dbug features of the original Plus Too are missing as the MIST
board does not have the necessary buttons, switches and LEDs.

Major components are still missing like keyboard, floppy write ...

History
-------

* [PlusToo_151013.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/plus_too/PlusToo_151013.rbf)
  - Initial release
  - No functional changes over the original version

