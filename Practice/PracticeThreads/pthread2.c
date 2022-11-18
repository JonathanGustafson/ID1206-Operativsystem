#include <stdio.h>
#include <pthread.h>

void *thread_func(void *args){
    printf("I am thread %d\n", *(int *)args);
    return NULL;
}

int main(){

    pthread_t t1,t2;
    int i = 1;
    int j = 2;

    /*create the thread t1 and t2 with two diffefrent values (but same attributes)*/
    pthread_create(&t1, NULL, thread_func, &i);
    pthread_create(&t2, NULL, thread_func, &j);

    /*wait for the termination of t1 and t2*/
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("I am the main thread");

    return 0;
}