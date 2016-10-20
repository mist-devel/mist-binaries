#!/bin/bash

# -- make_sd_root.sh
#    Constructs a folder structure for a blank SD card,
#    picking up the latest cores from SVN folders
#    
# -- We exclude the arcade cores as they don't seem to handle USB joysticks
# -- We also exclude these since I haven't been able to test them yet.
#    - Minimig
#    - Atari 800
#    - Spectrum
#    - ZX01
#

CP='cp'
XCP='cp -r'

CORES=../../cores
ROMS=../
CFG=../cfg

copy_latest_core() {
	cp `ls -r $1/*.rbf | head -1` $2
}

echo Creating sd_root folder...
if [ ! -e sd_root ]; then
	mkdir sd_root
fi

cd sd_root

${CP} ${CFG}/*.CFG .

# Default startup core - ST for now
DIR=${CORES}/mist
copy_latest_core ${DIR} core.rbf

# Atari ST core
echo AtariST...
DIR=${CORES}/mist
copy_latest_core ${DIR} atariST.rbf
${CP} ${DIR}/system.fnt system.fnt
${CP} ${DIR}/tos.img tos.img
${CP} ${DIR}/disk_a.st disk_a.st
${CP} ${ROMS}/harddisk.hd harddisk.hd
mkdir -p atariST
if [ -d ${ROMS}/atariST ]; then
	${XCP} ${ROMS}/atariST/* atariST/
fi

# Atari 2600
echo Atari2600...
DIR=${CORES}/a2600/
copy_latest_core ${DIR} atari2600.rbf
mkdir -p atari2600
if [ -d ${ROMS}/atari2600 ]; then
	${XCP} ${ROMS}/atari2600/* atari2600/
fi

# Atari 5200
echo Atari5200...
DIR=${CORES}/atari5200/
copy_latest_core ${DIR} atari5200.rbf
mkdir -p atari5200
if [ -d ${ROMS}/starter_pack_files/atari5200/rom ]; then
	${XCP} ${ROMS}/starter_pack_files/atari5200/rom/* atari5200/
fi

# Apple II+
echo AppleII...
DIR=${CORES}/appleii+/
copy_latest_core ${DIR} apple2.rbf
mkdir -p apple2
if [ -d ${ROMS}/apple2 ]; then
	${XCP} ${ROMS}/apple2/* apple2/
fi

# Colecovision
echo Coleco...
DIR=${CORES}/colecovision/
copy_latest_core ${DIR} coleco.rbf
mkdir -p coleco
if [ -d ${ROMS}/coleco ]; then
	${XCP} ${ROMS}/coleco/* coleco/
fi

# C64
echo C64...
DIR=${CORES}/fpga64/
copy_latest_core ${DIR} c64.rbf
mkdir -p c64
if [ -d ${ROMS}/c64 ]; then
	${XCP} ${ROMS}/c64/* c64/
fi
${XCP} ${DIR}/programs/* c64/

# NES
echo NES...
DIR=${CORES}/nes/
copy_latest_core ${DIR} nes.rbf
mkdir -p nes
if [ -d ${ROMS}/nes ]; then
	${XCP} ${ROMS}/nes/* nes/
fi

# SMS
echo SMS...
DIR=${CORES}/sms/
copy_latest_core ${DIR} sms.rbf
mkdir -p sms
if [ -d ${ROMS}/sms ]; then
	${XCP} ${ROMS}/sms/* sms/
fi

# ZX Spectrum
echo ZX Spectrum...
DIR=${CORES}/spectrum/
copy_latest_core ${DIR} spectrum.rbf
mkdir -p spectrum/demos spectrum/homebrew
if [ -d ${ROMS}/spectrum ]; then
	${XCP} ${ROMS}/spectrum/* spectrum/
fi
if [ -d ${ROMS}/spectrum/demos ]; then
	${XCP} ${ROMS}/spectrum/demos/* spectrum/demos/
fi
if [ -d ${ROMS}/spectrum/homebrew ]; then
	${XCP} ${ROMS}/spectrum/homebrew/* spectrum/homebrew/
fi

# TODO
# Amstrad
# Amiga
# Archimedes
# Astrocade

# diagnostic roms/disks
if [ -d ${ROMS}/zzz_diagnostic ]; then
	echo Diagnostic roms/disks
	mkdir -p zzz_diagnostic
	${XCP} ${ROMS}/zzz_diagnostic/* zzz_diagnostic/
fi

echo done.
