# ✅Question - 04
## Write a program to implement _Knapsack_ Problem💰 using bottom-up _Dynamic Programming👨🏻‍💻_.

```
#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; ++i)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int main()
{
    int n, W, i;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack weight: ";
    cin >> W;

    int val[n], wt[n];

    cout << "Enter the value and weight of each item:\n";
    for (i = 0; i < n; ++i)
        cin >> val[i] >> wt[i];

    int max_val = knapsack(W, wt, val, n);
    cout << "Maximum value that can be obtained is: " << max_val << endl;

    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/90fd7c18-0250-4186-a2fb-37784b69a4a5)
