#ifndef __POLINOMS_H__
#define __POLINOMS_H__
#include <string>
#include <iostream>

using namespace std;

struct Monom
{
	double coef;     
	int power;       
};

struct List
{
	Monom monom;
	List* pNext;
};

class Polynom
{
	List* pHead;
	static int maxPower;
	void Sort_MaxPower();     // сортировка по максимальной степени

public:
	Polynom();
	Polynom(char* strch);
	Polynom(string str);
	Polynom(const Polynom &polynom);//конструктор копирования
	~Polynom();

	static void SetMaxPower(unsigned int var)
	{
		if (var < 0)
			throw("Error power");
		else
			maxPower = var;
	}
	Polynom operator+(const Polynom &polynom);//оператор сложения полиномов
	Polynom operator-(const Polynom &polynom);//оператор вычитания полиномов
	Polynom operator*(const Polynom &polynom);//оператор умножения полиномов
	Polynom operator=(const Polynom &polynom);//оператор присваивания
	void PrintPolynom();//распечатать полином
	string PolynomToString();//преоьразовать полином в строчку
	int Calculate(int x);           //подсчет результата
};

#endif
