#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child, parent;

    parent = getpid();
    printf("Parent PID: %d\n", parent);

    child = fork();

    if (child < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (child == 0) {
        printf("Child PID: %d\n", getpid());
        printf("Parent PID in child process (before parent exits): %d\n", getppid());

        sleep(7);

        printf("Parent PID in child process (after parent exits): %d\n", getppid());
    } 
    else {
        printf("Parent process is exiting...\n");
        exit(0);
    }

    return 49;
}
