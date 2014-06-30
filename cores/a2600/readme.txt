Port of the A2601 FPGA implementation for the MiST
---------------------------------------------------------------------------------

Buttons:
- right MiST button -> Start
- Keyboard 1        -> Select
- Keyboard 2        -> BW/Color (yellow led on = Color)
- Keyboard F12      -> OSD to select roms from the sd card (needs extension .a26)

Current limitations:
- supports only the common Atari bank switching schemes
- no illegal opcodes

All MiST related files including the Quartus project files are in the 'mist' subdirectory.


Source files:
https://github.com/wsoltys/tca2601

Turbo Chameleon 64 port by Frank Buss:
https://github.com/FrankBuss/TCA2601

Original port by Retromaster:
http://retromaster.wordpress.com/a2601/