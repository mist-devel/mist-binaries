This is a port of fpgagen - Genesis/Megadrive core. Original project 

Robinsonb5 on forum http://www.atari-forum.com/viewtopic.php?f=115&t=31029&start=175#p343793 
has done additional porting work for the MiST.

The core shall be considered a work in progress as there are multiple issues:
1. Sprite flickering on heavy scenes, or on large sprites
2. No LFO modulation of the FM sound and other FM sound issues
3. Rom file formats supported are .bin and .gen, no support for .smd files

==== Installing the core ====
This core does not support the MiST menu, i.e. F12 key.

Copy the following files to the root of your sdcard:
- Copy the latest rbf file (i.e. fpgagen-beta_20180420.rbf) and rename it core.rbf
- Copy Config_VGA/FPGAGEN.CFG, or Config_TV/FPGAGEN.CFG (for 15 kHz video) to FPGAGEN.CFG
- Copy mist.ini - This remaps the controller buttons to Buffalo SNES, and you can customise
it to your controller.
- Copy your .bin games to the sdcard.
