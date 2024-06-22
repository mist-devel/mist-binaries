# Blockade by Sega/Gremlin Industries for [MiSTer](https://github.com/MiSTer-devel/Main_MiSTer/wiki)

An FPGA implementation of Blockade arcade hardware by Gremlin Industries for the MiSTer platform.

## Credits
- [__JimmyStones__](https://github.com/JimmyStones): Core design and implementation
- [__Vslav__](https://github.com/1801BM1): [vm80a](https://github.com/1801BM1/vm80a) CPU (8080A implementation reverse engineered from a Soviet replica!)
- [__Jotego__](https://github.com/jotego): [jtframe_resync](https://github.com/jotego/jtframe/blob/master/hdl/video/jtframe_resync.v) for analog video H/V re-positioning
- __Soltan_G42__: 1st order low-pass filter for audio circuit - thanks also to __Ace__ for explanations on how to use and tune the filter
- __Ethan__ of [The History of How We Play](https://thehistoryofhowweplay.wordpress.com): Editing and expansion of history

## FPGA implementation
- Built entirely in simulation using original schematics and information from MAME, logic has been simplified where possible
- Supports all Gremlin produced games which use the Blockade 8080A-based hardware
- Monochrome video output with selectable colour overlay (Green,White,Yellow,Red)

## Supported games
- Blockade (1976)
- CoMotion (1977)
- Hustle (1977)
- Blasto (1978)

## History of Blockade
Blockade was created by Lane Hauck in 1976 as a project to get the Gremlin management interested in producing video games.
Initially the game concept began as an expression of the “random walk” in physics, using a 2D plane with tiles to represent spaces where the cursor had been. He developed this into a game which proved popular enough to develop into a full product to be launched at the end of 1976.
The analog circuits used to generate the explosion sound effects were designed by Bob Pecoraro. Additional programming was done by George Kiss. Lonnie Pogue designed the cabinet for the game while Verl “Ole” Olson designed the four player cabinet.
The game was shown at the 1976 AMOA expo from November 12th-14th, along with a 4-player version called CoMotion. It received accolades from the coin-op trade press and was quickly copied by competitors.

Blockade is effectively the original 'light-cycles' game, but unfortunately due to Gremlin's inexperience in producing arcade cabinets they were outpaced by a number of clones, including Ramtek's Barricade, Midway's Checkmate, and Atari's Dominos.
This led to many circuit boards being unsold and so further games were produced using the surplus Blockade hardware, with minor changes including larger ROMs and more RAM.

Hustle was released in May 1977 and was the origin  of the 'Snake' genre which later became popular as a casual game on low end computers, web-based Flash applications, and mobile phones.  1 or 2 players compete to collect points while avoiding their ever growing tail and that of their opponent.

Blasto (conceived by Hauck and programmed by Bill Blewett) was released in July 1978, and is a 1 or 2 player shooter where players maneuver around a destructible maze and destroy mines, while avoiding the explosions and chain reactions that occur.

Sources:
- Ethan of [History of How We Play](https://thehistoryofhowweplay.wordpress.com)
- http://allincolorforaquarter.blogspot.com/2015/09/the-ultimate-so-far-history-of-gremlin_25.html

## Known issues
- Square-wave sound circuit is probably not producing the correct frequency (hard to verify without access to a good recording of original machine)
- Boom sound circuit is not implemented, so it uses a sample (from https://samples.mameworld.info/)
- Coin circuit timing is suspect, but it works!
- Free game on Hustle cannot be disabled in DIPs (due to limitation of MiSTer DIPs support)

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
