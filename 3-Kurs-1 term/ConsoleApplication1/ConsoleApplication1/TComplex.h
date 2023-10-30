#pragma once
#include <iostream>
using namespace std;
class TComplex
{
	double re, im;
public:
	TComplex();
	TComplex(int);

	TComplex operator*(TComplex);
	TComplex operator+(TComplex);
	TComplex operator-(TComplex);
	TComplex operator/(TComplex);
	int operator>(TComplex);
	int operator==(TComplex);
	bool operator==(TComplex&);
	friend istream& operator>>(istream&, TComplex&);
	friend ostream& operator<<(ostream&, TComplex);
	friend TComplex operator*(int, TComplex);
};

