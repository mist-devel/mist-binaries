# MiSTery - An Atari ST/STe core for the [MiST board](https://github.com/mist-devel/mist-board/wiki)

## Features:

- Cycle accurate STe GLUE+MMU combo (re-created from the [original schematics](https://www.chzsoft.de/asic-web/))
- Cycle accurate [FX68K CPU core](https://github.com/ijor/fx68k)
- Cycle accurate Blitter offered by Jorge Cwik
- Mostly cycle accurate shifter based on [schematics made from reverse engineering](http://www.atari-forum.com/viewtopic.php?t=29658)
- MegaSTe 16 MHz CPU mode
- Turbo bus - double RAM access speed
- RAM size up to 14MB
- Support for all TOS versions
- 2 Floppy disc drives
- ACSI hard disc support
- Viking compatible hi-res monochrome card support
- [Real IKBD](https://github.com/harbaum/ikbd) with HD63701 MCU
- Real MIDI input/output using MiST's UART pins
- Serial/parallel port redirect to USB
- Gauntlet type 4 joystick interface support
- STe controller port support
- Optional scandoubled/YPbPr video output

## Usage:

Put the core.rbf and the TOS as tos.img to the SD-Card. TOS/hard disc/floppy images are selectable in the OSD (F12).
With F11, you can toggle between normal and STe joystick ports.

## Current issues/limitations:

- Some MFP imperfections
- Some bugs in ST mode
- No RAM cache for Mega STe (but the cache control selects turbo bus speed)
- Missing Ethernec support
- No RTC
- Only fake LMC1992
- PAL clock only (32.084 MHz)
- Since Jagpads have 21 buttons, not all are mapped to MiST controllers when using STe game ports
- No STe paddle handling (but it has 0 software support)

## Thanks to:

- Till Harbaum for the MiST board, original MiST core, new IKBD code
- Jorge Cwik for the FX68K CPU core, FX ST Blitter code and shifter decap
- Christian Zietz for recovering the schematics of the GSTMCU
