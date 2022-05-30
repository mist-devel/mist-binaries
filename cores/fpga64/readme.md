### FPGA64 on MIST

This is the port of the FPGA64 C64 core by Peter Wendrich distributed with
his kind permission. The later ports are based on Dar FPGAs work and includes
a c1541 floppy implementation.

## Features

- Can use .CRT, .PRG, .D64 and .G64 files
- 1541 writeable floppy drive
- Cartridge support
- TAP file loading
- Load from real tape using the UART RX pin
- Save to real tape through audio output
- PAL/NTSC modes
- RAM Expansion Unit up to 16 MB
- RGB and YPbPr output, optionally with scandoubler (VGA)
- 6581 and 8580 SID support
- 1351 Mouse on both controller ports
- Stereo SIDs at D420 and D500 addresses
- C128-style turbo mode (with always ON option)
- Pseudo stereo mode (SID 6580 on left, 8580 on right, driven by the same data)
- 4 player interface support (up to 4 joysticks)
- UART support (RX and TX on M,B and C pins of the User port, or with UP9600 wiring)
- ACIA 6850 based MIDI interfaces

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

You need at least firmware version **200311**!

## Dual-SID

The second SID's address is $D420 and $D500 in stereo modes.

## Turbo modes

Software selectable turbo mode mimics the $D030 (53296) port of the C128.

```
POKE 53296,1
```
will turn ON turbo,
```
POKE 53296,0
```
will turn OFF turbo.

Note that the 2 MHz CPU operation steals the cycles from the VIC-II chip,
so it's wise to enable it only in the vertical border/blank period.
The **Turbo: ON** option does exactly that.

The 1541 disk drive doesn't work with enabled turbo.

## MIDI interfaces

The 6850 ACIA based interfaces are reachable on the addresses described on this page:
https://codebase64.org/doku.php?id=base:c64_midi_interfaces

## C64GS

Copy the C64GS.ROM and the C64GS.ARC file next to the C64.RBF file
(it's important to remove any version string from the filename - pure
C64.RBF will work). You can choose C64 or C64GS from the core selector then.

## ROM file

You must put a C64.ROM file to the root of the SD Card. The ROM format is
basic+kernal+1541. The file size can be 16k (basic+kernal)
or 32k (basic+kernal+1541).

## Special keys:

- F9  - Pound
- F10 - Plus
- F11 - Restore/Freeze
- CTRL+F11 - Soft reset
- Page Up - Start/Stop tape
