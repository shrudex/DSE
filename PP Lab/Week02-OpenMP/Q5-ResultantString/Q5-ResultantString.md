## 💁🏻‍♂️**Question 05** - Write a C program to read two strings S1 and S2 of same length and produce the resultant string.

### Sample
```
S1: string
S2: length

Resultant String: slternigntgh
```

### C Code
```c
#include <stdio.h>
#include <string.h>
#include <omp.h>

int main() {
    char str1[100];
    char str2[100];
    char res[200]; 
    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 > 0 && str1[len1 - 1] == '\n')
        str1[--len1] = '\0';
    if (len2 > 0 && str2[len2 - 1] == '\n')
        str2[--len2] = '\0';

    int max_len = (len1 > len2) ? len1 : len2;
    int ind = 0;
    
    #pragma omp parallel for
    for (int i = 0; i < max_len; ++i) {
        #pragma omp critical
        {
            if (i < len1)
                res[ind++] = str1[i];
            if (i < len2)
                res[ind++] = str2[i];
        }
    }

    res[ind] = '\0';
    printf("Answer string: %s\n", res);
    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/1759202b-2a75-4262-9ce1-d6b424d00320)
