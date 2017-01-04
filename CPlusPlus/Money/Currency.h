#pragma once
#include "stdafx.h"

class Currency
{
	UINT cash;
public:
	// Конструкторы и деструктор
	Currency();
	Currency(UINT unit, UINT cents);
	~Currency() {}

	// Виртуальные чистые методы
	virtual UINT to_RUB(UINT rate) = 0;
	virtual istream &Input(istream &is) = 0;
	virtual ostream &Show(ostream &os) const = 0;

	// Перегрузка потоковых операций
	friend istream &operator>>(istream &is, Currency &obj);
	friend ostream &operator<<(ostream &os, const Currency &obj);
};

class Dollar : public Currency
{
protected:
	double bucks;
public:
	// Конструкторы и деструктор
	Dollar() : Currency() {}
	Dollar(UINT unit, UINT cents) : Currency(unit, cents) {}
	~Dollar() {}

	// Методы
	virtual UINT to_RUB(UINT rate) { return bucks*rate; }
	virtual istream &Input(istream &is);
	virtual ostream &Show(ostream &os) const;
};

class Euro : public Currency
{
protected:
	double bucks;
public:
	// Конструкторы и деструктор
	Euro() : Currency() {}
	Euro(UINT unit, UINT cents) : Currency(unit, cents) {}
	~Euro() {}

	// Методы
	virtual UINT to_RUB(UINT rate) { return bucks*rate; }
	virtual istream &Input(istream &is);
	virtual ostream &Show(ostream &os) const;
};