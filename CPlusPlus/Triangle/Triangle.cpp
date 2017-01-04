#include "stdafx.h"
#include "Triangle.h"
#include "Utils.h"


Triangle::Triangle()
{
	a = 1.0;
	b = 1.0;
	c = 1.0;
} // Triangle::Triangle


Triangle::Triangle(double a, double b, double c)
{
	while((a <= 0. || b <= 0. || c <= 0.) || (!(a < c + b && b < a + c && c < a + b))){
		tMark("!!!Не корректные данные!!!\n",LtRed); cout <<"Причина сбоя: стороны не образуют треугольник!\n\n"
			 <<" Пожалуйста введите заново: "
			 << "Сторона А:"; cin>>a;
		cout << "Сторона B:"; cin>>b;
		cout << "Сторона C:"; cin>>c;
		system("cls");
	}
	
	this->a = a;
	this->b = b;
	this->c = c;
} // Triangle::Triangle


Triangle::~Triangle()
{
}

double Triangle::Perimeter()
{
	return a + b + c;
}

// Вычисление по формуле Герона
double Triangle::Area()
{
	double p = Perimeter() / 2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

double Triangle::Altitude()
{
	double S = Area();
	return 2*S/a;
}

// Функция возвращает угол треугольника. Например <ABC°.
int GetAngle(double ab, double bc, double ac)
{
	return acos((ab*ab + bc*bc - ac*ac / (2*ab*bc));
}

char Triangle::Type()
{	
	double AngleA = GetAngle(a, b, c); // Угол ABC
	double AngleB = GetAngle(b, c, a); // Угол BCA
	double AngleC = GetAngle(c, a, b); // Угол CAB
	
	// [v]ersatile 	 - разносторонний,	Sharp 	- острый
	// [e]quilateral - равносторонний,	Obtuse 	- тупой
	// [i]sosceles 	 - равнобедренный,	Right 	- прямоугольный
	
	bool vSharp = AngleA < 90 && AngleB < 90 && AngleC < 90;
	bool eSharp = AngleA == AngleC && AngleB < 90;
	bool iSharp = AngleA == AngleB == AngleC == 60;
	
	bool vObtuse = AngleB > 90 || AngleA > 90 || AngleC > 90;
	bool eObtuse = AngleB > 90;
	
	bool vRight = AngleC == 90;
	bool eRight = AngleA == AngleB == 45;
	
	if (vSharp)
		return "разносторонний, остроугольный";
	if (eSharp)
		return "равносторонний, остроугольный";
	if (iSharp)
		return "равнобедренный, остроугольный";
	
	if (vObtuse)
		return "разносторонний, тупоугольный";
	if (eObtuse)
		return "равнобедренный, тупоугольный";
	
	if (vRight)
		return "разносторонний, прямоугольный";
	if (eRight)
		return "равнобедренный, прямоугольный";
}

// Get/Set
void Triangle::Display(){
    cout <<   "Сторона А:" << a
		 << "\nСторона B:" << b
		 << "\nСторона C:" << c << endl;
}
Triangle Triangle::Read(){
    double a,b,c;
    cout<<" Ведите длину сторон треугольника: "
			 << "Сторона А:"; cin>>a;
		cout << "Сторона B:"; cin>>b;
		cout << "Сторона C:"; cin>>c;
    Triangle A=Triangle(a,b,c);
    return A;
}