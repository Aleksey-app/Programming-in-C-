//Определение класса создания снайпер лучник
#pragma once
#include "Factory.h"
class FactorySniper :public Factory
{
public:
	Warror* create();		//функция создания снайпер лучник класса воин
};

