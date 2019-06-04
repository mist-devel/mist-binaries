# Port of the A2601 FPGA implementation for the MiST

## Features:
- Tries to be cycle-perfect
- Support 15kHz TV/ scandoubled 30kHz VGA display
- RGB/YPbPr output

## Buttons:
- F9, Start button (Win key with MiST joystick emu)    -> Start
- F10, Select button (Alt key with MiST joystick emu)  -> Select
- F12                                                  -> OSD

## Mapper support:
- F4, F6, F8 - standard Atari mappers, autodetected from the ROM size
- E0 - Parker Bros. mapper, need .E0 file extension
- 3F - Used for Tigervision 8K ROMs, need .3F file extension
- FE - Activision mapper, used in Robot Tank and Decathlon, use .FE file extension
- FA - CBS RAM Plus titles, use .FA file extension
- CV - Commavid titles, use .CV file extension
- P2 - Pitfall II Lost Caverns (DPC chip), use .P2 extension
- E7 - M-Network cart (Bump'n'Jump, Burgertime), use .E7 extension

Some titles use an extra 128 byte RAM (called SuperChip). Unfortunately it cannot be
autodected easily, so use the Load SuperChip OSD option to load these titles, or set
the 3rd part of the file extension to 's'. E.g. Dig Dug is a game which requires
SuperChip, rename it to digdug.f6s, and it'll work with the normal Load OSD item.

## Current limitations:
- no support for DPC+, SaveKey and other custom EPROM/RAM/bank switching solutions
  on carts
- some games don't provide a stable sync, they might have problems using VGA/scandoubler
  or modern LCD TVs

Homepage:
http://ws0.org/tag/ma2601/

Source files:
https://github.com/wsoltys/tca2601

Turbo Chameleon 64 port by Frank Buss:
https://github.com/FrankBuss/TCA2601

Original port by Retromaster:
http://retromaster.wordpress.com/a2601/
