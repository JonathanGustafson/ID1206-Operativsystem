#include <stdio.h>
#include <stdlib.h>

int main(){

    char * file_buffer = 0;
    int length;
    FILE * f = fopen ("Loremipsum.txt", "r");

    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    file_buffer = malloc (length);
    fread (file_buffer, 1, length, f);
    fclose (f);

    printf("%s\n", file_buffer);

    return 0;
}