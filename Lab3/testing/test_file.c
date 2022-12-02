#include <stdio.h>
#include <stdlib.h>

#define FRAMES 256
#define SIZE 256

#define Offset(addr) (addr & 0x00FF)
#define PageNr(addr) ((addr & 0xFF00) >> 8)

typedef enum available {FREE, TAKEN} available;

int memory[FRAMES*SIZE]; // the memory 

available framemap[FRAMES] = {FREE};

typedef enum pte_status {ALLOCATED, LAZY, SHARED} pte_status;

typedef struct pt_entry {
  int frame;
  pte_status status;  
  struct pt_entry *copy;
} pt_entry;

typedef struct array {
  int pages;
  pt_entry *pagetable;   
} array;

int find_free() {
  for(int i = 0; i < FRAMES; i++) {
    if( framemap[i] == FREE ) {
      framemap[i] = TAKEN;
      return i;
    }
  }
  return -1;
}

void delete(array *arr) {
  int pages = arr->pages;
  //printf("delete array, freeing frames: ");
  for( int i = 0; i < pages; i++) {
    pt_entry *entry =  &arr->pagetable[i];

    switch(entry->status) {
    case ALLOCATED:
      printf(" %d", entry->frame);
      framemap[entry->frame] = FREE;
      break;
    case LAZY:
      break;
    case SHARED: 
      // unlink and update
      pt_entry *prev = entry;
      while(prev->copy != entry)
	    prev = prev->copy;

      prev->copy = entry->copy;

      if(prev->copy == prev) {
	    prev->status = ALLOCATED;
      }
    }
  }
  printf("\n");
  free(arr->pagetable);
  free(arr);
  return;
}


int main(int argc, char *argv[]){

    char* filename;

    if(argc > 1){
        filename = argv[1];
    }
    else{
        printf("Too few argumentos\n");
        exit(0);
    }
    
    char line[8];
    int length;
    FILE * file = fopen (filename, "r"); 

    int page;
    int offset;
    
    while (fgets(line, sizeof(line), file)) {
        page = extract_page(atoi(line));
        offset = extract_offset(atoi(line));
    }


    


    exit(0);
}