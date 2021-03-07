# ZXN - a ZX Next port to MiST
## Usage
To be able to run the core, you'll need a NextOS distribution. You can copy the files from the distribution directly to the SD Card (but this can be risky, as NextOS will have full access to the card, and any bug can destroy its contents), or use a **zxn.vhd** file in the root directory as a disk image.
## Limitations
- 28 MHz CPU mode is not implemented, but remapped to 14 MHz.
- 14 MHz mode is using extra wait states when layer 2 display is in use. This might break things, if they expect a cycle-exact implementation. Also sometimes DMA fails @14MHz.
## Source
The core is using the unmodified sources from https://gitlab.com/SpectrumNext/ZX_Spectrum_Next_FPGA. Only Xilinx specific parts were exhanged by generic ones.