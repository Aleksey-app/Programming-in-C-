#include "TComplex.h"
#include <iostream>
using namespace std;
TComplex::TComplex()
{
	re = 0;
	im = 0;
}

TComplex::TComplex(int v)
{
	re = v;
	im = 0;
}

TComplex TComplex::operator*(TComplex c)
{
	TComplex temp;
	temp.re = re * c.re - im * c.im;
	temp.im = re * c.im + im * c.re;
	return temp;
}

TComplex TComplex::operator+(TComplex c)
{
	TComplex temp;
	temp.re = re + c.re;
	temp.im = im + c.im;
	return temp;
}

istream& operator>>(istream& is, TComplex& c)
{
	is >> c.re >> c.im;
	return is;
}

ostream& operator<<(ostream& os, TComplex c)
{
	os << "(" << c.re << "+" << c.im << ")";
	return os;
}
