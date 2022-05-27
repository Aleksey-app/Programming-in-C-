//Определение класса создания мечник пехота
#pragma once
#include "Factory.h"
class FactorySwordsmen :public Factory
{
public:
	Warror* create();		//функция создания Мечник пехота класса воин
};

