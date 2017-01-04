#include "stdafx.h"
#include "Complex.h"

Complex Complex::add(Complex &c) const
{
	Complex d;
	d.a = a + c.a;
	d.b = b + c.b;
	return d;
} //add
Complex Complex::mul(Complex &c) const
{
	Complex t;
	t.a = a*c.a - b*c.b;
	t.b = a*c.b + b*c.a;
	return t;
} //mul
Complex Complex::div(Complex &c) const
{
	Complex t;
	t.a = (a*c.a + b*c.b) / (a*a + b*b);
	t.b = (b*c.a - a*c.b) / (a*a + b*b);
	return t;
} //div
Complex Complex::sub(Complex &c) const
{
	Complex y;
	y.a = a - c.a;
	y.b = b - c.b;
	return y;
} //sub

// Операция ввода
istream &operator >>(istream &is, Complex &obj)
{
	int x, y;

	is >> x >> y;

	obj.a = x;
	obj.b = y;
	return is;
} // operator>>


// Перегрузка операции вывода
ostream &operator <<(ostream &os, const Complex &obj)
{
	if (obj.b >= 0)
		os << obj.a << "+" << obj.b << "i";
	else
		os << obj.a << obj.b << "i";
	return os;
} // operator<< 