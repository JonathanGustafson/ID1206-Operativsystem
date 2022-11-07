#include <stdio.h>
#include <pthread.h>

void *thread_func(void *args){
    printf("I am thread %d\n", (void )args);
}

int main(){

    pthread_t t1,t2;
    int i = 1;
    int j = 2;

    pthread_create(&t1, NULL, thread_func, &i);
    pthread_create(&t2, NULL, thread_func, &j);

    printf("I am the main thread");

    return 0;
}