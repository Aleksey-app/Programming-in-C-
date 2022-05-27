#include<iostream>			//Реализация класса объект
#include<vector>
#include "Object.h"
#include"Gamefield.h"
#include"Unit.h"

using std::cout;
using std::endl;
using std::cin;

Object::Object()			//классический конструктор класса объект
{
	this->dotX = 1;
	dotY = 1;
	mapping = ' ';
	/*cout << "Clasic construktor class Object" << endl;		//для отладки*/
}
Object::~Object()		//классический деструктор класса объект удаление в обратном порядке
{
	/*cout << "Clasic destruktor ~Object" << endl;		//для отладки*/
}
void Object::SetX(unsigned X)		//задать значение точки по оси X
{
	this->dotX = X;
}
void Object::SetY(unsigned Y)		//задать значение точки по оси Y
{
	this->dotY = Y;
}
void Object::SetM(char M)		//задать графическое изображение объекта
{
	this->mapping = M;
}
std::vector<std::vector<Object*> >Object::Forma(Gamefield& b)		//создание матрицы Объектов заданного поля
{
	std::vector<std::vector<Object*>>SumObject;		//объявление переменной вектор векторов
	SumObject.resize(b.GetAxisX());					//задание размера по оси Х столбцы
	for (int i = 0; i < SumObject.size(); i++) {
		SumObject[i].resize(b.GetAxisY());			//задание размера по оси Y строки
	}			//создана матрица пока пустая
	for (int i = 0; i < b.GetAxisX(); i++) {		//в циклах заполняю матрицу размера XY объектами Конструктором
		for (int j = 0; j < b.GetAxisY(); j++) {
			SumObject[i][j] = new Object();
		}
	}
	return SumObject;
}
std::vector<std::vector<Object*>>Object::SetConsolObject(Gamefield& b)		//задание любых объектов в заданных координатах согласно размерам поля
{
	setlocale(LC_ALL, "Russian");
	cout << "Максимально возможное кол-во объектов на поле: " << "(" << b.MaxControl() << ")" << endl;
	cout << "Введите кол-во объектов, которое требуется создать:";
	unsigned kol;
	while (true)
	{
		cin >> kol;
		if (cin.fail())
		{
			cout << "Введенные данные не корректны. Повторите ввод" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (kol < 1 || kol > b.MaxControl())
		{
			cout << "Значение <В диапозоне от 1 до " << b.MaxControl() << ">" << endl;
			continue;
		}
		else break;
	}
	char View = '@';			//изображение объекта пока для отладки  const
	unsigned LineX, ColumnY;
	std::vector<Object>SetXY(kol); //переменные по осям 
	for (int i = 0; i < SetXY.size(); i++) {
		while (true)
		{
			cout << "Задайте координату по оси Х (строки)." << endl;
			cin >> LineX;
			if (cin.fail())
			{
				cout << "Введенные данные не корректны. Повторите ввод" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				continue;
			}
			if (LineX < 1 || LineX >b.GetAxisX())
			{
				cout << "Значение <В диапозоне от 1 до " << b.GetAxisX() << ">" << endl;
				continue;
			}
			else break;
		}
		SetXY[i].dotX = LineX - 1;
		while (true)
		{
			cout << "Задайте координату по оси Y (столбцы)." << endl;
			cin >> ColumnY;
			if (cin.fail())
			{
				cout << "Введенные данные не корректны. Повторите ввод" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				continue;
			}
			if (ColumnY < 1 || ColumnY >b.GetAxisY())
			{
				cout << "Значение <В диапозоне от 1 до " << b.GetAxisY() << ">" << endl;
				continue;
			}
			else break;
		}
		SetXY[i].dotY = ColumnY - 1;
		SetXY[i].mapping = View;
	}
	std::vector<std::vector<Object*> > SumObject = Forma(b);
	for (Object& x : SetXY) {
		SumObject[x.GetDotX()][x.GetDotY()]->mapping = x.GetMapping();
	}
	return SumObject;
}
std::vector<std::vector<Object*>> Object::SetOneObject(std::vector<std::vector<Object*> >One, Gamefield& b, unsigned X, unsigned Y, char mapp)	//задание одного обекта (координаты и вид) "Добавить"
{
	One[X][Y]->mapping = mapp;
	return One;
}
std::vector<std::vector<Object*>> Object::SetUnitObject(std::vector<std::vector<Object*> > one, Unit& u)			//add Unita
{
	one[u.GetDotX()][u.GetDotY()]->mapping = u.GetMapping();
	return one;
}
std::vector<std::vector<Object*> > Object::DelObject(std::vector<std::vector<Object*> >one, unsigned X, unsigned Y)		//delete Object
{
	one[X][Y]->mapping = '$';
	return one;
}

