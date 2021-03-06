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


using namespace std;


class Basement
{
private:
	int metr;
	bool make = false;

public:
	void setMetr(int m)
	{
		metr = m;
	}

	int getMetr()const
	{
		return metr;
	}

	void setMake(bool m)
	{
		make = m;
	}

	bool getMake()const
	{
		return make;
	}
};

class Wall
{
private:
	int count;
	bool make = false;

public:
	void setCount(int c)
	{
		count = c;
	}

	int getCount()const
	{
		return count;
	}

	void setMake(bool m)
	{
		make = m;
	}

	bool getMake()const
	{
		return make;
	}
};

class Roof
{
private:
	int square;
	bool make = false;

public:
	void setSquare(int s)
	{
		square = s;
	}

	int getSquare()const
	{
		return square;
	}

	void setMake(bool m)
	{
		make = m;
	}

	bool getMake()const
	{
		return make;
	}
};

class Door
{
private:
	int count;
	bool make = false;

public:
	void setCount(int c)
	{
		count = c;
	}

	int getCount()const
	{
		return count;
	}

	void setMake(bool m)
	{
		make = m;
	}

	bool getMake()const
	{
		return make;
	}
};

class Window
{
private:
	int count;
	bool make = false;

public:
	void setCount(int c)
	{
		count = c;
	}

	int getCount()const
	{
		return count;
	}

	void setMake(bool m)
	{
		make = m;
	}

	bool getMake()const
	{
		return make;
	}
	
};

class House
{
private:

	Basement bm;
	Wall wl; 
	Roof rf; 
	Door dr; 
	Window ww;

public:

	void makeBasement(int metr)
	{
		bm.setMetr(metr);
		bm.setMake(true);
	}
	
	void makeWall(int count)
	{
		wl.setCount(count);
		wl.setMake(true);
	}

	void makeRoof(int square)
	{
		rf.setSquare(square);
		rf.setMake(true);
	}

	void makeDoor(int count)
	{
		dr.setCount(count);
		dr.setMake(true);
	}

	void makeWindow(int count)
	{
		ww.setCount(count);
		ww.setMake(true);
	}
	

	void getHouse() const
	{
		if (bm.getMake()) cout << "Build basemeant " << bm.getMetr() << "m\n";
		if (wl.getMake()) cout << "Build wall " << wl.getCount() << " pieces\n";
		if (rf.getMake()) cout << "Build roof " << rf.getSquare() << " m2\n";
		if (dr.getMake()) cout << "Build door " << dr.getCount() << " pieces\n";
		if (ww.getMake()) cout << "Build window " << ww.getCount() << " pieces\n";
	}

};

class Builder abstract
{

public:
	virtual void buildBasement() = 0;
	virtual void buildWall() = 0;
	virtual void buildRoof() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow() = 0;

};

class BreakBuilder : public Builder
{
private:

	House h;

public:

	virtual void buildBasement() override
	{
		h.makeBasement(150);
	}

	virtual void buildWall() override
	{
		h.makeWall(8);;
	}

	virtual void buildRoof() override
	{
		h.makeRoof(75);
	}

	virtual void buildDoor() override
	{
		h.makeDoor(4);
	}

	virtual void buildWindow() override
	{
		h.makeWindow(12);
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
		sum += 100000;
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
	h.getHouse(); // тут нічого не повернеться, бо обєкт не побудований по екземплярам

	cout << "\n\tBreakBuilder" << endl;
	BreakBuilder b;
	d.setBuilder(&b);
	d.construct();
	h = b.getResult();
	h.getHouse(); // виводиться список побудованих екземлярів з параметрами

	cout << "\n\tMoneyBuilder" << endl;
	MoneyBuilder m;
	d.setBuilder(&m);
	d.construct();
	cout << "Sum of builder: " << m.getResult() << endl;

	cout << endl;
	system("pause");
	return 0;

}