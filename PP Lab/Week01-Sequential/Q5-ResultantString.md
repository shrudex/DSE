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
int main()
{
  	char str1[100];
  	char str2[100];
  	char res[100];
  	printf("Enter string 1: ");
  	gets(str1);
  	printf("\n");
  	printf("Enter string 2: ");
  	gets(str2);
  	int ind = 0;
  	for (int i = 0; str1[i]!='\0'; ++i)
  	{
  	   res[ind++]=str1[i];
  	   res[ind++]=str2[i];
  	}
  	printf("Answer string: %s", res);
  	return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/1759202b-2a75-4262-9ce1-d6b424d00320)
