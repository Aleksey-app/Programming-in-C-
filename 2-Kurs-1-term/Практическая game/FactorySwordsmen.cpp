//Реализация класса фабрика мечник пехота
#include<iostream>
#include "FactorySwordsmen.h"
#include"Warror.h"
#include"Swordsmen.h"


Warror* FactorySwordsmen::create()	//функция создания мечник пехота класса воин
{
	return new Swordsmen;
}