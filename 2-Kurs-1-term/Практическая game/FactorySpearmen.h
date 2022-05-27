//Определение класса создания копейщик пехота
#pragma once
#include "Factory.h"
class FactorySpearmen :public Factory
{
public:
	Warror* create();		//функция создания копейщик пехота класса воин
};

