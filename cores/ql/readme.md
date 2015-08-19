Sinclair QL core for the MIST board
===================================

This core needs a QL rom image on SD card named ql.rom in the SD cards
root directory. It's known to work with Minerva ROM 1.98 as well as the
original js.rom. Other ROMs may work as well. The ROM size must be exaclty
49152 bytes. Minerva and other roms are available as a free download from 
http://www.dilwyn.me.uk/qlrom/.

It is possible to add another 16k of extension ROM. The resulting size
of the ROM image should then be 65536 bytes. E.g. the Toolkit-2 ROM is
available for download at http://www.dilwyn.me.uk/pe. The necessary
combination of both ready-to-use is available 
[here](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/ql.rom).

This core honours the scandoubler_disable setting in the mist.ini and can
be used with the VGA to SCART cable.

The latest version implement the complete 8049 IPC controller and thus
fully support all keybaord monitoring modes as well as joysticks and
audio.

Files can be loaded from microdrive images stored in MDV files in QLAY
format. Thee files must be exactly 174930 bytes in size. Examples can
be found in http://web.inter.nl.net/hcc/A.Jaw.Venema/psion.zip as well as
in the [examples](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/examples) directory.

History
-------

* [ql_150819.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/ql_150819.rbf)
  - Fixed rtc speed
  - MDV tape direction configurable
  - QIMI compatible mouse

* [ql_150818.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/old/ql_150818.rbf)
  - Key mapping fixed
  - Joysticks connected
  - IPC IPL connected
  - PC keyboard shortcuts

* [ql_150817.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/old/ql_150817.rbf)
  - T48 core used to implement the IPC using the original firmware
  - Full IPC compatibility incl. audio

* [ql_150813.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/old/ql_150813.rbf)
  - Microdrive performance boost by playback of microdrive sectors in decending order
  - Code cleanup

* [ql_150811.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/old/ql_150811.rbf)
  - Adjusted pixel clock to 10.5Mhz
  - Fixed NTSC/Microdrive collision
  - Slower CPU (still too fast)
  - Microdrive selection fix
  - Code cleanup

* [ql_150810.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/old/ql_150810.rbf) Initial version
