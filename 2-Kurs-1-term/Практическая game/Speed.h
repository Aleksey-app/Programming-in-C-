//Определение класса cкоростной стрлок (лучник) для фабричного метода создания персов 
#pragma once
#include "Warror.h"
class Speed :public Warror
{
	unsigned Attack;		//атака
	unsigned Health;		//здоровье
	unsigned Armour;		//броня
	unsigned id;			//тип война
public:
	void InewWarType();		//инфа о скоростной стрелок лучник пока просто для теста
};

