#include <stdio.h>

int main(){

    int N, fizz, buzz;

    printf("Enter N:\n");
    do{
        scanf("%d", &N);
    } while(!(N >= 1 && N <= 100));

    printf("Enter Buzz:\n");
    do{
        scanf("%d", &buzz);
    } while(!(buzz >= 1 && buzz <= N));

    printf("Enter Fizz:\n");
    do{
        scanf("%d", &fizz);
    } while(!(fizz >= 1 && fizz <= buzz));

    for(int i = 1; i <= N; i++){
        if((i % buzz) == 0){
            if((i % fizz == 0)){
                printf("fizzbuzz\n");
            }
            else{
                printf("buzz\n");
            }
        }
        else if((i % fizz) == 0){
            printf("fizz\n");
        }
        else{
            printf("%d\n", i);
        }
    }

    return 0;
}