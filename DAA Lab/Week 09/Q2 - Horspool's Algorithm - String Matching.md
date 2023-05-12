# ✅Question - 02
## Write a program to implement _Horspool’s Algorithm_ for string matching👨🏻‍🔬 and find the number of key comparisons▶️ in successful search🔎 and unsuccessful search🔎.

```
#include <iostream>
#include <cstring>

using namespace std;

int horspoolStringMatch(const char* text, const char* pattern, int& comparisons) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m > n)  return -1;

    const int MAX_CHARS = 256;
    int shift_table [MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; i++)
        shift_table[i] = m;
    for (int i = 0; i < m - 1; i++)
        shift_table[pattern[i]] = m - 1 - i;

    int i = m - 1;
    while (i < n) {
        int k = 0;
        comparisons++;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            comparisons++;
            k++;
        }
        if (k == m)
            return i - m + 1;
        i += shift_table[text[i]];
    }
    return -1;
}

int main() {
    char text[1000];
    char pattern[100];
    cout << "Enter the text: ";
    cin.getline(text, 100);
    cout << "Enter the pattern: ";
    cin.getline(pattern, 100);

    int comparisons = 0;
    int index = horspoolStringMatch(text, pattern, comparisons);

    if (index != -1) {
        cout << "Pattern found at index " << index << endl;
        cout << "Number of key comparisons: " << comparisons << endl;
    } 
    else {
        cout << "Pattern not found" << endl;
        cout << "Number of key comparisons: " << comparisons << endl;
    }

    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/ebeb40b8-027d-4dbf-9ab9-d4af15c92811)

