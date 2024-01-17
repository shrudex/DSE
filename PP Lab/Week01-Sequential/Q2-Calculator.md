## 💁🏻‍♂️**Question 02** - Write a program in C to simulate the all the operations of a calculator. Given inputs A and B, find the output for A+B, A-B, A*B and A/B.

### Sample
```
Input: A = 9, B = 3
Output : A+B = 12, A-B = 6, A*B = 27, A/B = 3
```

### C Code
```c
#include <stdio.h>
int main()
{
   printf("Welcome to the Calculator App\n");
   int a, b;
   printf("Enter 2 elements : ");
   scanf("%d%d", &a, &b);

   int add = a + b;
   int sub = 0;
   int d = 0;

   if (a>b){
       sub = a-b;
       d = a/b;
   }
   else{
       sub = b-a;
       d = b/a;
   }

   int mul = a*b;

   printf("A+B -> %d\n", add);
   printf("A-B -> %d\n", sub);
   printf("A*B -> %d\n", mul);
   printf("A/B -> %d\n", d);

   return 49;
}
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/3d6efeda-5507-49db-80c4-458af2700f82)
