# ✅Question - 01
## Write a program to find the _Binomial Co-efficient🔢_ using Dynamic Programming👨🏻‍💻.

```
#include <iostream>
using namespace std;

int bC(int n, int k) {
    int C[n+1][k+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Binomial Coefficient is: " << bC(n, k) << endl;
    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/084b4eac-abb9-4d60-abef-8693a14756d8)
