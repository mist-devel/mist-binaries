// qemu2qlay 
// converts q-emulator mdv images into qlay mdv format 
//
// (c) 2015 by Till Harbaum
// https://github.com/mist-devel
// 
// Copyright (c) 2015 Till Harbaum <till@harbaum.org> 
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
#include <string.h>
#include <assert.h>

#define MAX_SECTORS 255

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

typedef struct {
  unsigned char sec_hdr[14];
  unsigned char block_hdr[2];
  unsigned char data[512];
} __attribute__((packed)) qlem_sector_t;

// buffer for mdv file
mdv_entry_t buffer[MAX_SECTORS];

unsigned short sum(unsigned char *p, int len) {
  unsigned short v = 0x0f0f;
  while(len--)
    v += *p++;

  return v;
}

typedef struct {
  char magic[8];   // Mdv*Dump
  int a;
  int b;
  short c;
  char sectors0;
  char sectors1;
  char stuff[26];
} __attribute__((packed)) qlem_hdr_t;

int main(int argc, char **argv) {
  FILE *in, *out;

  if(argc < 2) {
    printf("Usage: qemu2qlay mdv_in <mdv_out>\n");
    printf("       mdv_in will be overwritten if no mdv_out is given\n");
    return 0;
  }

  // do some sanity tests in the internal structures
  assert(sizeof(hdr_t) == 28);
  assert(sizeof(sector_t) == 658);
  assert(sizeof(mdv_entry_t) == 686);
  assert(sizeof(qlem_sector_t) == 528);

  // clean output buffer
  int i;
  for(i=0;i<MAX_SECTORS;i++) {
    memset(&buffer[i], 0, sizeof(mdv_entry_t));
    
    // setup header
    buffer[i].hdr.preamble[10] = 0xff;
    buffer[i].hdr.preamble[11] = 0xff;
    buffer[i].hdr.csum = 0x0f0f;

    // setup block header
    buffer[i].sec.bh_preamble[10] = 0xff;
    buffer[i].sec.bh_preamble[11] = 0xff;
    buffer[i].sec.bh_csum = 0x0f0f;

    // data
    buffer[i].sec.data_preamble[6] = 0xff;
    buffer[i].sec.data_preamble[7] = 0xff;
    buffer[i].sec.data_csum = 0x0f0f;
    memset(buffer[i].sec.extra_byte, 0x5a, 
	   sizeof(buffer[i].sec.extra_byte));
  }


  if(!(in = fopen(argv[1], "rb"))) {
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

  if((size-sizeof(qlem_hdr_t))%(512+16) != 0) {
    fprintf(stderr, "Input file size error\n");
    return -1;
  }

  qlem_hdr_t hdr;
  
  if(fread(&hdr, sizeof(qlem_hdr_t), 1, in) != 1) {
    fprintf(stderr, "Error reading header\n");
    perror("Error:");
    return -1;
  }

  if(strcmp(hdr.magic, "Mdv*Dump") != 0) {
    fprintf(stderr, "Input file is not a qlem mdv image\n");
    return -1;
  }

  int sectors = (size-sizeof(qlem_hdr_t))/(512+16);
  printf("Converting %d sectors ...\n", sectors );  

  for(i=0;i<sectors;i++) {
    qlem_sector_t qlem_sector;
    
    if(fread(&qlem_sector, sizeof(qlem_sector_t), 1, in) != 1) {
      fprintf(stderr, "error reading sector %d\n", i);
      return -1;
    }

    // copy sector header
    memcpy(&buffer[i].hdr.ff, qlem_sector.sec_hdr, sizeof(qlem_sector.sec_hdr));
    // set checksum
    buffer[i].hdr.csum = sum(&buffer[i].hdr.ff, sizeof(qlem_sector.sec_hdr));

    // copy block header
    memcpy(&buffer[i].sec.file, qlem_sector.block_hdr, sizeof(qlem_sector.block_hdr));
    // set checksum
    buffer[i].sec.bh_csum = sum(&buffer[i].sec.file, sizeof(qlem_sector.block_hdr));
    
    // copy data
    memcpy(&buffer[i].sec.data, qlem_sector.data, sizeof(qlem_sector.data));
    // set checksum
    buffer[i].sec.data_csum = sum((char*)&buffer[i].sec.data, sizeof(qlem_sector.data));
  }

  fclose(in);

  out = fopen(argv[(argc==3)?2:1], "wb");
  if(!out) {
    fprintf(stderr, "Error opening output file\n");
    perror("Error:");
    return -1;
  }

  if(fwrite(buffer, sizeof(mdv_entry_t), MAX_SECTORS, out) != MAX_SECTORS) {
    fprintf(stderr, "Error writing qlay image\n");
    perror("Error:");
    return -1;
  }

  fclose(out);

  return 0;
}
