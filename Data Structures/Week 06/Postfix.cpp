//conversion of infix to postfix
#include <iostream>
using namespace std;
int prec(char c) //to check precedence of operators
{
	if (c=='+' or c=='-')
		return 1;
	else if (c=='*' or c=='/')
		return 2;
	else if (c=='^')
		return 3;
	else
		return -1;
}
int main()
{
	string eq;
	cout << "Enter the equation : ";
	cin >> eq;
	char st[eq.length()];
	int top=-1;
	cout << "POSTFIX expression : ";
	for (int i=0; i<eq.length(); ++i)
	{
		if ((eq[i] >= 'a' and eq[i] <='z') or (eq[i] >= 'A' and eq[i] <='Z') or (eq[i] >= '0' and eq[i] <='9'))
			cout << eq[i];
		else if (eq[i]=='(')
			st[++top]='(';
		else if (eq[i]==')')
		{
			while(st[top]!='(')
				cout << st[top--];
			top--;
		}
		else
		{
			while(top!=-1 and prec(eq[i]) <= prec(st[top]))
				cout << st[top--];
			st[++top]=eq[i]; 
		}
	}
	while (top!=-1)
		cout << st[top--];
	return 49;
}
