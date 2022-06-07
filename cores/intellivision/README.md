# Intellivision for MiST

Mattel Intellivision, by Grabulosaure and Kitrinx,
ported to MiST and DeMiSTified platforms by Alastair M. Robinson

This core needs a ROM file, called intv.rom, on the root of the SD card.

**The ROM file has the following format:**

Size | Original name  | Content
-----|----------------|--------------------
8Kb  | exec.bin       | System ROM
2kb  | grom.bin       | Character generator ROM
2kb  | sp0256-012.bin | Intellivoice ROM
24kb | ecs.bin        | ECS extension ROM

The intv.rom file can be constructed like so:
```
cp exec.bin boot.rom
cat grom.bin >>boot.rom
cat sp0256-012.bin >>boot.rom
cat ecs.bin >>boot.rom
```

## Source code

The source of the MiST port can be found at: https://github.com/robinsonb5/Intv_DeMiSTified

The source of the original core can be found at: https://github.com/MiSTer-devel/Intv_MiSTer

