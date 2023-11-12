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

TComplex TComplex::get() const
{
	TComplex temp(re, im);
	return temp;

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

TComplex TComplex::operator-(TComplex c)
{
	TComplex temp;
	temp.re = re - c.re;
	temp.im = im - c.im;
	return temp;
}


TComplex TComplex::operator/(TComplex c)
{
	TComplex temp;
	temp.re = (re * c.re - im * c.im) / (c.re * c.re + c.im * c.im);
	temp.im = (re * c.im + im * c.re) / (c.re * c.re + c.im * c.im);
	return temp;
}

bool TComplex::operator==(TComplex& c)
{
	return ((re == c.re)) && (im == c.im);
}

double TComplex::modul()
{
	return pow(re*re+im*im,0.5);
}

double TComplex::argument()
{
	return atan2(im,re)*180/3.14159;
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

TComplex operator*(int b, TComplex c)
{
	TComplex temp;
	temp.re = b * c.re;
	temp.im = b * c.im;
	return temp;
}
