#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *thread_func(void *arg) {
    printf("%s\n", (char *)arg);
    return 0;
}

int main(){
    pthread_t thread;
    char *msg = "Hello World!";

    int createerror = pthread_create(&thread, NULL, thread_func, msg);

    /*check if there is an error creating the string, 
    if no errors, then wait for the thread to return 
    value and exit program successfully*/

    if(!createerror){ 
        pthread_join(thread, NULL);
        exit(EXIT_SUCCESS);
    }


    /*If code gets here, an error has occurred and 
    the program will exit with an error*/
    perror("pthread_create");
    exit(EXIT_FAILURE);

}