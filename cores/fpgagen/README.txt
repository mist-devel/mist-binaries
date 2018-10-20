This is a port of fpgagen - Genesis/Megadrive core. Original project 

Robinsonb5 on forum http://www.atari-forum.com/viewtopic.php?f=115&t=31029&start=175#p343793 
has done additional porting work for the MiST.

Some usage tips:

1. The core rquires at least firmware version 20181013.
2. Rom file formats supported are .bin and .gen, no support for .smd files
3. If the controls seems to not work, try switch to 3 buttons mode in the OSD

The fpgagen-beta_20180910_tg68k+ypbpr.rbf core replaces the very old
tg68 CPU core with the latest version of the tg68k. This should have
no functional changes. But it might be worthwile to check both versions
in case of compatibility issues.

Furthermore that version adds support for YPbPr cables (see https://github.com/mist-devel/mist-board/wiki/YPbPr_Cable).

Newer versions are using the standard MiST OSD and ROM loader.

==== Installing the core ====

Copy the following files to the root of your sdcard:
- Copy the latest rbf file (i.e. fpgagen-beta_20180930.rbf) and rename it core.rbf
- Copy mist.ini - This remaps the controller buttons to Buffalo SNES, and you can customise
it to your controller.
- Copy your .bin games to the sdcard.
