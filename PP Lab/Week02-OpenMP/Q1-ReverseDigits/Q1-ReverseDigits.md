## 💁🏻‍♂️**Question 01** - Write a program in C to reverse the digits of the following integer array of size 9. Initialize the input array to the following values.

### Sample
```
Input array: 18, 523, 301, 1234, 2, 14, 108, 150, 1928
Output array: 81, 325, 103, 4321, 2, 41, 801, 51, 8291
```

### C Code
```c
#include <stdio.h>
#include <omp.h>

int main() {
    int n = 9;
    int nums[n];

    printf("Enter the array elements :\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }

    // each iteration of the loop will execute parallely by a different thread
    #pragma omp parallel for
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

    printf("The resultant array elements are : \n");
    for (int i = 0; i < n; ++i)
        printf("%d ", nums[i]);

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/6c1d5c55-066b-438d-a237-66b0fd56cfe0)
