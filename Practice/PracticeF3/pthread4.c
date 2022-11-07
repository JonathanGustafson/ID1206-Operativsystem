#include <stdio.h>
#include <pthread.h>

struct thread_args{
    int a;
    double b;
};

struct thread_result {
    long x;
    double y;
};

void *thread_func(void *args_void){
    struct thread_args *args = args_void;
    struct thread_result *res = malloc();
}

int main(){

    pthread_t thread;
    struct thread_args in = {.a = 10, .b = 3.14};
    void *out_void;
    struct thread_result *out;


    return 0;
}