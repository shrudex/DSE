# ✅Question - 01
## Write a program to sort set🤲🏻 of integers using _Comparison Counting🔢_ Algorithm.

```
#include <iostream>
using namespace std;

void comparisonCountingSort(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    int* count = new int[max_val+1]();
    
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max_val; i++)
        count[i] += count[i-1];

    int* sorted_arr = new int[n];

    for (int i = 0; i < n; i++) {
        sorted_arr[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = sorted_arr[i];
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    comparisonCountingSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 49;
}
```

![image](https://github.com/shrudex/DSE/assets/91502997/a20e819a-32f1-4292-a7a7-c60a660e9f35)
