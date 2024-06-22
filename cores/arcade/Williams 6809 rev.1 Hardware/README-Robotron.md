robotron-fpga MiST port
=======================

Supported games: Robotron 2048, Joust, Splat, Bubbles, Stargate, Alien Arena, Sinistar,
  Playball!, Lotto Fun, Speed Ball

After loading the RBF (Core), a CMOS clearing happens. When the message 
"Factory Settings Restored" appears, press the MiST soft RESET button (right).

Usage:
------
- Make sure you use firmware 200215 or later.
- Create ROM and ARC files from MAME ROM zip files using the mra utility and the MRA files.
- Example: mra -A -z /path/to/mame/roms Stargate.mra
- Copy the RBF and the ARC files to the same folder.
- Copy the ROM files to the root of the SD Card.

- MRA utilty: https://github.com/sebdel/mra-tools-c

Note: the MRA files contains a dump of the CMOS RAM. It will be included in the generated ROM file.
Change it for permanent settings (search for the format online). It's possible to change these values
inside the core, with turning on "Auto-up" switch, and activate the "Advance" trigger in the OSD. Then
it's possible to save these settings and high scores into a RAM file via the "Save NVRAM" OSD item.
Refer to the arcade's user manual for further info.


Joystick Remaps
---------------

Some of the Williams cores use more buttons than usual and require remaps to be useful.

