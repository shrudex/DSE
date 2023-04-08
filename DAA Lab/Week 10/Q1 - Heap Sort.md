### Perform Heap Sort💌 on✋😥 an array of integers.

```
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int lar = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[lar])
		lar = l;
	if (r < n && arr[r] > arr[lar])
		lar = r;
	if (lar != i) {
	    int temp = arr[i];
	    arr[i] = arr[lar];
	    arr[lar] = temp;
		heapify(arr, n, lar);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
	    int temp = arr[0];
	    arr[0] = arr[i];
	    arr[i] = temp;
		heapify(arr, i, 0);
	}
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    
    int nums[n];
    cout << "Enter the elements : " << endl;
    for (int i=0; i<n; ++i) cin >> nums[i];
    
    cout << "Array before SORTING : ";
    for (int i=0; i<n; ++i) cout << nums[i] << " ";
    cout << endl;
    
	heapSort(nums, n);

	cout << "Array after SORTING : ";
    for (int i=0; i<n; ++i) cout << nums[i] << " ";
    
    return 49;
}
```

![image](https://user-images.githubusercontent.com/91502997/230702021-1f829e1d-c067-4f87-8bb0-b11aee0a054f.png)
