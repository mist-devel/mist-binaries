/* mdvtool */
/* another quick'n dirty tool to deal with microdrive images
 * Original author unknown */

/* 
 * Create MDV function added 
 * Fixed ZIP import
 * Squished a few bugs 
 * 
 * (c)2019 Jason Lucas
 * 
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <zip.h>


#include "mdv.h"

FILE *mdv = NULL;

#define SWAP16(a)   ((((a)&0xff)<<8)|(((a)&0xff00)>>8))
#define SWAP32(a)   ((((a)&0xff)<<24)|(((a)&0xff00)<<8)|(((a)&0xff0000)>>8)|(((a)&0xff000000)>>24))

void hexdump(void *data, int size) {
  unsigned char i, b2c;
  int n=0;
  char *ptr = data;

  if(!size) return;

  while(size>0) {
    printf("%04x: ", n);

    b2c = (size>16)?16:size;
    for(i=0;i<b2c;i++)      printf("%02x ", 0xff&ptr[i]);
    printf("  ");
    for(i=0;i<(16-b2c);i++) printf("   ");
    for(i=0;i<b2c;i++)      printf("%c", isprint(ptr[i])?ptr[i]:'.');
    printf("\n");
    ptr  += b2c;
    size -= b2c;
    n    += b2c;
  }
}
// buffer for mdv file
mdv_entry_t buffer[MAX_SECTORS];
unsigned char sector_table[MAX_SECTORS];
char medium_name[10];
unsigned char files[256][256];

int isbyte(unsigned char *c, unsigned char byte, int len) {
  while(len--)
    if(*c++ != byte)
      return 0;

  return 1;
}

unsigned short sum(unsigned char *p, int len) {
  unsigned short v = 0x0f0f;
  while(len--)
    v += *p++;

  return v;
}

unsigned short get_index(int s) {
  int i;
  for(i=0;i<MAX_SECTORS;i++)
    if(sector_table[i] == s)
      return i;

  // not found
  return 0xffff;
}

int check_preamble(unsigned char *p, int zeros) {
  if(!isbyte(p, 0, zeros)) 
    return -1;

  if(!isbyte(p+zeros, 0xff, 2)) 
    return -1;

  return 0;
}


// get entry from mapping table in sector 0
int get_mapping_entry(int i) {
  return 256*buffer[0].sec.data[2*i] + buffer[0].sec.data[2*i+1];
}

// compare mapping table with sector number of sector header
int mdv_check_mapping(void) {
  int i;
  for(i=0;i<255;i++) {
    // mapping entry from sector 0
    int me = get_mapping_entry(i);
    // check only used entries
    if(me != 0xff00) {
      // file/block entry as stored inside block header
     
      unsigned short phys = get_index(i);
      
      // check for valid physical entry
      if(phys>255){
        printf("WARNING: Invalid physical entry:%d\n",phys);
        return -1;
      }

      int me_bh = 256*buffer[phys].sec.file + buffer[phys].sec.block;

      if(me != me_bh)
	printf("%3d: %04x / %04x\n",  i, me, me_bh);
    } else {
      // this sector must not be used at all
      
      unsigned short phys = get_index(i);
      
      if(phys != 0xffff) {
        int me_bh = 256*buffer[phys].sec.file + buffer[phys].sec.block;
        printf("index = %d (%x/%x)\n", phys, me, me_bh);
      }
    }
  }
  return 0;
}

void file_dump_chain(int f) {	
  int j;

  // dump block chain
  for(j=0;j<256;j++) {
    if(files[f][j] != 255) 
      printf("%s%d", j?", ":"", files[f][j]);
  }
  printf("\n");
}
void mdv_create(void){
  if (!strlen(medium_name)) strncpy(medium_name,"MD        ",10);
	printf("Creating mdv\n");
	int rand=random();
	
	for(int c=0;c<MAX_SECTORS;c++){

		buffer[c].hdr.preamble[10]=0xFF;
		buffer[c].hdr.preamble[11]=0xFF;
		buffer[c].hdr.ff=0xFF;
		buffer[c].hdr.snum=c;
		buffer[c].hdr.rnd=rand;
		buffer[c].sec.bh_preamble[10]=0xFF;
		buffer[c].sec.bh_preamble[11]=0xFF;
		buffer[c].sec.data_preamble[6]=0xFF;
		buffer[c].sec.data_preamble[7]=0xFF;
		buffer[c].sec.file=0xFD;
		strncpy(buffer[c].hdr.name,medium_name,10);
		for(int d=0;d<512;d++) buffer[c].sec.data[d]=0x00;
		for(int d=0;d<120;d++) buffer[c].sec.extra_byte[d]=0x5A;		
		if(c==0){ //Sector 0 - File map
			buffer[c].sec.file=0x80;
			for(int d=0;d<512;d+=2) {
				buffer[c].sec.data[d]=0xFD;
				buffer[c].sec.data[d+1]=0x00;
			}
			buffer[c].sec.data[0]=0xF8;
			buffer[c].sec.data[2]=0x00;
		}
		if(c==1){//Root Dir
			buffer[c].sec.file=0x00;
      //Set Dir length to 1 entry (64 bytes)
			buffer[c].sec.data[2]=0x00;
      buffer[c].sec.data[3]=0x40;
		}
		buffer[c].hdr.csum=sum(&buffer[c].hdr.ff,14);
		buffer[c].sec.bh_csum=sum(&buffer[c].sec.file,2);
		buffer[c].sec.data_csum=sum(buffer[c].sec.data,512);
	}
	return ;

}

int mdv_load(char *name) {

  int size=sizeof(buffer);
  memset(medium_name, 0, sizeof(medium_name));
  memset(sector_table, 0xff, sizeof(sector_table));
  memset(files, 0xff, sizeof(files));
  if(!strcasecmp(name, "create")){
    mdv_create();
  } else {
    printf("Loading %s ...\n", name);
    mdv = fopen(name, "rb");
    if(!mdv) {
      fprintf(stderr, "Unable to open %s\n", name);
      return -1;
    }

    // check file size
    fseek(mdv, 0, SEEK_END);
    size = ftell(mdv);
    fseek(mdv, 0, SEEK_SET);

    if(size == sizeof(buffer)) {
      // load qlay format file
      if(fread(buffer, sizeof(mdv_entry_t), MAX_SECTORS, mdv) != MAX_SECTORS) {
        perror("fread()");
        return -1;
      }
    } else {
      fprintf(stderr, "Uexpected file size\n");
      
      // check if it's a qemulator image and load and convert it
      
      
      return -1;
    }
  }
  // check all chunks
  int i, free=0;
  int used = 0;
  for(i=0;i<MAX_SECTORS;i++) {
    /* -------------------- header checks ---------------- */
    hdr_t *hdr = &buffer[i].hdr;
    
    // check preamble
    if(check_preamble(hdr->preamble, 10) != 0) {
      fprintf(stderr, "Header @%d: Preamble check failed\n", i);
      return -1;
    }
    
    if(hdr->ff != 0xff) {
      // silently ignore unused entries
      //      fprintf(stderr, "Header %d ff check failed\n", i);
    } else {
      if(hdr->csum != sum(&hdr->ff, 14)) {
        printf("Header @%d: checksum failed\n", i);
        return -1;
      }
      
      if(!medium_name[0]) {
        memcpy(medium_name, hdr->name, 10);
      } else {
        if(memcmp(medium_name, hdr->name, 10) != 0) {
        fprintf(stderr, "Header @%d: Medium name mismatch ""(\"%.10s\" != \"%.10s\")\n", i, hdr->name, medium_name);
        return -1;
        }
      }
      
      if(sector_table[i] != 0xff) {
        fprintf(stderr, "Header @%d: Multiple sector number %d\n",i, hdr->snum);
        return -1;
      }
      sector_table[i] = hdr->snum;
      
      /* -------------------- sector checks ---------------- */
      sector_t *sec = &buffer[i].sec;
      
      // check preamble
      if(check_preamble(sec->bh_preamble, 10) != 0) {
	fprintf(stderr, "Sector @%d: Block header preamble check failed\n", i);
	return -1;
      }
      
      if(sec->bh_csum != sum(&sec->file, 2)) {
	printf("WARNING: Sector @%d(%d): Block header checksum failed\n", i, hdr->snum);
      }
      
      if(sec->data_csum != sum(sec->data, 512)) {
	printf("WARNING: Sector @%d(%d): Data checksum failed %x != %x\n", 
	       i, hdr->snum, sec->data_csum, sum(sec->data, 512));
      }
      
      // save the file index if it's not a free sector (file == 253)
      if(sec->file == 253)
	free++;
      else {
	if(files[sec->file][sec->block] != 255) {
	  fprintf(stderr, "Sector @%d: Multiple file/block %d/%d\n",
		  i, sec->file, sec->block);
	  return -1;
	}
	
	used++;
	files[sec->file][sec->block] = hdr->snum;
      }
    }
  }

  printf("Medium name: \"%.10s\"\n", medium_name);

  // check if we are having gaps in the sector list
  for(i=0;i<MAX_SECTORS;i++) {
    if(sector_table[i] != 255) {
      // for every sector != 0 the previous sector must also exist
      if(sector_table[i] > 0) {
	if(get_index(sector_table[i]-1) == -1) 
	  fprintf(stderr, "WARNING: Missing sector %d\n", sector_table[i]-1);
      }
    }
  }

  printf("Total sectors: %d (%d bytes)\n", used+free, (used+free)*512);
  printf("Sectors used: %d (%d bytes)\n", used, used*512);
  printf("Sectors free: %d (%d bytes)\n", free, free*512);

  return 0;
}

