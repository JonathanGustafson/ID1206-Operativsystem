#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *thread_func1(void *args){
    while(1){
        printf("Thread 1");
        counter++;
        sleep(1);

        if(counter == 2){
            pthread_exit();
        }
    }
}

thread_func2(void* args){ 
    
}

int main(){

    pthread_t t1,t2;
    int i = 1;
    int j = 2;

    pthread_create(&t1, NULL, thread_func1, &i);
    pthread_create(&t2, NULL, thread_func2, &j);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("I am the main thread");

    return 0;
}