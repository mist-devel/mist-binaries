ZX80/ZX81 core for MiST quick start guide
-----------------------------------------

The source code is here https://github.com/gyurco/ZX8X_MiST

NOTE: Requires firmware_180810 or later.
https://github.com/mist-devel/mist-binaries/tree/master/firmware

Copy the latest ZX8X core to SD card. Name the core "core.rbf" and place it 
in the SD cards root. Copy the zx8x.rom file to the SD cards root.

Add some ZX81 programs (*.p) files to the SD card.

The mist.ini file is supported to switch between VGA and 15khz TV. As usual
you can switch between VGA and 15khz by holding down the middle MiST button.

Put the SD card into the MiST and boot it. After a few seconds you
should see the familiar white screen with the inverted K in the lower
left corner. 

By default the core boots into ZX80 mode, simply select the mode, either
ZX80 or ZX81, in the F12 menu and select the memory mode. For most games
ZX81 and 16k RAM are recommended. To save these settings for default
use F12 and select "Save settings".

Your ZX81 is up and running. 

How to load a file
------------------

The ZX81 originally used cassette tapes for mass storage. ZX8X supports
instant loading of tape images.

To load a program select a .p program (ZX81) or .o (ZX80) from the MiST 
menu using F12. In ZX8X core enter 'load ""' by first pressing the 'j'
key and then two times SHIFT-'p'. Press return. The game should load,
some games will start automatically, others require you to enter the 
"run" command by pressing the 'r' key and return.

If there's no opened file, the standard ROM load routine is executed, 
and it can receive tape data from the UART port. Reset (ALT-F11 or the 
Reset OSD option) closes the .o or .p file.


Limitations
-----------

The ZX81 video is partly generated via the CPU. A perfect CPU timing is
thus required for perfect video. This is true for simple text modes
but it's even more critical with hirez video modes.

Unfortunately the ZX8X core and its CPU aren't perfect. Some programs
will have a slighly distorted video signal timing. Some screens cope
better with this, some don't ...
