#include "stdafx.h"
#include "Rational.h"

Rational::Rational()
{
}

Rational::~Rational()
{
}

// Инициализация - присваивание начальных значений
// полям класса
void Rational::Init(int num, int den)
{
	a = num;
	b = den;
} // Rational::Init


// Ввод значений полей с клавиатуры
void Rational::Read()
{
	cout << "\nЧислитель: "; cin >> a;
	cout << "\nЗнаменатель: "; cin >> b;
} // Rational::Read

// Вывод в консоль
void Rational::Display() {cout << (b == 1 || a == 0 ? a : a << '/' << b); }

Rational Rational::add(Rational x)
{
	Rational d;
	if( this->b == x.b ) {
		d.a = this->a + x.a;
		d.b = this->b;
	} else {
		d.b = this->b * x.b;
		d.a = (d.b / this->b * this->a ) + (d.b / x.b * x.a );
	}
	d.reduce();
	return d;
} // Rational::add

Rational Rational::sub(Rational x)
{
	Rational y;    
	if( this->b == x.b ) {
		y.a = this->a - x.a;
		y.b = this->b;
	} else {
		y.b = this->b * x.b;
		y.a = (y.b / this->b * this->a ) - (y.b / x.b * x.a );
	}
	y.reduce();
	return y;
} // Rational::sub

Rational Rational::mul(Rational x)
{
	Rational t;
	t.a = this->a * x.a;
	t.b = this->b * x.b;
	t.reduce();
	return t;
} // Rational::mul

Rational Rational::div(Rational x)
{
	Rational t;
	t.a = this->a * x.b;
	t.b = this->b * x.a;
	t.reduce();
	return t;
} // Rational::div

// Нахождение НОДа
static int NOD(const int& a1,const int& b1)
{
	int a = abs(a1), b = abs(b1);
	while(a!=0 && b!=0){
		if (a>=b)
			a = a%b;
		else
			b = b%a;
	}
	return a+b;
}
// Сокращение дроби
void Rational::reduce()
{
	int nod = NOD(a,b);
	a = a/nod;
	b = b/nod;
}