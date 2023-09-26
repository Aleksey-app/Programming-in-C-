#include "TPolinom.h"

TPolinom::TPolinom(number x,number y,number z)
{
	a = x;
	b = y;
	c = z;
}

ostream& operator<<(ostream& os, TPolinom& p)
{
	os << p.a << "x^2+" << p.b << "x+" << p.c;
	return os;
}
