// mdump2qlay v1.1
// converts mdump (q-emulator) mdv images into qlay mdv format 
//
// (c) 2015 by Till Harbaum
// https://github.com/mist-devel
// 
// Copyright (c) 2015 Till Harbaum <till@harbaum.org> 
//
// 2021 June squidrpi
//   Mostly rewritten to handle mdump v2 and correctly follow the 
//   mdump specification. Fixes broken mdump v2 files using the sector 0 map.
//
/////////////////////////////////////////////////////////////////////
// 
// This source file is free software: you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published 
// by the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version. 
// 
// This source file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License 
// along with this program.  If not, see <http://www.gnu.org/licenses/>. 
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_SECTORS 255

// QLAY file structure
typedef struct {
  unsigned char preamble[12];   // 10*0, 2*ff
  unsigned char ff;  
  unsigned char snum;  
  char name[10];
  unsigned char rnd[2];
  unsigned short csum;
} __attribute__((packed)) hdr_t;

typedef struct {
  unsigned char bh_preamble[12];   // 10*0, 2*ff
  unsigned char file;
  unsigned char block;
  unsigned short bh_csum;

  unsigned char data_preamble[8];   // 6*0, 2*ff
  unsigned char data[512];
  unsigned short data_csum;

  unsigned char extra_byte[120];
} __attribute__((packed)) sector_t;

typedef struct {
  hdr_t hdr;
  sector_t sec;
} mdv_entry_t;

//No longer valid as this sector is variable in size
//Kept for documenting the layout
//typedef struct {
//  unsigned char sec_hdr[14];
//  unsigned char block_hdr[2];
//  unsigned char data[512];
//} __attribute__((packed)) mdump_sector_t;

// buffer for mdv file
mdv_entry_t buffer[MAX_SECTORS];

unsigned short sum(unsigned char *p, int len) {
  unsigned short v = 0x0f0f;
  while(len--)
    v += *p++;

  return v;
}

// mdump file header structure
//This data is 68000 big endian
typedef struct {
  char magic[8];            // Mdv*Dump
  int header_len;           // *unused*
  int offset_MDV;           // offset to MDV sector data
  short bytes_MDV;          // bytes per MDV sector
  unsigned char sectors0;   // number of sectors in dump
  unsigned char sectors1;   // number of sectors in original MDV
  int offset0;              // offset of sector renumbering table (or NULL) *unused*
  int offset1;              // offset of sector map (or NULL) *future* 
  int offset2;              // offset of global sector header (or NULL) *unused*
  int dumptype;             // dump type/extension: pointer to linked list of extensions (or NULL) *unused*
  int flags;                // flags, first byte is mdump version, other flags not currently used
  short sector_data;        // Offset to start of sector data
  short sector_header;      // Offset to start of sector header
  short block_header;       // Offset to block header or negative if absent
} __attribute__((packed)) mdump_hdr_t;

mdump_hdr_t mdump_hdr;

// sector0 microdrive sector map
// Use this to detect and fix sector block head errors
typedef struct {
  unsigned char file;
  unsigned char block;
} __attribute__((packed)) sector0_map;

sector0_map sector0_data[MAX_SECTORS];

unsigned char mismatch_block[MAX_SECTORS];
unsigned char empty_sector[MAX_SECTORS];