sector_t *file_get_sector(int file, int block) {
  if(files[file][block] == 255) return NULL;
  return &buffer[get_index(files[file][block])].sec;
}

void mdv_files_check() {
  // check all files
  int i, used = 0;
  for(i=0;i<256;i++) {
    // check length of block chain and whether its continuous
    int j, bused = 0;
    for(j=0;j<256;j++) {
      if(files[i][j] != 255) {
	bused++;

	if((j > 0) && (files[i][j-1] == 255)) 
	  printf("File %d: Missing entry for block %d\n", i, j-1);
      }
    }

    if(bused) 
      if((i > 0)&&(i < 128))
	used++;
  }

  printf("Number of regular files: %d\n", used);

  // print infos from some special files
  if(files[249][0] != 0xff) {
    printf("List of defect sectors: ");
    file_dump_chain(249);
  }
}

file_t *file_get_entry(int i) {
  // each sector can hold 8 directory entries
  sector_t *s = file_get_sector(0,i/8);
  if(!s) {
    printf("Missing directory sector %d\n", i/8);
    return NULL;
  }

  return (file_t*)(s->data+sizeof(file_t)*(i&7));
}

int file_size(int i) {
  file_t *f = file_get_entry(i);
  if(!f) return -1;

  return SWAP32(f->length);
}

