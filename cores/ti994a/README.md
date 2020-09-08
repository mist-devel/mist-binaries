# EP994A - TI99/4A clone

## Cart loading

Cartridges can have .g (GROM), .c and .d parts. They could be auto-detected from the file extension,
or you must choose the appropriate menu item to load the correct type, if the extension is .bin.
If there's a .d part, load it last!

## Keyboard mapping

Caps Lock - Alpha Lock
Left Alt  - FCTN
Up        - FCTN + E
Down      - FCTN + X
Left      - FCTN + S
Right     - FCTN + D
Del       - FCTN + 1
Ins       - FCTN + 2
Esc       - FCTN + 9 (Back)

## Credits
Original code by Speccery (https://github.com/Speccery/EP994A)
Enhancements and bug fixes by greyrogue
MiST port by György Szombathelyi

VDP & PSG from FPGA Colecovision
Copyright (c) 2006, Arnim Laeuger (arnim.laeuger@gmx.net)

## Source code:
https://github.com/gyurco/colecovision_fpga/

## Limitation:
Only cartridges are supported for storage (but 32k DSR RAM is avaliable)
