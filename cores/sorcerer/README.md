# Exidy Sorcerer FPGA replica

The Sorcerer is a home computer system released in 1978 by the video game company Exidy.

### ROM file

The core needs a .ROM file, which can be created from rom/Sorcerer.mra, using MAME ROM collection (only *sorcerer.zip* is needed),
and the [MRA tool](https://github.com/mist-devel/mra-tools-c).

### Tape Loading

Loading real tapes are supported (using UART_RX on MiST or the Audio input port on SiDi).
A collection of WAV files can be found at https://www.classic-computers.org.nz/blog/2017-01-23-software-for-real-sorcerers.htm

Looks like 1200 baud files are not working, I'm not sure about the issue, but it seems the Monitor doesn't read the incoming data
fast enough, indicated by "Overrun" in the UART.

Another method is use .TAPE files, which can be loaded into the memory from the OSD **Load Tape** option. If there's a tape loaded,
the yellow LED will lit. In this case, the load commands (**LO** in the Monitor, or **CLOAD** in Basic) will use the loaded file instead
of the real tape input. **Note**: the UART cannot be used when a tape is loaded (yellow LED lit). A .TAPE file collection can be found
at https://forums.atariage.com/topic/372802-a-collection-of-games-for-the-exidy-sorcerer-categorized-by-year/

(C) 2024 Gyorgy Szombathelyi

T80 Copyright (c) 2001-2002 Daniel Wallner and others

