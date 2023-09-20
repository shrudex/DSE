## Q2 - Write a program to create a child process. Display the process IDs of the process, parent and child (if any) in both the parent and child processes.

### C program - **createChildProcess.c**
```
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
```

### Command to compile the C program
```
gcc -o createChildProcess createChildProcess.c
```

### Command to run the program
```
./createChildProcess
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/c0d209b5-4355-4351-a2f5-a19b73d54b5d)
![image](https://github.com/shrudex/DSE/assets/91502997/9b08a219-ebe1-4133-878f-49a19d5c08a9)
