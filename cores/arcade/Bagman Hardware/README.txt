Bagman Port to Mist FPGA

- Create ARC and ROM file from the MRA file using the MRA utility.
  Example: mra -A -z /path/to/mame/roms "Bagman.mra"
- Copy the ARC and ROM files to the root of the SD Card
- Copy the RBF file to the SD Card

-------------------------------------------------
Bagman (STERN) FPGA - (darfpga@aol.fr)
-- http://darfpga.blogspot.fr
-------------------------------------------------
-- Bagman releases
--
-- Release 0.0 - 2014 - Dar
--	External sram required
--
--
-- Release 0.1 - 05/06/2018 - Dar
--      DE10_lite board
--	No external sram required
--	435kbits internal ram
--
-------------------------------------------------
Educational use only
Do not redistribute synthetized file with roms
Do not redistribute roms whatever the form
Use at your own risk
--------------------------------------------------------------------
make sure to use bagman.zip roms
-------------------------------------------------------------------------
-- See my previous bagman/ckong release (2014) for some more explanations
-------------------------------------------------------------------------
The original arcade hardware PCB contains 7 memory regions

 cpu addressable space
 
 - program                  rom  24Kx8, cpu only access
 - working ram              ram   2Kx8, cpu only access
 - color/sprite-data        ram   1Kx8, cpu + (2 access / 8 pixels)
 - background buffer        ram   1Kx8, cpu + (1 access / 8 pixels)

 non cpu addressable region   

 - background/sprite graphics      rom 8Kx16, (1 access / 8 pixels) 
 - background/sprite color palette rom 64x8 , (1 access / pixels)
 - sound samples                   rom 8Kx8 , low rate

The pixel clock is 6MHz, the cpu clock is 3MHz.
 
Background color contains 2 high bits of tile code.
Sprite color contains horizontal and vertical invert control  
 
Video frame is 384 pixels x 264 lines.
  
Video display is 256 pixels x 240 lines.
Each lines contains 8 sprites and 32 background tiles. 
Each frames contains 28 background tiles height.

Each tile is 8x8 pixels
Each sprite is 16x16 pixels

Sound is composed of AY-3-8910 music and TMS5110 synthetized speech 
--------------------------------------------------------------------

---------------
VHDL File list 
---------------

bagman_de10_lite.vhd     Top level for de0-nano board

max10_pll_12M.vhd        Pll 12MHz from 50MHz altera mf

bagman.vhd               Main logic

video_gen.vhd            Video scheduler, syncs (h,v and composite)
line_doubler.vhd         Line doubler 15kHz -> 31kHz

bagman_speech.vhd        prom reader for speech synthetizer
lpc10_speech_synthetizer speech synthetizer logic (TMS5110) 

bagman_pal16r6           Random generator

kbd_joystick.vhd         Keyboard key to player/coin input
ram_loader               Load external sram from fpga internal ram

rtl_T80/T80s.vhd         T80 Copyright (c) 2001-2002 Daniel Wallner (jesus@opencores.org)
rtl_T80/T80_Reg.vhd
rtl_T80/T80_Pack.vhd
rtl_T80/T80_MCode.vhd
rtl_T80/T80_ALU.vhd
rtl_T80/T80.vhd

io_ps2_keyboard.vhd      Copyright 2005-2008 by Peter Wendrich (pwsoft@syntiac.com)

ym_2149_linmix.vhd       Copyright (c) MikeJ - Jan 2005

----------------------
Quartus project files
----------------------
de10_lite/bagman_de10_lite.qsf       de10_lite settings (files,pins...) 
de10_lite/bagman_de10_lite.qpf       de10_lite project

-----------------------------
Required ROMs (Not included)
-----------------------------
You need the following 15 ROMs from bagman.zip 
(MAME Bagman - Valadon Automation)

e9_b05.bin  CRC(e0156191) SHA1(bb5f16d49fbe48f3bac118acd1fea51ec4bc5355)
f9_b06.bin  CRC(7b758982) SHA1(c8460023b43fed4aca9c6b987faea334832c5e30)
f9_b07.bin  CRC(302a077b) SHA1(916c4a6ea1e631cc72bdb91ff9d263dcbaf08bb2)
k9_b08.bin  CRC(f04293cb) SHA1(ce6b0ae4088ce28c75d414f506fad2cf2b6920c2)
m9_b09s.bin CRC(68e83e4f) SHA1(9454564885a1003cee7107db18bedb387b85e9ab)
n9_b10.bin  CRC(1d6579f7) SHA1(3ab54329f516156b1c9f68efbe59c95d5240bc8c)

p3.bin      CRC(2a855523) SHA1(91e032233fee397c90b7c1662934aca9e0671482)
r3.bin      CRC(ae6f1019) SHA1(fd711882b670380cb4bd909c840ba06277b8fbe3)

e1_b02.bin  CRC(4a0a6b55) SHA1(955f8bd4bd9b0fc3c6c359c25ba543ba26c04cbd)
c1_b01.bin  CRC(705193b2) SHA1(ca9cfd05f9195c2a38e8854012de51b6ee6bb403)
j1_b04.bin  CRC(c680ef04) SHA1(79406bc786374abfcd9f548268c445b5c8d8858d)
f1_b03s.bin CRC(dba1eda7) SHA1(26d877028b3a31dd671f9e667316c8a14780ca73)

r9_b11.bin  CRC(2e0057ff) SHA1(33e3ffa6418f86864eb81e5e9bda4bf540c143a6)
t9_b12.bin  CRC(b2120edd) SHA1(52b89dbcc749b084331fa82b13d0876e911fce52)

r6.bin      CRC(c58a4f6a) SHA1(35ef244b3e94032df2610aa594ea5670b91e1449) (N.U.)

------
Tools 
------
You need to build vhdl ROM image files from the binary file :
 - Unzip the roms file in the tools/bagman_unzip directory
 - Double click (execute) the script tools/make_bagman_proms.bat to get the following files

bagman_program.vhd
bagman_tile_bit0.vhd
bagman_tile_bit1.vhd
bagman_palette.vhd
bagman_speech1.vhd
bagman_speech2.vhd

*DO NOT REDISTRIBUTE THESE FILES*

The script make_bagman_proms uses make_vhdl_prom and and duplicate_byte executables delivered both in linux and windows version. The script itself is delivered only in windows version (.bat) but should be easily ported to linux.

Source code of make_vhdl_prom.c and and duplicate_byte.c is also delivered.

---------------------------------
Compiling for de10_lite
---------------------------------
You can rebuild the project with ROM image embeded in the sof file. DO NOT REDISTRIBUTE THESE FILES.
4 steps

 - put the VHDL rom files into the project directory
 - rebuild bagman_de10_lite project
 - program bagman_de10_lite.sof into the fpga 

--------------------
Keyboard and swicth
--------------------
Use directional key to move, space to jump, F1/F2 to start player 1/2 and F3 for coins
de10_lite sw0 allow to switch 15kHz/31kHz

------------------------
End of file
------------------------
