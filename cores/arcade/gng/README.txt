JT_GNG FPGA Clone of Ghosts'n Goblins by Jose Tejada (@topapate)
================================================================

Please support this work: http://patreon.com/topapate

Yes, you always wanted to have a Ghosts'n Goblins arcade board at home. First you couldn't get it because your parents somehow did not understand you. Then you grow up and your wife doesn't understand you either. Don't worry, MiST is here to the rescue.

What you get with this is an extremely accurate (allegedly 100% accurate) clone of the original hardware. You will notice differences from MAME if you compare. Try resetting it and compare those screens for a start! Original hardware handled sound and graphics in a different way from the emulator. There were delays in CPU bus access and other details that will make the experience different from an emulator. Of course, no pause. Just like the real thing!

I hope you will have as much fun with it as I had it while making it!

ROM Generation
==============

unzip your rom files and use Python to execute the file gngrom.py from a command line. Then copy the .rom file to the SD card with the name JTGNG.rom.

You need to use the name of game version to make the conversion. If no name is provided, the Taito version (gngt.zip) will be converted. Note that the names are taken from the .zip file names but the .zip files must be unzipped. Depending on your MAME set, you may have to uncompress all game versions in order to get all the relevant files as some MAME sets have files spread across related zip files.

For some reason -probably related to DIP settings- if you play the Japanese version (makaimur) you will never die. I have left it that way so you can play the whole game (not as fun).

SD Card
=======

For MiST copy the file core.rbf to the SD card at the root directory. Copy also the rom you have generated with the name JTGNG.rom. It will get loaded at start.

Extras
======

You can press F12 to bring the OSD menu up. You can turn off music, or sound effects with it. By default, a screen filter makes the screen look closer to an old tube monitor. If you turn it off you will get sharp pixels. Note that if you switch from sharp to soft pixels you will need a couple of seconds to get your eyes used as the brain initially perceives this as an out of focus image compared to the old one.

Credits
=======

Jose Tejada Gomez. Twitter @topapate
Project is hosted in http://www.github.com/jotego/jt_gng
License: GPL3, you are obligued to publish your code if you use mine

Special thanks to Greg Miller and Alexey Melnikov

You can support my work at:
http://patreon.com/topapate
https://paypal.me/topapate