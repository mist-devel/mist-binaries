Minimig-AGA for MIST
====================

This is a beta release of Rok Krajnc's AGA extension of the Minimig
core with further enhancements by Alastair M. Robinson.

This is a work in progress and many things will still need fixing. 
Changes to get the CPU performance on par or beyond the A1200 have
caused some regressions. So a higher build number will not always
guarantee a more stable experience.

Recommended kickstart is Kickstart v3.1 rev 40.63 (A500-A600-A2000)

Optionally put the three files minimig.art, minimig.bal and
minimig.cop into the SD cards root directory for a nice boot
animation.

Source code can be found at
http://somuch.guru/minimig/minimig-mist/
https://github.com/rkrajnc/minimig-de1
https://github.com/rkrajnc/minimig-mist
https://github.com/robinsonb5/minimig_c3/tree/simplifiedsplitclock

minimig-mist-v1.1 (2016-01-xx)
------------------------------

These are development versions using an updated CPU core. The bitfield instructions in
68020 mode have been fixed. This required some significant changes and may have introduced
new problems. These versions are thus considered beta.

minimig-mist-v1.1 (2015-09-10) from http://somuch.guru/minimig/minimig-mist/
----------------------------------------------------------------------------

This is minimig AGA for the MiST board release 1.1.


In this zip file, there are several files:
- minimig-mist-1_1.rbf - the minimig core, place it on the root of your SD card
- firmware.upg         - firmware update, place it on the root of your SD card
- firmware.bin         - binary version of the firmware, used to update the ARM microcontroller through USB
- hrtmon.rom           - HRTmon monitor code, place it on the root of your SD card if you intend to use it
- minimig.art          - minimig core boot animation
- minimig.bal          - minimig core boot animation
- minimig.cop          - minimig core boot animation
- aros.rom             - AROS kickstart replacement, place in on the root of your SD card

Release notes:
The CPU in this release is slowed down a little, hopefully this will help with some of the problems some of you were having.

firmware.upg is included in the zip file, but only upgrade your firmware if it is older than 10th of September 2015.
If it is newer, there is no need to upgrade it.

This release supports 1MB ROMs, so you can try running AROS kickstart replacement ROM, or your custom kickstart ROM if you want.

The AROS kickstart replacement doesn't like something in the minimig IDE implementation, so using an IDE disk together with the AROS ROM will not work for now.

The Turbo option in OSD menu is still to be considered experimental.

The HRTmon monitor is accessed with the F11 key. There are currently some problems with the HRTmon implementation - 
it is only recommended to use it without moving the VBR (chipRAM only).


Updated features in this release:
- fixed mouse issues (fixes games Like Ishar 1, 2, 3, Robinson's Requiem, and many cracktros)
- fixed keyboard issues (fixes game Walker and probably many others)
- changes to FPGA clock handling, hopefully this will make a more stable minimig core
- entering the OSD menu using UP+DOWN buttons on a DB-9 connected joystick has been disabled
- 1MB kickstart ROM support added (enables you to run AROS ROM or your custom kickstart ROM)
- firmware now again supports using 256kB kickstart ROMs
- firmware now again supports using Cloanto AmigaForever encrypted kickstart ROMs
