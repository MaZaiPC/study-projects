#pragma once

class Complex
{
	double a, b;

	friend istream &operator >>(istream &is, Complex &obj);
	friend ostream &operator <<(ostream &os, const Complex &obj);
public:
	Complex(double x=0,double y=0){
        a=x;
        b=y;
    }
	Complex operator +(const Complex &c); //add
    Complex operator *(const Complex &c); //mul
    Complex operator -(const Complex &c); //sub
    Complex operator /(const Complex &c); //div
    bool operator ==(const Complex &c);   //equ
    const Complex& operator =(const Complex &c){
        a=c.a;
        b=c.b;
        return *this;
    }
    Complex conj(); //conj

	void Init(double a, double b);
};