## 💁🏻‍♂️**Question 06** - Write a C program to perform Matrix times vector product operation.

### Sample
```
Input matrix: {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
Input vector: {1, 2, 3}
Output product: {14, 32, 50}
```

### C Code
```c
#include <stdio.h>
#include <omp.h>

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int vector[3] = {1, 2, 3};
    int result[3] = {0};

    #pragma omp parallel for
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            result[i] += matrix[i][j] * vector[j];
    }

    printf("Resultant Vector: ");
    for (int i = 0; i < 3; ++i)
        printf("%d ", result[i]);

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/2d24bbf7-3a0c-4147-8e55-53a18b9a602b)
