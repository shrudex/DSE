Write✍ a program📺 to implement brute-force **String Matching**.😩 Analyze its time🕓 complexity.

```
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char text[100], pattern[100];
    int i, j, n, m, flag = 0;

    cout << "Enter the text string: ";
    cin >> text;

    cout << "Enter the pattern string: ";
    cin >> pattern;

    n = strlen(text);
    m = strlen(pattern);

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
            flag = 1;
        }
    }

    if (flag == 0)
        cout << "Pattern not found in the text." << endl;

    return 49;
}
```

_**OUTPUT**_

![image](https://user-images.githubusercontent.com/91502997/222747026-0cc75fa9-59c9-47c1-87b9-397e891fe639.png)

