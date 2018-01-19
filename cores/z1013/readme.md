# Z1013-mist                                                                                                                                                                         
Robotron Z1013 port for the MiST platform.


## Overview
This project emulates a robotron Z1013 computer from 1984.
The original Z1013 was sold as a kit (without case and power supply).

This Z1013.01 emulation use 2 MHz clock frequency and is equipped with 16 kByte RAM.

### Buttons
| left button   | reset MiST (reload core from SD card)
| middle button | open/close OSD (on screen display)
| right button  | reset Z1013


### OSD options
The OSD is called by F12 key.

| feature           | values
| ---               | ---
| Load *.Z80        | load from SD card (extension: .z80)
| Scanlines         | on/off
| Keyboard layout   | de/en
| Online help       | on/off
| Color scheme      | black&white or blue&yellow
| Joystick mode     | practic 1/88 or ju+te 6/87
| Autostart         | enable/disable

When the Z1013 is running, you can load .z80-files via the OSD direct into the memory.
Name, type, load address, end address and start address of the loaded file is show on top of screen.
When Autostart is enabled (default) then the program will be started automaticly.
Otherwise ```J <start address>```  will also jump to the start address.
The original keyboard layout is a littlebit strange, so expect unusal keys to control the games,
e.g. <U> for moving up und <space> for moving down.

The Z1013 core was developed and sucessfully tested with ARM firmware version ATH160123.


## Supported features

Z1013.01:
- 16 kByte RAM (0000h - 3FFFh)
- 1 kByte video RAM (EC00h - EFFFh), 
- 2 kByte ROM (F000h - F7FFh), Riesa monitor 2.02
- keyboard mapping from PS/2 scancodes to 8x4 matrix
- joystick on user port (PIO A)
- frequency switching 2 MHz/ 4 MHz, port 04h, bit 6
- sound output PIO B7 or user port (PIO A)

MiST additions:
- load z80 files (headersave format) from SD-card
- display file information on status line
- autostart z80-files
- scanline support
- online help for most monitor commands
- switchable color scheme
- switchable keyboard layout (en/de)
- right push button on mist for reset


## Limitations
- has only 16k of RAM (0000h - 3FFFh)
- no tape input
- somtime keyboard start in hexadecimal mode, result in wired inputs --> solution: switch to alphanumeric mode with *A*

## Source files
https://github.com/boert/Z1013-mist


## History

2018-01-19
- change clock speed to 2 MHz
- fix keyboard and screen problem
- add auto start
- add joystick support (practic 1/88 and ju+te 6/87)
