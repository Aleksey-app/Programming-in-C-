#include <iostream>
#include <cmath>
#include "TPolinom.h"

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
	return a*x*x+b*x+c;
}

void TPolinom::setPrintMod(EPrintMode m)
{
	printMode = m;
}

void TPolinom::discremenant(int a, int b, int c)
{
	int Disc = b * b - 4 * a * c;
	int x1, X2;
	if (Disc > 0) {
		x1 = (-b + sqrt(Disc)) / (2 * a);
		X2 = (-b - sqrt(Disc)) / (2 * a);
		cout << "X1 = " << x1 << endl;
		cout << "X2 = " << X2 << endl;
	}
	else if (Disc == 0) {
		x1 = -b / (2 * a);
		cout << "X1 = X2 = " << x1 << endl;
	}
	else {
		int part = -b / (2 * a);
		int complex = sqrt(-Disc) / (2 * a);
		cout << "X1 = " << part << "+" << complex << "i" << endl;
		cout << "X2 = " << part << "+" << complex << "i" << endl;
	}
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
