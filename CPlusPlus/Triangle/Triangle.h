#pragma once

class Triangle
{
	double a;   // ������� �����������
	double b;
	double c;
public:
	// ������������ � ����������
	Triangle();
	Triangle(double a, double b, double c);
	~Triangle();

	// ������
	double Perimeter();
	double Area();
	double Altitude();
	char Type();
};

