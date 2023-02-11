Write a program😲 to find GCD🔢 using **consecutive integer checking method** and analyze🔍 its time efficiency⌛.

```
#include <iostream>
using namespace std;
int gcd(int m, int n) {
    int t = (m>n)?n:m;
    while (t > 0) {
        if (m % t == 0 && n % t == 0) {
            return t;
        }
        t--;
    }
    return 1;
}
int main() {
    int a, b;
    cout << "Enter any two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is equal to " << gcd(a, b) << endl;
    return 49;
}
```

**_Output_**

![image](https://user-images.githubusercontent.com/91502997/218238268-cefb8609-2845-44c1-aa9f-5c4caeea9e51.png)

