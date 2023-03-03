Write📝 a program📺 to implement **Matrix Multiplication**❌ using 🏻 brute-force technique and analyze its time😁✨💞 efficiency.

```
#include <iostream>
using namespace std;

int main()
{
    int MAX_SIZE = 10;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int m, n, p, q, i, j, k;

    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> m >> n;

    cout << "Enter the elements of the first matrix: " << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> p >> q;

    cout << "Enter the elements of the second matrix: " << endl;
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            cin >> B[i][j];
        }
    }

    if (n != p)
    {
        cout << "Error: Matrix multiplication not possible" << endl;
        return 0;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "The product of the matrices is: " << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 49;
}
```

**_OUTPUT_**

![image](https://user-images.githubusercontent.com/91502997/222750256-d2e69d9a-b882-4ff9-994d-7ae581616670.png)
