#include <iostream>
using namespace std;
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printA (int num[], int n) {
    for (int i=0; i<n; ++i) cout << num[i] << " ";
}

void heapify(int arr[], int N, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < N && arr[left] > arr[largest])
		largest = left;
	if (right < N && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, N, largest);
	}
}
void hs(int arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	for (int i = N - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
    printA(arr, N);
}

void merge(int array[], int const left, int const mid, int const right)
{
    auto const s1 = mid - left + 1;
    auto const s2 = right - mid;
    auto *la = new int[s1], *ra = new int[s2];
    for (auto i = 0; i < s1; i++)
        la[i] = array[left + i];
    for (auto j = 0; j < s2; j++)
        ra[j] = array[mid + 1 + j];
    auto ios1 = 0, ios2 = 0; 
    int ioma = left; 
    while (ios1 < s1 && ios2 < s2) {
        if (la[ios1] <= ra[ios2]) {
            array[ioma] = la[ios1];
            ios1++;
        }
        else {
            array[ioma] = ra[ios2];
            ios2++;
        }
        ioma++;
    }
    while (ios1 < s1) {
        array[ioma] = la[ios1];
        ios1++;
        ioma++;
    }
    while (ios2 < s2) {
        array[ioma] = ra[ios2];
        ios2++;
        ioma++;
    }
}

int count = 0;

void ms(int array[], int n, int const begin, int const end)
{
    if (begin >= end) return;
    auto mid = begin + (end - begin) / 2;
    ms(array, n, begin, mid);
    ms(array, n, mid + 1, end);
    merge(array, begin, mid, end);
    if (count==0) {
        printA(array, n);
        count++;
    }
}

int main()
{
	cout << "Enter the number of elements : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array : " << endl;
    for (int i=0; i<n; ++i) cin >> arr[i];
    cout << "Heap Sort" << endl;
    hs(arr, n);
    cout << endl;
    cout << "Merge Sort" << endl;
    ms(arr, n, 0, n-1);
    return 49;
}
