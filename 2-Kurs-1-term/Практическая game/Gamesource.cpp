//клиентский код
#include<iostream>
#include<vector>
#include<conio.h>
#include"Gamefield.h"
#include"Object.h"
#include"Unit.h"
#include"Warror.h"
#include"Factory.h"
#include"Attacking.h"
#include"Swordsmen.h"
#include"Spearmen.h"
#include"Sniper.h"
#include"Speed.h"
#include"Defense.h"
#include"FactoryAttacking.h"
#include"FactorySwordsmen.h"
#include"FactorySpearmen.h"
#include"FactorySniper.h"
#include"FactorySpeed.h"
#include"FactoryDefense.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	Object a1;
	Gamefield b(15,23);		//создание объекта в стеке
	std::vector<std::vector <Object*> > a2 = a1.SetConsolObject(b);
	b.DefinitionField(a2);
	a1.SetOneObject(a2, b, 5, 5, '&');
	a1.SetOneObject(a2, b, 3, 3, ' ');
	Unit u;
	a1.SetUnitObject(a2, u);
	b.MoveUnit(a2, u);
	FactoryAttacking* testikAttacking = new FactoryAttacking;
	FactorySwordsmen* testikSwordsmen = new FactorySwordsmen;
	FactorySpearmen* testikSpearmen = new FactorySpearmen;
	FactorySniper* testukSniper = new FactorySniper;
	FactorySpeed* testtikSpeed = new FactorySpeed;
	FactoryDefense* testDefense = new FactoryDefense;
	std::vector <Warror*> FacPush;
	FacPush.push_back(testikAttacking->create());
	FacPush.push_back(testikSwordsmen->create());
	FacPush.push_back(testikSpearmen->create());
	FacPush.push_back(testukSniper->create());
	FacPush.push_back(testtikSpeed->create());
	FacPush.push_back(testDefense->create());
	for (int i = 0; i < FacPush.size(); i++)
	{
		FacPush[i]->InewWarType();
	}
	return 0;
}