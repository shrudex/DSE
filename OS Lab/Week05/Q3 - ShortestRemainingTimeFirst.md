## Q3 - Write a C program to simulate the following CPU scheduling algorithm: *Shortest Remaining Time First [SRTF]*

### C program - **algoSRTF.c**
```
#include <stdio.h>

int main() {
    int arrivalTime[10], burstTime[10], remainingTime[10], i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Times: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arrivalTime[i]);

    printf("Enter Burst Times: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &burstTime[i]);

    for (i = 0; i < n; i++)
        remainingTime[i] = burstTime[i];

    burstTime[9] = 9999;

    printf("\nPid\tAT\tBT\tTAT\tWT\n");
    for (time = 0; count != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (arrivalTime[i] <= time && burstTime[i] < burstTime[smallest] && burstTime[i] > 0)
                smallest = i;
        }
        burstTime[smallest]--;

        if (burstTime[smallest] == 0) {
            count++;
            end = time + 1;
            avg += end - arrivalTime[smallest] - remainingTime[smallest];
            tt += end - arrivalTime[smallest];
            
            double tat = end - arrivalTime[smallest];
            double wt = tat - remainingTime[smallest];
            
            printf("P%d\t%d\t%d\t%.2lf\t%.2lf\n", smallest + 1, arrivalTime[smallest], remainingTime[smallest], tat, wt);
        }
    }

    printf("\nAverage waiting time = %.2lf\n", avg / n);
    printf("Average Turnaround time = %.2lf", tt / n);

    return 49;
}
```

### Command to compile the C program
```
gcc -o algoSRTF algoSRTF.c
```

### Command to run the program
```
./algoSRTF 
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/9e1604b6-5b01-4418-bb9a-f5f15f72e8b8)
![image](https://github.com/shrudex/DSE/assets/91502997/4a7af870-0f8f-46a6-9963-70a4116db325)

