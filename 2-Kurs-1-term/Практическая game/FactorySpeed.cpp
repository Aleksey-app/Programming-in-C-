//Реализация класса фабрика cкоростной стрлок лучник
#include<iostream>
#include "FactorySpeed.h"
#include"Warror.h"
#include"Speed.h"

Warror* FactorySpeed::create()	// функция создания cкоростной стрлок лучник класса воин
{
	return new Speed;
}
