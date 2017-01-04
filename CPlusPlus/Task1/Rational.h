#pragma once
#include "Pair.h"

class Rational : Pair
{
	int a,b;
	void reduce();

	friend istream &operator >>(istream &is, Rational &obj);
	friend ostream &operator <<(ostream &os, const Rational &obj);
public:
	Rational() : a(1), b(1) {}
	Rational(double x,double y) : a(x), b(y) {}
	~Rational();
	
	virtual Rational add(Rational &obj) const; //add
    virtual Rational mul(Rational &obj) const; //mul
    virtual Rational sub(Rational &obj) const; //sub
	virtual Rational div(Rational &obj) const; //div
};