//Определение класса создания оборонная конница
#pragma once
#include "Factory.h"
class FactoryDefense :public Factory
{
public:
	Warror* create();		//функция создания оборонная конница класса воин
};

