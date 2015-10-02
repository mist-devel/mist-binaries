BBC Micro for MIST
==================

This is a port of Mike Sterlings great [BBC Micro on FPGA](http://www.mike-stirling.com/retro-fpga/bbc-micro-on-an-fpga/) with major changes by Stephen Leary. 

SD card
-------

This core includes os1.2, basic2 and SuperMMC. It implements a
[MMBEEB](http://swhs.home.xs4all.nl/bbc/mmbeeb/) compatible interface
and can use it to load software from SD card. The limitations of the original
mmbeed still apply and e.g. the SD card needs to be DAT16 formatted and the
'beeb.mmb' file needs to be written first to the SD card before anything else.

Sideways ROM/RAM
----------------

A 16k ROM image can be uploaded to Sideways ROM slot 10 using the OSD. 
An OSD option allows to map BASIC and SuperMMC from slots 12 and 14 (hi)
down to slots 0 and 2 (low) giving the uploaded ROM and the RAM banks 
priorty over SuperMMC and BASIC.

Four RAM banks are present in slots 4,5,6 and 7.

Status
------

All major functions work. Joystick support is still missing.
