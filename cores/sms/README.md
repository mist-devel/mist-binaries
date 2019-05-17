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

Backup RAM support
------------------

Some game carts have a battery-backed RAM, where high scores or other states
are preserved. You can use this on MiST with a bit of preparation:

- Create an empty file on the SD-Card, with .sav extension (with 8192 bytes length).
- After loading the ROM, choose "Mount *.SAV" OSD option, and select the
  files created previously. The game will reset, after the RAM content has loaded.
- To preserve the Backup RAM state, choose "Write Save RAM" from the OSD menu.
  A loaded Backup RAM is indicated by the yellow LED. If it doesn't lit, saving is not
  possible.

A list of games with Backup RAM: http://www.smspower.org/Tags/MemoryBackup

* Note: only 8K backup RAM is supported (maybe some carts have up to 32K, but
  seems all uses only 8K).

History
-------
* [sms_190414.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/sms/sms_190414.rbf)
  - Extra height modes are implemented (theflynn49)
  - Some general VPD fixes (theflynn49)
  - Hanging Game Gear fix (theflynn49)
  - Option to disable BIOS

* [sms_190320.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/sms/sms_190320.rbf)
  - BIOS fix for Shadow Dancer

* [sms_190111.rbf](https://github.com/mist-devel/mist-binaries/raw/master/cores/sms/sms_190111.rbf)
  - 8K Backup RAM support

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
