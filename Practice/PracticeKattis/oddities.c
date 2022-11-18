#include <stdio.h>

int is_odd(int nr);

int main(){

   
    //printf("enter amount of numbers:\n");
    int size;
    scanf("%d", &size);
    int sample_input[size];

    for(int i = 0; i < size; i++){
        int tmp;
        //printf("Enter number %d:\n", i+1);
        scanf("%d", &tmp);
        sample_input[i] = tmp;
    }

    for(int i = 0; i < size; i++){
        if(is_odd(sample_input[i]))
            printf("%d is odd\n", sample_input[i]);
        else
            printf("%d is even\n", sample_input[i]);
    }

    return 0;
}

int is_odd(int nr){
    if((nr % 2) == 0) return 0;
    else return 1;
}