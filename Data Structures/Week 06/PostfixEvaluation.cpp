#include <iostream>
using namespace std;
int main()
{
	cout << "Expression : ";
	string exp;
	cin >> exp;
	int st[exp.length()];
	int top = -1;
	for (int i=0; i<exp.length(); ++i)
	{
		if (exp[i]>='0' and exp[i]<='9')
			st[++top]= exp[i]-'0';
		else
		{
			int a1 = st[top--];
			int a2 = st[top--];
			if (exp[i]=='+')
				st[++top]=a2+a1;
			else if (exp[i]=='-')
				st[++top]=a2-a1;
			else if (exp[i]=='*')
				st[++top]=a2*a1;
			else if (exp[i]=='/')
				st[++top]=a2/a1;
			else if (exp[i]=='^')
				st[++top]=a2^a1;
		}
	}
	cout << "Value : " << st[0];
	return 49;
}
