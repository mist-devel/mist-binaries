OneChipMSX for MIST
===================

This is a port of the [OneChipMSX](http://de.wikipedia.org/wiki/1chipMSX) to the
MIST board. This is a work in progress by Alastair Robinson. The source
code is available from [Alastairs github repository](https://github.com/robinsonb5/OneChipMSX).

Quick start
-----------

A quick start is provided at [RetroRamblings](http://retroramblings.net/?page_id=921).

Notes
-----

The MSXDOS2 by design uses volume IDs in order to identify DOS2 disks
(supported features like undelete and cache). So booting the SD in
MiST the volume ID is missing and the system displays a ```"*** Wrong
version of MSX-DOS"``` error each time you are trying to run a program
under MSXDOS2. In order to get rid of this use the command 
```
   SET EXPERT = ON , 
```
you can put this command into an ```AUTOEXEC.BAT``` file.

History
-------

* [ocmsx_161226.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/msx/ocmsx_161226.rbf)
  - AMR fixed the timing of SDRAM controller for newer RAM chips used on 2016er MISTs

* [ocmsx_141022_r364.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/msx/old/ocmsx_141022_r364.rbf)

* [ocmsx_141012_r359.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/msx/old/ocmsx_141012_r359.rbf)

* [ocmsx_141010_r356.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/msx/old/ocmsx_141010_r356.rbf)
