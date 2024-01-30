## 💁🏻‍♂️**Question 01** - Write a program in C to reverse the digits of the following integer array of size 9. Initialize the input array to the following values.

### Sample
```
Input array: 18, 523, 301, 1234, 2, 14, 108, 150, 1928
Output array: 81, 325, 103, 4321, 2, 41, 801, 51, 8291
```

- Here is the sequential code for the question - [Sequential-Q1ReverseDigits](https://github.com/shrudex/DSE/blob/main/PP%20Lab/Week01-Sequential/Q1-ReverseDigits.md)
- Here is the parallel code for the question - [Parallel-Q1ReverseDigits](https://github.com/shrudex/DSE/blob/main/PP%20Lab/Week02-OpenMP/Q1-ReverseDigits.md)

### C Code to compare the time difference between the two approaches
```c
#include <stdio.h>
#include <time.h>

int main() {
    int n = 9;
    int nums[n];

    printf("Enter the array elements :\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }

    clock_t startTime, endTime;

    // sequential code
    startTime = clock();
    for (int i = 0; i < n; ++i) {
        int copy = nums[i];
        int rev = 0;
        while (copy != 0) {
            int d = copy % 10;
            rev = rev * 10 + d;
            copy = copy / 10;
        }
        nums[i] = rev;
    }
    endTime = clock();
    printf("Sequential Time: %f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    // parallel code
    startTime = clock();
    for (int i = 0; i < n; ++i) {
        int copy = nums[i];
        int rev = 0;
        while (copy != 0) {
            int d = copy % 10;
            rev = rev * 10 + d;
            copy = copy / 10;
        }
        nums[i] = rev;
    }
    endTime = clock();
    printf("Parallel Time: %f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    printf("The resultant array elements are : \n");
    for (int i = 0; i < n; ++i)
        printf("%d ", nums[i]);

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/c1a73ff7-1a1b-44da-a992-51bd47869d68)


