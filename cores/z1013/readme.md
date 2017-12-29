# Z1013-mist                                                                                                                                                                         

The robotron Z1013 port for the mist platform.

## OSD options
The OSD is called by F12 key.

| feature           | values
| ---               | ---
| Load *.Z80        | load files from SD card (extension: .z80)
| scanlines         | on/off
| keyboard layout   | de/en
| online help       | on/off
| color scheme      | black&white or blue&yellow

When the Z1013 is running, you can load .z80-files via the OSD direct into the memory.
Name, type, load address, end address and start address of the loaded file is show on top of screen.
To start a loaded progem use *J <start address>*.
The original keyboard layout is a littlebit strange, so expect unusal keys to control the games.

The Z1013 core was developed and sucessfully tested with ARM firmware version ATH160123.

## Features
- Z1013 with original ROM (2.02) from robotron Riesa
- 16kByte RAM
- keyboard input (switchable layout en/de)
- file load from SD card for z80-files with headersave format
- switchable color scheme black&whith (original) and blue/yellow


## Limitations
- has only 16k of RAM (0000h - 3FFFh)
- no sound
- no tape input/output
- no joystick support
- top two pixel lines are not shown
- sometimes the keyboard hang, no idee why --> solution: reset core
- somtime keyboard start in hexadecimal mode, result in wired inputs --> solution: switch to alphanumeric mode with *A*

## Source files
https://github.com/boert/Z1013-mist

