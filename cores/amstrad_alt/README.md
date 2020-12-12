
# Amstrad CPC 6128 for MiST and MiSTer
This core has been started as a port of [CoreAmstrad by Renaud Hélias](https://github.com/renaudhelias/CoreAmstrad) but every module has been either rewritten or replaced so, now it can be treated as a completely new core.

## Features
* Precise CPU timings including proper contention model.
* Cycle-exact Gate Array, created from [reverse engineered decapped original Amstrad 40010 chip](https://www.cpcwiki.eu/forum/amstrad-cpc-hardware/gate-array-decapped!/msg170713/#msg170713).
* Precise CRTC model supporting many tricks of Types 1 and 0.
* 2 disk drives
* Disk write support.
* Close to real disk drive emulation with support of some protections.
* Selectable CPC 6128/664 mode with separate ROM sets.
* Multiface 2.
* Several monochrome modes and 2 types of palette (GA/ASIC).
* Selectable expansion ROM loading.
* Joystick support with up to 3 buttons (2 on MiST)
* Kempston, SYMBiFACE II and Multiplay mice.
* HQ2x and Scanlines FX for scandoubler.
* Tape input through UART header (MiST)
* Support *.CDT tape files.
* Tape output through speaker.


## Installation
Place RBF and **amstrad.rom** into root of SD card. Or on **MiSTer** you can rename ROM to boot.rom and put it into Amstrad folder.

## Disk support
Put some *.DSK files into Amstrad folder and mount it from OSD menu.
important Basic commands:
* cat - list the files on mounted disk.
* run" - load and start the program. ex: run"disc
* |a, |b - switch between drives

## Boot ROM
Boot ROM has following structure:

OS6128 + BASIC1.1 + AMSDOS + MF2 + OS664 + BASIC664 + AMSDOS + MF2

Every part is 16KB. You can create your own ROM if you have a special preference.

## Expansion ROM
Expansion ROM should have file extension .eXX, where XX is hex number 00-FF of ROM page to load.
Every page is 16KB. It's possible to load larger ROM. In this case every 16KB block will be loaded in subsequent pages.

### Special extensions:
* eZZ - LowROM(OS)
* eZ0 - LowROM(OS) + Page 0(Basic) + subsequent pages depending on size.

### Notes
- You can load several expansions. With every load the system will reboot. System ROM also can be replaced the same way.
To restore original ROM you have to reload the core (Alt-F12).

### MiSTer specific
You can define boot extensions to automatically load at start of core. Use following name rules:
* boot.eXX  - load to both 664 and 6128 configs
* boot0.eXX - load to 6128 config
* boot1.eXX - load to 664 config

whehe XX is 00-FF, ZZ, Z0.

## CDT tape files
CDT supported in very basic form for retro feeling and for some very specific apps. There is no way to rewind or fast forward the file. 
USER LED will lit if there is a tape in the memory and still have data to play and blink while playback.

Control keys (MiSTer):
* Alt+F1 - mute/unmute the tape sound
* Alt+F2 - force playback
* Alt+F3 - force pause
* Alt+F2+F3 - unload the tape (turn off the LED)

CDT playback respects the tape motor state, so using F2/F3 is not required during playback.

## RAM
CPC664 model has only 64KB RAM - use this model for programs not compatible with 128KB RAM.

CPC6128 model has 64KB+512KB RAM. Upper 448KB are visible in special OS ROM or application aware of 512KB expansion.

## Multiface 2
* Multiface 2 can be activated with F11.
* USER LED shows if the MF2 ROM/RAM is active.
* Returning from the MF2 menu via (r)eturn makes the device invisible.
* Visibility can be restored via machine reset (original MF 2+).
* For loading a saved game, MF2 must be visible.
* ROM version is 8D.

## MiST specific notes
- Some demos sets up the CRTC to emit sync signals which are only compatible with the original Amstrad monitor, or CRT displays.
Enabling "Video & Audio => Sync signals: Filtered" tries to change these signals to be more LCD compatible,
however it doesn't work in every case.

- Reset is possbile with Alt+F11
