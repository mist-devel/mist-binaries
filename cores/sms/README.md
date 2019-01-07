Sega Master System and Game Gear Core for MiST
----------------------------------------------

This core is a port of Bens Sega Master System implementation for the
Papilio. See http://fpga-hacks.blogspot.de/

The core has been adopted to the MiST upload logic so cartridge images
can be uploaded via the MIST OSD as usual. To run a cartridge image
press F12 to open the OSD. Select a *.SMS file for upload. The core
will automatically be restarted after upload, so the cartridge is
started immediately.

It's recommended to use a USB joystick or gamepad with more the one
fire button since many SMS games expect a second fire button.

Source code lives together with the MiSTer port:
https://github.com/MiSTer-devel/SMS_MiSTer

History
-------
* [sms_190107.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/sms/sms_190107.rbf)
  - Added Korean mapper (Sangokushi 3, Dodgeball King)
  - Fixed some bugs

* [sms_190105.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/sms/sms_190105.rbf)
  - Fixed a lot of bugs.

* [sms_190102.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/sms/sms_190102.rbf)
  - FM sound and many fixes, based on the MiSTer port.

* [sms_160603.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/sms/sms_160603.rbf)
  - Audio clock adjustment

* [sms_140819_r315.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/sms/old/sms_140819_r315.rbf)
  - Joysticks swapped

* [sms_140818_r314.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/sms/old/sms_140818_r314.rbf)
  - Initial release
