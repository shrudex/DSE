#include <iostream>
using namespace std;
bool pal(string s)
{
	int n = s.length(), i, top=-1;
	char stack[n];
	for (i=0; i<n/2; ++i)
		stack[++top]=s[i];
	if (n%2!=0) ++i;
	char el;
	while (s[i]!='\0')
	{
		el = stack[top];
		--top;
	if (el!=s[i])
		return false;
	++i;
	}
	return true;
}
int main()
{
	string s;
	cout << "Enter any string : ";
	cin >> s;
	if (pal(s))
		cout << "palindrome";
	else
		cout << "not palindrome";
}
