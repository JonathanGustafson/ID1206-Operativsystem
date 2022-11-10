#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[]) {
    pid_t pid = 0;
    int status;
    int fd[2];
    pipe(fd);

    pid = fork();

if (pid == 0) {
    printf("I am the child");

    close(fd[0]);
    dup2(fd[1], 1);
    char* args[] = {"ls","/", NULL};
    execvp("ls", args);

}

if (pid > 0) {  

    close(fd[1]);
    dup2(fd[0],0);

    char*args[] = {"wc", "-l", NULL};
    execvp("wc", args);

    printf("End of process %d: ", pid);
}

exit(0);
}