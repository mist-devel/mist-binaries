Sinclair QL core for the MIST board
===================================

This core needs a QL rom image on the SD card named ql.rom. The included ql.rom should work OK and includes the Toolkit-2 extension which is required for most software. The Toolkit 2 also has much improved file commands.

In the OSD settings increase the memory to 640k from the default 128k. In most cases using 640k will always work fine.

Files can be loaded from microdrive images stored in MDV files in QLAY format (vDrive & mdump MDVs are not compatible). They are mounted read-only. The files must be exactly 174930 bytes in size. The MDVTOOL in the tools directory can manipulate the MDV files. There are some samples in the Games directory. NOTE: All software in the Games directory and QL-SD.zip is freeware or public domain. A collection is available on archive.org.

The MDUMP2QLAY program in tools will convert MDUMP (version 1 & 2) image files to QLAY suitable for the QL core.

Microdrives will self boot if you select an MDV and reset. This will look for a file called BOOT on the microdrive and run it. You can also start a program on an MDV be typing 'lrun mdv1_boot'.

There's a big collection of QL programs and related material at http://www.dilwyn.me.uk

Be careful when copying files from a PC to the QL, there's metadata in the QL file that gets stripped when extracting ZIP files on the PC. You should unzip the ZIP files on the QL. 

## Commands to get started
 
There's a comprehensive [User Manual](https://archive.org/details/sinclair-ql-user-guide) that came with the QL that is worth reading. [Toolkit-2](http://www.dilwyn.me.uk/pe/TK2.pdf) contains the important commands to manipulate files and drives.

After starting the computer, select a microdrive MDV in the OSD:

`dir mdv1_`

`lrun mdv1_file` (run a basic program)

`view mdv1_file` (view a file)

`load mdv1_file` (loads the basic file)

`list` (list the basic file)

`ed` (Edits the basic file, ESC to quit)

Pressing `<ALT><ENTER>` will bring back the last command on the command line.

You can change the default directory using the `data_use` command, which is like DOS cd command. So setting `data_use win1_` means you can just enter `dir`. Directories are supported on the QL, use `make_dir`. Other directory commands to use `ddown, dup`.

You can also load to the second microdrive by select OSD > "Load MDV2". Then access the drive using `mdv2_`.

## QL-SD

QL-SD can be viewed as a hard drive for the QL. If you have a QL-SD file called QXL.WIN (and the relevant .rom file) in the root directory of the SD card this will be mounted at boot. The drive is called `win1_` and you can manipulate files just the same as on the `mdv1_` drive.

The sample QL-SD QXL.WIN and relevant ROM ql_sd.rom files should be in the root of the SD card. To use this QL-SD select the ROM file in the OSD "Load *.ROM". This contains a number of games and the Psion applications and also has unzip. Format an SD card and extract this ZIP file first and then copy other files to the SD card, this is to stop and fragmentation which QL-SD cannot cope with. It will be mounted read/write in the QL core.

NOTE: The QL-SD ql_sd.rom file is not compatible with all software running from MDV1 so it is not the default ROM file.

To run the Quill application on this QL-SD use the command `lrun win1_a_quill_boot`. The `_` is like `\` in DOS.

If you want to manipulate the QL-SD file on an emulator, SMSQmulator is recommended. Just mount the QXL.WIN file in the emulator and mount a NFA directory so you can copy files onto the QXL.WIN files using the NFA directory, e.g. `copy nfa1_file to win1_file`. You can also use the Java program [QxlWinReader](http://www.wlenerz.com/qlstuff/#qxlwinr) but this appears to have problems with executables, it works fine with basic and text files.

To run the unzip program on this QL-SD drive:

`make_dir win1_tempdir`

`data_use win1_tempdir`

`ex unzip;"file.zip"`

The files will have been extracted into the win1_tempdir directory.

History
-------
* ql_210703.rbf
  - Switchable speed to get closer to original QL speed (now about 2-3x).
  - BUS improvements to attempt reduction in bus access speed including use of clkena_in to replicate DTACK waits.
  - Updated TG68K to latest version.
  - Reworked IPC communication logic in ZX8302 and added a COMDATA latch.
  - IPC code uses Hermes, fixes missing key-presses.
  - Eliminate most async clocks, better reliability?
  - Removed MDV reverse optionas this is unecessary, use "mdvtool file.mdv write file_new.mdv" to fix incorrect sector order of an MDV file.

* ql_210627.rbf
  - Second microdrive support added. Games that require MDV2_ support, like "QL Pawn", are now supported.
  - Selectable ROM added
  - Games/Software moved to "QL Software Collection" on archive.org

* [ql_150820.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/old/ql_150820.rbf)
  - QL-SD support

* [ql_150819.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/old/ql_150819.rbf)
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
