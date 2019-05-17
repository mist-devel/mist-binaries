Gameboy for MIST
================

This is an early version of a gameboy core for the MIST. 

A good number of games already work incl Tetris, Mario and Zelda. But
many things don't work fully yet.

If game cartridge is stored in the SD cards root directory under the name
gameboy.rom it will be loaded by default.

History:

gb_190216.rbf
-------------

- Many updates
- Game Boy Color support

gb_150914.rbf
-------------

- Fast boot option bypassing the logo animation
- Sprite priority (e.g. Super Mario sprite vs. pipes)

gb_150911.rbf
-------------

- Added audio
- Allow DMA from cartridge RAM (fixes Sprites in Warioland)
