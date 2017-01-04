#pragma once

// Разновидность класса, единственное различие между class- и struct- объектами в том, что по умолчанию в struct- стоит уровень доступа public.
struct complex{
    double a,b;
};

class Complex
{
	complex comp;
public:
	Complex(double x=0,double y=0){
        comp.a=x;
        comp.b=y;
    }
	Complex operator +(const Complex &c); //add
    Complex operator *(const Complex &c); //mul
    Complex operator -(const Complex &c); //sub
    Complex operator /(const Complex &c); //div
    bool operator ==(const Complex &c);   //equ
    const Complex& operator =(const Complex &c){
        comp.a=c.comp.a;
        comp.b=c.comp.b;
        return *this;
    }
    Complex conj(); //conj
    Complex Read();
    void Display();
	void Init();
};