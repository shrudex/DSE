Write a program😲 to find GCD🔢 using brute force approach💪.

```
#include <iostream>
using namespace std;
int main() {
	int a, b;
	int gcd = 1;
	cout << "Enter the two numbers : ";
	cin >> a >> b;
	int t = (a>b)?b:a;
	for (int i=1; i<=t; ++i) {
		if ((a%i==0) and (b%i==0))	gcd = i;
	}
	cout << "GCD of the two numbers : " << gcd << endl;
}
```

**_Output_**

![image](https://user-images.githubusercontent.com/91502997/221333361-e15add9e-f420-4f1f-9be7-a457ddec344d.png)
