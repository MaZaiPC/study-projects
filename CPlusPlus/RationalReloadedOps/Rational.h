#pragma once

class Rational
{
	int a,b;
	void reduce()
public:
	Rational();
	~Rational();
	
	
	Rational operator +(const Rational x); //add
    Rational operator *(const Rational x); //mul
    Rational operator -(const Rational x); //sub
    Rational operator /(const Rational x); //div
    bool operator < (const Rational & f);  //less
	bool operator > (const Rational & f);  //greate
	bool operator == (const Rational & f); //equal
    Rational Read();
    void Display();
	void Init(int num, int den);
};