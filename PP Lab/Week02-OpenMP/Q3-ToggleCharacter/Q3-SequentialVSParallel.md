## 💁🏻‍♂️**Question 03** - Write a program in C to toggle the character of a given string.

### Sample
```
Suppose the string is “HeLLo”, then the output should be “hEllO”.
```

- Here is the sequential code for the question - [Sequential-Q3-ToggleCharacter](https://github.com/shrudex/DSE/blob/main/PP%20Lab/Week01-Sequential/Q3-ToggleCharacter.md)
- Here is the parallel code for the question - [Parallel-Q3-ToggleCharacter](https://github.com/shrudex/DSE/blob/main/PP%20Lab/Week02-OpenMP/Q3-ToggleCharacter.md)

### C Code to compare the time difference between the two approaches
```c
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <omp.h>

int main() {
    char str[100];
    char str2[100];
    int i;

    printf("Enter any String: ");
    fgets(str, sizeof(str), stdin);
    strcpy(str2, str);

    // sequential code
    clock_t startTime = clock();
    for (i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') 
            str[i] = str[i] + 32; 
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    clock_t endTime = clock();
    printf("Sequential Time: %f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
    
    strcpy(str, str2);

    // parallel code
    startTime = clock();
    #pragma omp parallel for
    for (i = 0; str[i] != '\0'; ++i) {
        #pragma omp critical
        {
            if (str[i] >= 'A' && str[i] <= 'Z') 
                str[i] = str[i] + 32; 
            else if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
    }
    endTime = clock();
    printf("Parallel Time: %f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    printf("Toggled string: %s\n", str);

    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/44a9474a-2748-448a-9c46-3bdc725ebec8)