char *file_name(int i) {
  file_t *f = file_get_entry(i);
  if(!f) return NULL;
  
  return f->name;
}

int file_open(char *name) {
  int entries = file_size(0)/sizeof(file_t);
  if(entries < 2) return -1;

  // scan all entries
  int j;
  for(j=1;j<entries;j++) {
    if(strcmp(file_name(j), name) == 0)
      return j;
  }
  return -1;
}

void file_export(char *name) {
  int f = file_open(name);
  if(f < 0) {
    printf("File %s not found\n", name);
    return;
  }

  int size = file_size(f)-64; //Subtract 64 bytes for qdos header
  printf("Exporting %d bytes to '%s' ... ", size, name);

  FILE *out = fopen(name, "wb");
  if(!out) {
    printf("\nERROR: Unable to open %s for writing\n", name);
    return;
  }

  int block = 0;
  while(size) {
    sector_t *s = file_get_sector(f, block);
    if(!s) {
      printf("\nERROR: File %s is missing block %d\n", name, block);
      return;
    }
  
    // block 0 contains a file header which we need to skip
    int offset = (!block)?sizeof(file_t):0;
    int bytes2copy = (size>512-offset)?(512-offset):size;

    if(fwrite(s->data+offset, 1l, bytes2copy, out) != bytes2copy) {
      printf("\nERROR: Writing %s\n", name);
      fclose(out);
      return;
    }
    block++;
    size -= bytes2copy;
  }

  fclose(out);
  printf("ok!\n");
}

int file_exists(int i) {
  return(files[i][0] != 0xff);
}

void mdv_files_list_chain(int f) {
  printf("Sectors: ");
  file_dump_chain(f);
}

void show_file_entry(file_t *f) {
  printf("%16s %5d %s, V:%x, U:%d, B:%d", f->name,
	 SWAP32(f->length), (f->type<=1)?(f->type?"EXEC":"DATA"):"????",
	 SWAP32(f->version), SWAP32(f->last_update), SWAP32(f->last_backup));

  if(f->type == 1)
    printf(" info: %d/%d", SWAP32(f->info[0]), SWAP32(f->info[1]));

  printf("\n");
}

void mdv_files_list_chains() {
  printf("File chains:\n");
  
  int f;
  for(f=0;f<256;f++) {
    sector_t *s = file_get_sector(f,0);
    if(s) {
      printf("=== file %d ===\n", f);
      if((f>0) && (f<128)) {
	printf("Directory entry: ");
	show_file_entry((file_t*)s->data);
      }
      mdv_files_list_chain(f);
    }
  }
}

