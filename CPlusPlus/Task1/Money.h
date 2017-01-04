#pragma once
#include "stdafx.h"
#include "Pair.h"

class Money : Pair
{
	long bucks, cents;
	
	static void repare(Money &what);
public:
	// Конструкторы и деструктор
	Money();
	Money(long, long);
	~Money();

	// Виртуальные методы
	virtual Money add(Money &obj) const; // Сложение
	virtual Money mul(Money &obj) const; // Умножение
	virtual Money sub(Money &obj) const; // Вычитание
	virtual Money div(Money &obj) const; // Деление

	friend istream &operator >>(istream &is, Money &obj);
	friend ostream &operator <<(ostream &os, const Money &obj);
};

