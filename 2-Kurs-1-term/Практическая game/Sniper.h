//Определение класса снайпер для фабричного метода создания персов 
#pragma once
#include "Warror.h"
class Sniper :public Warror
{
	unsigned Attack;		//атака
	unsigned Health;		//здоровье
	unsigned Armour;		//броня
	unsigned id;			//тип война
public:
	void InewWarType();		//инфа о снайпере лучник пока просто для теста
};

