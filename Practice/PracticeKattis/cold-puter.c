#include <stdio.h>

int main(){

    int size;
    //printf("Enter size\n");
    do{
            scanf("%d", &size);
        } while (!(size >= 1 && size <= 100));

    int array[size];
    int tmp;

    for(int i = 0; i < size; i++){
        do{
            //printf("Enter number %d: \n", (i+1));
            scanf("%d", &tmp);
            array[i] = tmp;
        } while (!(tmp >= -1000000 && tmp <= 1000000));
        
    }

    int count = 0;

    for(int i = 0; i < size; i++){
        if(array[i] < 0){
            count++;
        }
    }
    
    printf("%d\n", count);

    return 0;
}
