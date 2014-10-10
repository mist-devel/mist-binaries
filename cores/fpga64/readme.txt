FPGA64 on MIST
--------------

These are ports of the FPGA64 C64 core by Peter Wendrich distributed with
his kind permission.

Usage
-----

This implementation does not implement a typical mass storage like a
cassette tape drive or a floppy drive.

Instead it implements some mechanism called direct memory injection.
This can be triggered via the OSD (which is opened with the F12 key)
allowing to to upload a c64 program binary (.PRG) directly into the
memory of the embedded c64. After injection the program can simply be
started using the basic "run" command. As shown in the beginning of this
video:
https://www.youtube.com/watch?v=tnboiECYXVo

For obvious reasons this limits the usability of the c64 core to games
and programs consisting of single files only.