The file [README-joystick-remaps.txt](https://github.com/Gehstock/Mist_FPGA_Cores/blob/master/Arcade_MiST/Williams%206809%20rev.1%20Hardware/README-joystick-remaps.txt) contains joystick remaps for the Williams cores.

** Note: ** Speed Ball is playable only with two human players. It needs two controllers and two mice (with the appropriate firmware supporting two mice).

---

robotron-fpga (Original Documentation)
=============

An implementation of the classic Robotron: 2084 video arcade game from 1982.
Both the sound board and CPU/interface boards are implemented, but are in
separate sub-projects at the moment. The CPU/interface implementation relies
on a Motorola MC6809E processor attached to the FPGA board via an adapter
board design that is part of this project.

![robotron-cpu on NEXYS2 FPGA board](https://github.com/sharebrained/robotron-fpga/raw/master/doc/photo/robotron-on-nexys2.jpg)

The goal is to have a complete Robotron: 2084 game implemented in a single,
compact, inexpensive FPGA board which includes the necessary peripherals:
video and sound outputs, joysticks interface, and coin/player buttons.

Status
======

The CPU/interface and sound boards are implemented as separate projects.
Both appear to function well.

The MC6809E breakout board has been fabricated, but has some design issues
that need to be addressed. The primary issue is the lack of pull-up/-down
resistors on key MC6809E signals, to keep the processor in a RESET state
until the FPGA board is ready to work with the MC6809E. I also screwed up
and put the NEXYS2 connector on the "bottom side" of the board. Smooth!

Documentation
=============

These documents served me well during development of this project.

[Sean Riddle](http://seanriddle.com/) - Williams arcade machine information,
including Robotron: 2084.

* [Hardware overview](http://seanriddle.com/willhard.html)
* [Memory map](http://seanriddle.com/memmap.gif)
* [Processor and video timing](http://seanriddle.com/timing.html)
* [BLTter description and test code](http://seanriddle.com/blittest.html)

[Robotron-2084](http://www.robotron-2084.co.uk/) - Williams arcade machine
official documentation.

* [Robotron schematics and instruction manuals](http://www.robotron-2084.co.uk/manualsrobotron.html)
* [Defender "later series" theory of operation](http://www.robotron-2084.co.uk/manualsdefender.html),
    interesting because the Robotron and Defender hardware is quite
    similar.
    
Documentation for various ICs in the original Robotron: 2084 machine.

* [MC6809E microprocessor datasheet](http://www.classiccmp.org/dunfield/r/6809e.pdf)
* [MC6809E microprocessor programming manual](http://www.classiccmp.org/dunfield/r/6809prog.pdf)
* [DM9316 Synchronous 4-Bit Binary Counter](http://www.ti.com/product/dm9316)
* National Semiconductor(?) DM7489 64-bit random access read/write memory
    (no good reference)
* [Harris HM-7641 512 x 8 PROM](http://www.bitsavers.org/pdf/harris/_dataBooks/1978_Harris_Memory_Vol1.pdf) (page 2-35)
* [Harris HM-6514 1024 x 4 CMOS RAM](http://www.bitsavers.org/pdf/harris/_dataBooks/1978_Harris_Memory_Vol1.pdf) (page 3-49)
* [Mostek MK4116 16,384 x 1 bit dynamic RAM](http://hardware.speccy.org/datasheet/MK4116.pdf)
* [Signetics 8T97 hex buffer](http://www.bitsavers.org/pdf/signetics/_dataBooks/1977_Bipolar_Microprocessor.pdf) (page 96)
* [Various 74-series logic ICs](http://www.ti.com/lsds/ti/logic/home_overview.page)
    
[Digilent](http://www.digilentinc.com/) - FPGA development boards and 
accessories.

* [NEXYS2 FPGA development board](http://digilentinc.com/Products/Detail.cfm?NavPath=2,400,789&Prod=NEXYS2)

[Xilinx](http://www.xilinx.com/) - FPGA silicon and tools vendor.

* [Spartan-3E documentation](http://www.xilinx.com/support/documentation/spartan-3e.htm)

Requirements
============

* Digilent NEXYS2 Spartan-3E FPGA development board.

    This is the board I've done my development on, and is a good choice
    because it has plenty of inputs, a VGA output connector, many switches
    and LEDs, and enough onboard RAM and flash to meet the game's memory
    needs.

* Williams Robotron: 2084 ROM binary files:

    These files are often used with MAME, the arcade emulator. CPU board
    ROM files are named "robotron.sb?", where "?" is "1" through "9" and
    "a" through "c". The sound board ROM file is named "robotron.snd".

* Python 2.7:

    Used to transform ROM and PROM files into VHDL files.

* Xilinx ISE WebPack 13.4:

    For compiling VHDL and generating the bit file for the FPGA.

* Digilent Adept or other JTAG tool:

    For loading the bit file into FPGA board.

* VGA monitor:

    Video output is 31.25 kHz horizontal sync and 60 Hz vertical sync,
    which is compatible with VGA monitors. The output is line-doubled
    from the arcade game's original 15.625 kHz horizontal sync.

* RC lowpass filter:

    The PWM audio output from the FPGA needs filtering to sound reasonable,
    or an eight-bit DAC can be attached to the 8-bit audio output pins of
    the FPGA board.

Tools
=====

* make_rom_file.py:

    Translates a set of Robotron ROM board ROM files
    (like those you would use with the MAME arcade emulator) into a
    binary file that can be loaded into the flash device on the Digilent
    FPGA board.

* make_decoder_vhdl.py:

    Translates a decoder.4 or decoder.6 file (data
    dumped from decoder PROMs on the Robotron CPU board) into a VHDL
    file used by the robotron_cpu project.

* dac_out_wave.py:

    Translates the text file output of robotron_test.vhd
    into a WAV file that can be played.

* make_sound_rom.py:

    Produces rom_snd_blocks.vhd, containing VHDL ROM
    blocks, from the contents of a robotron.snd ROM file. The
    robotron.snd file is not provided due to copyright on the original
    ROM binaries produced by Williams. I happen to have a physical
    instance of the ROM board, so I'm in the clear. :-)

Contributing
============

Contributions are welcome!

Please respect Williams Electronics' copyright and do not post any VHDL
or .bit files containing their binary code.

License
=======

This hardware design is licensed under a
[Creative Commons Attribution-ShareAlike 3.0 Unported License]
(http://creativecommons.org/licenses/by-sa/3.0/).

The associated software is provided under the GNU Public License, 
version 3:

This project is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This project is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this project. If not, see <http://www.gnu.org/licenses/>.

Contact
=======

Jared Boone <jared@sharebrained.com>

ShareBrained Technology, Inc.

<http://www.sharebrained.com/>


The latest version of this repository can be found at
https://github.com/sharebrained/robotron-fpga
