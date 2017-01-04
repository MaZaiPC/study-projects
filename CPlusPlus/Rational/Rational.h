#pragma once

class Rational
{
	int a;
	int b;
	
	void reduce();
public:
	// Конструктор и деструктор
	Rational();
	~Rational();
	
	// Инструменты
	void Init(int num, int den);	// инициализаци€ полей
	void Read();					// ввод с клавиатуры

	void Display();					// вывод в консоль

	// јрифметические операции
	Rational add(Rational x);
	Rational sub(Rational x);
	Rational mul(Rational x);
	Rational div(Rational x);
	
	// ќперации сравнени€
	bool less(Rational & f) { return a * f.b < f.a * b; }
	bool greate(Rational & f) { return a * f.b > f.a * b; }
	bool equal(Rational & f) { return a == f.b && b == f.b; }
};

