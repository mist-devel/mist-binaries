This explains the mdump format used for exact image copying of a microdrive.

The mdump image format contains a header and then multiple sector images. The sector images can be a 
variable size but all sectors in the MDV file will be the same size to each other. The header shows 
the sector size and offsets to the sector header, block header and data. 
The book "QL advanced user guide" by Adrian Dickens has a detailed explanation of the original 
microdrive format. The QLAY format tries to replicate the original microdrive format including the 
low level preamble data and is always a fixed size. The mdump format does not store such low level 
information as it is not required to replicate a microdrive.

The mdump format can be read by Q-emulator. QLAY format can be read by MiST QL core, QL2K & Q-emulator.

The mdump image contains a header and then multiple sectors.

=================
HEADER (46 bytes)

(The source code defines the format below in the mdump_hdr_t structure)
0   ID "Mdv*Dump"
8   header len in words (for versioning)            (unused)
12  offset to MDV sector data
16  bytes per MDV sector
18  number of sectors in dump
19  number of sectors in original MDV
20  offset of sector renumbering table (or NULL)    (unused)
24  offset of sector map (or NULL)                  (unused)
28  offset of global sector header (or NULL)        (unused)
32  dump type/extension: pointer to linked list of extensions (or NULL) (unused)
36  flags:                                          
      - true physical order (for emulation of out-of order sector headers)
      - data followed by checksum (unused)
      - has gaps (missing sectors, mdump1) (unused)
      - version number (1 or 2)
40  sector data offset
42  sector header offset
44  block header offset (or negative if absent)

=================
SECTOR

The sectors are not a fixed size and maybe different. All sectors in an mdump file will be the same
size though. The following shows the common sector structure but this can vary in sizes.  
0   sector header 
      0xFF
      sector number (1 byte)
      medium name (10 bytes)
14  block header 
      file number (1 byte)
      block number  (1 byte)
16  data (512 bytes) 
=================



Notes:
* Some parts of this format are for potential future expansion and have not been implemented in
  Q-emuLator or mdump 
* There are two versions of mdump, 1 and 2, and they produce images that are
  quite different. One way to differentiate if needed is to look at the flags (offset 36), mdump 1
  (only) sets the "true physical order" flag 
* The mdump 2 images can be very big for damaged cartridges (there are extra copies of bad sectors 
  at the end, which can be safely ignored) There maybe multiple copies of a sector, the first one 
  found will usually be OK.  
* Some prerelease versions of mdump2 had a bug where the block header was always set to zero. It can be
  reconstructed from the microdrive map (sector 0). mdump2qlay automatically reconstructs these.
* mdump 2 images have a checksums, but mdump 1 images don't, and there is in general no benefit in
  reproducing the errors of damaged sectors, so Q-emuLator chooses to just always recomputed the
  checksum 
* Data is in 68000 big endian format, i.e. x86 needs to convert short and int to little endian.

Some differences with QLAY format are:
* Header and variable offsets and sizes 
* Sectors can be out of order, QLAY are always in order.
* Unreadable sectors may be missing (but sector 0 is always readable, otherwise mdump fails) 
* No preambles and gaps Extra sector copies at the end for microdrive preservations, but readers should
  ignore them (the best copy is always in the main part of the image) 
* QLAY requires valid checksums for the sectors.
