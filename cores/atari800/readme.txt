Atari800 core for MiST by Mark Watson

(Website looks to have been removed!)
Original Binaries - http://www.scrameta.net/autobuild/
Source - http://www.scrameta.net/autobuild/
Manual - http://ssh.scrameta.net/Atari%20800%20FPGA%20Manual.pdf
Thread - http://atariage.com/forums/topic/213827-potential-new-hardware/

Quickstart:
- Use the latest firmware.
- Choose your core, VGA for VGA monitor, RGB for 15khz RGB. There is no
  mist menu or mist.ini support.
- Rename atari800_XXX.rbf to core.rbf and put it into your SD cards root.
- Unzip the roms.zip into the root of the SD card so you have a structure
  atari800/rom and atari800/user.
- Make sure atarixl.rom and ataribas.rom are under atari800/rom
  to your SD card.
- Optionally add some atr disk images under atari800/user to your
  SD card.
- Insert SD card, boot MiST.
- Press F11 to insert disk in drive 1 and cold start.
- Press F12 for all options.
- Some games require the Basic ROM to be disabled when running, to do this
  press F8 whilst a game is loading.
- Start a games with F6(Start).

mist button0=F11, mist button0+fire=F12, mist button0+stick=reboot
mist button1=option, mist button1+fire=start, mist button1+stick=select
