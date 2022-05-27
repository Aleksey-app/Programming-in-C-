//ќпределение класса фабрика дл€ фабричного метода создани€ персов (јбстрактный родительский класс фабрика
#pragma once
class Warror;
class Factory
{
public:
	virtual Warror* create() = 0;		//виртуальна€функци€ создани€ война класса воин
	virtual ~Factory() {};
};

