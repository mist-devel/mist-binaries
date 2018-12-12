Port of the A2601 FPGA implementation for the MiST
---------------------------------------------------------------------------------

Buttons:
- F9 or right MiST button -> Start
- F10        		  -> Select
- F12	 	          -> OSD 

OSD
- Select roms from the sd card (needs extension .a26 or .bin)
- Special extensions (.e0, .3f, .fe) allows to force a specific mapper
- Switch between ntsc/pal and color/b&w
- Select difficulty for left and right (140723)

Current limitations:
- supports only the common Atari bank switching schemes (F8, F6, F4, E0, 3F, FE)

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
