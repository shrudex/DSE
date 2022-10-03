#include <iostream>
using namespace std;
int fib(int n)
{
	if (n>1)
		return (fib(n-1)+fib(n-2));
	else
		return n;
}
int main()
{
	int num;
	cout << "Enter the number of terms you want to print : ";
	cin >> num;
	cout << "The fibonnaci series upto first "<< num << " terms : " << endl;
	for (int i=0; i<num; i++)
		cout << fib(i) << "\t";
	return 49;
}
