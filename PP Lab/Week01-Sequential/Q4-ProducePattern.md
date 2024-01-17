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
int main()
{
    char str[100];
    char res[100];
    int i;
    int ind;
    printf("Enter any string: ");
    gets(str);
    for (i = 0; str[i]!='\0'; ++i)
    {
       int itr = i+1;
       while (itr!=0){
           res[ind]=str[i];
           ind+=1;
           itr-=1;
       }
    }
    printf("Answer string: %s", res);
    return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/ca3e71a4-2009-4de4-beaa-ab0dbdf0208e)
