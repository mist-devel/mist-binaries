### Apple //e for MiST

This the MiST/SiDi port of a reconstruction of an 1980s-era Apple//e (enhanced),
based on the Apple ][+ implemented in VHDL for FPGAs.
* Original for the DE2: http://www1.cs.columbia.edu/~sedwards/apple2fpga/
* Port for the MiST: http://ws0.org/tag/apple2/
* Current [source code](https://github.com/gyurco/apple2efpga) on GitHub

Features:
- 6502 or 65C02 CPU
- disk loading via OSD (read/write support)
- joystick support
- tape input from the UART RX pin
- 15kHz TV and 30kHz VGA support (optional YPbPr output)
- scanlines
- color, amber, green and black&white monitor
- 64k auxilary memory with 80 column card in Slot 3
- Mockingboard model A (two AY-3-8913 chips for six audio channels) in slot 4
- CFFA 2.0 compatible IDE interface in slot 7
- Super Serial Card in slot 2
- AppleMouse // in slot 5

On the "Apple II/e" boot screen open the OSD with F12 and choose a nibblelized disk. It will boot
the disk automatically. Use dsk2nib to convert AppleII disk images to .nib images.

If you press reset (the right button on the MiST/SiDi128) you'll enter Applesoft with the ] prompt.
From here you have some limited commands. See: http://www.landsnail.com/a2ref.htm.
If you want to boot another disk choose a .nib image via the OSD and choose Cold Reset.

## CFFA IDE interface

The core implements a CFFA 2.1 compatible IDE interface. CFFA's default configuration is only for one drive.
To support two drives, enter the CFFA configuration utility by selecting Cold Reset, then quickly press 'M'
key. The settings is written to an EEPROM on the original interface, this can be preserved with the
"Save CFFA settings" menu item in the OSD.
For further settings, please refer to the [CFFA 2.1 manual](https://dreher.net/projects/CFforAppleII/downloads/CFFA_Manual_2.11.pdf).

When the core boots, the IDE interface automatically mounts appleII.hd0 as master IDE drive and appleII.hd1 as slave.
Later on, you can select different images via the OSD menu.

The core requires firmware version **250314** or later.
