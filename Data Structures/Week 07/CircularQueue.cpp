#include <iostream> 
using namespace std;
int queue[10], head = 0, tail = 0, n = 10, cnt=0;
void enqueue(int ele) {
	if (cnt==n)	cout << "Queue Overflow" << endl;
	else {
		queue[tail]=ele;
		tail = (tail+1) % n;
		cnt+=1;
	}
} 
void dequeue() {
	if (cnt==0)	cout << "Queue Underflow";
	else {
		cout << "Element being deleted: " << queue[head] << endl;
		head = (head+1) % n;
		cnt-=1;
	}
}
void display() {
	if (cnt==0)	cout<<"Empty Queue"<<endl;
	else {
		cout<<"The elements are : " << endl; 
		if (head < tail)	for (int i = head; i <tail; ++i)	cout << queue[i] << "\t";
		else {
			for (int i = head; i<n; ++i)	cout << queue[i] << "\t";
			for (int i = 0; i < tail ; ++i)	cout << queue[i] << "\t";
		}
		cout << endl;		
	}
}

int main() {
	int ch,ele;
	cout<<"Enter 1 to enQueue\nEnter 2 to deQueue\nEnter 3 to display\nEnter 4 to Exit" << endl;
	do {
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout << "Enter element to be inserted : " << endl;
				cin >> ele;
			    enqueue(ele);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				cout<<"Head: " << queue[head] << "\t" << "Tail :"<<queue[tail-1];
				cout << endl;
				break;
			case 4:
				cout<< "EXIT" ;
				break;
			default:
				cout<< "Enter a valid choice"<<endl;
		}
	}while (ch!=4);
}

