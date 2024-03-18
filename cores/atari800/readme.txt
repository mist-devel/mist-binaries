Atari800 core for MiST by Mark Watson

Original Binaries - http://www.64kib.com/autobuild/
Source - http://www.64kib.com/atarixlfpga_svn/trunk/atari_800xl/
         https://github.com/gyurco/Atari800XL
Manual - http://www.64kib.com/Atari%20800%20FPGA%20Manual.pdf
Thread - http://atariage.com/forums/topic/213827-potential-new-hardware/

Binaries here are using the standard MiST settings and OSD.

Quickstart:
- Copy A800XL.ROM and the .rbf file to the same directory on your SD Card.
- Alternative BASIC and OS ROMs can be loaded via the first Load ROM option in the OSD.
- Create a directory A800XL on your SD Card and put your disks or game rom images in there.
- Select a disk/rom from the OSD and then press F10, or "Cold Reset" from the OSD.
- Keyboard shortcuts:
  F6 - Start
  F7 - Select
  F8 - Option
  F9 - Reset
  F10 - Cold reset
- Some games require the Basic ROM to be disabled when running, to do this
  press F8 while reset.
- Start games with F6(Start).

32KB ROM files (like A800XL.ROM) consist of:
2 x BASIC (8K) + OS (16K)