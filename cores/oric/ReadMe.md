# Oric 48K in MiST and SiDi FPGA

Oric-1 and Oric Atmos re-implementation on a modern FPGA.

### Background:

There is one version made and ported by [Gehstock](https://github.com/Gehstock/Mist_FPGA/tree/master/Computer_MiST/OricInFPGA_MiST) at github , but it's far to be functional like an Oric. Gehstock's version for MiST board was realeased as a proof of concept with only 32KB RAM (no oric existed with that memory, only **16K** ,**48K** and **64K**)(64KB is real RAM) so there were errors managing **HIRES** mode) and no way to load audio tapes and lots of graphics errors on screen.

### What can you expect from Oric 48K in MiST and SiDi FPGA ?

This project began in november 2019 with the aim to preserve the Oric's computer family into fpga.

Actually Oric 1, Oric Atmos and Microdisc are fully functional.
* **ULA HCS10017**.
* **VIA 6522**.
* **CPU 6502**.
* Full 64KB of **RAM**.
* Keyboard managed by GI-8912.
* Sound (**AY-3-8910**).
* switchable **ROM** (between 1.1a ATMOS version and 1.0 ORIC 1 version).
* Tape loading working (via audio cable on the RX pin).
* Oric Microdisc implementation vía **CUMULUS**
* Disc Read / Write operations fully supported with EDSK (The same as amstrad cpc) format.
* Disc Sedoric/OricDOS Operating System Loading fully working

### TODO

 * Debugging, checking for possible bugs at video and improving the core.


### KNOWN BUGS

   * None at the moment..., but if You find one, let Us know, please.

### HOW TO USE AN ORIC 1 & ATMOS WITH MiST, MiSTica and SiDi FPGA boards.

* **Create a directory called ORIC at your sd's root and put inside the disc images to work on**

   * Once the core is launched:

   Keyboard Shorcuts:
   * F10 - NMI button, acts like original ORIC NMI
   * F11 - Reset. Use F11 to reboot once a DSK is selected at OSD
   * F12 - OSD Main Menu.

   ![shortcuts](img/shorcuts.jpg?raw=true "Keyboard shortcuts")   

   * Activate FDC controller at OSD MENU
   * Select an Image from /ORIC directory, exit OSD and press F11. System will boot inmeddiately



## The Oric Fpga preservation TEAM

   * Ron Rodritty:  Team coordination and QA testing.
   * Fernando Mosquera: FPGA guru.
   * Subcritical: Verilog and VHDL.
   * ManuFerHi: Hardware consulting.
   * Chema Enguita: Oric Software gurú
   * SiliceBit: Oric hardware Gurú
   * ZXMarce: Hardware support 24/7...
   * Ramón Martínez:  Oric hardware, Some software, and fpga coding.
   * Slingshot: SDRAM work and advisor.

* Kudos to: Sorgelig, Gehstock, DesUBIKado, RetroWiki and friends.

## About disk images.

  Despite of the .dsk extension, Disk images are the defacto standard **edsk** for disk preservation (also known as "AMSTRAD CPC EXTENDED FORMAT"). To convert images
  from the oric "dsk" to the needed "dsk" you need the [HxCFloppyEmulator software] (https://hxc2001.com/download/floppy_drive_emulator/HxCFloppyEmulator_soft.zip).

  Load the disk oric disk and export it as **CPC DSK file** the resulting image should load flawlessly on the Oric.
  This images are also compatible with fastfloppy firmware on gothek, cuamana reborn, etc working with real orics.

## Joystick

  Almost all the Oric games dont have joystick support, but you can "map" the
most used keys to a joystick adding thist to your **mist.ini** file.

	[oric]
	joy_key_map=1,4f     ; cursor right
	joy_key_map=2,50     ; cursor left
	joy_key_map=4,51     ; cursor down
	joy_key_map=8,52     ; cursor up
	joy_key_map=10,2c    ; button A as SPACE
	joy_key_map=40,28    ; button SEL as ENTER
	joy_key_map=80,44    ; button STA as F11 

## Software redistribution.

 In the dsk directory, you will find some disk images in the proper format. 

* **SEDORIC 4.0** operating System disk image redistributed with permission from Symoon.
* **Blake's 7** game, redistributed with permission of chema enguita you can download manual and additional info from [Defence force](http://www.defence-force.org/index.php?page=games&game=blakes7)
* **Oricium** game, redistributed with permission of chema enguita you can download manual and additional info from [Defence force](http://www.defence-force.org/index.php?page=games&game=oricium)
* **Space:1999** game, redistributed with permission of chema enguita you can download manual and additional info from [Defence force](http://www.defence-force.org/index.php?page=games&game=space1999)
* **1337** game, redistributed with permission of chema enguita you can download manual and additional info from [Defence force](http://www.defence-force.org/index.php?page=games&game=1337)
* **Torreoscura** game, redistributed with permission of Bieno. you can download manual and additional info from [itch.io](https://commodore-plus.itch.io/torreoscura-eng-c64-oric)
* **El prisionero** game, redistributed with permission of Bieno. you can download manual and additional info from [itch.io](https://commodore-plus.itch.io/el-prisionero)

