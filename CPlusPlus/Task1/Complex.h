#pragma once
#include "Pair.h"

class Complex : Pair
{
	double a, b;

	friend istream &operator >>(istream &is, Complex &obj);
	friend ostream &operator <<(ostream &os, const Complex &obj);
public:
	Complex() : a(), b() {}
	Complex(double x,double y) : a(x), b(y) {}

	virtual Complex add(Complex &obj) const; // ��������
    virtual Complex mul(Complex &obj) const; // ���������
    virtual Complex sub(Complex &obj) const; // ���������
    virtual Complex div(Complex &obj) const; // �������
};