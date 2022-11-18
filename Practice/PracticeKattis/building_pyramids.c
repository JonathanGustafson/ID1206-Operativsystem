#include <stdio.h>

int main(){

    int n;
    int layers = 0;
    int next_layer = 1;
    int next_layer_width = 1;
    scanf("%d", &n);

    while (n >= next_layer)
    {
        n -= next_layer;
        layers++;
        next_layer_width += 2;
        next_layer = next_layer_width * next_layer_width;

    }


    printf("%d\n", layers);

    return 0;
}

/*

1
9
121

*/