
# Nichibutsu M68000 (Armed F) FPGA Implementation

Based on FPGA compatible core of Nichibutsu M68000 (Terra Force Based) arcade hardware written by [**Darren Olafson**](https://twitter.com/Darren__O).
Original core: https://github.com/va7deo/ArmedF

Port, factoring out PCB code, new SDRAM controller, clocking and other fixes by Slingshot.

The intent is for this core to be a 1:1 implementation of the Nichibutsu (Terra Force based) 68000 hardware.

## Supported Games

| Title | Status | Released | Protection | Unprotected Sets |
|------|---------|----------|------------|------------------|
[**Terra Force**](https://en.wikipedia.org/wiki/Nihon_Bussan)           | Implemented   | **terraf, terrfj, terrafu**         | NB1414M4 | **terrafjb, terrafb**   |
[**Kozure Ōkami**](https://en.wikipedia.org/wiki/Nihon_Bussan)          | Implemented   | **kozure**                          | NB1414M4 | N/A                     |
[**Chouji Meikyuu Legion**](https://en.wikipedia.org/wiki/Nihon_Bussan) | Implemented   | **legion, legionj2**                | NB1414M4 | **legionjb, legionjb2** |
[**Crazy Climber 2**](https://en.wikipedia.org/wiki/Nihon_Bussan)       | Implemented   | **cclimbr2, cclimbr2a**             | NB1414M4 | N/A                     |
[**Armed F**](https://en.wikipedia.org/wiki/Formation_Armed_F)          | Implemented   | **armedf, armedff**                 | None     | N/A                     |
[**Tatakae! Big Fighter**](https://en.wikipedia.org/wiki/Nihon_Bussan)  | Implemented   | **skyrobo, bigfghtr**               | i8751    | N/A                     |

## External Modules

|Name| Purpose | Author |
|----|---------|--------|
| [**fx68k**](https://github.com/ijor/fx68k)                                                    | [**Motorola 68000 CPU**](https://en.wikipedia.org/wiki/Motorola_68000) | Jorge Cwik                    |
| [**t80**](https://opencores.org/projects/t80),[**updates**](https://github.com/mist-devel/T80)| [**Zilog Z80 CPU**](https://en.wikipedia.org/wiki/Zilog_Z80)           | Daniel Wallner and others     |
| [**jtopl2**](https://github.com/jotego/jtopl)                                                 | [**Yamaha OPL 2**](https://en.wikipedia.org/wiki/Yamaha_OPL#OPL2)      | Jose Tejada                   |
| [**jt8751**](https://github.com/jotego/jtframe/blob/master/hdl/cpu/jtframe_8751mcu.v)         | [**Intel 8751**](https://en.wikipedia.org/wiki/Intel_8051)             | Oregano Systems / Jose Tejada |

# Support

Please consider showing support for this and future projects via [**Ko-fi**](https://ko-fi.com/darreno). While it isn't necessary, it's greatly appreciated.

# Licensing

Contact the author for special licensing needs. Otherwise follow the GPLv2 license attached.
