#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    int array[n];
    int tmp;

    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        array[i] = tmp;
    }

    for(int j = n-1; j >= 0; j--){
<<<<<<< Updated upstream
        printf("%d\n",  array[j]);
=======
        printf("%d\n" ,  array[j]);
>>>>>>> Stashed changes
    }

    return 0;
}