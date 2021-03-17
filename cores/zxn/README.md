# ZXN - a ZX Next port to MiST
## Usage
To be able to run the core, you'll need a NextOS distribution. You can copy the files from the distribution directly to the SD Card (but this can be risky, as NextOS will have full access to the card, and any bug can destroy its contents), or use a **zxn.vhd** file in the root directory as a disk image.
## Limitations
- 14 MHz mode is using extra wait states when layer 2 display is in use. 28 MHz mode always inserts extra wait states. This might break things, if they expect a cycle-exact implementation.
## Source
The core is based on the sources from https://gitlab.com/SpectrumNext/ZX_Spectrum_Next_FPGA. Modifications needed are uploaded to https://gitlab.com/gyurco/ZX_Spectrum_Next_FPGA/-/tree/altera_sdram_changes.
