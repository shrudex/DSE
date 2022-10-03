//conversion of infix to prefix
#include <iostream>
using namespace std;
int prec(char c) //to check the precedence of operators
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
	string ans="";
	cout << "PREFIX expression : ";
	for (int i=eq.length()-1; i>=0; --i)
	{
		if ((eq[i] >= 'a' and eq[i] <='z') or (eq[i] >= 'A' and eq[i] <='Z') or (eq[i] >= '0' and eq[i] <='9'))
			ans+=eq[i];
		else if (eq[i]==')')
			st[++top]=')';
		else if (eq[i]=='(')
		{
			while(st[top]!=')')
				ans+=st[top--];
			top--;
		}
		else
		{
			while(top!=-1 and prec(eq[i]) < prec(st[top]))
				ans+=st[top--];
			st[++top]=eq[i]; 
		}
	}
	while (top!=-1)
		ans+=st[top--];
	for (int i=ans.length()-1; i>=0; --i)
		cout << ans[i];
	return 49;
}
