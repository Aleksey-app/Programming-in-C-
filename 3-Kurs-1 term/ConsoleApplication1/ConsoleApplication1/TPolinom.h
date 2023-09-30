#pragma once
#include <iostream>
#include "number.h"

using namespace std;

enum EPrintMode
{
	EPrintModeClassic,
	EPrintModeCanonic,
};
class TPolinom
{
	EPrintMode printMode;
	number a, b, c;
public:
	TPolinom(number,number,number);
	friend ostream& operator << (ostream&, TPolinom&);
	number value(number);
	void setPrintMod(EPrintMode);
	void discremenant(int a, int b, int c);
};

