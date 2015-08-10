ql_XXXXXXX.tbf
--------------

Sinclair QL core for the MIST board.

This core needs a QL rom image on SD card named ql.rom in the SD cards
root directory. It's known to work with Minerva ROM 1.98 as well as the
original js.rom. Other ROMs may work as well. The ROM size must be exaclty
49152 bytes.

It should be possible to add another 16k of extension ROM. The resulting size
of the ROM image should then be 65536 bytes.

This core honours the scandoubler_disable setting in the mist.ini and can
be used with the VGA to SCART cable.

Currently only parts of the keyboard functionality of the IPC is supported.
Many games scanning the keymap won't work. Also no sound is implemented.

Files can be loaded from microdrive images stored in MDV files in QLAY
format. Thee files must be exactly 174930 bytes in size. Examples can
be found in http://web.inter.nl.net/hcc/A.Jaw.Venema/psion.zip
