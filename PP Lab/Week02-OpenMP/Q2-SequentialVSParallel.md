## 💁🏻‍♂️**Question 02** - Write a program in C to simulate the all the operations of a calculator. Given inputs A and B, find the output for A+B, A-B, A*B and A/B.

### Sample
```
Input: A = 9, B = 3
Output : A+B = 12, A-B = 6, A*B = 27, A/B = 3
```

- Here is the sequential code for the question - [Sequential-Q2Calculator](https://github.com/shrudex/DSE/blob/main/PP%20Lab/Week01-Sequential/Q2-Calculator.md)
- Here is the parallel code for the question - [Parallel-Q2Calculator](https://github.com/shrudex/DSE/blob/main/PP%20Lab/Week02-OpenMP/Q1-Calculator.md)

### C Code to compare the time difference between the two approaches
```c
#include <stdio.h>
#include <time.h>

int main() {
    printf("Welcome to the Calculator App\n");
    int a, b;
    printf("Enter 2 elements : ");
    scanf("%d%d", &a, &b);

    int add = a + b;
    int sub = 0;
    int d = 0;

    // sequential code
    clock_t startTime = clock();
    if (a > b) {
        sub = a - b;
        d = a / b;
    } else {
        sub = b - a;
        d = b / a;
    }
    int mul = a * b;
    clock_t endTime = clock();
    printf("Sequential Time: %f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    // parallel code
    startTime = clock();
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            if (a > b) {
                #pragma omp critical
                sub = a - b;
            } else {
                #pragma omp critical
                sub = b - a;
            }
        }

        #pragma omp section
        {
            if (a > b) {
                #pragma omp critical
                d = a / b;
            } else {
                #pragma omp critical
                d = b / a;
            }
        }
    }
    int mul_parallel = a * b;
    endTime = clock();
    printf("Parallel Time: %f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    // Output results
    printf("A+B -> %d\n", add);
    printf("A-B -> %d\n", sub);
    printf("A*B -> %d\n", mul);
    printf("A/B -> %d\n", d);

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/ce6d6dff-b11c-4817-98ef-3d2df585476f)
