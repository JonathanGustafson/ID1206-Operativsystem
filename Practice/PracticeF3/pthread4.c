#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_args{
    int a;
    double b;
};

struct thread_result {
    long x;
    double y;
};

/*
Note:
res->x is res.x for a struct, and a struct is like a class in java

the thread_func must (?) be declared with return type and argument as void*
*/
void *thread_func(void *args_void){
    struct thread_args *args = args_void;
    struct thread_result *res = malloc(sizeof *res);

    res->x = 10 + args->a;
    res->y = args->a * args->b;
    return res;
}

int main(){

    pthread_t thread;
    struct thread_args in = {.a = 20, .b = 3.14};

    /*we create this variable to save the results from the thread.
    Since the thread_func returns a void* type we need to create a
    separate variable to store results. Thats why we can't just save
    it to the thread_result *out*/ 
    void *out_void; 
    struct thread_result *out;

    pthread_create(&thread, NULL, thread_func, &in);
    pthread_join(thread, &out_void);
    out = out_void;
    printf("out -> x = %ld\tout -> b = %f\n", out->x, out->y);
    free(out);

    return 0;
}