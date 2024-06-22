# Irem M92 Core

![](docs/header-small.png)

This is the port of the [MiSTer FPGA core for the Irem M92 arcade system](https://github.com/MiSTer-devel/Arcade-IremM92_MiSTer) (http://www.system16.com/hardware.php?id=747). The Irem M92 system is known for its high-quality graphics and sound, and this core brings these games to FPGA platforms for arcade enthusiasts to enjoy.

New SDRAM controller, optimizations to fit into the MiST FPGA by Gyorgy Szombathelyi. Original core by [Martin Donlon](https://github.com/wickerwaka).

The Irem M92 core includes numerous games that have not been ported elsewhere, providing a unique and authentic arcade experience. Some of the popular games available in this core are:

- In the Hunt
- Gunforce
- R-Type Leo
- Hook
- Blade Master
- Mystic Riders
- Undercover Cops
- Ninja Baseball Batman

## Controls
All of the games use standard 8-way input with two buttons with the exception of *Superior Soldiers* which uses six button input. Several of the games support 3 or 4 players but you will need to change a DIP switch in the DIP switch menu to enable that. By default the button buttons are mapped to the MiSTers SNES-like layout as `B,A,X,Y,L,R`. The `Coin` and `Start` buttons are mapped to Select and Start. There are two additional buttons that can be mapped that are not mapped by default. `P2 Start` maps the the second players start button. The only purpose this serves is for accessing the service menu with a single controller since most games require pressing P1 and P2 start to access it. The second unmapped button is `Pause` which pauses the core.

Standard MAME keyboard controls are also supported for up to 4-players.


## Thanks
Many people, knowingly or not, contributed to this work.
- Mark, for his R-Type Leo PCB and his support through the years.
- @sorgelig, for developing and maintaining MiSTer.
- @RobertPeip, for the v30mz cpu I am using as the basis for the v33 & v35.
- @jotego, for the YM2151 implementation and analog adjustment module.
- @ArtemioUrbina, for their support building [MDfourier](https://junkerhq.net/MDFourier/) tests.
- @zakk4223, for hiscore support.
- @birdybro, @Toryalai1 & @wwark for MRA help.
- Sanborn, for help with the docs.
- The people from PLD Archive collecting and archiving PAL information https://wiki.pldarchive.co.uk/index.php?title=Category:Irem_M92
- The MiSTer FPGA discord server for support, advice and testing.


