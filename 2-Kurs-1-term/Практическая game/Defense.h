//Определение класса оборонная конница для фабричного метода создания персов 
#pragma once
#include "Warror.h"
class Defense :public Warror
{
	unsigned Attack;		//атака
	unsigned Health;		//здоровье
	unsigned Armour;		//броня
	unsigned id;			//тип война
public:
	void InewWarType();		//инфа о оборонная конница пока просто для теста
};

