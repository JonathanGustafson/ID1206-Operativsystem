#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <mqueue.h>
#include <fcntl.h>
#include <string.h>

int main(void){

    pid_t pid = 0;
    int status;
    

    pid = fork();

    if(pid == 0){
        printf("NOOO, I'll send my response through message queue\n");
        char *my_mq = "/mymq";
        char *write_msg = "wienerbrööd";
        mqd_t mqd;

        mqd = mq_open(my_mq, O_WRONLY);
        mq_send(mqd, write_msg, strlen(write_msg), 0);
        mq_close(mqd);
        
    }
    else if(pid > 0){
        printf("Luke, I am your father\n");

        int MAX_SIZE = 100;
        int MAX_NUM_MSG = 10;
        char *my_mq = "/mymq";
        char buf[MAX_SIZE];
        mqd_t mqd;
        struct mq_attr attr;

        // Form the queue attributes
        attr.mq_maxmsg = MAX_NUM_MSG;
        attr.mq_msgsize = MAX_SIZE;

        // Create message queue
        mqd = mq_open(my_mq, O_RDONLY | O_CREAT, 0644, &attr);

        wait(&status);

        printf("Alright Luke, here's the message i got:\n");
        // Read the message from the message queue
        mq_receive(mqd, buf, MAX_NUM_MSG, NULL);
        printf("Message: %s\n", buf);

        // Close the message queue
        mq_close(mqd);
        
    }


    exit(0);
}