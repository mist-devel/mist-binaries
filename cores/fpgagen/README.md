# MIST port of fpgagen - Genesis/Megadrive core

This core implements a Sega Genesis/Megadrigve for the MIST.

The cores main features
  - Complete 68k and z80 CPU implementations
  - Video controller (VDP)
  - Stereo sound
  - Analog video output
    - VGA
    - SCART RGB (TV)
    - YPbPr component

By now the core runs most games perfectly incl. the Titan Overdrive demo. Some games using
special and undocumented hardware features show visual or accousic artifacts or may not
run at all.

![Sonic on TV](sonic_tv.jpg)

## Installing the core

Copy the following files to the root of your sdcard:
  - Copy the latest rbf file (i.e. fpgagen_20181026.rbf) and rename it core.rbf
  - Copy mist.ini - This remaps the controller buttons to Buffalo SNES, and you can customise
it to your controller.
  - Copy your .bin/.md/.gen cartridge images to the sdcard (preferrably into a genesis subdirectory)

## Some usage tips

  1. The core rquires at least firmware version 20181013.
  2. Rom file formats supported are .bin and .gen, no support for .smd files
  3. If the controls seems to not work, try switch to 3 buttons mode in the OSD
  4. Includes support for [YPbPr cables](https://github.com/mist-devel/mist-board/wiki/YPbPr_Cable)
  5. While lot of effort went into emulating the correct VRAM access timings of the Sega VDP, it's
     still not perfect. So you can turn off this emulation with the "VRAM Speed" option. "Slow" setting
     means the VRAM access times are emulated, "Fast" when not. This might be required for Sonic I and
     Clue.
  6. Some carts have an SRAM or EEPROM to allow saving game states. SRAM is always enabled at 2MB (if
     the cart size < 2MB), and you can turn on a "fake" EEPROM at 2MB in the OSD. For example, it
     allows NBA Jam TE to run.

## Contributors

  - [Original core by Torlus](https://github.com/Torlus/fpgagen)
  - [TG68K CPU core by Tobias Gubener](https://opencores.org/project/tg68)
  - [T80 CPU core by Daniel Wallner](https://opencores.org/project/t80/overview)
  - [Initial MIST port by Robinsonb5](https://github.com/robinsonb5/fpgagen)
  - [JT12 YM2612 sound core by Jose Tejada](https://github.com/jotego/jt12)
  - [Improvements by Gyurco](https://github.com/gyurco/fpgagen)
  - [Improvements by Sorgelig](https://github.com/MiSTer-devel/Genesis_MiSTer)
  - and many more ...

