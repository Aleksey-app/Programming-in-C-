//Определение класса мечник для фабричного метода создания персов 
#pragma once
#include "Warror.h"
class Swordsmen :public Warror
{
	unsigned Attack;		//атака
	unsigned Health;		//здоровье
	unsigned Armour;		//броня
	unsigned id;			//тип война
public:
	void InewWarType();		//инфа о Мечник пехота пока просто для теста
};

