# MIST port of fpgapce - PC Engine/TurboGrafx-16 core

- [Binaries](https://github.com/mist-devel/mist-binaries/tree/master/cores/pcengine)
- [Sources](https://github.com/gyurco/TurboGrafx16_MiSTer/tree/mist)

### Features:
- SuperGrafx support
- CD-ROM support
- 384K, 768K and SF2 special ROM mapper support
- Multitap up to 5 controllers (4 reported to work)
- 6 buttons controller support

# Installation #

Copy the `*.rbf` file to the root of the SD card.
You can rename the file to `core.rbf` if you want the MiST to load it automatically at startup.

Copy the PCE ROMS to the TGFX16 folder to automatically list them when you select the Load options in the OSD menu. TurboGrafx-16 titles should use .pce file extension, SuperGrafx ROMS have to be .sgx files.

**You'll need a recent firmware (at least 210525) for CD support.**

## OSD Menu (F12 key or middle button)

  * **Load \*.BIN,\*.PCE**: Loads a ROM in TurboGrafx-16 mode.
  * **Load \*.SGX**: Loads a ROM in SuperGrafx mode.
  * **Scanlines**: activate scanlines - best used in VGA mode (won't work in TV mode).
  * **ROM Data Swap**: Byteswaps the ROM. Seldom needed.
  * **6 Buttons**: Enables/disables 6 buttons controller support. Some games doesn't like active 6 buttons.
  * **Multitap**: Enables Multitap device for supporting up to 5 joysticks/gamepads in some games.

## CD support

Only CUE files with single image file (FILE keyword) are supported!

### Usage

- Load a BIOS with the first OSD option (as it would be a normal HuCard).
- Mount the CUE file via the "Mount CD" option
- Optionally mount a SAV file (size: 2KB - 2048 byte). Before the first use,
  it must be formatted from the BIOS menu. Use the "Write Save RAM" option to
  save its contents to the SD Card.

## Contributions

- [Original core by Torlus](https://github.com/Torlus/fpgapce)
- [Alastair Robinson's updates](https://github.com/robinsonb5/fpgapce)
- [MiSTer improvements by srg320](https://github.com/MiSTer-devel/TurboGrafx16_MiSTer)
- MiST improvements by Gyurco: SuperGrafx, CDROM support and many other improvements.

## Notes ##

  * You can switch TV/VGA mode with pressing the middle MiST button for 2 seconds, or with the scandoubler_disable setting in mist.ini.
  * YPbPr output can be activated via the ypbpr option in mist.ini, or by pressing the middle and right buttons on MiST simultaneously.

## Compatibility

Almost all released games are working, Davis Cup Tennis and Andre Panza Kick Boxing have issues.

## Gameplay videos of the older core versions

- [Devil's Crush](http://www.youtube.com/watch?feature=player_embedded&v=eqkAILkPe5I)
- [Super Star Soldier](http://www.youtube.com/watch?feature=player_embedded&v=4l58HPSzfjQ)
- [Parodius](http://www.youtube.com/watch?feature=player_embedded&v=CzeHW-gyMSI)
- [R-Type](http://www.youtube.com/watch?feature=player_embedded&v=OvreesBg8AE)
