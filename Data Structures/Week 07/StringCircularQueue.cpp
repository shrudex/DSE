#include <iostream>
using namespace std;
string queue[7];
int front = 0, rear = 0, n = 7, count = 0;
void Delete() {
	if (count==0) cout << "Queue Underflow" << endl;
	else {
		cout<<"Element being deleted: "<< queue[front] << endl;
		front = (front+1)%n;
		count = count - 1;;
	}
}
void Insert(string ele) {
	if (count==n) cout << "Queue Overflow" << endl;
	else {
		queue[rear]=ele;
		rear=(rear+1)%n;
		count+=1;
	}
}
void Display() {
	if (count==0) cout << "Empty Queue" << endl;
	else {
		cout << "Queue elements are : " << endl;
		if (front<rear) {
			for (int i=front; i<=rear; ++i) cout << queue[i] << "\t";
			cout << endl;
		}
		else {
			for (int i=front; i<n; ++i)	cout << queue[i] << "\t";
			for (int i=0; i<rear; ++i)	cout << queue[i] << "\t";
			cout << endl;
		}		
	}
}
int main() {
	int ch;
	string ele;
	cout<<"Enter: \n1 to Display\n2 to Enqueue\n3 to Dequeue\n4 to Exit"<<endl;
	do {
		cin >> ch;
		switch(ch)
		{
			case 1:
				Display();
				cout << "Front:" << queue[front] << "\t" << "Rear:" << queue[rear-1];
				break;
			case 2:
				cout<<"Enter element to insert:"<<endl;
				cin>>ele;
			    Insert(ele);
				break;
			case 3:
				Delete();
				break;
			case 4:
				cout << "EXIT";
				break;
			default:
				cout<<"Enter a valid choice : "<<endl;
		}
	}while (ch!=4);
}
