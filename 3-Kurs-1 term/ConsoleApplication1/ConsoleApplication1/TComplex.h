#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class TComplex
{
	double re, im;
public:
	TComplex();
	TComplex(int);
	TComplex get()const;
	TComplex operator*(TComplex);
	TComplex operator+(TComplex);
	TComplex operator-(TComplex);
	TComplex operator/(TComplex);
	bool operator==(TComplex&);
	double modul();
	double argument();
	friend istream& operator>>(istream&, TComplex&);
	friend ostream& operator<<(ostream&, TComplex);
	friend TComplex operator*(int, TComplex);
};

