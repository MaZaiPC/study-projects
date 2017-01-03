#pragma once

class Triangle
{
	double a;   // стороны треугольнка
	double b;
	double c;
public:
	// Конструкторы и деструктор
	Triangle();
	Triangle(double a, double b, double c);
	~Triangle();

	// Методы
	double Perimeter();
	double Area();
	double Altitude();
	char Type();
};

