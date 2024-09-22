# TSConf for MiST FPGA computer
This is the port of TSConf (advanced ZX Spectrum-compatible platform) to [MiST](https://github.com/mist-devel/mist-board) and [MiST.1010](https://github.com/UzixLS/mist1010-board).

For details, see https://github.com/UzixLS/TSConf_MiST or mirror https://git.err200.net/uzix/TSConf_MiST


## Installation
Place TSConf.ROM, TSConf.R01 and RBF file into root of SD card.

Also you need to place TSConf.VHD file with  Wild Commander and your games and demos. There is example VHD to start with. \
As alternative to VHD you can just unzip Wild Commander into root of your FAT32-formatted SD card.

By default, if everything is done right, Wild Commander will be loaded where you can choose software to start.


## Usage
Original TSConf F12 key (reset) is transferred to F11. \
To enter BASIC press Shift+F11. \
To enter TS-BIOS Setup Utility press Ctrl+F11. By default these setting are volatile and lost after MiST reset. To save them - open OSD menu (with F12 key) and tap "Save NVRAM settings".


## Software
- Wild Commander: https://forum.tslabs.info/viewtopic.php?f=26&t=143
- ZiFi: http://zifi.vtrd.in/
- Demos and games: https://prods.tslabs.info/
