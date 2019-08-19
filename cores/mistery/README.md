# MiSTery - An Atari ST/STe core for the [MiST board](https://github.com/mist-devel/mist-board/wiki)

## Features:

- Cycle accurate STe GLUE+MMU combo (re-created from the [original schematics](https://www.chzsoft.de/asic-web/))
- Cycle accurate [FX68K CPU core](https://github.com/ijor/fx68k)
- Mostly cycle accurate shifter based on [schematics made from reverse engineering](http://www.atari-forum.com/viewtopic.php?t=29658)
- MegaSTe 16 MHz CPU mode
- RAM size up to 14MB
- Support for all TOS versions
- 2 Floppy disc drives
- ACSI hard disc support
- Viking compatible hi-res monochrome card support
- [Real IKBD](https://github.com/harbaum/ikbd) with HD63701 MCU
- Real MIDI input/output using MiST's UART pins
- Serial/parallel port redirect to USB
- Gauntlet type 4 joystick interface support
- Optional scandoubled/YPbPr video output

## Usage:

Put the core.rbf and the TOS as tos.img to the SD-Card. TOS/hard disc/floppy images are selectable in the OSD (F12).

The core needs at least firmware version 20190819.

## Current issues/limitations:

- Some MFP imperfections
- Some bugs in ST mode
- Blitter is not cycle accurate (affects STe demos)
- No RAM cache for Mega STe
- Missing Ethernec support
- No RTC
- Only fake LMC1992
- PAL clock only (32.084 MHz)

## Thanks to:

- Till Harbaum for the MiST board, original MiST core, new IKBD code
- Jorge Cwik for the FX68K CPU core and shifter decap
- Christian Zietz for recovering the schematics of the GSTMCU
