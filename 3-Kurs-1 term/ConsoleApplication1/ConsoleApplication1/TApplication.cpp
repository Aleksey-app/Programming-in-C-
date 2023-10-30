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
	number a = 1 , b = 2, c = 1;
	while (true)
	{
		ch = menu();
		switch (ch)
		{
		case 1:
			a = clearA();
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			break;
		case 2:
		{
			number x;
			cout << "x = ";
			cin >> x;
			TPolinom p(a, b, c);
			number v = p.value(x);
			cout << "p(" << x << ")" " = " << v << endl;}
			break;
		case 3: {
			TPolinom p(a, b, c);
			p.discremenant(p); 
		}
			break;
		case 4:
		{
			TPolinom p(a, b, c);
			p.setPrintMod(EPrintModeClassic);
			cout << p << endl; }
			break;
		case 5:
		{
			TPolinom p(a, b, c);
			p.setPrintMod(EPrintModeCanonic);
			cout << p << endl; }
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
	cout << "1 - coefficients" << endl;
	cout << "2 - value" << endl;
	cout << "3 - roots" << endl;
	cout << "4 - print (classic)" << endl;
	cout << "5 - print (canonical)" << endl;
	cout << "0 - exit" << endl << ">";
	while (true) {
		cout << "Select the menu items:" << " _";
		cin >> ch;
		if (cin.fail()) {
			cout << "Value from 0 to 5" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;} 
		if (ch > 5) {
			cout << "Value from 0 to 5" << endl;
			continue;}
		if (ch < 0) {
			cout << "Value from 0 to 5" << endl;
			continue;
		}
		else break;
	}
	return ch;
}
int TApplication::clearA()
{
	int A;
	while(true) {
		cout << "Set values to the a" << endl;
		cin >> A;
		if (cin.fail()) {
			cout << "number" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (A == 0) {
			cout << "is not equal to 0" << endl;
			continue;
		}
		else break;
	}
	return A;
}
