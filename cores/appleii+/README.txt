This the MiST port of a reconstruction of an 1980s-era Apple ][+ implemented in VHDL for FPGAs.

Original for the DE2: http://www1.cs.columbia.edu/~sedwards/apple2fpga/
Port for the MiST: http://ws0.org/tag/apple2/
Sources: https://github.com/wsoltys/mist-cores/tree/master/apple2fpga

On the "Apple ][" boot screen open the OSD with F12 and choose a nibblelized disk. It will boot
the disk automatically. Use dsk2nib to convert AppleII disk images to .nib images. 
The disk emulation is read only.

If you press reset (the right button on the MiST) you'll enter Applesoft with the ] prompt.
From here you have some limited commands. See: http://www.landsnail.com/a2ref.htm
If you want to boot another disk choose a .nib image via the osd and type the following:

]CALL -151
*C600G

The call command will enter the Monitor. Type the call a second time if the * prompt won't
show the first time. 
At the Monitor you can also type 6 and then Ctrl-P followed by return.
See http://vectronicsappleworld.com/appleii/dos.html#bootdos