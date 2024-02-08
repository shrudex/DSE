## 💁🏻‍♂️**Question 08** - Write a C program that reads a matrix of size MxN and produce an output matrix B of same size such that it replaces all the non-border elements of A with its equivalent 1’s complement and remaining elements same as matrix A. Also produce a matrix D.

### Sample
![image](https://github.com/shrudex/DSE/assets/91502997/1c11e9a5-95d6-4ef0-8f75-ee12f6812580)

### C Code
```c
#include <stdio.h>
#include <omp.h>

int main() {
    int M, N;

    printf("Enter the number of rows (M): ");
    scanf("%d", &M);
    printf("Enter the number of columns (N): ");
    scanf("%d", &N);

    int A[M][N], B[M][N];

    printf("Enter matrix A of size %dx%d:\n", M, N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            scanf("%d", &A[i][j]);
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == 0 || j == 0 || i == M - 1 || j == N - 1)
                B[i][j] = A[i][j];
            else
                B[i][j] = ~A[i][j];
        }
    }

    printf("\nMatrix B (1's complement for non-border elements):\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/8f4795c2-be27-4ec9-8de8-de17acc97828)
