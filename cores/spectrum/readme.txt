ZX Spectrum for MIST
--------------------

This is a port of Mike Stirlings "ZX Spectrum on FPGA" project 
http://www.mike-stirling.com/retro-fpga/zx-spectrum-on-an-fpga/

Usage
-----

The core implements a tape drive for mass storage using the csw1 
format. The MISTs on screen display opened with the F12 key can be 
used to start the replay of the tape image in this format from the
SD card.

The MIST svn contains a tool that allows to convert from the more
popular tzx file format to the csw1 format required by the MIST:
https://code.google.com/p/mist-board/source/browse/#svn/trunk/tools/tzx2wav

The command for this is:
tzx2wav <file>.tzx -c1 <file>.csw

In order to load a image select "Tape Loader" from the spectrum main menu
and then open the OSD and select the file to load from the OSD as
shown in this video:
   https://www.youtube.com/watch?v=GHe0ySUqkoA
