# Z1013-mist                                                                                                                                                                         
The robotron Z1013 port for the MiST board.


## Overview
This project emulates a robotron Z 1013 computer from 1984/1985.
The original Z 1013 was sold as a kit (without case and without power supply).

There exists two variants for MiST platform:
- Z1013.01 with 2 MHz clock frequency and 16 kByte RAM
- Z1013.64 with 2/4 MHz clock frequency and 64 kByte RAM


## Getting started with Z1013.01

Copy the core (rename core_z1013_01.rbf to core.rbf) on your SD card and start the MiST device.

## Getting started with Z1013.64

Copy the core (rename core_z1013_64.rbf to core.rbf) on your SD card and start the MiST device.


### Overview of OSD options
| feature           | values
| ---               | ---
| Load *.Z80        | load file from SD card into RAM
| Decoration        | Scanlines (on/off), Color scheme (black&white or blue&yellow)
| Keyboard layout   | de/en
| Online help       | on/off
| Joystick mode     | practic 1/88, ju+te 6/87, practic 4/87 or ERF-Soft
| Autostart         | enable/disable

When the Z1013 is running, you can load .z80-files via the OSD direct into the memory.
Name, type, load address, end address and start address of the loaded file is show on status line (top of screen).
When Autostart is enabled (default) then the program will be started automaticly.
This works only from monitor (the operating system), because some keypresses need to be emulated.
Otherwise ```J <start address>```  will also jump to the start program.
The original keyboard layout is a littlebit strange, so expect unusal keys to control the games,
e.g. <U> for moving up und <space> for moving down.

The Z1013 core was developed and sucessfully tested with ARM firmware version ATH160123.


## Supported features

Z1013.01:
- 16 kByte RAM (0000h - 3FFFh)
- 1 kByte video RAM (EC00h - EFFFh)
- 2 kByte ROM (F000h - F7FFh), Riesa monitor 2.02
- keyboard mapping from PS/2 scancodes to 8x4 matrix
- joystick on user port (PIO A)
- sound output PIO B7 or user port (PIO A)

Z1013.64 (with "Peters-Extension"):
- 64 kByte RAM (0000h - FFFFh)
- 64x16 character video output, port 04h, bit 7
- frequency switching 2 MHz/ 4 MHz, port 04h, bit 6
- 2nd character ROM (umlauts, control chars & inverse), port 04h, bit 5
- ROM (F000h - F7FFh) disable, port 04h, bit 4

MiST additions:
- map video output to 800x600@60MHz (SVGA)
- load z80 files (headersave format) from SD-card
- display file information on status line
- autostart z80-files
- scanline support
- online help for major monitor commands
- switchable color scheme
- switchable keyboard layout (en/de)
- right push button on MiST for Z1013 reset
- middle push button on MiST or F12  for OSD
- left push button on MiST for MiST reboot

![Z1013 with OSD (center), online help (right) and status line (top)](https://raw.githubusercontent.com/boert/Z1013-mist/master/documentation/Screenshot_Z1013_on_MiST.jpg)

## First example
Enter the following lines on the monitor prompt:
```
M 300
3E 00
21 00 EC
11 01 EC
01 00 04
77
ED B0
3C
C2 02 03
FF
;
J 300
```

### Explanation
The Z1013 is based on a Z80/U880D CPU. It can be directly programmed with Z80 opcodes.
```M 300``` starts editing the memory:
```
LOC   OBJECT CODE   LINE   STMT SOURCE CODE
                       1      1         org     00300h  ; start the program at address 300h
                       2      2
0300  3e 00            3      3         ld a, 000h      ; clear register A
                       4      4 next:
0302  21 00 ec         5      5         ld hl, 0ec00h   ; EC00h = screen buffer
0305  11 01 ec         6      6         ld de, 0ec01h   ; 
0308  01 00 04         7      7         ld bc, 00400h   ; 32x32 = size of screen
030b  77               8      8         ld (hl), a      ; set first position to reg A
030c  ed b0            9      9         ldir            ; fill complete screen with A
030e  3c              10     10         inc a           ; next character
030f  c2 02 03        11     11         jp nz, next     ; loop through all characters
0312  ff              12     12         rst 38h         ; jump back to operating system
```
The ```;``` stops editing.
With ```J 300``` (jump) the program is started at address 300h.


## Project structure

| Directory              | remark 
| ---                    | ---    
| contrib                | code used from other projects
| cores                  | stuff generated with MegaWizard
| documentation          | some basic documents
| library                | helper source code
| ROMs                   | monitor ROMs for Z1013
| rtl                    | source code
| rtl_tb                 | testbench source code
| simulation_modelsim    | simulation scripts
| synthesis_quartus      | synthesis scripts
| vhdl_files.txt         | list of used files (for simulation and synthesis)


to start a simulation change to directory *simulation_modelsim* and do
```
cd simulation_modelsim
make
make simulate
```

to generate *core_z1013.rbf* use directory *synthesis_quartus* and start
```
cd synthesis_quartus
make all
```

to reprogram the FPGA (JTAG-Blaster required) just do
```
cd synthesis_quartus
make program
```


## Known problems

- somtimes keyboard start in hexadecimal mode, result in wired inputs,

  solution: switch to alphanumeric mode with *A*


## Project history

original project by FPGAkuechle published 2012/2013 at mikrocontroller.net:

https://www.mikrocontroller.net/articles/Retrocomputing_auf_FPGA


ported by abnomane to Altera, April 2013:

http://abnoname.blogspot.de/2013/07/z1013-auf-fpga-portierung-fur-altera-de1.html


adapted to mist platform by Boert, released December 2017:


https://github.com/boert/Z1013-mist
