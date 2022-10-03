#include <iostream>
using namespace std;
void toh (int d, char f, char t, char a)
{
	if (d>0){
	toh (d-1, f, a, t);
	cout << "Move the ring " << d << " from " << f << " to " << t << endl;;
	toh (d-1, a, t, f);
	}
}
int main()
{
	int n;
	char a, b, c;
	cout << "Enter the number of disks : ";
	cin >> n;
	cout << "Let A be the initial rod, B be the auxillary rod and C be the final rod." << endl;
	cout << endl;
	toh(n, 'A', 'C', 'B');
	return 49;
}
