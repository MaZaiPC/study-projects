#pragma once
#include "Pair.h"

class Fraction : public Pair
{
private:
	long num; //Целая часть
	WORD den; //Дробная часть
public:
	// Конструкторы и деструктор
	Fraction() : num(), den() {};
	Fraction(long, WORD);
	~Fraction() {}

	// Методы класса
	long GetNum() { return num; }
	unsigned short GetDen() { return den; }

	virtual Fraction add(Fraction &obj) const; // Сложение
	virtual Fraction mul(Fraction &obj) const; // Умножение
	virtual Fraction sub(Fraction &obj) const; // Вычитание
	virtual Fraction div(Fraction &obj) const; // Деление
	
	bool is_greater_than(Fraction &obj) const;
	bool is_less_than(Fraction &obj)	const;
	bool is_equal_to(Fraction &obj)		const;

	friend ostream &operator <<(ostream &os, const Fraction &obj);
	friend istream &operator >>(istream &os, Fraction &obj);
};
