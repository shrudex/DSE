#include <iostream>
using namespace std;
int main()
{
	cout << "Enter the order of the matrix : ";
	int n;
	cin >> n;
	int size = n;
	cout << "Enter the "<<size<<" elements of the diagonal matrix : " << endl;
	int arr[n][n];
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (i==j)
				cin >> arr[i][j];
			else
				arr[i][j]=0;
		}
		cout << endl;
	}
	cout << "Diagonal Matrix is : " << endl;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			cout << arr[i][j] <<"\t";
		cout << endl;
	}
	int b[size]={};
	int k=0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (i==j)
				b[k++]=arr[i][j];
		}
	}
	cout << endl << "Mapped 1-D Array is : "<< endl;
	for (int i=0; i<k; i++)
		cout << b[i] << "\t";
	cout << endl;
	int a1, a2;
	cout << "Enter the row and column to search for : ";
	cin >> a1 >> a2;
	cout << b[a1] << endl;
	return 49;
}
