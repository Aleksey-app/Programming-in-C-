#include "TPolinom.h"

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

ostream& operator<<(ostream& os, TPolinom& p)
{
	if (p.printMode == EPrintModeClassic)
	os << p.a << "x^2+" << p.b << "x+" << p.c;
	else {

	}
	return os;
}
