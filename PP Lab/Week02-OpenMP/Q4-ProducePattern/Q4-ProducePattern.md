## 💁🏻‍♂️**Question 04** - Write a C program to read a word of length N and produce the pattern as shown in the example.

### Sample
```
Input: PCBD
Output: PCCBBBDDDD
```

### C Code
```c
#include <stdio.h>
#include <string.h>
#include <omp.h>

int main() {
    char str[100];
    char res[200]; 
    int i, ind = 0;

    printf("Enter any string: ");
    fgets(str, sizeof(str), stdin);

    // each thread processes each character of the string
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
    printf("Answer string: %s\n", res);

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/ca3e71a4-2009-4de4-beaa-ab0dbdf0208e)
