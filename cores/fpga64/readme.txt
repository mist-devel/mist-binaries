FPGA64 on MIST
--------------

These are ports of the FPGA64 C64 core by Peter Wendrich distributed with
his kind permission. The latest ports are based in Dar FPGAs work and includes
a c1541 floppy implementation.

The c1541 enabled core needs at least firmware_150715_r1207.

Usage
-----

The current core implements a c1541 floppy disk drive. A D64 image can
be mounted from the MISTs OSD. Programs can afterwards be loaded from
floppy using the usual commands (e.g. LOAD "$",8 and LOAD"*",8,1)

Additionally it implements some mechanism called direct memory injection.
This can be triggered via the OSD (which is opened with the F12 key)
allowing to to upload a c64 program binary (.PRG) directly into the
memory of the embedded c64. After injection the program can simply be
started using the basic "run" command. As shown in the beginning of this
video: https://www.youtube.com/watch?v=tnboiECYXVo
