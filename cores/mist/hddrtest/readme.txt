This is a test release including various changes related to ACSI and
HDDriver compatibility.

This isn't extensively tested and should only be used if you are
willing to risk data corruption.

ACSI0 Direct SD
---------------

Firmware_141121_r512.upg introduces "direct SD" for ACSI0 in the
Storage submenu. With this option enabled TOS is granted direct access
to the first partition of the SD card avoiding the need to use hardisk
images.

This features can be quite difficult to use since the first partition
on the card has tp be formatted in a way that the MIST board itself
understands to be able to load the core and the tos image from
it. Furthermore the embedded ST must be able to use it and finally a
PC may also need to access it to be able to exchange data with the
MIST/ST.

I haven't yet found a simple way to get a fully working setup.

The best working approach so far is to use a Linux PC to create a
partition of slightly less than 32MB size. Set partition type to 4 and
forcing the use of two sectors per cluster using the command "mkdosfs
-s2 /dev/<yourpartition>" results in a file system understood by
Windows, Linux, the MIST board itself and a ST running Hddriver.

Then place core.rbf and tos.img and floppy disk images on that
partition to be able to boot the mist board with it. Using hddriver
9.03 from a floppy disk image allows to access this partition from
within the ST. However, hddriver cannot be installed on this setup.

Hddutil from the hddriver package has an option to create a file 
system that is accessible by all systems involved and with the ability
to let the ST boot from it. So far i have had to do some manual further
tweaking to get this working.

The requirements of the mist don't differ from any other sd card
solution and it's assumed that e.g. a sd card formatted for usage in
the ultrasatan should also work in the MIST.

Very useful information regarding this can be found in the
Atari_HD_File_Sytem_Reference_Guide.pdf
