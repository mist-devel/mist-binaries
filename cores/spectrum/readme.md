ZX Spectrum for MIST
--------------------

This is a port of Mike Stirlings [ZX Spectrum on FPGA" project](http://www.mike-stirling.com/retro-fpga/zx-spectrum-on-an-fpga/).

Usage
-----

See the [wiki page](https://github.com/mist-devel/mist-board/wiki/CoreDocSpectrum) for further details and instructions how to setup the DIVMMC.

History
-------

* [spectrum_151204.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/old/spectrum_151204.rbf)
  - SDRAM timing relaxed
  - Improved memory access interleaving
  - Reset timing adjusted
  - Scanlines effect

* [spectrum_150319_r894.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/old/spectrum_150319_r894.rbf)
  - Video top left pixels fix
  - NMI on F11
  - PAL/TV mode (set by disable_scandoubler in [mist.ini](https://github.com/mist-devel/mist-board/wiki/DocIni))

* [spectrum_150318_r882.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/old/spectrum_150318_r882.rbf)
  - Code cleanup and forced esxdos init at reboot

* [spectrum_150317_r877.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/old/spectrum_150317_r877.rbf)
  - DIVMMC & ESXDOS support

* [spectrum_150312_r822.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/old/spectrum_150312_r822.rbf)
  - Spectrum +2 incl. ZXMMC+

* [spectrum_140812_r306.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/old/spectrum_140812_r306.rbf)
  - Video fix
