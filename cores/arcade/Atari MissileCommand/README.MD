# Missile Command by Atari for [MiSTer](https://github.com/MiSTer-devel/Main_MiSTer/wiki)

An FPGA implementation of the __Missile Command__ arcade hardware by __Atari__ for the MiSTer platform.

## Credits, acknowledgements, and thanks
- [__JimmyStones__](https://github.com/JimmyStones): Core design and implementation
- [__JaguarLV__](https://github.com/JaguarLV): Collaboration and code sharing when we were both stuck trying to get this core working!
- [__Andy McFadden__](https://6502disassembly.com/va-missile-command/): Missile Command disassembly project
- [__Jotego__](https://github.com/jotego): [jtframe_resync](https://github.com/jotego/jtframe/blob/master/hdl/video/jtframe_resync.v) for analog video H/V re-positioning
- [__Bird Computer__](https://github.com/robfinch/Cores/blob/master/bc6502/bc6502.v): 6502 CPU in Verilog
- [__MiSTer Walrus__](https://twitter.com/WalrusFPGA) and [__ThePulseRifle__](https://twitter.com/thepulserifle): Alpha testing action

## FPGA implementation
- Created using original schematics, information from the MAME project, and insight from the excellent disassembly by Andy McFadden (https://6502disassembly.com/va-missile-command/).
- Logic has been simplified, and re-engineered where necessary to interact reliably with FPGA block RAM.

## Controls
This core supports multiple control methods:
### Mouse/Trackball
- Use a combination of the 'Mouse/Trackball Speed' OSD option and the 'Trackball Speed' DIP switch to achieve a comfortable speed for your device
- Use the 'Button order' OSD option to change the layout of the mouse/trackball buttons to suit your device'
### Digital joypad/stick
- Set the 'Joystick mode' OSD option to Digital to use a pad or digital stick
- Use the 'Joystick speed' OSD option to achieve a comfortable speed for your device
### Analog stick
- Set 'Joystick mode' OSD option to Analog to use an analog stick
- Use the 'Joystick speed' OSD option to achieve a comfortable speed for your device


## Hiscore save/load
To save your hiscores manually, press the 'Save Settings' option in the OSD.  Hiscores will be automatically loaded when the core is started.

To enable automatic saving of hiscores, turn on the 'Autosave Hiscores' option and press the 'Save Settings' option in the OSD.  Hiscores will then be automatically saved (if they have changed) any time the OSD is opened.

Hiscore data is stored in /media/fat/config/nvram/ as ```<mra filename>.nvm```

## Known issues
- Cocktail mode is not currently supported

## Installation
Place `*.rbf` into the "_Arcade/cores" folder on your SD card.  Then, place `*.mra` into the "_Arcade" folder and ROM files from MAME into "games/mame".

### ****ATTENTION****
ROMs are not included. In order to use this arcade core, you must provide the correct ROMs.

To simplify the process, .mra files are provided in the releases folder that specify the required ROMs along with their checksums.  The ROM's .zip filename refers to the corresponding file in the M.A.M.E. project.

Please refer to https://github.com/MiSTer-devel/Main_MiSTer/wiki/Arcade-Roms-and-MRA-files for information on how to setup and use the environment.

Quick reference for folders and file placement:

/_Arcade/<game name>.mra
/_Arcade/cores/<game rbf>.rbf
/games/mame/<mame rom>.zip
/games/hbmame/<hbmame rom>.zip
