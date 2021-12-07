**minimig_mist_rtg_211207.rbf**
- Add analogue joystick support (turn on in Chipset menu)
- Digital joystick also affects POT registers (fix Jimmy White's whirlwind snooker)
- Update RTG, support screen dragging, update the utility disk (by AMR)

**vic20_211127.rbf**
- VIC-I color-pixel data alignment fix (thanks, AMR!)
- Audio filter simplifications / improvements by AMR
- 1541 update from C64/C16, add disk unmounting to OSD

**colecovision_211126.rbf**
- Increase keyboard FIFO size to avoid overflow
- Change SDRAM drive strength to 8mA
- Update the CPU and other components

**Ti994a_211126.rbf**
- Use higher SDRAM clock
- Change SDRAM drive strength to 8mA

**msx_mist-211124.rbf**
- Fix keyboard FIFO overflow

**msx_mist-211017.rbf**
- Update to OCM-PLD v3.9
- MIDI OUT supoort
- Casette input/DAC output changes (hopefully fixes)

**nes_211003.rbf**
- Add lot of selectable palettes

**tgfx16_210910.rbf**
- Fix YPbPr mode
- Updates from upstream

**C64_210901.rbf**
- Fix some cases when the ROM/Tape downloading fails
- Use the ID values in the BAM for the whole disk on 1541
- Add C128-style 2 MHz turbo mode

**nes_210824.rbf**
- Fix backup RAM reading/writing from/to the SD card

**zxspectrum_210824.rbf**
- Add Issue2/Issue3 selector
- Option to disable snowing (unrainer)
- Sinclair II joystick and Kempston mouse fix

**Next186_210802.rbf**
- Many improvements in PIC, PIT and PC Speaker
- MPU-401 interface (by squidrpi)
- More frequent cache flushes reducing VGA artifacts (however reducing the performance, too)
- EGA/VGA VDE register fix
- Joystick support
- Cache the whole phyisical address space
- NMI button (useful for Turbo Debugger)

The BIOS also needs to be updated!

**minimig_mist_rtg_210727.rbf**
- Don't freeze on writing 256 sectors
- Make the secondary IDE disabling effective
- Configurable audio filter mode & power LED off-state (by retrofun)

**ql_210627.rbf**
- Improved video positioning.

**Next186_210715.rbf**
- New core

**ql_210713.rbf**
- Improved speed to be near the original QL hardware speed.

**msx_mist_210712.rbf**
- Update common MiST components - support multiple write SD Card command

**MiSTery-210711.rbf**
- Fix extra RAM selection (works with TG68K now)
- Various updates of components (FX68K, TG68K, FDC)

**tgfx16_210705.rbf**
- New SDRAM controller and cofi module by robinsonb5
- Fix sprite rendering in hires mode
- Source tree merged with the Turbo Chameleon port

**ql_210703.rbf**
- Switchable speed to get closer to original QL speed.
- BUS improvements to attempt reduction in bus access speed including use of clkena_in to replicate DTACK waits.
- Reworked IPC communication logic in ZX8302 and added a COMDATA latch.
- IPC code uses Hermes, fixes missing key-presses.
- Eliminate most async clocks.

**Ti994a_210701.rbf**
- Fix disk image handling

**ql_210627.rbf**
- Second microdrive support added. Games that require MDV2_ support, like "QL Pawn", are now supported.
- Selectable ROM added

**plusToo_210625.rbf**
- TG68K update: MOVEP fix for SCSI (works now in SE mode)
- Speed up ADB transmission for TG68K/16MHz mode

**plusToo_210622.rbf**
- Fix SCSI bugs: data corruption, 3rd and 4th drives, GET CAPACITY command
- Add fake VERIFY commands to SCSI - some formatters are using it

**plusToo_210620.rbf**
- Support Macintosh SE mode (automatically switched if a 256KB SE ROM is used)
- Support 4 SCSI drives (need at least firmware 210618!)
- Greatly increased SCSI performance

**minimig_mist_rtg_210618.rbf**
- Add support for secondary IDE channel (need IDEFix/ATAPIMagic)
- 64 MB RAM support
- Tentative CIA fix for OS3.1.4 time gain problem
- RTG now supports 16 bit as well as 15 bit

**snes_mist_210618.rbf**
- Fix SAV file writing
- Updates from upstream

**fpgagen_210616.rbf**
- Try again to simulate RAM refresh delays
- Fix writing save RAM to SD Card

**tgfx16_210529.rbf**
- Fix several reported bugs and glitches (need a firmware update for all fixes - will released soon)

**tgfx16_210525.rbf**
- CD support (need recent firmware)

**sms_210424.rbf**
- Boost PSG and FM volume, and replace the DAC (by robinsonb5)
- Adjust VDP collision flag (for Donkey homebrew)

**zxspectrum_210424.rbf**
- Adjust Pentagon interrupt and border timings
- Don't mix NMI key with reset (F10 - NMI, F11 - Reset)

**bbc_210402.rbf**
- Use 48 MHz main clock to be synchronous with both the Teletext and ULA
- FDC update (fix write corruption)
- Allow unmountig of disks from the OSD (requires firmware 210330)
- RTC support
- CMOS RAM save/load support

**atari800_210402.rbf**
- Add a joystick swap option
- Allow unmountig of disks from the OSD (requires firmware 210330)

**c16_210331.rbf**
- TED: revert a wrong change (thanks to Istvan Hegedus).
- Update T65/1541
- Allow unmountig of disks from the OSD (requires firmware 210330)

**C64_210331.rbf**
- Adjust motor momentum timing (fixes some loaders)
- Allow unmountig of disks from the OSD (requires firmware 210330)

**Ti994a_210331.rbf**
- SDRAM controller update
- Allow unmountig of disks from the OSD (requires firmware 210330)

**zxspectrum_210331.rbf**
- TZXplayer update
- Allow unmountig of disks from the OSD (requires firmware 210330)
- Get rid of GLUK ROM
- Add DivMMC RAM/ROM extension (hint: ESXDOS)
- T80 interrupt acknowledge fixes (not really affecting the Speccy)

**plusToo_210329.rbf**
- Implement the video back buffer
- Keyboard/Keypad fix
- 16 MHz was not enabled for TG68K, fixed

**ZXN_210327.rbf**
- Fix an off-by-one error of the TZX playing
- Port the CPU fixes from the pure ZX core
- Add Sinclair and Cursor joysticks

**ZXN_210322.rbf**
- Stabilty improvements
- Increase the performance of the SD Card
- Add tzxplayer

**ZXN_210317.rbf**
- Enable 28 MHz mode
- Some internal fixes

**plusToo_210311.rbf**
- FX68K/TG68K selectable CPUs
- RTC/PRAM support (can boot OS 7.5)
- Two harddisks support without (reasonable) size limt
- Use the cycle-exact VIA from Gideon

**ZXN_210307.rbf**
- New core

**C64_210302.rbf**
- Simulate tape momentum in the TAP player
- Add a progressbar for tape playing

**nes_210302.rbf**
- APU rewrite by Kitrinx
- Fixes for mappers 18,30,32,88,97,38,165
- Backup RAM support

**zxspectrum_210226.rbf**
- Fix F10 and F11 shortcut keys
- TZXPlayer update from Amstrad CPC
- TZXPlayer improvement: different length of header and data tones

**snes_mist_210226.rbf**
- Updates from upstream
- Add Justifier lightgun option

**vic20_210205.rbf**
- Same VIA is used in the machine and 1541
- Lot of VIC-I fixes (RL, IMPO3 demos are much better)

**atari800_210130.rbf**
- New version with standard video settings and OSD

**MiSTery-210130.rbf**
- Blitter force dest read fix regarding to endmasks
- Add selectable 68020 CPU (TG68K)

**Amstrad_201223.rbf**
- CDT player fixes
- Add a progressbar for CDT playback

**fpgagen_210108.rbf**
- VDP T80 interrupt length fix (Metal Blast 2277)
- VDP Vcounter reload with NTSC/V30 mode fix (SOR2 Simpsons hack)
- Allow using the save RAM in Sonic Delta 40Mbit ROM hack
- CRAM dots option
- Lightgun support (single Menacer or single/dual Justifier) via mice

**tgfx16_201230.rbf**
- New TurboGrafx16 core based on srg320's code

**Amstrad_201212.rbf**
- Change VSYNC triggering in the CRTC (Onescreen Colonies #0)
- Add Alt-F11 as reset

**zxspectrum_201212.rbf**
- Fix Kempston mouse
- Z80 (both 128K and 48K) and SNA (48K only) snapshot loading
- More joystick options
- Tape input polarity and EAR output feedback fix

**Ti994a_201201.rbf**
- Add a PHP1240-compatible single-density disk controller

**MiSTery-201126.rbf**
- Fix some reset issues (shifter desync, extra RAM)
- Simulate up and down keypresses with the mouse wheel

**minimig_mist_rtg_201122.rbf**
- Fix border blank (by AMR)
- Add +4MB Fast RAM (+2MB if Slow RAM is enabled) (by AMR)
- Enable the cache for Turbo Chip RAM
- 32 bit access to normal Chip RAM in AGA
- Slow RAM is always Turbo in AGA
- Gayle IDE irq flag fix
- Swap left&right audio channels

**MiSTery-201122.rbf**
- Add Ethernec support
- Gauntlet II interface fix
- Add composite-like blending
- Connect 2nd fire button on joyport0

**a2600_201121**
- Fix 2k cart mirroring
- Fix 8k cart default bank
- TIA: fix center signal (Bird and Beans)

**minimig_mist_rtg_201017.rbf**
- Fix the RAM selector (applied only at reset)
- Fix Chip RAM mirrors (Kickstart 1.2 works again)
- Slight Fast RAM cache improvement
- TG68K update - all instructions pass the tester

**minimig_mist_rtg_201006.rbf**
- Significant performance increase of the Fast RAM cache
- Master clock is switched between PAL (28.375 MHz) and NTSC (28.6363 MHz)
- The old video filters for chipset video are re-enabled

**zxspectrum_201002.rbf**
- Use the original PSG from MikeJ
- General Sound register access fixes (e.g. Alienate demo)

**c64_200925.rbf**
- Paged OSD
- CTRL-F11 as soft reset
- Some internal updates

**minimig_mist_rtg_200923.rbf**
- RTG and C2P support by Alastair M. Robinson
- TG68K updates with stack frame fixes in 68010+ modes

**Ti994a_200908.rbf**
- Cart file type auto detection
- Mask cart unused address bits (detected from .d type)
- Add some keyboard shortcuts

**Ti994a_200907.rbf**
- New core

**a2600_200831.rbf**

- TIA: fix divider by 6 (E.T., but affects all C,D,E audio waveforms)
- Update the DPC mask flags after changing the counters (Pitfall II)
- TIA: transparent latches for the color registers (D.K.VCS)
- TIA: don't apply pf_score when pf_priority=1 (Bobby is Going Home)

**zxspectrum_200822.rbf**
- Further ULA timing fixes (Timing_Tests-128k_v.1.0)
- Increase GS clock to 14 MHz
- Fix hires Timex mode

**fpgagen_200821.rbf**
- Bus arbitration rework
- ZRAM access rework
- Pages in OSD
- Update jt12
- DMA COPY cycle-exactness

**msx_mist_200821.rbf**
- CPU update
- RTC support

**a2600_200812.rbf**
- TIA fixes: Playfield mirroring, playfield score flag, (no) collisions in blanks.
  Canyon Bomber, Tutankham, Caverns games are fixed

**gb_200810.rbf**
- Lot of fixes from paulb-nl and brNX. GBC games are really good!

**zxspectrum_200809.rbf**
- ULA and CPU timing fixes
- Implement the snow effect
- Update PSG
- Beeper + PSG volume mixing adjustment

**archimedes_200808.rbf**
- Fix audio clock
- Add reset to Amber (by Robert Peip)

**archimedes_200726.rbf**
- USB-RTC support (read-only)

**minimig_mist_200725**
- Don't read the mouse twice
- USB-RTC support (read-only)

**mistery-200725**
- FDC force IRQ command should start the motor
- USB-RTC support (read-only)

**Amstrad_200724.rbf**
- Fix FDC writes

**Amstrad_200723.rbf**
- The alternative Amstrad CPC core from Sorgelig added to mist-binaries
- New GA based on reverse-engineered decapped chip
- FDC improvements
- Playcity 6 channel sound + Z80 CTC expansion support

**zxspectrum_200625**
- Fix 7MHz CPU turbo
- Some adjusments in GS, seems to work better

**mistery-200621**
- Implement ST mode differences in GSTMCU (Closure finally runs in ST mode!)
- Fix FDC when a command is terminated during SD Card access
- MFP timer input filtering (BMT3 part in SkidRow demo)

**minimig_mist-200614**
- Support a second mouse (for playing The Settlers) and scrolling wheel for the first mouse.
  **Note:** need firmware version 200614!

**snes_mist_200605**
- Update from upstream
- Reduce SDRAM clock phase shift to -800ps
- Load files with 512 bytes header (SMC)

**sms_200604**
- Add multitap and lightgun via mouse support
