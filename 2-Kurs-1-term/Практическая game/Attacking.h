//Определение класса атакующая конница для фабричного метода создания персов 
#pragma once
#include "Warror.h"
class Attacking :public Warror
{ 
	unsigned Attack;		//атака
	unsigned Health;		//здоровье
	unsigned Armour;		//броня
	unsigned id;			//тип война
public:
	void InewWarType();		//инфа о Атакующей конницы пока просто для теста
};

