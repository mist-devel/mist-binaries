# Next186 SoC PC

This is a MiST port of the [Next186 SoC](https://opencores.org/projects/next186_soc_pc) by (C) Nicolae Dumitrache.

Modifications from the original core:

- Added a standard MiST BIOS loader, the Next186.ROM will be loaded when the core starts.
- Selectable CPU speed (Maximum, half, third, quarter).
- CPU clock is 50 MHz, SDRAM clock is 100 MHz.
- DSP coprocessor is enabled, but too slow for MP3 playing.
- Using JTOPL2 as FM chip.
- MPU 401 MIDI output.
- More complete VGA implementation (programmable CRTC, some compatibility fixes, CGA modes support).
- Cache controller tweaks to flush VGA data on-demand.

## Usage

You'll need an installed MS-DOS (up to v6.22) on the SD-Card (or on a **Next186.VHD** or **Next186.HD0** file),
and the **Next186.ROM** BIOS file next to the **RBF**. 

There's a sample VHD "MIST & SIDI Next186 DOS VHD" on archive.org to get you started.

The core requires firmware version at least **220821**.

This core has several compatibility issues (but slowly improving). Here's a spreadsheet with
hint and tips for some titles:
https://docs.google.com/spreadsheets/d/1r07Ubfzquz2FxnKp4GROk8_Kq6kTlVW7YxVTmBDR_c4/edit#gid=0

### Settings

- CPU Speed: Maximum, /2, /3, /4 - Normally it is OK to use Maximum but quite a few games work better when set to /3 
- ISA Bus Wait: 1,2,3,4 us - Delay reading/writing AdLib ports. Might affect detectability/sound playback.
- MIDI: MPU401, COM1 - MPU401 enables the standard MIDI out port, COM1 enables COM1 serial rs232 out of the MIDI port.
- NMI: Hardware interrupt useful for debugging in DOS.

### VHD Support

You can mount a VHD file in Windows 10 using "Disk Management" > Attach VHD. You can then write files directly to the VHD as normal. Make sure file names are no more than 8 characters long.
To mount a VHD in MacOS use `hdiutil attach -imagekey diskimage-class=CRawDiskImage Next186.vhd`

### MIDI out

MPU 401 MIDI out is supported at the default 330 address. Interrupts are not support and not required for MIDI out. 

If you have no MIDI synth you can use MT32-Pi on a Raspberry Pi to play MIDI music for Roland MT-32 & General MIDI game support. If you have no MIDI input on the Raspberry Pi it is possible to connect MIDI out pins 2 (GND) & 5 (TX) to the Raspberry Pi GPIO pins 6 & 10. MT32-Pi is configured out of the box to play through the GPIO. On a MIST without MIDI ports, or a SIDI, you can connect the GPIO to the serial port. DO NOT CONNECT ANY VOLTAGE LINES.

Some games may require a slower CPU /3 speed to work correctly with the MT-32 when sending sysex.

You can also control the MT32-Pi from DOS using [mt32-pi-control](https://github.com/gmcn42/mt32-pi-control/tree/main/dos_bin)

### IDE support

The primary/slave drive is a permanent ATAPI CDROM. It's possbile to mount CUE/ISO files from the OSD. DOS requires an ATAPI CDROM driver (VIDE-CDD.SYS is recommended) and MSCDEX.

The secondary IDE channel is for ATA Hard Disk images. **Next186.HD2** and **Next186.HD3** files are automatically mounted during boot for the master/slave drives.
As the Next186 BIOS doesn't have IDE support, it requires a DOS driver, like **3DRIVES** or **4DRIVES**. **Notice:** to mount these drives,
the first (boot) drive must be called **Next186.HD0**, not **Next186.VHD**!

## Source code

- [Original code on opencores.org](https://opencores.org/projects/next186_soc_pc)
- [MiST port](https://github.com/gyurco/Next186)
