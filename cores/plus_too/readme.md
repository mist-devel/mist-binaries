Plus Too for the MiST board
===========================

This is a port of the [Plus Too project](http://www.bigmessowires.com/plus-too/) to the MiST board.

Usage
-----

- Copy the core onto a sd card naming it core.rbf for auto boot
- Copy the a Mac Plus rom onto the SD card under the name plus_too.rom
- Copy disk images in dsk format (e.g. [Disk605.dsk](http://www.rolli.ch/MacPlus/Archives/ZIP/Disk605.zip)) onto the SD card

Boot the MIST. After a few seconds the floppy disk icon should
appear. Open the on screen display using the F12 key and select the
a disk image. The upload of the disk image will take a few seconds. Plus Too will then boot into the MacOS desktop.

The necessary rom images can be found in the original [Plus Too project archive](http://www.bigmessowires.com/plustoo.zip).

Floppy disk image format
------------------------

Floppy disk images need to be in raw disk format. Double sided 800k disk images have to be exactly 819200 bytes in size. Single sided 400k disk images have to be exactly 409600 bytes in size.

Both the internal as well as the external floppy disk are supported. The first entry in the OSD refers to the internal floppy disk, the second one to the external floppy disk.

Currently floppy disk images cannot be uploaded while the Mac accesses a floppy disk. Thus it's recommended to wait for the desktop to appear until a second floppy can be inserted.

Before uploading a different disk image it's recommended to eject the previously inserted disk image from within MacOS.

Some system floppy disk images in matching dsk format can be found at [here](http://www.rolli.ch/MacPlus/welcome.html). Some nice applicatons on 400k dsk images can be found [here](http://tkc8800.com/page/Macintosh-128k-512k-disk-images). Official system disk images are available from apple e.g. via [ftp](http://ftp.iinet.net.au/pub/apple/US/Macintosh/System/Older_System/System_6.0.x/). Under Linux these can be converted into the desired dsk format using [Linux stuffit](http://web.archive.org/web/20060205025441/http://www.stuffit.com/downloads/files/stuffit520.611linux-i386.tar.gz), unar and [dc2dsk](http://www.bigmessowires.com/dc2dsk.c) in that order.

Hard disk support
-----------------



History
-------

* [plusToo_151118.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/plus_too/plusToo_151118.rbf)
  - Initial SCSI support

* [plusToo_151027.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/plus_too/old/plusToo_151027.rbf)
  - Basic audio support

* [plusToo_151026.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/plus_too/old/plusToo_151026.rbf)
  - Floppy disk image format changed to standard dsk format
  - Support for both floppies
  - Added ability to eject disk images
  - Mouse counter wrapping fixed
  - Some more simplifications
  - Removed debug video overlay

* [plusToo_151016.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/plus_too/old/plusToo_151016.rbf)
  - Simplified internal timing
  - Reduced SDRAM clock to 65MHz
  - Added keyboard support

* [plusToo_151013.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/plus_too/old/plusToo_151013.rbf)
  - Initial release
  - No functional changes over the original version

