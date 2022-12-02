#include <stdio.h>
#include <stdlib.h>

//assumes 16bit input
int extract_page(int addr){
    return (addr & 0xFF00) >> 8;
}

int main(){

    unsigned char buffer[256];
    FILE *file;
    file = fopen("data/BACKING_STORE.bin","rb");  // r for read, b for binary
    int indexes[] = {64815,53683,40185,28781,24462,45688,40891}; //expected res{75,108,0,0,,,}

    for(int i = 0; i < 7; i++){
        
        fseek(file, exctract_page(indexes[i]), SEEK_SET);
        fread(buffer,sizeof(buffer),1,file);

        //for(int i = 0; i<256; i++)
        printf("%u ", buffer[0]); 
    }

    printf("\n");
    return 0;
}