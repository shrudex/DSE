#include <iostream>
using namespace std;
int top;
int isEmpty(int arr[])
{
	if (top==-1)
		return 1;
	else
		return 0;
}
bool isFull(int arr[] ,int n)
{
	if (top==n-1)
		return true;
	else
		return false;
}
void push (int arr[], int n)
{
	arr[++top]=n;
}
int pop (int arr[])
{
	return arr[top--];
}
int peek(int arr[])
{
	return arr[top];
}
int main()
{
	top = -1;
	char ans = 'Y';
	int n;
	cout<< "Implementation of Stacks" << endl;
	cout << "Enter the size of the stack : ";
	cin >> n;
	int st[n];
	cout << "Enter \n1 to PUSH \n2 to POP \n3 to PEEK" << endl;
	while (ans=='Y')
	{
		cout << "Enter your CHOICE :  ";
		int choice; 
		cin >> choice;
		if (choice==1)
		{
			int i;
			cout << "Enter the element to be pushed : ";
			cin >> i;
			if (isFull(st, n)==false)
			{
				push (st, i);
				cout << i << " element pushed SUCCESSFULLY" << endl;
			} 
			else
				cout << "Stack OVERFLOW!!!" << endl;
		}
		else if (choice==2)
		{
			if (isEmpty(st)==1)
				cout << "Stack UNDERFLOW!!!" << endl;
			else
			{
				int el = pop (st);
				cout << el << " element popped SUCCESSFULLY" << endl;
			}
		}
		else if (choice==3)
		{
			if (isEmpty(st)==1)
				cout << "Stack EMPTY!!!" << endl;
			else{
				int el = peek (st);
				cout << el << " element found at the TOP" << endl;
			}
		}
		else
			cout << "WRONG CHOICE";
		cout << "Do you wish to continue? (Y to continue) : ";
		cin >> ans;
		cout << endl ;
	}
	return 49;
} 