void mdv_close() {
  if(mdv)
    fclose(mdv);
}

void mdv_show_sector_mapping() {
  int i;

  printf("File offset -> sector number\n");
  for(i=0;i<MAX_SECTORS;i++) 
    if(sector_table[i] != 255) 
      printf("%3d -> %3d\n", i, sector_table[i]);
}

void mdv_dir() {
  
  int entries = file_size(0)/sizeof(file_t);
  if(entries >= 1) {
    printf("DIR listing from directory file:\n");

    // scan all entries
    int j;
    for(j=1;j<entries;j++) {
      file_t *f = file_get_entry(j);
      if(f) show_file_entry(f);
    }
  } else
    printf("ERROR: directory file does not exist\n");

  // by scanning for files

  printf("DIR listing from file headers:\n");

  // valid files from 1 to 127
  int i;
  for(i=1;i<127;i++) {
    sector_t *s = file_get_sector(i, 0);
    if(s) show_file_entry((file_t*)s->data);
  }

  printf("Special:\n");
  for(i=128;i<255;i++) {
    if(file_exists(i)) {
      printf("<%02x> ", i);
      mdv_files_list_chain(i);
    }
  }
}

sector_t *get_free_block(int file_index,int block,int last_block){
  // get a free block
  int i, s;
  for(i=0;i<MAX_SECTORS;i++) {
    s = last_block - 13 - i;
    if(s < 0) s += MAX_SECTORS;
    if((get_mapping_entry(s) &0xff00) == 0xfd00) break;
  }

  if(i == MAX_SECTORS) {
    printf("Image full\n");
    return 0;
  }

  // set new mapping entry
  buffer[0].sec.data[2*s] = file_index;
  buffer[0].sec.data[2*s+1] = block;
  files[file_index][block] = s;

  return file_get_sector(file_index, block);
}

void file_write(file_t *file, char *data) {
  //Convert dots in file name to underscores
  for(int c=0;c<strlen(file->name);c++){
    if(file->name[c]=='.') file->name[c]='_';
  }

  
  printf("Writing file '%s' with %d bytes to mdv image ...\n",file->name, SWAP32(file->length));

  // many programs have been modified to run from floppy
  // Change them to run from microdrive

  int i, replace = 0;
  for(i=0;i<SWAP32(file->length)-5;i++) {
    if(memcmp(data+i, "flp1_", 5) == 0) {
      memcpy(data+i, "mdv1_", 5);
      replace++;
    }
  }

  if(replace) printf("!!!!INFO: Replaced %d occurances of flp1_ by mdv1_\n", replace);

  //Add 64 bytes to file length for qdos header
  file->length=SWAP32(SWAP32(file->length) +64);

  // check if file exists
  if(file_open(file->name) >= 0) {
    printf("file already exists!\n");
    return;
  }
    
  // search for a free directory entry
  int file_index = -1;
  int entries = file_size(0)/sizeof(file_t);
  // check if we need to extend the directory file
  if((entries & 7) == 7) {
    //Extend directory
    sector_t *sec = get_free_block(0,(entries/8)+1,(entries/8));
    sec->file = 0;
    sec->block = (entries/8)+1;
    sec->bh_csum = sum(&sec->file, 2);
    entries = file_size(0)/sizeof(file_t);
  }
  
  // write directory entry 
  file_index = entries;
  file_t *new_entry = file_get_entry(file_index);
  if(!new_entry) {
    fprintf(stderr, "ERROR: Locating new entry\n");
    return;
  }
  
  // write new entry
  memcpy(new_entry, file, sizeof(file_t));

  // update directory file length
  file_get_entry(0)->length = SWAP32((entries+1)*sizeof(file_t));

  //  printf("Using file %d\n", file_index);

  // write all sectors
  int last_block = 0;
  int block = 0;
  int size = SWAP32(file->length);
  while(size) {
    int blk_size = block?512:(512-sizeof(file_t));
    if(blk_size > size) blk_size = size;

    //printf("Writing block %d with %d bytes\n", block, blk_size);

    sector_t *sec = get_free_block(file_index,block,last_block);
    // update mapping entry and fill sector
    if(!block) {
      memcpy(sec->data, file, sizeof(file_t));
      memcpy(sec->data + sizeof(file_t), data, blk_size);
    } else
      memcpy(sec->data, data, blk_size);

    // adjust headers
    //   unsigned short phys = get_index(s);

    sec->file = file_index;
    sec->block = block;
    sec->bh_csum = sum(&sec->file, 2);
    last_block=files[file_index][block];
    block++;
    size -= blk_size;
    data += blk_size;

    //last_block = s;
    
  }
}

