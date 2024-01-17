## 💁🏻‍♂️**Question 07** - Write a C program to read a matrix A of size 5x5. It produces a resultant matrix B of size 5x5. It sets all the principal diagonal elements of B matrix with 0. It replaces each row elements in the B matrix in the following manner. If the element is below the principal diagonal it replaces it with the maximum value of the row in the A matrix having the same row number of B. If the element is above the principal diagonal it replaces it with the minimum value of the row in the A matrix having the same row number of B.

### Sample
![image](https://github.com/shrudex/DSE/assets/91502997/b68526d5-9d15-4855-b512-fa668b10b9b0)


### C Code
```c
#include <stdio.h>

int main() {
    int A[5][5], B[5][5];

    printf("Enter matrix A of size 5x5:\n");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            scanf("%d", &A[i][j]);
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i == j)
                B[i][j] = 0;
            else if (i < j)
                B[i][j] = A[i][j] < A[i][i] ? A[i][j] : A[i][i];
            else
                B[i][j] = A[i][j] > A[i][i] ? A[i][j] : A[i][i];
        }
    }

    printf("Matrix B of size 5x5:\n");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/e3f30b60-804f-4dca-8d19-0c064a2ce277)
