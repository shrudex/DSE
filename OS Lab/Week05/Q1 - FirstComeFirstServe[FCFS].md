## Q1 - Write a C program to simulate the following CPU scheduling algorithm: *First Come First Serve [FCFS]*

### C program - **algoFCFS.c**
```
#include<stdio.h>

void findWaitingTime(int processes[], int n, int burstTime[], int waitingTime[]) {
    waitingTime[0] = 0;

    //waiting time calculation
    for (int i = 1; i < n; ++i)
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
}

void findTurnAroundTime(int processes[], int n, int burstTime[], int waitingTime[], int turnaroundTime[]) {
    //turnaround time calculation
    for (int i = 0; i < n; ++i)
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
}

void findAvgTime(int processes[], int n, int burstTime[]) {
    int waitingTime[n], turnaroundTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    findWaitingTime(processes, n, burstTime, waitingTime);

    findTurnAroundTime(processes, n, burstTime, waitingTime, turnaroundTime);

    printf("Processes\tBurst time\tWaiting time\tTurnaround time\n");

    for (int i = 0; i < n; i++) {
        printf(" %d\t\t %d\t\t %d\t\t %d\n", processes[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("Average waiting time = %f\n", avgWaitingTime);
    printf("Average turnaround time = %f\n", avgTurnaroundTime);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burstTime[n];
    
    printf("Assuming the Pid as the order in which processes arrive. \n\n");
    
    for (int i = 0; i < n; ++i) {
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
        processes[i] = i + 1;
    }

    findAvgTime(processes, n, burstTime);

    return 49;
}
```

### Command to compile the C program
```
gcc -o algoFCFS algoFCFS.c
```

### Command to run the program
```
./algoFCFS
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/34d75894-96f8-4f2c-a755-8ea3a2559646)
![image](https://github.com/shrudex/DSE/assets/91502997/19270a51-7a2c-4325-b93b-225400b33b5c)
