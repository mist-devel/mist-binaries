This is the MiST port of the vic20 hardware simulation by MikeJ: http://fpgaarcade.com/?q=node/19
You can read more about it here: http://ws0.org/tag/vic20/
The source can be found here: https://github.com/wsoltys/mist-cores/tree/master/vic20

Features:
- pal vic20/vc20 unexpanded or with 3kb or 24kb ram expansion
- .prg and .crt upload from sd card
- scanline support
- joystick support
- the double scan can be turned off

Limitations:
There're no safety checks for games for the unexpanded vic20 so they usual overwrite the screen ram.
The prg upload expects the start address in the first two bytes as usual. the .crt upload
via osd expects cartridge roms with the auto start sequence. Since the TOSEC archive contains .crt
files with and without load address you can choose that via OSD.
A few glitches are visible. I don't know if its due to my changes or were already in the original
core.

Multipart cartridges:
To run multipart crt's turn on "CRT with load address:yes" and load the lower part first.
Use the Tosec crt's without the [a] as those have the load address removed. Load the $4000 or $6000
part first and then the $A000 part. The $A000 crt will trigger a reset and starts the game.