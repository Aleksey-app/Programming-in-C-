//Реализация класса отряд
#include<iostream>	
#include<vector>
#include"Object.h"
#include "Unit.h"

using std::cout;
using std::endl;
Unit::Unit()		//конструктор по умолчанию
{
	this->SetX(0);
	this->SetY(1);
	this->SetM('U');
	this->sumArmour = 30;
	this->sumAttack = 12;
	this->sumHealth = 12;
	this->Quantity = 6;
	/*cout << "Clasic construktor class Unit" << endl;*/
}
void Unit::SetsumArmour(int A)		//задать значение брони отряда
{
	this->sumArmour = A;
}
void Unit::SetsumHealth(int H)		//задать значение здоровья отряда
{
	this->sumHealth = H;
}
void Unit::SetsumAttack(int A)		//задать значение атаки отряда
{
	this->sumAttack = A;
}
void Unit::SetsumQuantity(unsigned Q)		//задать кол-во бойцов отряда
{
	this->Quantity = Q;
}