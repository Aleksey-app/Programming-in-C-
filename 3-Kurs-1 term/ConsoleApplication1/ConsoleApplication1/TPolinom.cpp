#include <iostream>
#include <math.h>
#include "TPolinom.h"
#include "TComplex.h"

using std::cout;
using std::endl;

TPolinom::TPolinom(number x,number y,number z)
{
	printMode = EPrintModeClassic;
	a = x;
	b = y;
	c = z;
}
number TPolinom::value(number x)
{
	return a * x * x + b * x + c;
}
void TPolinom::setPrintMod(EPrintMode m)
{
	printMode = m;
}
void TPolinom::discremenant(TPolinom q)
{
	number Disc = b * b - 4 * a * c;
	/*if (Disc > 0) {
		cout << "X1 = " << (-b + sqrt(Disc)) / (2 * a) << endl;
		cout << "X2 = " << (-b - sqrt(Disc)) / (a + a) << endl;
	}
	else if (Disc == 0) {
		cout << "X1 = X2 = " << -b / (2 * a) << endl;
	}
	else {
		cout << "There are no real roots" << endl;
	}*/
	cout << Disc << endl <<
}
void TPolinom::print_complex()
{
		if (im >= 0) {
			cout << re << "+" << im << "i" << endl;
		}
		else
			cout << re << im << "i" << endl;
}
ostream& operator<<(ostream& os, TPolinom& p)
{
	if (p.printMode == EPrintModeClassic)
		os << p.a << "x^2+" << p.b << "x+" << p.c;
	else {
		os << p.a << "x^2+" << p.b << "x+" << p.c << "=0";
	}
	return os;
}
