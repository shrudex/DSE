### Write✍ a program in C++ to take an integer array and search🔍 for an element in😏👉 the array using🤳 BINARY SEARCH.

```
#include <iostream>
using namespace std;

int bs(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)  return mid;
        else if (arr[mid] > x) return bs(arr, l, mid - 1, x);
        else return bs(arr, mid + 1, r, x);
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in ascending order:" << endl;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    int result = bs(arr, 0, n - 1, x);

    if (result == -1) cout << "Element not found in array." << endl;
    else cout << "Element found at index " << result << endl;
  
    return 49;
}
```
