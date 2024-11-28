**colecovision_241128.rbf**
- Fix 'blend' setting

**nes_241008.rbf**
- Real Zapper support (by UzixLS)
- X/Y as turbo fire buttons (by UzixLS)
- FAMICON keyboard support
- A few mapper support enhancements

**TSConf_241005.rbf**
- Mouse: add scroll support
- Tune JT49 to match sound output as on ZX-Multisound and zxtune
- Fix covox output to the left channel only
- Fix time counting when there is no USB-RTC on MIST
- Fix glitches while reading RTC in Basic
- Keyboard: change keyboard layout to same as in ZX Evolution
- Keyboard: fix arrow keys in Basic
- Keyboard: better handling of simultaneously pressed keys
- Keyboard: add fifo for scancodes to improve compatibility with some picky software

**snes_mist_240922.rbf**
- Auto-detect option for ROM files. Needs fw version *240922*

**TSConf_240921.rbf**
- New core

**C64_240814.rbf**
- Support Magic Desk 2 format with 2 MiB size
- Don't disable REU when a cart is attached, but no IOF line used

**SMS-Nuked_240716.rbf**
- New core based on [Nuked-SMS-FPGA](https://github.com/nukeykt/Nuked-SMS-FPGA)

**fpgagen_240716.rbf**
- Fix IO area decoding (Ballz 3D)
- Auto-detect Virtua Racing cart

**c16_240405.rbf**
- Open bus reads from some free ares (fixes Giana Sisters)
- Use PCM sound output from TED instead of PWM for better sound quality
- Update 1541

**menu_240113.rbf**
- Shorter hsync/longer back porch at 15kHz

**menu_240111.rbf**
- More close to VGA timings (at least in NTSC mode)
- Large OSD (need firmware version at least 240105!)
- Background image changed to 640x312 (reload/resize menu.rom, if using it)

**Atari7800_240105.rbf**
- New core based on k7800 (c) by Jamie Blanks (Kitrinx)

**C64_240105.rbf**
- Lot of VIC-II accuracy improvements
- Selectable VIC-II variant

**C64_231205.rbf**
- Add the extended Magic Desk cartridge format
- VIC-II: apply color change (background mainly) one pixel earlier (fixes many demos with one-pixel glitches, like Edge of Disgrace or The Space is Broken)

**snes_mist_231202.rbf**
- Add an NTSC-DeJitter video mode, which breaks 100% cycle accuracy, but works better on some displays

**ZXN_230902.rbf**
- Update to the latest core (3.02)

**NeoGeo_230806.rbf**
- Timer fix in PAL mode
- Some CD related fixes (Double Dragon, Karnov's Revenge)

**NeoGeo_230705.rbf**
- CD support

**NeoGeo_230620.rbf**

- Fixes and some optimizations in the SDRAM controller
- Finished the conversion to synchronous logic. No more latches/generated clocks!
- Use upstream jt12
- Memcard save/load support
- Revisit button assignments

**NeoGeo_230607.rbf**
- New port

**msx_mist_230512.rbf**
- Fix the MIDI/WiFi module use
- Option to choose between MIDI/WiFi mode for the UART pins

**snes_mist_230503.rbf**
- Fix in the scandoubler to handle the NTSC short line

**PCXT_mist_230421.rbf**
- New core

**snes_mist_230420.rbf**
- Update with the latest upstream changes since the last release
- SFC player option (exit from it with reset)

**C64_230402.rbf**
- Allow to set the mouse port manually in the OSD
- PRG injection should set some ZP variables +1 beyond the end
- VIC-II: fix NTSC bus access slots

**ZXN-230331.rbf**
- Rebase to the latest ISSUE4 release
- Update mist-modules

**msx_mist-230331.rbf**
- Update to OCM-PLD 3.9.1
- Add a Mount VHD option to the OSD
- Fix the SD Card emulation for Nextor kernels

**TVC_230228.rbf**
- Fix sound divider and interrupt generator

**C64_230228.rbf**
- Add a normal reset without removing the cartridge
- Fix cartridge (C64.R02) file autoload
- Add support for cart type 36 (Retro Replay)
- Fix a regression with VIC-II data fetch when AEC is asserted

**zxspectrum_230122.rbf**
- Replace WD1772
- Fix PlusD interface
- Disable Covox/Sndrive during TRDOS/PlusD use

**TVC_230113.rbf**
- Enhanced from the original core (originally by József László)
- Rewritten some parts to synchronous code
- Updated the various components, like the T80 CPU and MC8645 CRTC
- Cartridge and FDC support
- Some additional fixes, like digi sound is working now
- 15kHz (original) and 31kHz(scandoubled) video outputs are supported in one core

**ep128_221116.rbf**
- New core by Kyp

**apple2e_221113.rbf**
- Fix the floating bus values
- Correct the vertical counter advancing (make Cycle Counting Megademo from VMW work)
- NTSC/PAL mode switch option
- Update T65 and mist-modules

**C64_220530.rbf**
- Adjust blanking/sync timings according to prelimiary VIC-II datasheet/Christian Bauer's VIC-II docs
- T65: rework interrupt dispatching
- CPUPort: bit 5 is low when input
- Update VIA
- C64.R02 can be used as a default cart image

**Oric_221104.rbf**
- Fix the refresh logic in the SDRAM controller

**Oric_221030.rbf**
- Some updates and cleanups since the last released version
- Internal TAP playback support
- VIA6522 updated to the latest from the Commodore cores
- ROM resides in SDRAM now (an oric.rom is required)

**zxspectrum_221024.rbf**
- ESXDOS ROM updated to 0.8.9
- Currah uSpeech support based on Dar's SP0256 implementation

**vic20_221022.rbf**
- Update 1541
- Fix VIA's port latching (Robotic Liberation!)
- Update MiST modules

**Intellivision_20221001.rbf**
- Updated ROM loading, should now work with Intellicart .rom files.

**minimig_mist_rtg_220906.rbf**
- CD audio playback

**Next186_220826.rbf**
- IDE/ATAPI CDROM related fixes

**Amstrad_220826.rbf**
- FDC & CRTC related fixes
- Symbiface II support with IDE and RTC

**Next186_220821.rbf**
- Some VGA fixes
- IDE support (Primary slave/Secondary master and slave)

**minimig_mist_rtg_220821.rbf**
- Fixed bitplane offset bug which broke blitterscreens with sprite masks (by AMR)
- Implemented ToD clock bug, fixes music for Torvak the Warrior (by AMR)
- Tweaked bitplane shifting, fixes offset logo in 3le-Passengers (by AMR)
- ATAPI CDROM support

**pet2001_220722.rbf**
- New core, ported from https://github.com/skibo/Pet2001_Nexys3 by way of the MiSTer port.
- Uses SDRAM for ROM and Tape.

**fpgagen_220706.rbf**
- Update jt12/jt89
- Multitap support
- Fix 68K RAM writes from Z80 (fixes Mamono Hunter Yohko)

**apple2e_220701.rbf**
- Fix disk writes when dirty track buffer left in memory before disk change
- Add support for 2 disks. Need at least firmware version 220701!

**atari800_220617.rbf**
- Support for ATX and XFD disk images

**intv_20220607.rbf**
- Mattel Intellivision, by Grabulosaure and Kitrinx, ported to MiST and DeMiSTified platforms by Alastair M. Robinson

**apple2e_220605.rbf**
- Generic updates in mist-modules/mockingboard/CPU/etc.
- Disk write support (tested in DOS 3.3 only)
- Apple keys are mapped to left/right ALT

**C64_220530.rbf**
- 1541 fix for Krill's loader
- Prophet64 cartridge support with second SID
- 6850 ACIA based MIDI interfaces
- UP9600 wiring of the user port
- G64 support for 1541 (loads some protected disks)

**Next186_220508.rbf**
- Implement 40 char text modes
- Expand hcounter to 11 bit (fixes Simpsons arcade)
- Implement the preset row scan CRTC register
- Option to hide Adlib (for games like Dimo's Quest)
- Add /32 speed option (for near XT speed)
- Output active negative syncs
- Increased BIOS size to 16K (The core won't work with the old BIOS! Also update the FONT.EXE from font-BIOS16k.zip)

**zxspectrum_220505.rbf**
- Add CRC_ON_OFF command to SD card driver (for Wildplayer DivMMC)
- Fix unreadable menu when scandoubled disabled
- Add Covox at #FB port and SounDrive at #0F,#1F,#4F,#5F ports
- Increase brightness for colors without BRIGHTNESS bit
Thanks to Eugene Lozovoy (UzixLS) for these patches!

**fpgagen_220420.rbf**
- Update JT12
- Return FM status register as in Model 1 (fixes Hellfire)
- Clear RAM after ROM loading (fixes Handy Harvy)
- Merge robinsonb5's DeMISTify branch with some SDRAM controller updates

**Next186_220416.rbf**
- More VGA improvements
- Flush the instruction queue on reg->mem writes (fixes Army Moves and other Dinamic games)
- Preliminary Tandy sound and video support

**MiSTery-220401.rbf**
- Support the Cubase 2 dongle as well

**MiSTery-220329.rbf**
- Internal Cubase dongle support (update the firmware, too!)

**Next186_220319.rbf**
- Implement programmable CRTC timings (Battle Isle 2, Flashback using it for custom video modes)
- Fix VGA address wraparound (Raiden, Alien Breed, etc.)

**apple1_220315.rbf**
- Fixed bug when loading programs in the range $4000-$BFFF
- Added debounce filter to cassette input (ACI) to reduce loading errors

**Next186_220311.rbf**
- JTOPL2 timer fix (affects AdLib detectability)
- Cache/VGA coherency changes - lot less cache flushes
- More speed options
- CGA mode support (BIOS modes 04h, 05h, 06h)
- Note: BIOS functions are missing to write text in graphics modes

**menu_220220.rbf**
- Together with **firmware_220220**, menu core has its own menu
- Use direct transfer to load the background image

**Next186_220217.rbf**
- Switch Adlib to JTOPL2
- Selectable Fake286 option (normally the CPU will behave & detected as 80186 now).
  Patch by Aitor Gómez. Need special version of FDXMS and EMU386 (see below).
- There are useful utilities in the DOS directory
- Some easy VGA fixes
- Prevent mouse FIFO overflow (like in Battle Chess)
- The SDRAM controller works with 64MB modules (still using 32MB only)

**tgfx16_220216.rbf**
- Enable vertical overscan blanking
- Fixes from upstream by srg320 & dshadoff

**menu_pal_220205.rbf**
**menu_ntsc_220205.rbf**
- Menu with background image support
- PAL(50Hz) and NTSC(60Hz) versions

**MiSTery-220116.rbf**
- Support ED floppy disks
- Hide the RTC chip if no valid date arrives from the firmware

**apple1_220115.rbf**
- Extend free RAM to ~64K
- Load programs via F12 osd menu
- Full working ACI audio cassette interface via UART_RX/AUDIO_L
- Accurate CPU clock speed and RAM refresh lost cycles
- NTSC output and integration with mist_video
- 5x7 display character matrix as in the real machine
- Crosstalk pixel artifacts as in the real machine
- F1 and F5 keys for CLS and RESET

**vic20_220114.rbf**
- Mega-Cart support (Mega-Thanks to AMR!)

**C64_211224.rbf**
- Merry "Treu Love" Christmas!

**C64_211220.rbf**
- CIA Timer fixes
- VIC-II: latch xscroll one pixel later (Happy 2021 demo)
- Keyboard numpad symbol support
- REU up to 16 MB with original timings and bus arbitration

**Amstrad_211211.rbf**
- Some FDC updates
- Fix some CRTC behavior (especially CRTC0 ones)
- Allow umounting disk images from the OSD

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
