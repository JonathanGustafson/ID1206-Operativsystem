#include <stdio.h>
#include <pthread.h>

void *thread_func(void *message) {
printf("%s\n", (const char *)message);
return message;
}

int main(){

    pthread_t t1,t2;
    const char *message1 = "thread 1";
    const char *message2 = "thread 2";

    pthread_create(&t1, NULL, thread_func, (void *)message1);
    pthread_create(&t2, NULL, thread_func, (void *)message2);

    // Wait for the threads to exit.
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}