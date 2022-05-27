#pragma once			//Определение класса объект
#include<vector>
class Gamefield;
class Unit;
class Object
{
	unsigned dotX, dotY;
	char mapping;
public:
	Object();			//классический конструктор для 1-го объекта чтобы был
	~Object();			//классический деструктор
	void SetX(unsigned);		//задать значение точки по оси X
	void SetY(unsigned);		//задать значение точки по оси Y
	void SetM(char);		//задать графическое изображение объекта
	unsigned GetDotX() const { return dotX; }		//получить координату объекта в точке Х строки
	unsigned GetDotY() const { return dotY; }		//получить координату объекта в точке Y столбцы
	char GetMapping() const { return mapping; }			//получить графическое отображение объекта	
	std::vector<std::vector<Object*> >Forma(Gamefield&);		//создание матрицы Объектов заданного поля
	std::vector<std::vector<Object*> > SetConsolObject(Gamefield &);				//задание любых объектов в заданных координатах согласно размерам поля
	std::vector<std::vector<Object*> > SetOneObject(std::vector<std::vector<Object*> >, Gamefield&, unsigned, unsigned, char);				//задание одного обекта (координаты и вид) add
	std::vector<std::vector<Object*>> SetUnitObject(std::vector<std::vector<Object*> >, Unit&);				//add Unita
	std::vector<std::vector<Object*> > DelObject(std::vector<std::vector<Object*> >, const unsigned, const unsigned);		//delete Object
};