int main(int argc, char **argv) {
  FILE *in, *out;
  int arg_file=1;
  int opt_i=0, opt_v=0;
  int i;

  if(argc < 2) {
    //printf("Usage: mdump2qlay mdv_in <mdv_out>\n");
    printf("Usage: mdump2qlay [-iv] mdv_in.mdv\n");
    printf("       (output filename automatically generated from input name)\n");
    printf("       -i information about file only\n");
    printf("       -v verbose output\n");

    return 0;
  }

  for (i = 1;i < argc;i++) {
    if (strcasecmp(argv[i],"-i") == 0) {
      opt_i=1;
      arg_file++; 
    }
    if (strcasecmp(argv[i],"-v") == 0) {
      opt_v=1;
      arg_file++; 
    }
  }  

  //Create output filename
  char outfile[FILENAME_MAX];
  strcpy(outfile, argv[arg_file]);
  outfile[strlen(outfile)-4] = '\0';
  strcat(outfile, "_qlay.mdv");

  // do some sanity tests in the internal structures
  assert(sizeof(hdr_t) == 28);
  assert(sizeof(sector_t) == 658);
  assert(sizeof(mdv_entry_t) == 686);

  // clean output buffer
  for(i=0;i<MAX_SECTORS;i++) {
    memset(&buffer[i], 0, sizeof(mdv_entry_t));
    
    // setup header
    buffer[i].hdr.preamble[10] = 0xff;
    buffer[i].hdr.preamble[11] = 0xff;
    buffer[i].hdr.csum = 0x0f0f;

    // setup block header
    buffer[i].sec.bh_preamble[10] = 0xff;
    buffer[i].sec.bh_preamble[11] = 0xff;
    buffer[i].sec.file = 0xFD;      //default to empty block
    buffer[i].sec.block = 0x00;
    buffer[i].sec.bh_csum = 0x0f0f;

    // data
    buffer[i].sec.data_preamble[6] = 0xff;
    buffer[i].sec.data_preamble[7] = 0xff;
    buffer[i].sec.data_csum = 0x0f0f;
    memset(buffer[i].sec.extra_byte, 0x5a, 
	   sizeof(buffer[i].sec.extra_byte));
  }

  if(!(in = fopen(argv[arg_file], "rb"))) {
    fprintf(stderr, "Error opening input file\n");
    perror("Error:");
    return -1;
  }

  // do some sanity checks on input file

  // check if file size makes sense
  int size = 0;
  fseek(in, 0, SEEK_END);
  size = ftell(in);
  fseek(in, 0, SEEK_SET);

  if(fread(&mdump_hdr, sizeof(mdump_hdr_t), 1, in) != 1) {
    fprintf(stderr, "Error reading header\n");
    perror("Error:");
    return -1;
  }

  //Endianness conversion from 68k to x86
  mdump_hdr.bytes_MDV = __builtin_bswap16(mdump_hdr.bytes_MDV);
  mdump_hdr.offset_MDV = __builtin_bswap32(mdump_hdr.offset_MDV);
  mdump_hdr.sector_data = __builtin_bswap16(mdump_hdr.sector_data);
  mdump_hdr.sector_header = __builtin_bswap16(mdump_hdr.sector_header);
  mdump_hdr.block_header = __builtin_bswap16(mdump_hdr.block_header);
  mdump_hdr.flags = __builtin_bswap32(mdump_hdr.flags);

  if(strcmp(mdump_hdr.magic, "Mdv*Dump") != 0) {
    fprintf(stderr, "Input file is not a mdump mdv image\n");
    return -1;
  }

  //Number of sectors in this mdump image
  int sectors = mdump_hdr.sectors0;

  if (opt_i) {
    //Get medium name from next sector
    char tempbuf[12];
    fread(&tempbuf, 12, 1, in);

    printf("MDV info: \n");
    printf("       mdump version: %d\n", mdump_hdr.flags&0xFF);
    printf("         Medium name: \"%.10s\"\n", &tempbuf[2]);
    printf("   Number of sectors: %d (original MDV %d)\n", mdump_hdr.sectors0, mdump_hdr.sectors1);
    printf("  Offset to MDV data: %d\n", mdump_hdr.offset_MDV);
    printf("Bytes per MDV sector: %d\n", mdump_hdr.bytes_MDV);
    printf("Offset sector header: %d\n", mdump_hdr.sector_header);
    printf("  Offset sector data: %d\n", mdump_hdr.sector_data);
    printf(" Offset block header: %d\n", mdump_hdr.block_header);
    printf("\n");
    fclose(in);
    return 0;
  }

  printf("mdump version %d\n", mdump_hdr.flags&0xFF);
  printf("Converting %d sectors ...\n", sectors );  

  char sector_list[MAX_SECTORS];
  memset(&sector_list, 0, sizeof(sector_list));
  memset(&mismatch_block[0], 0x0, sizeof(mismatch_block)-1);
  memset(&empty_sector[0], 0x0, sizeof(empty_sector)-1);

  //mdump sectors size isnt fixed
  char *mdump_sector = malloc(mdump_hdr.bytes_MDV);

  for(i=0;i<sectors;i++) {
    unsigned char cursec, sfile, sblock;
    
    if(fread(mdump_sector, mdump_hdr.bytes_MDV, 1, in) != 1) {
      fprintf(stderr, "error reading sector %d\n", i);
      return -1;
    }

    cursec = mdump_sector[1];

    //Check for duplicate sectors
    if (sector_list[cursec] != 0) {
        printf("Skipping duplicate sector %d\n",cursec);
        continue;
    }
    sector_list[cursec] = 1;

    // Special handling of sector 0, read in the sector map for validating the mdump
    // as sometimes the file/block information is missing from the actual sectors
    if (cursec == 0) {
        memcpy(&sector0_data, mdump_sector+mdump_hdr.sector_data, 510);
    }

    // copy sector header
    memcpy(&buffer[cursec].hdr.ff, mdump_sector+mdump_hdr.sector_header, 14);
    // set checksum
    buffer[cursec].hdr.csum = sum(&buffer[cursec].hdr.ff, 14);

    // copy block header
    memcpy(&buffer[cursec].sec.file, mdump_sector+mdump_hdr.block_header, 2);

    sfile = buffer[cursec].sec.file;
    sblock = buffer[cursec].sec.block;

//debug    printf("Sector %u file 0x%X block 0x%X\n", cursec, sfile, sblock);

    // Detect and fix a number of potential issues in the mdump source file
    if (sector0_data[cursec].file == 0xFF && sfile != 0xFD) {
      //Fix wrong empty or faulty sector block marker
      if (opt_v) {
        printf("Fixing empty %u sector 0x%X 0x%X map 0x%X 0x%X\n", cursec, sfile, 
               sblock, sector0_data[cursec].file, sector0_data[cursec].block);
      }
      buffer[cursec].sec.file = 0xFD;
      buffer[cursec].sec.block = sector0_data[cursec].block; 
      empty_sector[cursec] = 1;
    }
    if (sector0_data[cursec].file != 0xFF) { // Ignore 0xFF file
      if (sfile != sector0_data[cursec].file || sblock != sector0_data[cursec].block) {
        if (opt_v) {
          printf("Fixing mismatch %u sector 0x%X 0x%X map 0x%X 0x%X\n", cursec, sfile, 
                sblock, sector0_data[cursec].file, sector0_data[cursec].block);
        }
        buffer[cursec].sec.file = sector0_data[cursec].file;
        buffer[cursec].sec.block = sector0_data[cursec].block;
        if (cursec) {
          mismatch_block[cursec] = 1; 
        }
      }
    }

    // set checksum after any fixes
    buffer[cursec].sec.bh_csum = sum(&buffer[cursec].sec.file, 2);
    
    // copy data
    memcpy(&buffer[cursec].sec.data, mdump_sector+mdump_hdr.sector_data, 512);
    // set checksum
    buffer[cursec].sec.data_csum = sum((char*)&buffer[cursec].sec.data, 512);
  }

  fclose(in);
  free(mdump_sector);

  out = fopen(outfile, "wb");
  if(!out) {
    fprintf(stderr, "Error opening output file\n");
    perror("Error:");
    return -1;
  }


  // Write all sectors to output file,
  // First write sector 0 then others in reverse order
  for(i=MAX_SECTORS;i>0;i--) {
    unsigned char cursec;

    cursec=i;
    if(cursec == MAX_SECTORS) cursec = 0;

    if(!fwrite(&buffer[cursec], sizeof(mdv_entry_t), 1, out)) {
      fprintf(stderr, "Error writing qlay image\n");
      perror("Error:");
      return -1;
    }

  }

  fclose(out);

  //Check for missing sectors, show warning
  for(i=0;i<sectors;i++) {
    if (sector_list[i] == 0) {
      printf("Warning: Sector missing %d\n",i);
    }
  }

  //Display any fixes for mismatch and empty sectors
  unsigned char prstr[2000];
  int flage=0,flagm=0;
  prstr[0] = '\0';
  for(i=0;i<MAX_SECTORS;i++) {
    if(empty_sector[i]) {
      flage=1;
    }
    if(mismatch_block[i]) {
      flagm=1;
    }
  }
  if (flage) {
    prstr[0] = '\0';
    for(i=0;i<MAX_SECTORS;i++) {
      char tempnum[4]; 
      if (empty_sector[i]) {
        sprintf(tempnum,"%d",i);
        strcat(prstr, tempnum);
        strcat(prstr, " ");
      }
    }
    printf("Fixed empty sectors %s\n",prstr);
  }
  if (flagm) {
    prstr[0] = '\0';
    for(i=0;i<MAX_SECTORS;i++) {
      char tempnum[4]; 
      if (mismatch_block[i]) {
        sprintf(tempnum,"%d",i);
        strcat(prstr, tempnum);
        strcat(prstr, " ");
      }
    }
    printf("Fixed mismatch blocks %s\n",prstr);
  }

  printf("\nConversion of mdump to QLAY successful.\n\n");

  return 0;
}
