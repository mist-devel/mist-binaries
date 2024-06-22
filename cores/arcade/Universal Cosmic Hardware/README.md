# [Arcade: Universal Cosmic](https://www.arcade-museum.com/game_detail.php?game_id=7398) games (Z80-based) originally for [MiSTer](https://github.com/MiSTer-devel/Main_MiSTer/wiki)

By [Mike Coates](https://github.com/macrofpga)
Current Version - 1.00 - 03/07/2022

## Description

This is a recreation of the [Universal](https://www.arcade-museum.com/manuf_detail.php?manuf_id=1703&orig_game_id=7398) games that run on similar hardware.

The game timing should be very close to the original, but the code is not necessarily identical to the real thing, but achieves the same end result.

## Controls

Up, Down, Left, Right, Fire 1, Fire 2 (not all games use all buttons)

## Games currently supported

* [Cosmic Alien](https://www.arcade-museum.com/game_detail.php?game_id=7398)
* [Devil Zone](https://www.arcade-museum.com/game_detail.php?game_id=7576)
* [Magical Spot](https://www.arcade-museum.com/game_detail.php?game_id=8505)
* [No Mans Land](https://www.arcade-museum.com/game_detail.php?game_id=19281)
* [Space Panic](https://www.arcade-museum.com/game_detail.php?game_id=9676)

## Known differences/problems

Sound effects are all implemented using samples (other than the DAC).

I have added a screen flip option to the sprite code, sprites are flipped by the software on the real hardware, but everything else does have a flip signal. It is implemented as a fake dip switch.

## ROM Files Instructions

- Create ROM and ARC files from the MRA files in the meta directory using the MRA utility.
  Example: mra -A -z /path/to/mame/roms "Cosmic Alien.mra"
- Copy the ROM files to the root of the SD Card
- Copy the RBF and ARC files to the same folder on the SD Card

MRA utility: https://github.com/sebdel/mra-tools-c/
