#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>  
#include <stdlib.h>

struct thread_result{
    int count;
    int thread_id;
};

int buffer = 0;
pthread_mutex_t lock;

void *thread_func(void* args) {

    struct thread_result *res = (struct thread_result*) malloc(sizeof *res);

    int count = 0;
    int pid = getpid();
    int tid = pthread_self();

    int loop = 1;

    while(loop){

        pthread_mutex_lock(&lock);
        if(buffer < 15) {
            printf("TID: %u, PID: %u, BUFFER: %d\n", tid, pid, buffer);
            buffer++;
            pthread_mutex_unlock(&lock);
            count++;
            sleep(1);
        }
        else {
            pthread_mutex_unlock(&lock);
            loop = 0;
        }
        
    }

    res->count = count;
    res->thread_id = tid;

    return (void*)res;


}

int main(){

    pthread_t t1, t2, t3;

    pthread_mutex_init(&lock, NULL);

    void *out_void1;
    void *out_void2;
    void *out_void3; 

    struct thread_result *out1;
    struct thread_result *out2;
    struct thread_result *out3;
    
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);
    pthread_create(&t3, NULL, thread_func, NULL);


    // Wait for the threads to exit.
    pthread_join(t1, &out_void1);
    pthread_join(t2, &out_void2);
    pthread_join(t3, &out_void3);

    out1 = out_void1;
    out2 = out_void2;
    out3 = out_void3;

    printf("TID %u worked on the buffer %d times\n", out1->thread_id, out1->count);
    printf("TID %u worked on the buffer %d times\n", out2->thread_id, out2->count);
    printf("TID %u worked on the buffer %d times\n", out3->thread_id, out3->count);

    pthread_mutex_lock(&lock);
    printf("Total buffer access: %d\n", buffer);
    pthread_mutex_unlock(&lock);

    pthread_mutex_destroy(&lock);

    return 0;

}