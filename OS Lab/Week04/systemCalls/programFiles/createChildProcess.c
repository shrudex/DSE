#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t parent, child;

    parent = getpid();
    printf("Parent PID: %d\n", parent);

    child = fork();

    if (child < 0) {
        perror("Fork failed");
        return 1; 
    } 
    
    else if (child == 0) {
        //code is executing in the child process (childPID = 0)
        printf("Child PID: %d\n", getpid());
        printf("Parent PID in child process: %d\n", getppid());
    } 
    
    else {
        //code is executing in the parent process (childPID > 0)
        printf("Child PID in parent process: %d\n", child);
    }

    return 49;
}
