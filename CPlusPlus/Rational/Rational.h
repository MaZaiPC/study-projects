#pragma once

class Rational
{
	int a;
	int b;
	
	void reduce();
public:
	// ����������� � ����������
	Rational();
	~Rational();
	
	// �����������
	void Init(int num, int den);	// ������������� �����
	void Read();					// ���� � ����������

	void Display();					// ����� � �������

	// �������������� ��������
	Rational add(Rational x);
	Rational sub(Rational x);
	Rational mul(Rational x);
	Rational div(Rational x);
	
	// �������� ���������
	bool less(Rational & f) { return a * f.b < f.a * b; }
	bool greate(Rational & f) { return a * f.b > f.a * b; }
	bool equal(Rational & f) { return a == f.b && b == f.b; }
};

