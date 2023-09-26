#pragma once
#include <iostream>
#include "number.h"

using namespace std;

class TPolinom
{
	number a, b, c;
public:
	TPolinom(number,number,number);
	friend ostream& operator << (ostream&, TPolinom&);
};

