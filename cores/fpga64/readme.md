### FPGA64 on MIST

This is the port of the FPGA64 C64 core by Peter Wendrich distributed with
his kind permission. The later ports are based on Dar FPGAs work and includes
a c1541 floppy implementation.

## Features

- Can use .CRT, .PRG and .D64 files
- 1541 writeable floppy drive
- Cartridge support
- TAP file loading
- Load from real tape using the UART RX pin
- Save to real tape through audio output
- PAL/NTSC modes
- RGB and YPbPr output, optionally with scandoubler (VGA)
- 6581 and 8580 SID support
- 1351 Mouse on both controller ports
- Stereo SIDs at D420 and D500 addresses
- Pseudo stereo mode (SID 6580 on left, 8580 on right, driven by the same data)
- 4 player interface support (up to 4 joysticks)
- UART support (RX and TX on M,B and C pins of the User port)

## Usage

The current core implements a c1541 floppy disk drive. A D64 image can
be mounted from the MISTs OSD. Programs can afterwards be loaded from
floppy using the usual commands (e.g. LOAD "$",8 and LOAD"*",8,1)

Additionally it implements some mechanism called direct memory injection.
This can be triggered via the OSD (which is opened with the F12 key)
allowing to to upload a c64 program binary (.PRG) directly into the
memory of the embedded c64. After injection the program can simply be
started using the basic "run" command. As shown in the beginning of this
video: https://www.youtube.com/watch?v=tnboiECYXVo

## ROM file

You must put a C64.ROM file to the root of the SD Card. The ROM format is
basic+kernal+1541. The file size can be 16k (basic+kernal)
or 32k (basic+kernal+1541).

## Special keys:

- F9  - Pound
- F10 - Plus
- F11 - Restore/Freeze
- CTRL+F11 - Reset
- Page Up - Start/Stop tape