void zip_import(char *name) {

  printf("Importing from ZIP %s\n", name);

  assert(sizeof(zip_extra_qdos_t) == 72);

  struct zip *zip = zip_open(name, 0, NULL);
  if(!zip) {
    fprintf(stderr, "Error opening zip file %s\n", name);
    return;
  }

  // walk through all files stored in that zip
  int entries = zip_get_num_entries(zip, 0);
  printf("ZIP contains %d files\n", entries);
  
  int i;
  for(i=0;i<entries;i++) {
    const char *name = zip_get_name(zip, i, 0);
   
    // open that file
    struct zip_file *file = zip_fopen_index(zip, i, 0);
    if(!file) 
      fprintf(stderr, "Error opening zip file %s, skipping it\n", name);
    else {
      short unsigned int x_len,index=0,x_id;
      file_t b, *qdos = NULL;
       // parse extra fields

      const unsigned char *extra = zip_file_extra_field_get(zip, i,index,&x_id, &x_len, ZIP_FL_CENTRAL);
      if(x_id == 0xfb4a) {
        if(x_len != sizeof(zip_extra_qdos_t)) 
          fprintf(stderr, "Warning extra entry size mismatch, ignoring it\n");
        else {
          zip_extra_qdos_t *qdos_extra = NULL;
          qdos_extra = (zip_extra_qdos_t*)(extra);
          qdos = &qdos_extra->file;
          show_file_entry(qdos);
        }
      }

      // chekk file size vs 
      struct zip_stat sb;
      if(zip_stat_index(zip, i, 0, &sb) != 0)
          fprintf(stderr, "Error get file stat, skipping it\n");
      else {
        if(!(sb.valid & ZIP_STAT_SIZE))
          fprintf(stderr, "Error file size unknown, skipping it\n");
        else {
          if(qdos && (sb.size != SWAP32(qdos->length)))
            printf("WARNING: qdos/zip file size mismatch\n");
	  
          if(!qdos) {
            // create qdos file entry of none was given
            memset(&b, 0, sizeof(b));
            b.length = SWAP32(sb.size);
            b.name_len = SWAP16(strlen(name));
            strcpy(b.name, name);
            qdos = &b;
          }
	  
          // load file contents into memory
          char *buffer = (char*)malloc(sb.size);
          if(zip_fread(file, buffer, SWAP32(qdos->length)) != SWAP32(qdos->length)) 
            fprintf(stderr, "Error unzipping file %s, skipping it\n", name);
          else file_write(qdos, buffer);
          free(buffer);
        }
      }
      
      zip_fclose(file);
    }
  }
  
  zip_close(zip);

}

void file_import(char *name) {
  FILE *in = fopen(name, "rb");
  if(!in) {
    fprintf(stderr, "Unable to open input file %s\n", name);
    return;
  }

  // check file size
  fseek(in, 0, SEEK_END);
  int size = ftell(in);
  fseek(in, 0, SEEK_SET);
 
  char *buffer = malloc(size);
  if(fread(buffer, 1, size, in) != size) {
    perror("fread()");
    free(buffer);
    fclose(in);
    return;
  }

  fclose(in);

  file_t f;
  memset(&f, 0, sizeof(f));
  f.length = SWAP32(size);
  f.name_len = SWAP16(strlen(name));
  strcpy(f.name, name);

  file_write(&f, buffer);

  free(buffer);
}

void mdv_write(char *name) {
  printf("Writing mdv %s\n", name);

  // adjust checksums
  int i;
  for(i=0;i<MAX_SECTORS;i++) {
    if(buffer[i].hdr.ff == 0xff)
      buffer[i].sec.data_csum = sum(buffer[i].sec.data, 512);
  }

  FILE *out = fopen(name, "wb");
  if(!out) {
    fprintf(stderr, "Error opening output file %s\n", name);
    return;
  }

  if(fwrite(buffer, sizeof(mdv_entry_t), MAX_SECTORS, out) != MAX_SECTORS) {
    perror("fwrite()");
    fclose(out);
    return;
  }

  fclose(out);
}




