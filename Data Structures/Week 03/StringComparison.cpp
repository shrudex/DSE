
#include<iostream>
using namespace std;
int main()
{
    char str1[50], str2[50];
    int i=0, chk=0;
    int diff = 0;
    cout << "Enter the first string : ";
    cin >> str1;
    cout << "Enter the second string : ";
    cin >> str2;
    while(str1[i]!='\0' || str2[i]!='\0')
    {
        if(str1[i]!=str2[i])
        {
            chk = 1;
            diff = str1[i]-str2[i];
            break;
        }
        i++;
    }
    if(chk==0)
        cout << "Strings are Equal";
    else
        cout << "Strings are not Equal" << endl;
        cout << "Difference is : " << diff << endl;
    return 0;
}
