#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int array[n];
    int tmp;

    for(int i = 0; i < n; i++){
        tmp = array[i];
        scanf("%d", tmp);
    }

    for(int j = 0; j < n; j++){
        tmp = array[j];
        printf("%d",  tmp);
    }

    return 0;
}