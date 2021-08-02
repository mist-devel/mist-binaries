# Next186 SoC PC

This is a MiST port of the [Next186 SoC](https://opencores.org/projects/next186_soc_pc) by (C) Nicolae Dumitrache.

Modifications from the original core:

- Added a standard MiST BIOS loader, the Next186.ROM will be loaded when the core starts.
- Selectable CPU speed (Maximum, half, third, quarter).
- CPU clock is 50 MHz, SDRAM clock is 100 MHz.
- DSP coprocessor is disabled currently (out of BRAM), MP3 playing is not possible.

# Usage

You'll need an installed MS-DOS on the SD-Card (or on a **Next186.VHD** file),
and the **Next186.ROM** BIOS file next to the **RBF**.

The core requires firmware version at least **210715**.

This core has several compatibility issues (but slowly improving). Here's a spreadsheet with
hint and tips for some titles:
https://docs.google.com/spreadsheets/d/1r07Ubfzquz2FxnKp4GROk8_Kq6kTlVW7YxVTmBDR_c4/edit#gid=0

# Source code

- [Original code on opencores.org](https://opencores.org/projects/next186_soc_pc)
- [MiST port](https://github.com/gyurco/Next186)
