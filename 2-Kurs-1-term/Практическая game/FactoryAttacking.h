//Определение класса создания атакующая конница 
#pragma once
#include "Factory.h"
class FactoryAttacking :public Factory
{
public:
	Warror* create();		//функция создания атакующая конница класса воин
};

