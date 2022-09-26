
#include<iostream>
using namespace std;
int main()
{
    char str1[50], str2[30], str3[100];
    int index;
    cout << "Enter the string : ";
    cin.get(str1,50);
    cout << "Enter the substring : ";
    cin.get(str2,30);
    int pos=0, k=0;
    for (int i=0; str1[i]!='\0'; i++)
    	if (str1[i]==str2[pos])
    	{
    		pos++;
    		continue;
		}
		else
		{
			str3[k++]=str1[i];
		}
    for (int i=0; str3[i]!='\0'; i++)
    	cout << str3[i];
    return 49;
}
