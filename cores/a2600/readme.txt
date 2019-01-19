Port of the A2601 FPGA implementation for the MiST
---------------------------------------------------------------------------------

Buttons:
- Win key         -> Start
- Alt key         -> Select
- F12             -> OSD

OSD
- Select roms from the sd card (needs extension .a26 or .bin)
- Special extensions (.e0, .3f, .fe, fa, cv) allows to force a specific mapper
- P2 extension for Pitfall II Lost Caverns allows to use the DPC chip
- Switch between ntsc/pal and color/b&w
- Select difficulty for left and right (140723)

Current limitations:
- supports only the common Atari bank switching schemes (F8, F6, F4, E0, 3F, FE, FA, CV)

Mapper support:
- F4, F6, F8 - standard Atari mappers, autodetected by ROM size
- E0 - Parker Bros. mapper, need .E0 file extension
- 3F - Used for Tigervision 8K ROMs, need .3F file extension
- FE - Activision mapper, used in Robot Tank and Decathlon, use .FE file extension
- FA - CBS RAM Plus titles, use .FA file extension
- CV - Commavid titles, use .CV file extension
- P2 - Pitfall II Lost Caverns (DPC chip), use .P2 extension

Some titles use an extra 128 byte RAM (called SuperChip). Unfortunately it cannot be
autodected easily, so use the Load SuperChip OSD option to load these titles.

Supports mist.ini scandoubler_disable for RGB 15khz, or you can hold the middle MiST
button to switch between modes. ypbpr=1 in mist.ini also honored.

All MiST related files including the Quartus project files are in the 'mist' subdirectory.
The cpu65xx core was added with permission of Peter Wendrich.

Homepage:
http://ws0.org/tag/ma2601/

Source files:
https://github.com/wsoltys/tca2601

Turbo Chameleon 64 port by Frank Buss:
https://github.com/FrankBuss/TCA2601

Original port by Retromaster:
http://retromaster.wordpress.com/a2601/
