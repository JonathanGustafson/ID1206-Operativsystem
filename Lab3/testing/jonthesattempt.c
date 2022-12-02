#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FRAMES 256
#define SIZE 256

int memory[FRAMES][SIZE]; // the memory 
bool frame_available_map[FRAMES]; //true is available

//find first free frame
int find_free() {
  for(int i = 0; i < FRAMES; i++) {
    if(frame_available_map[i] == false) {
      frame_available_map[i] = true;
      return i;
    }
  }
  return -1;
}

//assumes 16bit input
int extract_page(int addr){
    return (addr & 0xFF00) >> 8;
}

//assumes 16bit input
int extract_offset(int addr){
    return addr & 0x00FF;
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