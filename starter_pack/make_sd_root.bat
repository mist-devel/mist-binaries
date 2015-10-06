@echo off
rem -- make_sd_root.bat
rem    Constructs a folder structure for a blank SD card,
rem    picking up the latest cores from SVN folders
rem    
rem -- We exclude the arcade cores as they don't seem to handle USB joysticks
rem -- We also exclude these since I haven't been able to test them yet.
rem    - Minimig
rem    - Atari 800
rem    - Spectrum
rem    - ZX01
rem

echo Creating sd_root folder...
if not exist sd_root (
    mkdir sd_root
)
cd sd_root

set CP=copy /Y
set XCP=xcopy /Y /Q

set GET=for /f "tokens=*" %%a in ('dir 
set LATEST=\*.rbf /b /on /a-d') do set latest_core=%%a

set CORES=..\..\cores
set ROMS=..\starter_pack
set CFG=..\cfg

rem cd %SD_ROOT%

rem config files
%CP% %CFG%\*.CFG .\


rem Default startup core - ST for now
set DIR=%CORES%\mist\
%GET%%DIR%%LATEST%
%CP% %DIR%%latest_core% .\core.rbf

rem Atari ST core
echo AtariST...
%CP% %CORES%\mist\%latest_core% .\atariST.rbf
%CP% %CORES%\mist\system.fnt .\system.fnt
%CP% %CORES%\mist\tos.img .\tos.img
%CP% %ROMS%\disk_a.st .\disk_a.st
%CP% %ROMS%\harddisk.hd .\harddisk.hd
mkdir .\atariST
%XCP% %ROMS%\atariST\*.* .\atariST\

rem Atari 2600
echo Atari2600...
set DIR=%CORES%\a2600\
%GET%%DIR%%LATEST%
%CP% %DIR%%latest_core% .\atari2600.rbf
mkdir .\atari2600
%XCP% %ROMS%\atari2600\*.* .\atari2600\

rem Atari 5200
echo Atari5200...
set DIR=%CORES%\atari5200\
%GET%%DIR%%LATEST%
%CP% %DIR%%latest_core% .\atari5200.rbf
mkdir .\atari5200
%XCP% %ROMS%\atari5200\*.* .\atari5200\

rem Apple II+
echo AppleII...
set DIR="%CORES%\appleii+\"
%GET%%DIR%%LATEST%
%CP% %DIR%%latest_core% .\apple2.rbf
mkdir .\apple2
%XCP% %ROMS%\apple2\*.* .\apple2\

rem Colecovision
echo Coleco...
set DIR=%CORES%\colecovision\
%GET%%DIR%%LATEST%
%CP% %DIR%%latest_core% .\coleco.rbf
mkdir .\coleco
%XCP% %ROMS%\coleco\*.* .\coleco\

rem C64
echo C64...
set DIR=%CORES%\fpga64\
%GET%%DIR%%LATEST%
%CP% %DIR%%latest_core% .\c64.rbf
mkdir .\c64
%XCP% %ROMS%\c64\*.* .\c64\
%XCP% %DIR%\programs\*.* .\c64\

rem NES
echo NES...
set DIR=%CORES%\nes\
%GET%%DIR%%LATEST%
%CP% %DIR%%latest_core% .\nes.rbf
mkdir .\nes
%XCP% %ROMS%\nes\*.* .\nes\

rem SMS
echo SMS...
set DIR=%CORES%\sms\
%GET%%DIR%%LATEST%
%CP% %DIR%%latest_core% .\sms.rbf
mkdir .\sms
%XCP% %ROMS%\sms\*.* .\sms\

rem ZX Spectrum
echo ZX Spectrum...
set DIR=%CORES%\spectrum\
%GET%%DIR%%LATEST%
%CP% %DIR%%latest_core% .\spectrum.rbf
mkdir .\spectrum
mkdir .\spectrum\demos
mkdir .\spectrum\homebrew
%XCP% %ROMS%\spectrum\*.* .\spectrum\
%XCP% %ROMS%\spectrum\demos\*.* .\spectrum\demos\
%XCP% %ROMS%\spectrum\homebrew\*.* .\spectrum\homebrew\

rem TODO
rem Amstrad
rem Amiga
rem Archimedes
rem Astrocade


rem diagnostic roms/disks
rem %XCP% /E %ROMS%\zzz_diagnostic\ .\zzz_diagnostic\

echo done.

pause
