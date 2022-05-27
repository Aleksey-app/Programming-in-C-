//Определение класса Войн для фабричного метода создания персов (Абстрактный родительский класс войнов
#pragma once
class Warror
{
	
public:
	virtual void InewWarType() = 0;		//виртуальнаяфункция создания война
	virtual ~Warror() {};
};

