#include <stdio.h>

int main(){

    int array[3][5];
    int tmp;
    char *c;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &tmp);
            array[i][j] = tmp;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", tmp);
        }
        printf("\n");
    }


    return 0;
}