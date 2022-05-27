//Реализация класса фабрика копейщик пехота
#include<iostream>
#include "FactorySpearmen.h"
#include"Warror.h"
#include"Spearmen.h"

Warror* FactorySpearmen::create()	//функция создания копейщика пехота класса воин
{
	return new Spearmen;
}
