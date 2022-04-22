// Практическая работа №1.cpp 
#include <iostream>
using namespace std;
int main()
{
	cout << "int " << sizeof(int) << "\t short int " << sizeof(short int)
		<< "\t long int " << sizeof(long int) << "\t float " << sizeof(float)
		<< "\t double " << sizeof(double) << "\t long double " << sizeof(long double) << "\t char " << sizeof(char) << "\t bool " << sizeof(bool) << "\n";
	int a = 65535;
	int z = 1 << 31;
	for (int i = 0; i < 32; i++)
	{
		if (a&z)
			cout << 1;
		else
			cout << 0;
		a <<= 1;
		if (i == 0)
			cout << "\t ";
	}
	cout << "\n";
	union {
		float b = 2.718;
		int c;
	}x;
	for (int i = 0; i < 32; i++)
	{
		if (z&x.c)
			cout << 1;
		else
			cout << 0;
		x.c <<= 1;
		if (i == 0)
			cout << "\t ";
		if (i == 8)
			cout << "\t";
	}
	cout << "\n";
	return 0;
}