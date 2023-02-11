Write an algorithm😲 for finding the Greatest Common Divisor (GCD) of two numbers🔢 using Euclid’s algorithm🤔. Write a program to implement👨‍💻 the Euclid’s algorithm.

```
#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (a==0) return b;
	if (b==0) return a;
	return gcd(b%a, a);
}
int main() {
	int a, b;
	cout << "Enter any two numbers : ";
	cin >> a >> b;
	int c = gcd(a, b);
	cout << "GCD of " << a << " and " << b << " is equal to " << c;
	return 49; 
}
```

**_Output_**

![image](https://user-images.githubusercontent.com/91502997/218238142-a7acdc8d-a3ce-498b-ab7a-2492f65123b2.png)
