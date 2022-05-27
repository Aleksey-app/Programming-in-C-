//Реализация класса фабрика оборонная конница
#include<iostream>
#include "FactoryDefense.h"
#include"Warror.h"
#include"Defense.h"

Warror* FactoryDefense::create()	// функция создания оборонная конница класса воин
{
	return new Defense;
}
