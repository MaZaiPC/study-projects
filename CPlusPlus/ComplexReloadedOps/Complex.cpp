#include "stdafx.h"
#include "Complex.h"

Complex Complex::operator +(const Complex &c){
	Complex d;
	d.a = a + c.a;
	d.b = b + c.b;
	return d;
} //add
Complex Complex::operator *(const Complex &c){
	Complex t;
	t.a = a*c.a - b*c.b;
	t.b = a*c.b + b*c.a;
	return t;
} //mul
Complex Complex::operator /(const Complex &c){
	Complex t;
	t.a = (a*c.a + b*c.b) / (a*a + b*b);
	t.b = (b*c.a - a*c.b) / (a*a + b*b);
	return t;
} //div
Complex Complex::operator -(const Complex &c){
	Complex y;
	y.a = a - c.a;
	y.b = b - c.b;
	return y;
} //sub
bool Complex::operator ==(const Complex &c){
	if ((a == c.a) && (b == c.b))
		return true;
	return false;
} //equ
Complex Complex::conj(){
	a = a;
	b = -b;
	return *this;
} //conj

void Complex::Init(double a, double b)
{
	this->a = a;
	this->b = b;
}

// Операция ввода
istream &operator >>(istream &is, Complex &obj)
{
	int x, y;

	is >> x >> y;

	obj.Init(x, y);
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