### Write✍ a program📺 in👌 C++ to input🔢 an integer array and perform QUICK SORT🏃‍ on it.

```
#include <iostream>

using namespace std;

int partition(int num[], int low, int high) {
    int pivot = num[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (num[j] <= pivot) {
            ++i;
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }

    int temp = num[i + 1];
    num[i + 1] = num[high];
    num[high] = temp;

    return i + 1;
}

void quickSort(int num[], int low, int high) {
    if (low < high) {
        int pi = partition(num, low, high);

        quickSort(num, low, pi - 1);
        quickSort(num, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int num[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    quickSort(num, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << num[i] << " ";
    }

    return 49;
}
```
