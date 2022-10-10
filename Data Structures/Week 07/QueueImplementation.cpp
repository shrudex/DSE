//implementation of queues using arrays
#include <iostream>
using namespace std;
int rear;
int isEmpty(int arr[])
{
	if (rear==0)
		return 1;
	else
		return 0;
}
bool isFull(int arr[] ,int n)
{
	if (rear==n)
		return true;
	else
		return false;
}
void enqueue (int arr[], int n)
{
	arr[rear++]=n;
}
int dequeue (int arr[])
{
	int el = arr[0];
	for (int i=0; i<rear; ++i)
		arr[i]=arr[i+1];
	rear--;
	return el;
}
int r(int arr[])
{
	return arr[rear-1];
}
int f(int arr[])
{
	return arr[0];
}
void display(int arr[])
{
	for (int i=0; i<rear; ++i)
		cout << arr[i] << "\t";
}
int main()
{
	rear = 0;
	char ans = 'Y';
	int n;
	cout<< "Implementation of Queues" << endl;
	cout << "Enter the size of the queue : ";
	cin >> n;
	int q[n];
	cout << "Enter \n1 to ENQUEUE \n2 to DEQUEUE \n3 to PEEK FRONT \n4 to PEEK REAR \n5 to DISPLAY" << endl;
	while (ans=='Y')
	{
		cout << "Enter your CHOICE :  ";
		int choice; 
		cin >> choice;
		if (choice==1)
		{
			int i;
			cout << "Enter the element to be enqueued : ";
			cin >> i;
			if (isFull(q, n)==false)
			{
				enqueue (q, i);
				cout << i << " element enqueued SUCCESSFULLY" << endl;
			} 
			else
				cout << "Queue OVERFLOW!!!" << endl;
		}
		else if (choice==2)
		{
			if (isEmpty(q)==1)
				cout << "Queue UNDERFLOW!!!" << endl;
			else
			{
				int el = dequeue (q);
				cout << el << " element dequeued SUCCESSFULLY" << endl;
			}
		}
		else if (choice==3)
		{
			if (isEmpty(q)==1)
				cout << "Queue EMPTY!!!" << endl;
			else{
				int el = f (q);
				cout << el << " element found at the FRONT" << endl;
			}
		}
		else if (choice==4)
		{
			if (isEmpty(q)==1)
				cout << "Queue EMPTY!!!" << endl;
			int el = r (q);
			cout << el << " element found at the REAR" << endl;
		}
		else if (choice==5)
		{
			cout << "Queue elements : " << endl;
			display(q);
			cout << endl;
		}
		else
			cout << "WRONG CHOICE";
		cout << "Do you wish to continue? (Y to continue) : ";
		cin >> ans;
		cout << endl ;
	}
	return 49;
} 
