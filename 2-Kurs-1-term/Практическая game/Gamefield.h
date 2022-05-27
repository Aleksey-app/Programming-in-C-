#pragma once				//ќпределение класса игровоеполе
#include<vector>
class Object;
class Unit;
class Gamefield
{
	unsigned axisX, axisY;	//оси игровогопол€
    std::vector<std::vector<Object> > Matrix;			//игровоеполе основной объект дл€ работы 
public:
	friend class Iterator;			
	Gamefield();			//класический конструктор по умолчанию
	Gamefield(unsigned Line, unsigned ColumnY);		//класический конструктор игровогопол€
	~Gamefield();		//класический деструктор
	Gamefield(const Gamefield&);		//конструктор копировани€ просто чтобы был в данном классе хватает и побитового копировани€ 
	unsigned GetAxisX() const { return axisX; }		//inline получить значение оси ’ строки
	unsigned GetAxisY() const;			//получить значение оси Y столбцы
	unsigned MaxControl() const;			//максимально возможное кол-во объектов на поле
	void DefinitionField(std::vector<std::vector<Object*>> Field);		//инициализаци€ пол€	
	void MoveUnit(std::vector<std::vector<Object*> > Game, Unit&);		//движение юнита (отр€да) по полю с объектами
};
inline unsigned Gamefield::GetAxisY() const { return axisY; }		//получить значение оси Y
