#pragma once
#include "stdafx.h"

class Root
{
public:
	// Виртуальные чистые методы
	virtual void Solve(double a, double b, double c) = 0;

	virtual ostream &Show(ostream &os) const = 0;
	friend ostream &operator<<(ostream &os, const Root &obj);
};

class Linear : public Root
{
	double x;
	bool res;
public:
	// Конструкторы и деструктор
	Linear() : x(), res(false) {}
	Linear(double a, double b) { Solve(a, b, NULL); }
	~Linear() {}

	// Методы
	// переменная 'с' не нужна, но требуется абстрактным
	// классом можно ли обойти строгое кол-во переменных?
	virtual void Solve(double a, double b, double c);

	virtual ostream &Show(ostream &os) const;
};

class Square : public Root
{
	double x1;
	double x2;
	bool res;
public:
	// Конструкторы и деструктор
	Square() : x1(), x2(), res(false) {}
	Square(double a, double b, double c) { Solve(a, b, c); }
	~Square() {}

	// Методы
	virtual void Solve(double a, double b, double c);

	virtual ostream &Show(ostream &os) const;
};