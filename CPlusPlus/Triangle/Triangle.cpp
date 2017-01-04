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
		tMark("!!!�� ���������� ������!!!\n",LtRed); cout <<"������� ����: ������� �� �������� �����������!\n\n"
			 <<" ���������� ������� ������: "
			 << "������� �:"; cin>>a;
		cout << "������� B:"; cin>>b;
		cout << "������� C:"; cin>>c;
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

// ���������� �� ������� ������
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

// ������� ���������� ���� ������������. �������� <ABC�.
int GetAngle(double ab, double bc, double ac)
{
	return acos((ab*ab + bc*bc - ac*ac / (2*ab*bc));
}

char Triangle::Type()
{	
	double AngleA = GetAngle(a, b, c); // ���� ABC
	double AngleB = GetAngle(b, c, a); // ���� BCA
	double AngleC = GetAngle(c, a, b); // ���� CAB
	
	// [v]ersatile 	 - ��������������,	Sharp 	- ������
	// [e]quilateral - ��������������,	Obtuse 	- �����
	// [i]sosceles 	 - ��������������,	Right 	- �������������
	
	bool vSharp = AngleA < 90 && AngleB < 90 && AngleC < 90;
	bool eSharp = AngleA == AngleC && AngleB < 90;
	bool iSharp = AngleA == AngleB == AngleC == 60;
	
	bool vObtuse = AngleB > 90 || AngleA > 90 || AngleC > 90;
	bool eObtuse = AngleB > 90;
	
	bool vRight = AngleC == 90;
	bool eRight = AngleA == AngleB == 45;
	
	if (vSharp)
		return "��������������, �������������";
	if (eSharp)
		return "��������������, �������������";
	if (iSharp)
		return "��������������, �������������";
	
	if (vObtuse)
		return "��������������, ������������";
	if (eObtuse)
		return "��������������, ������������";
	
	if (vRight)
		return "��������������, �������������";
	if (eRight)
		return "��������������, �������������";
}

// Get/Set
void Triangle::Display(){
    cout <<   "������� �:" << a
		 << "\n������� B:" << b
		 << "\n������� C:" << c << endl;
}
Triangle Triangle::Read(){
    double a,b,c;
    cout<<" ������ ����� ������ ������������: "
			 << "������� �:"; cin>>a;
		cout << "������� B:"; cin>>b;
		cout << "������� C:"; cin>>c;
    Triangle A=Triangle(a,b,c);
    return A;
}