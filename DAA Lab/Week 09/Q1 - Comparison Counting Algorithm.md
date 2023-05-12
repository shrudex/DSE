# ✅Question - 01
## Write a program to sort set🤲🏻 of integers using _Comparison Counting🔢_ Algorithm.

```
#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp)
{
    int output[n]; 
    int count[10] = {0}; 

    //storing the count of occurrences in count[] array
    for (int i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    //changing count[i] so that it contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    //building the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    //copying the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    //finding the maximum number to know the number of digits
    int m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m)
            m = arr[i];

    //counting sort for every digit
    for (int exp = 1; m/exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int n;
    cout << "Enter the number of elements to be sorted: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements to be sorted: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 49;
}
```
