#include <iostream>
using namespace std;
int main()
{
	cout << "Enter the order of the matrix : ";
	int n;
	cin >> n;
	int size = n;
	cout << "Enter the elements of the matrix : " << endl;
	int arr[n][n];
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
				cin >> arr[i][j];
		cout << endl;
	}
	cout << "Square Matrix is : " << endl;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			cout << arr[i][j] <<"\t";
		cout << endl;
	}
	int b[size]={};
	int k=0;
	// mapping begins
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
				b[k++]=arr[j][i];
	}
	cout << endl << "Mapped 1-D Array is : "<< endl;
	for (int i=0; i<k; i++)
		cout << b[i] << "\t";
	cout << endl;
	int a1, a2;
	cout << "Enter the row and column to search for : ";
	cin >> a1 >> a2;
	cout << b[a2*n+a1] << endl;
	return 49;
}
