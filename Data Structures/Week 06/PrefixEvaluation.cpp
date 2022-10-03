#include <iostream>
using namespace std;
int main()
{
	cout << "Expression : ";
	string exp;
	cin >> exp;
	int st[exp.length()];
	int top = -1;
	for (int i=exp.length()-1; i>=0; --i)
	{
		if (exp[i]>='0' and exp[i]<='9')
			st[++top]= exp[i]-'0';
		else
		{
			int a1 = st[top--];
			int a2 = st[top--];
			if (exp[i]=='+')
				st[++top]=a1+a2;
			else if (exp[i]=='-')
				st[++top]=a1-a2;
			else if (exp[i]=='*')
				st[++top]=a1*a2;
			else if (exp[i]=='/')
				st[++top]=a1/a2;
			else if (exp[i]=='^')
				st[++top]=a1^a2;
		}
	}
	cout << "Value : " << st[0];
	return 49;
}
