### Apple //e for MiST

This the MiST port of a reconstruction of an 1980s-era Apple//e (enhanced),
based on the Apple ][+ implemented in VHDL for FPGAs.
* Original for the DE2: http://www1.cs.columbia.edu/~sedwards/apple2fpga/
* Port for the MiST: http://ws0.org/tag/apple2/

Features:
- 6502 or 65C02 CPU
- disk loading via osd (no write support yet)
- joystick support
- 15kHz TV and 30kHz VGA support (optional YPbPr output)
- scanlines
- color, amber, green and black&white monitor
- 64k auxilary memory with 80 column card in Slot 3
- Mockingboard model A (two AY-3-8913 chips for six audio channels) in slot 4

On the "Apple II/e" boot screen open the OSD with F12 and choose a nibblelized disk. It will boot
the disk automatically. Use dsk2nib to convert AppleII disk images to .nib images. 
The disk emulation is read only.

If you press reset (the right button on the MiST) you'll enter Applesoft with the ] prompt.
From here you have some limited commands. See: http://www.landsnail.com/a2ref.htm
If you want to boot another disk choose a .nib image via the OSD and choose Cold Reset
