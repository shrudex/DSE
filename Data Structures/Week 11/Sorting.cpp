#include <iostream>
using namespace std;
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printA (int num[], int n) {
    for (int i=0; i<n; ++i) cout << num[i] << " ";
}

void bs (int num[], int n) {
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<n-i-1; ++j) {
            if (num[j]>num[j+1]) swap(&num[j+1], &num[j]);
        }
    }
    printA(num, n);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low-1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int count = 0;
void qs (int num[], int n, int low, int high) {
    if (low < high) {
        int pi = partition(num, low, high);
        qs(num, n, low, pi - 1);
        qs(num, n, pi + 1, high);
    }
    if (count==0) {
        printA(num, n);
        ++count;
    }
}

void ss (int num[], int n) {
    for (int i=0; i<n-1; ++i) {
        int min = i;
        for (int j=i+1; j<n; ++j) {
            if (num[min]>num[j]) min = j;
            if (min!=i) swap (&num[i], &num[min]);
        }
    }
    printA(num, n);
}

void is (int num[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = num[i];
        j = i - 1;
        while (j >= 0 && num[j] > key)
        {
            num[j + 1] = num[j];
            j = j - 1;
        }
        num[j + 1] = key;
    }
    printA(num, n);
}

int main() {
    cout << "Enter the number of elements : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array : " << endl;
    for (int i=0; i<n; ++i) cin >> arr[i];
    cout << "Bubble Sort" << endl;
    bs(arr, n);
    cout << endl;
    cout << "Quick Sort" << endl;
    qs(arr, n, 0, n-1);
    cout << endl;
    cout << "Selection Sort" << endl;
    ss(arr, n);
    cout << endl;
    cout << "Insertion Sort" << endl;
    is(arr, n);
    return 49;
}
