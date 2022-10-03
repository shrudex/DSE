#include <iostream>
using namespace std;
int main()
{
	string eq;
	cin >> eq;
	int n = eq.length();
	int top = -1;
	char stack[n];
	for (int i=0; i<n; ++i)
	{
		if (eq[i]=='(' or eq[i]=='{' or eq[i]=='[' or eq[i]==')' or eq[i]=='}' or eq[i]==']')
		{
			if (top==-1)
				stack[++top]=eq[i];
			else if (stack[top] == '(' && eq[i] == ')' || stack[top] == '[' && eq[i] == ']' || stack[top] == '{' && eq[i] == '}')
				--top;
			else
				stack[++top]=eq[i];
		}
	}
	if (top==-1)
		cout << "The given equation has properly matching open and closing parenthesis" <<endl;
	else
		cout << "The given equation doesn't contains properly matching open and closing parenthesis" << endl;
}
