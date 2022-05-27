//Реализация класса фабрика снайпер лучник
#include<iostream>
#include "FactorySniper.h"
#include"Warror.h"
#include"Sniper.h"

Warror* FactorySniper::create()	// функция создания снайпер лучник класса воин
{
	return new Sniper;
}
