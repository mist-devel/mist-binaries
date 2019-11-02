Minimig-AGA for MIST
====================
http://somuch.guru/minimig/minimig-mist

REQUIREMENTS
====================

To use this minimig core on the MiST board, you will at the minimum need an SD/SDHC card, formatted with the FAT32 filesystem, an USB keyboard and a compatible monitor / TV. Joysticks & mouse can be emulated on the keyboard. You will probably want to attach a set of speakers or headphones, a real Amiga or USB mouse and a real Amiga joystick or an USB gamepad. The MiST board is needed, too, of course!

You will also need a Kickstart ROM image file, which you can obtain by copying Kickstart ROM IC from your actual Amiga, or by buying an Amiga Forever software pack. The Kickstart image should be placed on the root of the SD card with the name kick.rom.


The minimig can also use HDF harddisk images, which can be created with WinUAE.

Recommended minimig config:
* for ECS: Kickstart 1.3, CPU 68000, Turbo NONE, Chipset ECS, chipRAM 0.5MB, slowRAM 0.5MB
* for AGA: Kickstart 3.1, CPU 68020, Turbo NONE, Chipset AGA, chipRAM 2.0MB, slowRAM 0.0MB, fastRAM = 24MB

FILES
====================

minimig_mist-???.zip
- minimig-mist.rbf     - the minimig core, place it on the root of your SD card

minimig_boot_art.zip
- minimig.art          - minimig core boot animation
- minimig.bal          - minimig core boot animation
- minimig.cop          - minimig core boot animation

Plus two additional files:
- aros.rom             - AROS kickstart replacement, place in on the root of your SD card
- hrtmon.rom           - HRTmon monitor code, place it on the root of your SD card if you intend to use it

RELEASE NOTES
====================
minimig_mist-20191102

Many more CPU fixes
24 bit wide address bus in 68000 mode - that means the max. Fast RAM is 8MB, but that's the correct behavior

minimig_mist-20191005

A couple of 68020 CPU fixes from Retrofun
4-player interface support

minimig_mist-20190418

Some internal fixes for stability
Enable CD32 Pad support

minimig_mist-20160224 (2016-02-24)

This is just a bugfix release with fixed turbo mode implementation, no new features are added on top of the 1.2 release.
