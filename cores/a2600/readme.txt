Port of the A2601 FPGA implementation for the MiST
---------------------------------------------------------------------------------

Buttons:
- F9 or right MiST button -> Start
- F10        		  -> Select
- F12	 	          -> OSD 

OSD
- select roms from the sd card (needs extension .a26)
- Switch between ntsc/pal and color/b&w
- Select difficulty for left and right (140723)

Current limitations:
- supports only the common Atari bank switching schemes (F8, F6, F4)

Supports mist.ini scandoubler_disable for RGB 15khz, or you can hold the middle MiST
button to switch between modes.

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
