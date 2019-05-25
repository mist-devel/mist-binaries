A Colecovision and SG-1000 core for the MiST
---------------------------------------------------------------------------------

Buttons:
- Keyboard 0-9 	    -> 0-9
- Keyboard Z        -> fire button 1 (Y on German Keyboard)
- Keyboard X        -> fire button 2
- Keyboard Q        -> #
- Keyboard W        -> *
- Arrow Keys        -> Move
- Keyboard F12      -> OSD to select roms from the sd card (needs extension .col or .bin)
- Two player joystick support
- Expansion module 2 support (steering wheel in some games)

Support for the MegaCart (ROMs up to 1MB) and SuperGameModule (32k RAM, AY-8910 sound chip) added
from the 181127 version.

SG-1000 mode supports the Dahjee Type A RAM expansion module automatically.

Sega Keyboard (SK-1100) added in release 190525, effectively extending SG-1000 to SC-3000.
Tape input from UART_RX pin also supported in this mode.

Homepage:
http://ws0.org/tag/colecovision/

Source files:
https://github.com/wsoltys/mist-cores/tree/master/fpga_colecovision

Original Source
https://svn.pacedev.net/repos/pace/sw/synth/platform/colecovision/