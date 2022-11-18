#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    
    /*
    struct cat
    {
        char* black;
        char* red;
        char* dilution;
    };
    */

    char* female;
    char* male;
    char* gene_pool[12];

    scanf("%s", &female);
    scanf("%s", &male);

    if(strcmp(female, "Red")){
        gene_pool[0] = "";
    }

    return 0;
}