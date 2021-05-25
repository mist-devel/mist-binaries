# MIST port of fpgapce - PC Engine core

Current development sources can be found at:

https://github.com/gyurco/TurboGrafx16_MiSTer/tree/mist

# CD support

Only CUE files with single image file (FILE keyword) are supported!

Usage:

- Load a BIOS with the first OSD option (as it would be a normal HuCard).
- Mount the CUE file via the "Mount CD" option
- Optionally mount a SAV file (size: 2KB - 2048 byte). Before the first use,
  it must be formatted from the BIOS menu. Use the "Write Save RAM" option to
  save its contents to the SD Card.

You'll need a recent firmware (at least 210525) for CD support.

# Contributions

- [Original core by Torlus](https://github.com/Torlus/fpgapce)
- [Alastair Robinson's updates](https://github.com/robinsonb5/fpgapce)
- [MiSTer improvements by srg320](https://github.com/MiSTer-devel/TurboGrafx16_MiSTer)