# Nichibutsu M68000 (Terra Cresta) FPGA Implementation

Based on FPGA compatible core of Nichibutsu M68000 (Terra Cresta based) arcade hardware written by [**Darren Olafson**](https://twitter.com/Darren__O).
Original core: https://github.com/va7deo/TerraCresta

Port, factoring out PCB code, SDRAM controller, flip support, clocking and other fixes by Slingshot.

The intent is for this core to be a 1:1 implementation of the Nichibutsu (Terra Cresta based) 68000 hardware.

## Supported Games

| Title | Status | Released | Protection | Protected Sets |
|------|---------|----------|------------|----------------|
[**Terra Cresta**](https://en.wikipedia.org/wiki/Terra_Cresta)                | Implemented | **Y** | None     | N/A                    |
[**Sei Senshi Amatelass**](https://en.wikipedia.org/wiki/Nihon_Bussan)        | Implemented | **Y** | NB1412M2 | **amatelass, amazon**  |
[**Kid no Hore Hore Daisakusen**](https://en.wikipedia.org/wiki/Nihon_Bussan) | Implemented | **Y** | NB1412M2 | **horekid**            |

## External Modules

|Name| Purpose | Author |
|----|---------|--------|
| [**fx68k**](https://github.com/ijor/fx68k)    | [**Motorola 68000 CPU**](https://en.wikipedia.org/wiki/Motorola_68000) | Jorge Cwik     |
| [**t80**](https://opencores.org/projects/t80) | [**Zilog Z80 CPU**](https://en.wikipedia.org/wiki/Zilog_Z80)           | Daniel Wallner |
| [**jtopl**](https://github.com/jotego/jtopl)  | [**Yamaha OPL**](https://en.wikipedia.org/wiki/Yamaha_OPL#OPL)         | Jose Tejada    |

# Support

Please consider showing support for this and future projects via [**Ko-fi**](https://ko-fi.com/darreno). While it isn't necessary, it's greatly appreciated.

# Licensing

Contact the author for special licensing needs. Otherwise follow the GPLv2 license attached.
