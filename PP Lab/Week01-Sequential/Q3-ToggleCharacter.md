## 💁🏻‍♂️**Question 03** - Write a program in C to toggle the character of a given string.

### Sample
```
Suppose the string is “HeLLo”, then the output should be “hEllO”.
```

### C Code
```c
#include <stdio.h>
#include <string.h> 
int main()
{
  	char str[100];
  	int i;
  	printf("Enter any String: ");
  	gets(str);
  	for (i = 0; str[i]!='\0'; ++i)
  	{
  	    if(str[i] >= 'A' && str[i] <= 'Z') 
              str[i] = str[i] + 32; 
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
  	}
  	printf("Toglled string: %s", str);
  	return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/d50060e1-1f3e-424a-bc9e-cb5a28a4931b)
