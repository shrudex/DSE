
#include<iostream>
#include <string.h>
using namespace std;
int main()
{
    char str1[50], str3[100];
    string str2;
    int index;
    cout << "Enter the string : ";
    cin.get(str1,50);
    cout << "Enter the index at which you want to enter : ";
    cin >> index;
    fflush(stdout);
    cout << "Enter the substring : ";
    cin >> str2;
    for (int i=0; i<index; i++)
    	str3[i]=str1[i];
    int k=index;
    for (int i=0; str2[i]!='\0'; i++)
    	str3[k++]=str2[i];
    for (int i=index; str1[i]!='\0'; i++)
    	str3[k++]=str1[i];
    for (int i=0; str3[i]!='\0'; i++)
    	cout << str3[i];
    return 49;
}
