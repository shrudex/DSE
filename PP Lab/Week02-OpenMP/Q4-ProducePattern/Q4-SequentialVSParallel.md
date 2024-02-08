## 💁🏻‍♂️**Question 04** - Write a C program to read a word of length N and produce the pattern as shown in the example.

### Sample
```
Input: PCBD
Output: PCCBBBDDDD
```

- Here is the sequential code for the question - [Sequential-Q4-ProducePattern](https://github.com/shrudex/DSE/blob/main/PP%20Lab/Week01-Sequential/Q4-ProducePattern.md)
- Here is the parallel code for the question - [Parallel-Q4-ProducePattern](https://github.com/shrudex/DSE/blob/main/PP%20Lab/Week02-OpenMP/Q4-ProducePattern.md)

### C Code to compare the time difference between the two approaches
```c
#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <time.h>

int main() {
    char str[100];
    char res[200]; 
    int i, ind = 0;
    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Enter any string: ");
    fgets(str, sizeof(str), stdin);

    //sequential code
    start_time = clock();
    for (i = 0; str[i] != '\0'; ++i) {
        int itr = i + 1;
        while (itr != 0) {
            res[ind] = str[i];
            ind += 1;
            itr -= 1;
        }
    }
    res[ind] = '\0';
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("%s", res);
    printf("Sequential Execution Time: %f seconds\n", cpu_time_used);

    // Reset for Parallel Version
    ind = 0;

    //parallel code
    start_time = clock();
    #pragma omp parallel for
    for (i = 0; str[i] != '\0'; ++i) {
        int itr = i + 1;
        while (itr != 0) {
            #pragma omp critical
            {
                res[ind] = str[i];
                ind += 1;
                itr -= 1;
            }
        }
    }
    res[ind] = '\0';
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Parallel Execution Time: %f seconds\n", cpu_time_used);

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/02b548d5-3559-4cad-8623-7af7d9c7372d)
