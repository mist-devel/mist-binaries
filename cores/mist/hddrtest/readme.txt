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

The most useful setup i've found so far is this:

The current ACSI implementation of the MiST board is limited to 1GB
(this is the limit of the original Atari ST harddisk interface). So
these instruction will only give you access to up to 1GB of your SD
card even if it's bigger.

Step 1: Start with an SD card of any size and put a tos.img (tos 2.06
recommended) and a core.rbf and a floppy disk image containing
hddriver (tested with 9.03) onto the card.

Step 2: Boot the MIST board from that card. While tos does the ram
test enable "ACSI0 direct SD" in the Storage submenu of the OSD. Then
select the hddriver floppy image and boot into TOS. Hddriver will load
from disk and detect the card as ACSI device 0.

Step 3: Launch hddrutil from the floppy disk image. Select the ACSI0
drive in the window "Available Devices". Then pick
"Medium"->"Partition" from the menu. This will show a capacity of not
more than 1073.7MB. Click on "split" and split the available space
into two partitions. Select "Compatibility" and Check "TOS". Click
"ok" until the new partition is being done. Reboot.

Step 4: Launch hddrutil again. Select drive C: in the list of the
"Available Devices" and select "File"->"Install HDDRIVER" from the
menu.  You now have a SD card with two DOS & TOS compatible partitions
of nearly 512MB of which Windows can use the first one out of the box.

Step 5: Reinstall core.rbf, tos.img and a few floppy images on the first
partition. Reinsert the SD card into the MIST.

Step 6: Boot the MIST. Again select "ACSI0 direct SD". You may save
this setting permanently while the ST is doing its RAM test. Don't use
the OSD to save settings later when the Atari runs and this will cause
the Atari and the MISTs firmware to alter the same data on disk which
will very likely corrupt the data on the card. But the moment when TOS
tests its RAM is a safe moment to save the MIST settings on the card.

Step 7: Swap the card between the MIST and your Windows PC to exchange
files.

Very useful information regarding this can be found in the
Atari_HD_File_Sytem_Reference_Guide.pdf
