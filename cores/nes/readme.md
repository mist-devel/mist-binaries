# NES core for MiST

This is a port of Luddes NES core to the MIST. See his FPGANES blog at
<http://fpganes.blogspot.de> for details. The original source code can
be found at <https://github.com/strigeus/fpganes>

You need a USB game pad with at least 2 buttons to run NES games. With
4 buttons SELECT and START will also be mapped. For pads with two buttons
START and SELECT can also be reached from the OSD.

## 15 khz support (TV)
Create a mist.ini file with at least the following line:

```
[mist]
scandoubler_disable=1
```

## Keyboard support in NES

* 1 - switch to joystick A
* 2 - switch to joystick B
* Up,Down,Left,Right
* Esc - start
* Tab - select
* Space - fire 1
* Left Alt - fire 2

## [Powerpad](https://en.wikipedia.org/wiki/Power_Pad) emulation support

The powerpad/Family Trainer/Family Fun Fitness accessory is emulated through
the keyboard.

Side A:
*    O  O    -   T R
* O  O  O  O - H G F D
*    O  O    -   B V   

Side B:
* 1  2  3  4 - E R T Y
* 5  6  7  8 - D F G H
* 9 10 11 12 - C V B N 

## FDS image support

Famicom Disk System images are supported through Loopy's FDS mapper. It needs
a modified FDS BIOS, can be found in the [NES PowerPak](https://www.retrousb.com/product_info.php?products_id=34).
Get FDSBIOS.BIN from the archive, and load using the OSD Load FDS BIOS option before
loading an FDS file.

If a game requires a disk swap, hold down the PgUp key for a while. If the automatic
mechanism determining the requested disk side doesn't work, select it using the
OSD Disk Side option.

## NSF music files

They're played using Loopy's NSF player. Just load the NSF file and enjoy.

## Backup RAM support / FDS image save

TODO
