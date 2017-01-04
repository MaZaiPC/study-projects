#pragma once

class Rational
{
	int a;
	int b;
	
	void reduce();
public:
	// Љонструктор и деструктор
	Rational();
	~Rational();
	
	// €нструменты
	void Init(int num, int den);	// инициализация полей
	void Read();					// ввод с клавиатуры

	void Display();					// вывод в консоль

	// Арифметические операции
	Rational add(Rational x);
	Rational sub(Rational x);
	Rational mul(Rational x);
	Rational div(Rational x);
	
	// Операции сравнения
	bool less(Rational & f) { return a * f.b < f.a * b; }
	bool greate(Rational & f) { return a * f.b > f.a * b; }
	bool equal(Rational & f) { return a == f.b && b == f.b; }
};

