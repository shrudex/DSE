Write📝 a program📺 to sort a set📚 of integers using📤📤 **Selection Sort**💌 algorithm and analyze its time🕘 efficiency.
```
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 49;
}
```

**_OUTPUT_**

![image](https://user-images.githubusercontent.com/91502997/222741079-9eb9351c-f170-4c15-b96a-0b3eeeb4e908.png)
