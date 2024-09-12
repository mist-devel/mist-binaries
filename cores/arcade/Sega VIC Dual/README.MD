# VIC Z80 by Gremlin Industries/Sega Enterprises for [MiSTer](https://github.com/MiSTer-devel/Main_MiSTer/wiki)

An FPGA implementation of Z80-based VIC (Video Interface Chip) era arcade hardware by Gremlin Industries/Sega Enterprises for the MiSTer platform.

This core is a work-in-progress!  Many of the games on this hardware are technically playable but have no sound and are not fully tested. 

## Credits
- [__JimmyStones__](https://github.com/JimmyStones): Core design and implementation
- [__Jotego__](https://github.com/jotego/jt49) AY-3-8910 module
- [__Daniel Wallner__]: T80/T80se - Z80 compatible CPU
- [__Arnim Läuger__](https://github.com/devsaurus/t48): T48 µController core

## FPGA implementation
- Built entirely in simulation using original schematics and supporting information from MAME and other sources.  Logic has been simplified where possible and differences between boards have been ignored where there is no functional impact.
- Analog sound boards are not implemented.  Sampled audio is used to re-create analog audio where possible.

## Games

### Fully working
- Carnival (upright AY8912 music)	(1980)
- Pulsar (1981)

### Complete with issues
- Invinco	(1979) - crashes/hangs after the 1st stage

### Generally playable with no sound
- Alpha Fighter / Head On	
- Borderline (1981)
- Car Hunt / Deep Scan [France] (1979)
- Digger	(1980)
- Frogs	(1978)
- Head On (bootleg alt maze)	(1979)
- Head On 2	(1979)
- Head On (2 players)	(1979)
- Heiankyo Alien	(1979)
- Invinco / Car Hunt [Germany]	(1979)
- Invinco / Deep Scan	(1979)
- Invinco / Head On 2 (set 1)	(1979)
- Missile / Circuit (bootleg of Alpha Fighter / Head On)
- N-Sub (upright)	(1980)
- Samurai [World]	(1980)
- Space Attack / Head On	(1979)
- Space Attack (upright set 1)	(1979)
- Space Trek (upright)	(1980)
- Star Raker	(1981)
- Tranquillizer Gun	(1980)
- Wanted (Sega)	(1982)

### Not working at all
- Safari
- Sub Hunt

## Known issues
- Carnival, Invinco and Pulsar have fully working sound implemented using WAV samples from the MAME project.
- Invinco initally appears fully working but consistently crashes/hangs after completing the 1st stage
- The remaining games should playable except for Safari and Sub Hunt, but none of them have sound.

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
