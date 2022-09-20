
#include <iostream>
using namespace std;
int main()
{
	char str[100];
	int i, c=0;
	cout<<"Enter any string : ";
	cin.get(str,100);
	for(i=0; str[i]!='\0'; i++)
		c++;
	cout<<"Length of the string ["<< str <<"] is : "<<c;
	return 0;
}
