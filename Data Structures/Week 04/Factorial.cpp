#include <iostream>
using namespace std;
int fact(int n)
{
	if (n>1)
		return n*fact(n-1);
	else
		return 1;
}
int main()
{
	int num;
	cout << "Enter any number : ";
	cin >> num;
	cout << "The factorial of the number " << num <<  " is : " << fact(num);
	return 49;
}
