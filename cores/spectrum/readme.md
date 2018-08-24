ZX Spectrum for MIST
--------------------

This is a port of [Goran Devic's Sinclair ZX Spectrum on the A-Z80](http://www.devic.us/hacks/sinclair-zx-spectrum-z80/). The port has been done by [sorgelig](https://github.com/sorgelig). The CPU is also available via [opencores](http://opencores.org/project,a-z80). The full source code is available from [sorgelig's github repository](https://github.com/sorgelig/ZX_Spectrum-128K_MIST).

Previous versions were based on Mike Stirlings [ZX Spectrum on FPGA" project](http://www.mike-stirling.com/retro-fpga/zx-spectrum-on-an-fpga/).

Usage
-----

See the [wiki page](https://github.com/mist-devel/mist-board/wiki/CoreDocSpectrum) for further details and instructions how to setup the DIVMMC. 

History
-------

* [spectrum_20180804.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/spectrum_20180804.rbf)
  - Many fixes and enhancements.

* [spectrum_160514.rbf] (https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/old/spectrum_160514.rbf)
  - Various fixes and better timings for 128K and 48K modes.

* [spectrum_151230.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/old/spectrum_151230.rbf)
  - Option to autoload ESXDOS at boot time

* [spectrum_151228.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/spectrum/old/spectrum_151228.rbf)
  - Whole new port by [sorgelig](https://github.com/sorgelig)
  - Based on [Goran Devic's Sinclair ZX Spectrum on the A-Z80](http://www.devic.us/hacks/sinclair-zx-spectrum-z80/)

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
