//Определение класса копейщик для фабричного метода создания персов 
#pragma once
#include "Warror.h"
class Spearmen :public Warror
{
	unsigned Attack;		//атака
	unsigned Health;		//здоровье
	unsigned Armour;		//броня
	unsigned id;			//тип война
public:
	void InewWarType();		//инфа о копейщик пехота пока просто для теста
};

