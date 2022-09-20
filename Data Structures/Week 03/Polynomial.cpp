#include <iostream>
using namespace std;
struct Poly
{
	int base, power;
};
int main()
{
	int n1, n2;
	cout << "Enter the number of terms in polynomial 1 : ";
	cin >> n1;
	cout << "Enter the number of terms in polynomial 2 : ";
	cin >> n2;
	struct Poly p1[n1];
	struct Poly p2[n2];
	cout << "Enter the polynomial 1 in (base, power) pairs : " << endl;
	for (int i=0; i<n1; i++)
		cin >> p1[i].base >> p1[i].power;
	cout << endl;
	cout << "Enter the polynomial 2 in (base, power) pairs : " << endl;
	for (int i=0; i<n2; i++)
		cin >> p2[i].base >> p2[i].power;
	cout << "Polynomial P1 : " <<endl;
	for (int i=0; i<n1; i++)
		cout << p1[i].base << "\t" << p1[i].power << endl;
	cout << endl;
	cout << "Polynomial P2 : " <<endl;
	for (int i=0; i<n2; i++)
		cout << p2[i].base << "\t" << p2[i].power << endl;	
	struct Poly p3[n1+n2];
	int m = 0, n = 0, k = 1, count = 0;
	while (m!=n1 and n!=n2)
	{
		if (p1[m].power == p2[n].power)
		{
			int sum = p1[m].base + p2[n].base;
			if (sum==0)
			{
				m++;
				n++;
			}
			else
			{
			p3[k].base = p1[m].base + p2[n].base;
			p3[k++].power = p1[m].power;
			m++;
			n++;
			count++;
		    }
			
		}
		else if (p1[m].power > p2[n].power)
		{
			p3[k].base = p2[n].base;
			p3[k++].power = p2[n].power;
			n++;
			count++;
		}
		else
		{
			p3[k].base = p1[m].base;
 			p3[k++].power = p1[m].power;
			m++;
			count++;
		}
	}
	if (n!=n2)
	{
		for (int i=n; i<n2; i++)
		{
			p3[k].base = p2[i].base;
			p3[k++].power = p2[i].power;
			count++;
		}
	}
	else
	{
		for (int i=m; i<n1; i++)
		{
			p3[k].base = p1[i].base;
			p3[k++].power = p1[i].power;
			count++;
		}
	}
	p3[0].base = count;
	cout << "Polynomial P3 : " << endl;
	cout << "BASE\tPOWER" <<endl;
	cout << p3[0].base << endl;
	for (int i=1; i<=count; i++)
		cout << p3[i].base <<"\t" << p3[i].power << endl;
	return 17;	
}
