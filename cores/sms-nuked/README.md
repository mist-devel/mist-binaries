Sega Master System for MiST/SiDi
--------------------------------

This core is based on [Nuked-SMS-FPGA](https://github.com/nukeykt/Nuked-SMS-FPGA).

SMS BIOS is needed as NUKEDSMS.ROM in the same directory as the .RBF file. Only
8K BIOSes are supported. One of the Japanese BIOSes is recommended, since it doesn't
check cart signatures (compatible with all .SMS files).

Backup RAM support
------------------

Some game carts have a battery-backed RAM, where high scores or other states
are preserved. You can use this on MiST/SiDi with a bit of preparation:

- Create an empty file on the SD-Card, with .sav extension (with 8192 bytes length).
- After loading the ROM, choose "Mount *.SAV" OSD option, and select the
  files created previously. The game will reset, after the RAM content has loaded.
- To preserve the Backup RAM state, choose "Write Save RAM" from the OSD menu.
  A loaded Backup RAM is indicated by the yellow LED. If it doesn't lit, saving is not
  possible.

A list of games with Backup RAM: http://www.smspower.org/Tags/MemoryBackup

* Note: only 8K backup RAM is supported (maybe some carts have up to 32K, but
  seems all uses only 8K).


Source code:

https://github.com/gyurco/SMS-Nuked