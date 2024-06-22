
# SNK M68000 (Ikari III) FPGA Implementation

FPGA compatible core of SNK M68000 (Ikari III based) arcade hardware originally written by [**Darren Olafson**](https://twitter.com/Darren__O). FPGA implementation has been verified against schematics for Ikari III (A7007). PCB measurements taken from Datsugoku: Prisoners of War (A7008), Street Smart (A8007), and Ikari III: The Rescue (A7007).

Ikari III PCB donated by [**atrac17**](https://github.com/atrac17) / [**DJ Hard Rich**](https://twitter.com/djhardrich) and verified by [**Darren Olafson**](https://twitter.com/Darren__O). Other SNK68K PCB verification done by [**atrac17**](https://github.com/atrac17). The intent is for this core to be a 1:1 playable implementation of SNK M68000 (Ikari III) arcade hardware. Currently in **beta state**, this core is in active development with assistance from [**atrac17**](https://github.com/atrac17).

MiST port, new SDRAM controller, some fixes and enhancements by Gyorgy Szombathelyi.

## Supported Games

| Title | PCB<br>Number | Status  | Released | ROM Set  |
|-------|---------------|---------|----------|----------|
| [**脱獄: Prisoners of War**](https://en.wikipedia.org/wiki/P.O.W.:_Prisoners_of_War)<br>P.O.W.: Prisoners of War | A7008         | Implemented | Yes | .245 merged |
| [**怒III**](https://en.wikipedia.org/wiki/Ikari_III:_The_Rescue)<br>Ikari III: The Rescue                        | A7007         | Implemented | W.I.P | .245 merged |
| [**Street Smart**](https://en.wikipedia.org/wiki/Street_Smart_(video_game))                                      | A7008 / A8007 | Implemented | Yes   | .245 merged |
| [**SAR: Search and Rescue**](http://snk.fandom.com/wiki/SAR:_Search_and_Rescue)                                  | A8007         | Implemented | Yes   | .245 merged |

## External Modules

|Name| Purpose | Author |
|----|---------|--------|
| [**fx68k**](https://github.com/ijor/fx68k)                      | [**Motorola 68000 CPU**](https://en.wikipedia.org/wiki/Motorola_68000) | Jorge Cwik     |
| [**t80**](https://opencores.org/projects/t80)                   | [**Zilog Z80 CPU**](https://en.wikipedia.org/wiki/Zilog_Z80)           | Daniel Wallner |
| [**jtopl2**](https://github.com/jotego/jtopl)                   | [**Yamaha OPL 2**](https://en.wikipedia.org/wiki/Yamaha_OPL#OPL2)      | Jose Tejada    |
| [**jt7759**](https://github.com/jotego/jt7759)                  | [**NEC uPD7759**](https://github.com/jotego/jt7759)                    | Jose Tejada    |

# PCB Check List

<br>

FPGA implementation has been verified against [**schematics**](https://github.com/va7deo/SNK68/blob/main/doc/A7007%20(Ikari%20III)/Schematic/A7007%20Schematics.pdf) for Ikari III. PCB measurements taken from Datsugoku: Prisoners of War (A7008), Street Smart (A8007), and Ikari III: The Resucue (A7007).

### Clock Information

H-Sync      | V-Sync      | Source   | PCB<br>Number  |
------------|-------------|----------|----------------|
15.625kHz   | 59.185606Hz | [**DSLogic+**](https://github.com/va7deo/SNK68/blob/main/doc/A7008%20(P.O.W.)/PCB%20Measurements/POW_CSYNC_50MHz.png) | A7008 (P.O.W.) |
15.625kHz   | 59.185606Hz | TBD                                                                                                                   | A7007 (IK3)    |
15.625kHz   | 59.185606Hz | DSLogic+                                                                                                              | A8007 (SS)     |

### Crystal Oscillators

Location               | PCB<br>Number               | Freq (MHz) | Use                       |
-----------------------|-----------------------------|------------|---------------------------|
X-4  (4MHZ)            | A7008 (P.O.W.) / A8007 (SS) | 4.000      | Z80 / YM3812 / uPD7759    |
X-2  (18MHZ)           | A7008 (P.O.W.) / A8007 (SS) | 18.000     | M68000                    |
X-1  (24MHz)           | A7008 (P.O.W.) / A8007 (SS) | 24.000     | Video / Pixel Clock       |

<br>

Location               | PCB<br>Number             | Freq (MHz) | Use                       |
-----------------------|---------------------------|------------|---------------------------|
F-18 (4MHZ)            | A7007 (IK3) / A8007 (SAR) | 4.000      | Z80 / YM3812 / uPD7759    |
H-17 (18MHZ)           | A7007 (IK3) / A8007 (SAR) | 18.000     | M68000                    |
E-9  (24MHz)           | A7007 (IK3) / A8007 (SAR) | 24.000     | Video / Pixel Clock       |

**Pixel clock:** 6.00 MHz

**Estimated geometry:**

    383 pixels/line
  
    263 pixels/line

### Main Components

Location | PCB<br>Number | Chip | Use |
---------|---------------|------|-----|
68000    | A7008 (P.O.W.) / A8007 (SS) | [**Motorola 68000 CPU**](https://en.wikipedia.org/wiki/Motorola_68000)   | Main CPU      |
Z-80A    | A7008 (P.O.W.) / A8007 (SS) | [**Zilog Z80 CPU**](https://en.wikipedia.org/wiki/Zilog_Z80)             | Sound CPU     |
YM3812   | A7008 (P.O.W.) / A8007 (SS) | [**Yamaha YM3812**](https://en.wikipedia.org/wiki/Yamaha_OPL#OPL2)       | OPL2          |
7759     | A7008 (P.O.W.) / A8007 (SS) | [**NEC uPD7759**](https://github.com/jotego/jt7759)                      | ADPCM Decoder |

Location | PCB<br>Number | Chip | Use |
---------|---------------|------|-----|
H-11/12  | A7007 (IK3) / A8007 (SAR) | [**Motorola 68000 CPU**](https://en.wikipedia.org/wiki/Motorola_68000)   | Main CPU      |
Z80      | A7007 (IK3) / A8007 (SAR) | [**Zilog Z80 CPU**](https://en.wikipedia.org/wiki/Zilog_Z80)             | Sound CPU     |
YM3812   | A7007 (IK3) / A8007 (SAR) | [**Yamaha YM3812**](https://en.wikipedia.org/wiki/Yamaha_OPL#OPL2)       | OPL2          |
C-18     | A7007 (IK3) / A8007 (SAR) | [**NEC uPD7759**](https://github.com/jotego/jt7759)                      | ADPCM Decoder |

### Custom Components

Location | PCB<br>Number | Chip | Use |
---------|---------------|------|-----|
SNKCLK   | A7007 (IK3) / A8007 (SAR) | [**SNK CLK**](https://github.com/va7deo/SNK68/blob/main/doc/Custom%20Components/SNK_CLK.jpg) | Counter |
SNKI/O   | A7007 (IK3) / A8007 (SAR) | [**SNK I/O**](https://github.com/va7deo/SNK68/blob/main/doc/Custom%20Components/SNK_IO.jpg)  | Rotary  |

# Support

Please consider showing support for this and future projects via [**Darren's Ko-fi**](https://ko-fi.com/darreno) and [**atrac17's Patreon**](https://www.patreon.com/atrac17). While it isn't necessary, it's greatly appreciated.

# Licensing

Contact the author for special licensing needs. Otherwise follow the GPLv2 license attached.
