# PET2001 for MiSTer

### This is the port of [pet2001fpga](https://github.com/skibo/Pet2001_Nexys3).

### Ported to MiST and DeMiSTified platforms by Alastair M. Robinson

## ROM format
Suitable ROMs can be found in the VICE emulator package and should be concatenated into
a single file called PET2001.ROM
The ROM chunks should appear in the following order:
* BASIC ROM (12k)
* Edit ROM (2k)
* Characters ROM (2k)
* Kernal ROM (4k)
The ROM file should be 20k in total.

Note that the Edit ROM is specific to the keyboard type of the machine - so if the keyboard does weird things
try toggling the keyboard between "Graphics" and "Business" in the System menu.

## Installation:
Copy the *.rbf and the PET2001.ROM file to the root of the SD card.
Copy roms (*.prg,*.tap) to a directory of your choice.

### Notes:
* PRG apps are directly injected into RAM. Load command is not required.
* TAP files are loaded through virtual tape input. Type "LOAD" and press Return, so the PET displays the message "SEARCHING"
then choose TAP file in OSD.
* **F12** opens OSD.

### Source code:
The source for this core can be found [here](https://github.com/robinsonb5/PET2001_DeMiSTified).

