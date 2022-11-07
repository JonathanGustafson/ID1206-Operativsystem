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

    pthread_create(&t1, NULL, thread_func, &i);
    pthread_create(&t2, NULL, thread_func, &j);

    printf("I am the main thread");

    return 0;
}