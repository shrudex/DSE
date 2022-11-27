#include <iostream>
using namespace std;
void ls (int num[], int n, int x) {
    for (int i=0; i<n; ++i) {
        if (num[i]==x) {
            cout << "Element found at index : " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}
void bs (int num[], int n, int x) {
    int s = 0, e = n-1, m = s + (e-s)/2;
    while (s<=e) {
        if (x==num[m]) {
            cout << "Element found" << endl;
            return;
        }
        if (x>num[m]) s = m+1;
        if (x<num[m]) e = m-1;
        m = s + (e-s)/2;
    }
    cout << "Element not found" << endl;
}
int main() {
    cout << "Enter the number of elements : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array : " << endl;
    for (int i=0; i<n; ++i) cin >> arr[i];
    cout << "Enter the element to be searched for : ";
    int y;
    cin >> y;
    cout << "Linear Search" << endl;
    ls(arr, n, y);
    cout << "Binary Search" << endl;
    bs (arr, n, y);
    return 49;
}
