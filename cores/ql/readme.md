Sinclair QL core for the MIST board
===================================

This core needs a QL rom image on the SD card named ql.rom. The included ql.rom should work OK and includes the Toolkit-2 extension which is required for most software. The Toolkit 2 also has much improved file commands.

In the OSD settings increase the memory to 640k from the default 128k. In most cases using 640k will always work fine.

Files can be loaded from microdrive images stored in MDV files in QLAY format (vDrive MDVs are not compatible). The files must be exactly 174930 bytes in size. The MDVTOOL in the tools directory can manipulate the MDV files. There are some samples in the examples directory. 

Microdrives will self boot if you select an MDV and reset. This will look for a file called BOOT on the microdrive and run it. You can also start a program on an MDV be typing 'lrun mdv1_boot'.

There's a big collection of QL programs and related material at http://www.dilwyn.me.uk

Be careful when copying files from a PC to the QL, there's a header in the QL file that gets stripped when extracting ZIP files on the PC. You should unzip the ZIP files on the QL. 

## Commands to get started
 
There's a comprehensive [User Manual](https://archive.org/download/sinclair-ql-user-guide/Sinclair%20QL%20User%20Guide.pdf) that came with the QL that is worth reading. [Toolkit-2](http://www.dilwyn.me.uk/pe/TK2.pdf) contains the important command to manipulate files and drives.

After starting the computer, select a microdrive MDV in the OSD:

`dir mdv1_`

`lrun mdv1_file` (run a basic program)

`view mdv1_file` (view a file)

Pressing `<ALT><ENTER>` will bring back the last command on the command line.

You can change the default directory using the `data_use` command, which is like DOS cd command. So setting `data_use win1_` means you can just enter `dir`. Directories are supported on the QL, use `make_dir`. Other directory commands to use `ddown, dup`.

## QL-SD

QL-SD can be viewed as a hard drive for the QL. If you have a QL-SD file called QXL.WIN (and the relevant .rom file) in the root directory of the SD card this will be mounted at boot. The drive is called `win1_` and you can manipulate files just the same as on the `mdv1_` drive.

A sample QL-SD file and the required ql.rom is in the QL-SD.zip file. This contains a number of games and the Psion applications and also has unzip. Format an SD card and extract this ZIP file first and then copy other files to the SD card, this is to stop and fragmentation which QL-SD cannot cope with. It will be mounted read/write in the QL core.

To run the Quill application on this QL-SD use the command `lrun win1_a_quill_boot`. The `_` is like `\` in DOS.

If you want to manipulate the QL-SD file on an emulator, SMSQmulator is recommended. Just mount the QXL.WIN file in the emulator and mount a NFA directory so you can copy files onto the QXL.WIN files using the NFA directory, e.g. `copy nfa1_file to win1_file`

To run the unzip program on this QL-SD drive:

`make_dir win1_tempdir`

`data_use win1_tempdir`

`ex unzip;"file.zip"`

The files will have been extracted into the win1_tempdir directory.

History
-------
* [ql_150820.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/ql/ql_150820.rbf)
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
