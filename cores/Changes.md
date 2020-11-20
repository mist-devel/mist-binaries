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