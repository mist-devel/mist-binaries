# Tandy CoCo/Dragon32/64 FPGA replica

This core is based on the [work of dshadoff and alanswx and pcornier](https://github.com/MiSTer-devel/CoCo2_MiSTer).

It's enhanced, bugfixed, cleaned up by (C) 2025 Gyorgy Szombathelyi.

The core is re-implementing [Tandy Color Computer](https://en.wikipedia.org/wiki/TRS-80_Color_Computer), is a series of home computers developed and sold by Tandy Corporation.
Also implementing the [Dragon 32/64](https://en.wikipedia.org/wiki/Dragon_32/64), which is very similar to the CoCo.

### ROM file

The core needs a .ROM file, which can be created from rom/CoCoDragon.mra, using MAME ROM collection
(the file is assembled from several zip files: *coco.zip*, *coco_fdc.zip*, *dragon32.zip*, *dragon_fdc.zip*),
and the [MRA tool](https://github.com/mist-devel/mra-tools-c).

### Tape Loading

Loading real tapes are supported (using UART_RX on MiST or the Audio input port on SiDi), however I usually faced of IO error during loading.

A better method is to use the disk interface. The most common disk image files for CoCo are 161280 bytes long (35 track, 18 sectors/track, 256 bytes/sector).
For Dragon, similar disk images are 184320 bytes long (40 track, 18 sectors/track, 256 bytes/sector). Most commonly found *VDK* files has a 12 bytes header,
it must be stripped off before use.
On Linux, the *dd* utility can be used:

```
dd if=SPACEWAR.VDK of=SPACEWAR.DSK bs=1 skip=12
```


(C) 2025 Gyorgy Szombathelyi based on the work of dshadoff, alanswx, pcornier

MC6809 by Greg Miller

PIA6520 by (C) 2011, Thomas Skibo

mc6847.vhd and mc6883.vhd origins are unknown, found in old Pace source tree, greatly enhanced by persons above
