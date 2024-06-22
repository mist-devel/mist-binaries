
# Alpha Denshi M68000 FPGA Implementation

FPGA compatible core of Alpha Denshi M68000 (ALPHA68K96V based) arcade hardware written by [**Darren Olafson**](https://twitter.com/Darren__O).

FPGA implementation has been verified against schematics for Sky Adventure. PCB measurements taken from Gang Wars (ALPHA-68K96V) and Sky Soldiers (ALPHA-96KII).

Sky Adventure (bootleg) PCB purchased by [**Darren Olafson**](https://twitter.com/Darren__O) / [**atrac17**](https://github.com/atrac17). Gang Wars, Sky Soldiers, and The Next Space (authentic) PCBs purchased by [**atrac17**](https://github.com/atrac17).

The intent is for this core to be a 1:1 playable implementation of Alpha Denshi M68000 arcade hardware. Currently in **beta state**, this core is in active development with assistance from [**atrac17**](https://github.com/atrac17).

MiST port, new SDRAM controller, some fixes and enhancements by Gyorgy Szombathelyi.

## Supported Games

| Title | PCB<br>Number | Status  | Released | ROM Set |
|-------|---------------|---------|----------|---------|
| [**Gang Wars**](https://en.wikipedia.org/wiki/Gang_Wars_(video_game))                | ALPHA-68K96V (GW)  | Implemented                | Yes | .249 merged set |
| [**Super Champion Baseball**](https://snk.fandom.com/wiki/Super_Champion_Baseball)   | ALPHA-68K96V (GW)  | Implemented                | Yes | .249 (**sbasebalj** only) |
| [**Sky Adventure**](https://snk.fandom.com/wiki/Sky_Adventure)                       | ALPHA-68K96V (GW)  | Implemented                | Yes | .249 merged set |
| [**バトル フィールド**](https://en.wikipedia.org/wiki/Time_Soldiers)<br>Time Soldiers      | ALPHA-68K96II (SS) | Implemented                | Yes | .249 merged set |
| [**Sky Soldiers**](https://en.wikipedia.org/wiki/Sky_Soldiers)                       | ALPHA-68K96II (SS) | Implemented                | Yes | .249 merged set |
| [**Gold Medalist**](https://snk.fandom.com/wiki/Gold_Medalist)                       | ALPHA-68K96II (SS) | Implemented                | No | .249 (**goldmedl** only) |
| [**Paddle Mania**](https://snk.fandom.com/wiki/Paddle_Mania)                         | ALPHA-68K96I       | **W.I.P**                  | No | N/A |
| [**The Next Space**](https://snk.fandom.com/wiki/The_Next_Space)                     | A8004-1            | **Separate<br>Repository** | No | N/A |
| [**Super Stingray**](https://segaretro.org/Super_Stingray)                           | N/A                | **W.I.P**                  | No | N/A |
| [**Kyros no Yakata**](http://www.hardcoregaming101.net/kyros-desolator/)             | N/A                | **W.I.P**                  | No | N/A |
| [**Mahjong Block Jongbou**](https://snk.fandom.com/wiki/Jongbou)                     | ALPHA-68K96N       | **W.I.P**                  | No | N/A |

## External Modules

|Name| Purpose | Author |
|----|---------|--------|
| [**fx68k**](https://github.com/ijor/fx68k)                      | [**Motorola 68000 CPU**](https://en.wikipedia.org/wiki/Motorola_68000)   | Jorge Cwik     |
| [**t80**](https://opencores.org/projects/t80)                   | [**Zilog Z80 CPU**](https://en.wikipedia.org/wiki/Zilog_Z80)             | Daniel Wallner |
| [**jt2413**](https://github.com/jotego/jtopl)                   | [**Yamaha OPL-L**](https://en.wikipedia.org/wiki/Yamaha_YM2413)          | Jose Tejada    |
| [**jt03**](https://github.com/jotego/jt12)                      | [**Yamaha OPN**](https://en.wikipedia.org/wiki/Yamaha_YM2203)            | Jose Tejada    |

# PCB Check List

<br>

FPGA implementation has been verified against [**schematics**](https://github.com/va7deo/alpha68k/blob/main/doc/ALPHA-68K96V/ALPHA68K-96V_Schematics.pdf) for Sky Adventure. The schematics are improperly labeled Prehistoric Isle (hand written), this was discovered during development of the [**Prehistoric Isle FPGA implementation**](https://github.com/va7deo/PrehistoricIsle). PCB measurements taken from Gang Wars (ALPHA-68K96V) and Sky Adventure (ALPHA-68K96II).

### Clock Information

H-Sync      | V-Sync      | Source   | PCB<br>Number  |
------------|-------------|----------|----------------|
15.625kHz   | 59.185606Hz | [**DSLogic+**](FILLME) | ALPHA-68K96V (GW)  |
15.625kHz   | 59.185606Hz | [**DSLogic+**](FILLME) | ALPHA-68K96II (SS) |

### Crystal Oscillators

- MAME documentation for the Alpha96k.cpp states that ALPHA-68K96II hardware runs the M68000 at 8.00 MHZ. The actual frequency for the M68000 is 9.00 MHZ based on board readings from Sky Soldier.

Location                | PCB<br>Number      | Freq (MHz) | Use                                                                                          |
------------------------|--------------------|------------|----------------------------------------------------------------------------------------------|
X-1  (24 MHZ)           | ALPHA-68K96V (GW)  | 24.000     | Z80 CLK (6MHZ)<br><br>YM2203 (CLK 3 MHZ)<br><br>Sprite CLK (12 MHZ)<br><br>Pixel CLK (6 MHZ) |
X-2  (20 MHZ)           | ALPHA-68K96V (GW)  | 20.000     | M68000 CLK (10 MHZ)                                                                          |
X-3  (3.579545 MHz)     | ALPHA-68K96V (GW)  | 3.579545   | YM2413 CLK (3.579545 MHz)                                                                    |
X-1  (3.579545 MHz)     | ALPHA-68K96II (SS) | 24.000     | YM2413 CLK (3.579545 MHz)                                                                    |
X-2  (18 MHZ)           | ALPHA-68K96II (SS) | 18.000     | M68000 CLK (9 MHZ)                                                                           |
X-3  (24 MHZ)           | ALPHA-68K96II (SS) | 3.579545   | Z80 CLK (6MHZ)<br><br>YM2203 (CLK 3 MHZ)<br><br>Sprite CLK (12 MHZ)<br><br>Pixel CLK (6 MHZ) |

**Pixel clock:** 6.00 MHz

**Estimated geometry:**

    383 pixels/line
  
    263 pixels/line

### Main Components

Location | PCB<br>Number | Chip | Use |
---------|---------------|------|-----|
68000D   | ALPHA-68K96V (GW)  | [**Motorola 68000 CPU**](https://en.wikipedia.org/wiki/Motorola_68000)   | Main CPU      |
Z80B     | ALPHA-68K96V (GW)  | [**Zilog Z80 CPU**](https://en.wikipedia.org/wiki/Zilog_Z80)             | Sound CPU     |
YM2203   | ALPHA-68K96V (GW)  | [**Yamaha YM2203**](https://en.wikipedia.org/wiki/Yamaha_YM2203)         | OPN           |
YM2413   | ALPHA-68K96V (GW)  | [**Yamaha YM2413**](https://en.wikipedia.org/wiki/Yamaha_YM2413)         | OPL-L         |

Location | PCB<br>Number | Chip | Use |
---------|---------------|------|-----|
68000-10 | ALPHA-68K96II (SS) | [**Motorola 68000 CPU**](https://en.wikipedia.org/wiki/Motorola_68000)   | Main CPU      |
Z80B     | ALPHA-68K96II (SS) | [**Zilog Z80 CPU**](https://en.wikipedia.org/wiki/Zilog_Z80)             | Sound CPU     |
YM2203   | ALPHA-68K96II (SS) | [**Yamaha YM2203**](https://en.wikipedia.org/wiki/Yamaha_YM2203)         | OPN           |
YM2413   | ALPHA-68K96II (SS) | [**Yamaha YM2413**](https://en.wikipedia.org/wiki/Yamaha_YM2413)         | OPL-L         |

### Custom Components

Location | PCB<br>Number | Chip | Use |
---------|---------------|------|-----|
SP85<br><br>ALPHA-8511<br><br>ALPHA-8411 | ALPHA-68K96V (GW)<br><br>ALPHA-68K96II (SS)<br><br>ALPHA-68K96V (SA) | [**SP85N**](https://github.com/va7deo/alpha68k/blob/main/doc/ALPHA-68K96V/ALPHA68K-96V_Schematics.pdf)          | Coin Handling<br><br>Dipswitch Handling<br><br>Screen Inversion Handling |
SNKCLK                           | ALPHA-68K96V (GW)                                                            | [**SNK CLK**](https://github.com/va7deo/alpha68k/blob/main/doc/ALPHA-68K96V/ALPHA68K-96V_Schematics.pdf)        | Counter                                                                  |
INPUT 84                         | ALPHA-68K96II                                                                | [**ALPHA-INPUT 84**](https://github.com/va7deo/alpha68k/blob/main/doc/ALPHA-68K96V/ALPHA68K-96V_Schematics.pdf) | Rotary Handling                                                          |
INPUT 87                         | ALPHA-68K96V (GW)                                                            | [**ALPHA-INPUT 87**](https://github.com/va7deo/alpha68k/blob/main/doc/ALPHA-68K96V/ALPHA68K-96V_Schematics.pdf) | Input Handling                                                           |
ALPHA-8921                       | ALPHA-68K96V (GW)                                                            | [**ALPHA-8921**](https://github.com/va7deo/alpha68k/blob/main/doc/ALPHA-68K96V/ALPHA68K-96V_Schematics.pdf)     | GFX Muxing                                                               |

### SP85 / ALPHA-8511 / ALPHA-8411 Handling

The SP85N or ALPHA-8511/8411 utilized on Alpha Denshi M68000 hardware for I/O handling appears to be closely related to the Motorola M68705p5. Early Alpha Denshi M68000 hardware utilized the M68705 before SNK / Alpha Denshi moved to a custom component. It's possible this is a rebadged custom.<br><br>
There is a known dump for the ALPHA-8511 (possibly a M68705 from a bootleg) used on Super Stingray and a dump of the M68705 used on the Kyros no Yakata bootleg. The program code from the Kyros no Yakata bootleg may match the original ALPHA-8511 program code according to mame documentation.<br><br>
The Sky Adventure bootleg purchased also uses a M68705p5 which is dumpable and will be submitted to mame along with the ROMs. Disassembly of the program code will be done for analysis based on current MCU implementation.<br><br>
[**Readings have been pulled from the Gang Wars SP85N**](https://github.com/va7deo/alpha68k/blob/main/doc/ALPHA-68K96V/Gang%20Wars/SP85N_Readings/SP85N_Gang_Wars_Readings.png) revealed that the MCU pushes 15 interrupts per second, mame's driver for Alpha68k has this coded as 100 or 120 interrupts per second.

# Core Features

### Rotary Joystick Support

- Rotary control is supported via gamepad L and R buttons, or right stick on dual-stick gamepads.

# Support

Please consider showing support for this and future projects via [**Darren's Ko-fi**](https://ko-fi.com/darreno) and [**atrac17's Patreon**](https://www.patreon.com/atrac17). While it isn't necessary, it's greatly appreciated.

# Licensing

Contact the author for special licensing needs. Otherwise follow the GPLv2 license attached.
