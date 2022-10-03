#include <iostream>
using namespace std;
int gcd(int n1, int n2)
{
	if (n2==0)
		return n1;
	else
		return gcd(n2, n1%n2);
}
int main()
{
	int num1, num2;
	cout << "Enter any 2 numbers : ";
	cin >> num1 >> num2;
	cout << "The GCD of the numbers " << num1 << " and " << num2 <<  " is : " << gcd(num1, num2);
	return 49;
}
