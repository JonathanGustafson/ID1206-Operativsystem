#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FRAMES 256
#define SIZE 256

#define Offset(addr) (addr & 0x00FF)
#define PageNr(addr) ((addr & 0xFF00) >> 8)

int memory[FRAMES*SIZE]; // the memory 
bool frame_available_map[FRAMES]; //true is available

//find first free frame
int find_free() {
  for(int i = 0; i < FRAMES; i++) {
    if( frame_available_map[i]) {
      frame_available_map[i] = false;
      return i;
    }
  }
  return -1;
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