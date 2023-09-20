#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t childPid;

    //creating a child process
    childPid = fork();

    if (childPid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (childPid == 0) {
        //code is executing in the child process
        printf("Child process is running (PID: %d)\n", getpid());
        //sleeping to check child process
        sleep(49); 
        printf("Child process completed\n");
        exit(0);
    } else {
        //code is executing in the parent process
        printf("Parent process is waiting for the child to complete...\n");

        //blocking the parent until the child completes
        int status;
        pid_t terChildPid = wait(&status);

        if (terChildPid == -1) {
            perror("Wait failed");
            exit(1);
        } 
        else {
            if (WIFEXITED(status))
                printf("Child process (PID: %d) exited with status %d\n", terChildPid, WEXITSTATUS(status));
            else if (WIFSIGNALED(status)) 
                printf("Child process (PID: %d) terminated by signal %d\n", terChildPid, WTERMSIG(status));  
        }

        printf("Parent process completed\n");
    }

    return 49;
}
