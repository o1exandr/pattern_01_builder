/*
Завдання 1.
Зведення будинку містить наступні кроки: залив фундаменту, встановлення стін, даху, вікон та дверей. Скласти програму для виконання(та виведення)   кроків побудови та обчислення вартості зведення будинку. Використати патерн проектування Builder.
Змінити розроблений на занятті клас House. House повинен містити екземпляри типу
Basement, Wall, Roof, Door, Window.
Додати  в інтерфейс Будівельника методи вставки дверей та вікон.
Доповнити   відповідними реалізаціями класи конкретних будівельників.
*/

#include "stdafx.h"
#include <iostream> 
#include <string>


using namespace std;

class Builder abstract
{

public:
	virtual void buildBasement() = 0;
	virtual void buildWall() = 0;
	virtual void buildRoof() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow() = 0;

};

class House
{
private:
	string house;

public:

	House()
	{
		house = "";
	}

	string getHouse() const
	{
		return house;
	}

	void addPart(string s)
	{
		house += s;
	}

};

class BreakBuilder : public Builder
{
private:

	House h;

public:

	virtual void buildBasement() override
	{
		h.addPart("Build basemeant\n");
	}

	virtual void buildWall() override
	{
		h.addPart("Build walls\n");
	}

	virtual void buildRoof() override
	{
		h.addPart("Build roof\n");
	}

	virtual void buildDoor() override
	{
		h.addPart("Build door\n");
	}

	virtual void buildWindow() override
	{
		h.addPart("Build window\n");
	}

	House getResult()const
	{
		return h;
	}

};

class MoneyBuilder : public Builder
{
private:
	int sum = 0;
public:

	virtual void buildBasement() override
	{
		sum += 10000;
	}

	virtual void buildWall() override
	{
		sum += 40000;
	}

	virtual void buildRoof() override
	{
		sum += 30000;
	}

	virtual void buildDoor() override
	{
		int door;
		cout << "Enter num of doors: ";
		cin >> door;
		sum += (door * 3000);
	}

	virtual void buildWindow() override
	{
		int window;
		cout << "Enter num of windows: ";
		cin >> window;
		sum += (window * 1500);
	}

	int getResult()const
	{
		return sum;
	}

};



class Director
{
private:
	Builder * builder;

public:

	Director()
	{

	}

	void construct()
	{
		builder->buildBasement();
		builder->buildWall();
		builder->buildRoof();
		builder->buildDoor();
		builder->buildWindow();
	}
	
	void setBuilder(Builder * build)
	{
		builder = build;
	}
	

};

int main()
{
	Director d;
	House h;

	cout << "\n\tBreakBuilder" << endl;
	BreakBuilder b;
	d.setBuilder(&b);
	d.construct();
	h = b.getResult();
	cout << h.getHouse();

	cout << "\n\tMoneyBuilder" << endl;
	MoneyBuilder m;
	d.setBuilder(&m);
	d.construct();
	cout << "Sum of builder: " <<m.getResult() << endl;

	cout << endl;
	system("pause");
	return 0;

}