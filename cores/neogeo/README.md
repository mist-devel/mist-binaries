# [SNK Neo Geo](https://en.wikipedia.org/wiki/Neo_Geo_(system)) for [MiST FPGA](https://github.com/mist-devel/mist-board/wiki)

This is the port of the [NeoGeo FPGA implementation](https://github.com/MiSTer-devel/NeoGeo_MiSTer) by [Furrtek](https://www.patreon.com/furrtek/posts)

## Limitations
The original Neo Geo system has big RAM/ROM memories, which don't fit into the BRAM of the MiST's FPGA. A new SDRAM controller was written, which can
read one 64 bit and one 32 bit word simultaneously in just 12 cycles using bank interleaving, and running at 120MHz. Later on, it was replaced by
a 96MHz variant reading two 32 bit words in 8 cycles. Both 32MiB and 64MiB equipped MiSTs are supported, the later obviously can load more games.

The limitation of ROM sizes for both variants:

**32 MiB** - supports  ~6 MiB PROMS and 24 MiB CROM+VROMs (in any size combination)

**64 MiB** - supports ~14 MiB PROMS and 48 MiB CROM+VROMs (in any size combination. Note: PROM size is not a real limitiation in this case.)

## Usage

Internal ROMs (System ROM, SFIX, LO ROM and SM1 ROM) can be created from MAME's neogeo.zip with the help of the [MRA files](https://github.com/mist-devel/mist-board/wiki/CoreDocArcade#mra-and-arc-files).

TerraOnion .NEO file format was choosen as the supported cart format, as it conveniently merges all the various ROMs in one file. The following utilities can be used to create such files:

[Original NeoBuilder tool](https://wiki.terraonion.com/index.php/Neobuilder_Guide)

[MAME to .neo conversion tool](https://github.com/city41/neosdconv)

[Darksoft to .neo conversion tool](https://gitlab.com/loic.petit/darksoft-to-neosd/)

Note: Core doesn't support encrypted ROMs. Make sure the ROM has no encrypted parts before use. MAME ROM pack includes many encrypted ROMs so it's not recommended for inexperienced users. Using the .neo conversion tool with a MAME ROM set will result in some ROMs still being encrypted. There is an alternate .neo conversion tool for the Darksoft ROM set that will give you a fully decrypted set.

## Controls

| NeoGeo | MiST    |
|--------|---------|
| A      | A       |
| B      | B       |
| C      | X       |
| D      | Y       |
| Start  | Start   |
| Select | Select  |
| Coin1  | L       |
| Coin2  | R       |

Mouse (trackball) support for the game Irritating Maze can be selected in the OSD. Middle mouse button is Start. **Note:** this game requires its own system BIOS.

## Memory Card

A 8K (8192 bytes) empty file can be used as a memory card. It can be loaded-unloaded and saved via the OSD (use a .SAV extension). Hint: rename it to **NeoGeo.vhd** and it'll be auto-mounted. One memory card
can store progress and high score information for a couple of games.

## CD support

From the core version **230705**, Neo Geo CD is supported (thanks to the work of paulb-nl). It needs at least firmware version **230705**. The CD file format must be CUE + a single binary.
Also it needs a CD BIOS, too (Hint: use [ARC files](https://github.com/mist-devel/mist-board/wiki/ARC-Files) to load it automatically). Universe BIOS 3.3 (CD version) is recommended, as it handles both the top-loader and CDZ variants.

To convert CHD files to the required format, MAME's **chdman** utility can be handy:

```
chdman extractcd -i input.chd -o output.cue -ob output.img
```

## Sidenotes:

The core was inherently unstable. While Furrtek (Sean Gonsalves) did a very good and tedious job reverse-engineering and documenting the original Neo-Geo chipset,
the resulting HDL is not very good for FPGAs. Probably MiSTer's Cyclone V FPGA can deal with it better, as it's built in a newer process, has smaller inner delays, has more clock networks,
or the more recent Quartus tool is better synthesizing such code, but it still broken. Translating old ASIC designs 1-1 into FPGA won't work, as there are dozens of generated signals
(even with combinatorial output) used as clocks, which are glitching, the compiler cannot check if flip-flops clocked by these signals meet setup and hold times, resulting
in very unstable cores.

At the end, the core's HDL was converted into synchronous code, using a simulator to check if it still produces the same signals as before. Finally all latches were eliminated,
and all generated clock usages were removed.

Thanks to all who supported this conversion!

## Source code

The source code can be find at [GitHub](https://github.com/gyurco/NeoGeo_FPGA/tree/mist/mist).