void mdv_erase(void) {
  printf("Erasing MDV image ...\n");

  // mark all sectors as free
  int i;
  for(i=0;i<MAX_SECTORS;i++) {
//    unsigned short phys = get_index(i);

    // set new mapping entry

    int file = buffer[0].sec.data[2*i];
    int block = buffer[0].sec.data[2*i+1];
    sector_t *sec = file_get_sector(file, block);

    if(sec) {
      if(file) {
		printf("erasing file %d, block %d\n", file, block); 
	
	files[file][block] = 0xff;
	buffer[0].sec.data[2*i] = 0xfd;
	buffer[0].sec.data[2*i+1] = 0x00;
	
	// adjust headers
	sec->file = 0xfd;
	sec->block = 0x00;
	sec->bh_csum = sum(&sec->file, 2);
      } else {
	// leave directory intact
	//	printf("keeping dir block %d\n", block);

	// but erase it
	memset(sec->data, 0, 512);
      }
    }
  }

  // finally set the directory file length to 1 (dir file only)
  file_get_entry(0)->length = SWAP32(1*sizeof(file_t));
}

void mdv_rename(char *name) {
  char lname[11];
  strncpy(lname, name, 11);

  // expand name to 10 characters
  lname[10] = 0;
  while(strlen(lname) < 10)
    lname[strlen(lname)] = ' ';

  printf("Setting name: '%s'\n", lname);
  strncpy(medium_name,lname,10);
  int i;
  unsigned short rnd = random();
  for(i=0;i<MAX_SECTORS;i++) {
    if(buffer[i].hdr.ff == 0xff) {
      memcpy(buffer[i].hdr.name, lname, 10);
      buffer[i].hdr.rnd = rnd;
      buffer[i].hdr.csum = sum(&buffer[i].hdr.ff, 14);
    }
  }
	
}

int main(int argc, char **argv) {


  assert(sizeof(hdr_t) == 28);
  assert(sizeof(sector_t) == 658);
  assert(sizeof(file_t) == 64);


    if(argc < 3) {
      printf("Usage: mdvtool <mdv> commands\n");
      printf("   or: mdvtool create commands\n");
      printf("Commands:\n");
      printf("   create               - create a new MDV image\n");
      printf("   dir                  - list MDV contents\n");
      printf("   check_files          - check file integrity\n");
      printf("   file_chains          - list chain of sectors for each file\n");
      printf("   check_mapping        - check the sector mapping\n");
      printf("   show_mapping         - show physical/loginal sector mapping\n");
      printf("   export file_name     - export a file from the MDV image\n");
      printf("   erase                - erase the MDV image\n");
      printf("   name image_name      - rename the MDV image\n");
      printf("   import file_name     - import a file to the MDV image\n");
      printf("   zip_import file_name - import an entire ZIP archive\n");
      printf("   write file_name      - write the MDV image\n"); 
      return 0;
    }

    if(mdv_load(argv[1]) < 0) {
      mdv_close();
      return -1;
    }


  int c = 2;
  while(c < argc) {
    puts("");

    if(!strcasecmp(argv[c], "dir"))
      mdv_dir();

    else if(!strcasecmp(argv[c], "export")) {
      if(++c >= argc) {
		printf("export needs a file name as parameter\n");
		return 0;
      }

      file_export(argv[c]);
    }
    
    else if(!strcasecmp(argv[c], "import")) {
      if(++c >= argc) {
		printf("import needs a file name as parameter\n");
		return 0;
      }

      file_import(argv[c]);
    }

    else if(!strcasecmp(argv[c], "name")) {
      if(++c >= argc) {
		printf("name needs an image name as parameter\n");
		return 0;
      }

      mdv_rename(argv[c]);
    }

    else if(!strcasecmp(argv[c], "zip_import")) {
      if(++c >= argc) {
		printf("zip_import needs a file name as parameter\n");
		return 0;
      }

      zip_import(argv[c]);
    }

    else if(!strcasecmp(argv[c], "write")) {
      if(++c >= argc) {
		printf("write needs a file name as parameter\n");
		return 0;
      }

      mdv_write(argv[c]);
    }

    else if(!strcasecmp(argv[c], "check_files"))
      mdv_files_check();

    else if(!strcasecmp(argv[c], "erase"))
      mdv_erase();

    else if(!strcasecmp(argv[c], "file_chains"))
      mdv_files_list_chains();

    else if(!strcasecmp(argv[c], "check_mapping"))
      mdv_check_mapping();

    else if(!strcasecmp(argv[c], "show_mapping"))
      mdv_show_sector_mapping();

    else
      printf("Unknown command %s\n", argv[c]);

    c++;
  }

  mdv_close();

  return 0;
}

