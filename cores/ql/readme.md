Sinclair QL core for the MIST board
===================================

This core needs a QL rom image on the SD card named ql.rom. The included ql.rom should work OK and includes the Toolkit-2 extension which is required for most software. The Toolkit 2 also has much improved file commands.

In the OSD settings increase the memory to 640k from the default 128k. In most cases using 640k will always work fine. The disadvantage is that the boot times will be slower as the QL has to scan more memory.

The speed is switable using "QL Speed" in the OSD. It defaults to be near the original speed of the QL hardware. Switch this off and it runs 3-4x faster than the original QL hardware. The slower speed uses a crude slow down method which is not very accurate but gives a good approximation of the original hardware.

Files can be loaded from microdrive images stored in MDV files in QLAY format (vDrive & mdump .mdv files are not compatible). They are mounted read-only. The files must be exactly 174930 bytes in size. The [MDVTOOL](https://github.com/mist-devel/mist-binaries/tree/master/cores/ql/tools/mdvtool) program can manipulate the MDV files. There are some samples in the "QL" directory. NOTE: All software in the "QL" directory and QL-SD.zip is freeware or public domain. A software collection is available on archive.org.

The [MDUMP2QLAY](https://github.com/mist-devel/mist-binaries/tree/master/cores/ql/tools/mdump2qlay) program will convert MDUMP (version 1 & 2) image files to QLAY suitable for the QL core.

Microdrives will self boot if you select an MDV and reset. This will look for a file called BOOT on the microdrive and run it. You can also start a program on an MDV be typing 'lrun mdv1_boot'.

There's a big collection of QL programs and related material at http://www.dilwyn.me.uk

Be careful when copying files from a PC to the QL, there's metadata in the QL file that gets stripped when extracting ZIP files on the PC. You should unzip the ZIP files on the QL. 

If you find an MDV that was not created with latest MDVTOOL or MDUMP2QLAY and it is slow, it is possible the sectors are in the wrong order. Run it through mdvtool to fix the sector order, e.g. "mdvtool old.mdv write new.mdv" 

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

The sample QL-SD QXL.WIN contains a number of games, the Psion applications and also has unzip. The QXL.win and relevant ROM ql-sd.rom files should be in the root of the SD card. To use this QL-SD select the ROM file in the OSD "Load *.ROM". It will be mounted read/write in the QL core.

Format an SD card and extract the ZIP file first on the PC, copy the QXL.win to the SD card, to stop fragmentation which QL-SD cannot cope with. 
Then copy the following to the SD card:
* ql.rbf as core.rbf
* ql_SD.rom
* js.rom (optional from http://www.dilwyn.me.uk/qlrom/index.html)
* create a directory called "QL" and copy your MDV images into it
* Insert the SD card in the Mist, switch it on
* F12 choose the ql-sd.rom as ROM
* press F1 on the start screen 
* to boot from a Microdrive image with the ql-sd.rom hold CTRL and press F1
* for some older games select the JS.rom and press F2

NOTE: The QL-SD ql_sd.rom file is not compatible with all software running from MDV1 so it is not the default ROM file.

To run the Quill application on this QL-SD use the command `lrun win1_a_quill_boot`. The `_` is like `\` in DOS.

If you want to manipulate the QL-SD file on an emulator, SMSQmulator is recommended. Just mount the QXL.WIN file in the emulator and mount a NFA directory so you can copy files onto the QXL.WIN files using the NFA directory, e.g. `copy nfa1_file to win1_file`. You can also use the Java program [QxlWinReader](http://www.wlenerz.com/qlstuff/#qxlwinr) but this appears to have problems with executables, it works fine with basic and text files.

To run the unzip program on this QL-SD drive:

`make_dir win1_tempdir`

`data_use win1_tempdir`

`ex unzip;"file.zip"`

The files will have been extracted into the win1_tempdir directory.
