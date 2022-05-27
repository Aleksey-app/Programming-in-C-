//Определение класса создания cкоростной стрлок лучник
#pragma once
#include "Factory.h"
class FactorySpeed :public Factory
{
public:
	Warror* create();		//функция создания cкоростной стрлок лучник класса воин
};

