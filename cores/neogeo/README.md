# [SNK Neo Geo](https://en.wikipedia.org/wiki/Neo_Geo_(system)) for [MiST FPGA](https://github.com/mist-devel/mist-board/wiki)

This is the port of the [NeoGeo FPGA implementation](https://github.com/MiSTer-devel/NeoGeo_MiSTer) by [Furrtek](https://www.patreon.com/furrtek/posts)

## Limitations
The original Neo Geo system has big RAM/ROM memories, which don't fit into the BRAM of the MiST's FPGA. A new SDRAM controller was written, which can
read two 32 bit words simultaneously in just 8 cycles using bank interleaving, and running at 96MHz. Both 32MiB and 64MiB equipped MiSTs are supported,
the later obviously can load more games.

The limitation of ROM sizes for both variants:

**32 MiB** - supports  ~6 MiB PROMS and 24 MiB CROM+VROMs (in any size combination)

**64 MiB** - supports ~14 MiB PROMS and 48 MiB CROM+VROMs (in any size combinaion. Note: PROM size is not a real limitiation in this case.)

## Usage

Internal ROMs (System ROM, SFIX, LO ROM and SM1 ROM) can be created from MAME's neogeo.zip with the help of the MRA files.

TerraOnion .NEO file format was choosen as the supported cart format, as it conveniently merges all the various ROMs in one file. The following utilities can be used to create such files:

[Original NeoBuilder tool](https://wiki.terraonion.com/index.php/Neobuilder_Guide)

[MAME to .neo conversion tool](https://github.com/city41/neosdconv)

[Darksoft to .neo conversion tool](https://gitlab.com/loic.petit/darksoft-to-neosd/)

Note: Core doesn't support encrypted ROMs. Make sure the ROM has no encrypted parts before use. MAME ROM pack includes many encrypted ROMs so it's not recommended for inexperienced users. Using the .neo conversion tool with a MAME ROM set will result in some ROMs still being encrypted. There is an alternate .neo conversion tool for the Darksoft ROM set that will give you a fully decrypted set.

## Sidenotes:

The core was inherently unstable. While Furrtek (Sean Gonsalves) did a very good and tedious job reverse-engineering and documenting the original Neo-Geo chipset,
the resulting HDL is not very good for FPGAs. Probably MiSTer's Cyclone V FPGA can deal with it better, as it's built in a newer process, has smaller inner delays, has more clock networks,
or the more recent Quartus tool is better synthesizing such code, but it still broken. Translating old ASIC designs 1-1 into FPGA won't work, as there are dozens of generated signals
(even with combinatorial output) used as clocks, which are glitching, the compiler cannot check if flip-flops clocked by these signals meet setup and hold times, resulting
in very unstable cores.

At the end, the core's HDL was converted into synchronous code, using a simulator to check if it still produces the same signals as before. At the end, all latches were eliminated,
and almost all generated clock usages were removed.

Thanks to all who supported this conversion!

## Source code

The source code can be find at [GitHub](https://github.com/gyurco/NeoGeo_MiSTer/tree/mist).