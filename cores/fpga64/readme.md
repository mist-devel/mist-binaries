### FPGA64 on MIST

This is the port of the FPGA64 C64 core by Peter Wendrich distributed with
his kind permission. The later ports are based on Dar FPGAs work and includes
a c1541 floppy implementation.

## Features

- Can use .CRT, .PRG and .D64 files
- 1541 writeable floppy drive
- Cartridge support
- RGB and YPbPr output, optionally with scandoubler (VGA)
- 6581 and 8580 SID support
- Stereo 6581 at D420 and D500 addresses
- 4 player interface support (up to 4 joysticks)

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

The kernal+basic+1541 ROMs can be overriden by putting a new C64.rom to
the root folder of the SD card. The file size can be 16k (kernal+basic)
or 32k (kernal+basic+1541).
