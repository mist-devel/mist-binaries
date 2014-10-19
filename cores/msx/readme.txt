OneChipMSX for MIST
-------------------

This is a port of the OneChipMSX (http://de.wikipedia.org/wiki/1chipMSX) to the
MIST board. This is a work in progress by Alastair Robinson. The source
code is available at https://github.com/robinsonb5/OneChipMSX

Known problems (as of 10/10/14) are e.g. SD card write problems.

Quick start
-----------

A quick start is provided at http://retroramblings.net/?page_id=921

Notes:

The MSXDOS2 by design uses volume IDs in order to identify DOS2 disks
(supported features like undelete and cache). So booting the SD in
MiST the volume ID is missing and the system displays a "*** Wrong
version of MSX-DOS" error each time you are trying to run a program
under MSXDOS2. In order to get rid of this use the command 
  SET EXPERT = ON , 
you can put this command into an AUTOEXEC.BAT file.
