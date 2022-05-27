#pragma once	//Определение класса юнит
#include<vector>
#include"Object.h"

class Unit :public Object
{
	unsigned sumArmour;		//броня
	unsigned sumHealth;		//здоровье
	unsigned sumAttack;		//атака
	unsigned Quantity;		//сумма бойцов отряда
public:
	Unit();		//конструктор по умолчанию
	unsigned GetsumArmour() const { return sumArmour; }			//получить значение брони отряда
	unsigned GetsumHealth() const { return sumHealth; }			//получить значение здоровья отряда
	unsigned GetsumAttack() const { return sumAttack; }			//получить значение атаки отряда
	unsigned GetQuantity() const { return Quantity; }			//получить кол-во бойцов отряда
	void SetsumArmour(int);		//задать значение брони отряда
	void SetsumHealth(int);		//задать значение здоровья отряда
	void SetsumAttack(int);		//задать значение атаки отряда
	void SetsumQuantity(unsigned);		//задать кол-во бойцов отряда
};

