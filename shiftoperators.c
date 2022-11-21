#include <stdio.h>

int main(){

    volatile int a = (241 & 0xF0) >> 4; // "11110000" >> "00001111" 

    printf("%d\n", a);

    return 0;
}