## Q*Bert port to MiST

Original by [Pierco](https://github.com/MiSTer-devel/Arcade-QBert_MiSTer).

Fully rewritten using synchronous logic by Gyorgy Szombathelyi.

M6532 (RIOT) from k7800 (c) by Jamie Blanks

i8088 core by Ted Fried, MicroCore Labs

NVRAM for saving high scores and games with background RAM instead of ROM are supported (e.g. Krull).

## Usage

- Create ROM and ARC files from the MRA files using the MRA utility.
  Example: mra -A -z /path/to/mame/roms "Q'bert (US, Set 1).mra"
- Copy the ROM files to the root of the SD Card
- Copy the RBF and ARC files to the same folder on the SD Card
- MRA utility: https://github.com/sebdel/mra-tools-c/

## Issues

- Votrax chip is cruelly missing, QBert needs his @!#?@! voice!!!
