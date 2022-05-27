//Реализация класса фабрика Атакующей конницы
#include<iostream>
#include"FactoryAttacking.h"
#include"Warror.h"
#include"Attacking.h"

Warror* FactoryAttacking::create()	// функция создания Атакующей конницы класса воин
{
	return new Attacking;
}