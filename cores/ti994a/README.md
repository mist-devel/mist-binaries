# EP994A - TI99/4A clone

## Cart loading

Cartridges can have .g (GROM), .c and .d parts. They could be auto-detected from the file extension,
or you must choose the appropriate menu item to load the correct type, if the extension is .bin.

If there's a .d part, load it last!

## Keyboard mapping
|  Keyboard | TI99/4A    |
|-----------|------------|
|Caps Lock  | Alpha Lock |
|Left Alt   | FCTN       |
| Up        | FCTN + E   |
| Down      | FCTN + X   |
| Left      | FCTN + S   |
| Right     | FCTN + D   |
| Del       | FCTN + 1   |
| Ins       | FCTN + 2   |
| Esc       | FCTN + 9 (Back) |

## Disk support
The PHP1240 disk controller card is implemented in the core, which has
a WD1771 FM-only FDC (single density).

The supported image format is v9t9 (sector dump). These images usually have
the .DSK extension.

Only single-density images are supported at the moment
(40 tracks/side, 9 sector/track), either single-sided or double-sided.

Basic usage of the disk system from BASIC:
- SAVE DSK1.PRG - saves the current BASIC program to Drive 1 as PRG
- OLD DSK1.PRG - loads the program from Drive 1

## Credits
Original code by Speccery (https://github.com/Speccery/EP994A)  
Enhancements and bug fixes by greyrogue  
MiST port by György Szombathelyi

VDP & PSG from FPGA Colecovision  
Copyright (c) 2006, Arnim Laeuger (arnim.laeuger@gmx.net)

## Source code:
https://github.com/gyurco/colecovision_fpga/
