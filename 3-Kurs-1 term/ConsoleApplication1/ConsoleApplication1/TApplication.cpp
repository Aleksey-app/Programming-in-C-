#include <iostream>
#include "TPolinom.h"
#include "TApplication.h"
#include "number.h"

using namespace std;

TApplication::TApplication()
{
}

int TApplication::exec()
{
	int ch;
	number a = 1, b = 2, c = 1;
	while (true)
	{
		ch = menu();
		switch (ch)
		{
		case 1:
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
		{
			TPolinom p(a, b, c);
			cout << p << endl; }
			break;
		case 5:
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}
}
int TApplication::menu()
{
	int ch;
	cout << "1 -  coefficients" << endl;
	cout << "2 - value" << endl;
	cout << "3 - roots" << endl;
	cout << "4 - print (classic)" << endl;
	cout << "5 - print (canonical)" << endl;
	cout << "0 - exit" << endl << ">";
	cin >> ch;
	return ch;
}
