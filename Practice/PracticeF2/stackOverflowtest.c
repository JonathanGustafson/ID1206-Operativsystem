#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    pid_t pid;
    int fd[2];
    char buf[20];

pipe(fd);


switch(pid = fork()){

    case -1:
        perror("pipe");
        exit(1);

    case 0: 
        /*child process*/
        close(fd[1]);
        read(fd[0], buf, 20);
        printf("Child read message from parent: %s\n", buf);
        exit(1);
        break;

    default:
     /*parent process*/
        close(fd[0]);
        write(fd[1], "Hello from parent\n", 17);
        break;
    } 
    return 0;

}