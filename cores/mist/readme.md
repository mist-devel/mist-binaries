Atari ST core for the MIST board
================================

In order to use this core you need to put it under the name core.rbf onto
the SD card. 

You also need a tos rom image. It's preferred to use a TOS 2.06 image
from e.g. [here](http://www.atariworld.org/tos-rom/). The tos rom
image must be named tos.img and has to be placed in the SD cards root
directory just like the core itself. Emutos is also supported, but is
not recommended due to its limited game compatibility.

To speed up booting a floppy disk image should also be present. Just
put the [demo
disk](https://github.com/mist-devel/mist-binaries/raw/master/cores/mist/disk_a.st)
also into the root of the SD card and the system will boot into the
desktop imediately.

To use the Atari ST system font for the MISTs first boot messages the
(Atari ST system
font)[https://github.com/mist-devel/mist-binaries/raw/master/cores/mist/system.fnt]
may also be copied into the cards root.

Other floppy disk images in .ST format can be selected in the OSD
(open with F12).
