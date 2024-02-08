## 💁🏻‍♂️**Question 09** - Write a C program that reads a character type matrix and integer type matrix B of size MxN. It produces and output string STR such that, every character of A is repeated r times.

### Sample
```
Input matrix A: {{p, C, a, P}, {e, X, a, M}}
Input matrix B: {{1, 2, 4, 3}, {2, 4, 3, 2}}
Output string: pCCaaaaPPPeeXXXXaaaMM
```

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

    char A[M][N];
    int B[M][N];

    printf("Enter character matrix A of size %dx%d:\n", M, N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            scanf(" %c", &A[i][j]);
    }
    
    printf("Enter integer matrix B of size %dx%d:\n", M, N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            scanf("%d", &B[i][j]);
    }

    char STR[M * N * 49];

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            char currentChar = A[i][j];
            int repeatCount = B[i][j];
            int startIndex = (i * N + j) * 49;
            for (int k = 0; k < repeatCount; ++k)
                STR[startIndex + k] = currentChar;
        }
    }

    STR[M * N * 49] = '\0'; 
    printf("\nOutput String STR: %s\n", STR);

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/d25a9101-c2be-498c-a459-42a5b890906d)
