# Williams rev.2 hardware games by darfpga

Supported games: Turkey Shoot, Joust 2, Inferno, Mystic Marathon

After loading the RBF (Core), a CMOS clearing happens. When the message 
"Factory Settings Restored" appears, press the MiST soft RESET button (right).

Later on you can save the CMOS RAM using the "Save NVRAM" OSD option.

## Usage

- Create ROM and ARC files from MAME ROM zip files using the mra utility and the MRA files.
- Example: mra -A -z /path/to/mame/roms Inferno.mra
- Copy the RBF and the ARC files to the same folder.
- Copy the ROM files to the root of the SD Card.

- MRA utilty: https://github.com/sebdel/mra-tools-c

## Controls

### Turkey Shoot

| Function        | Button   |
| --------------- | -------- |
| Aim             | Mouse    |
| Fire            | Button A |
| Grenade         | Button B |
| Gobble          | Button C |

### Joust2

| Function        | Button   |
| --------------- | -------- |
| Flap            | Button A |
| Transform/start | Button B |
| Left            | Left     |
| Right           | Right    |

### Inferno

| Function        | Button     |
| --------------- | ---------- |
| Move            | Left/Right/Down/Up |
| Aim             | Left/Right/Down/Up on Right Stick (dual stick gamepad only) OR |
|                 | Button C/D/E/B |
| Shoot           | Button A       |

### Mystic Marathon

| Function        | Button   |
| --------------- | -------- |
| Jump            | Button A |
| Left            | Left     |
| Right           | Right    |
