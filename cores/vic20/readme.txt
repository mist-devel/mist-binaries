This is the MiST port of the vic20 hardware simulation by MikeJ: http://fpgaarcade.com/?q=node/19
You can read more about it here: http://ws0.org/tag/vic20/
The source can be found here: https://github.com/wsoltys/mist-cores/tree/master/vic20

Features:
- pal vic20/vc20 unexpanded or with 3kb or 16kb ram expansion
- .prg and .crt upload from sd card
- scanline support
- joystick support
- the double scan can be turned off

Limitations:
There're no safety checks for games for the unexpanded vic20 so they usual overwrite the screen ram.
The prg upload expects the start address in the first two bytes as usual. the .crt upload
via osd expects cartridge roms with the auto start sequence.
A few glitches are visible. I don't know if its due to my changes or were already in the original
core.