#pragma once
#include "Pair.h"

class Fraction : public Pair
{
private:
	long num; //����� �����
	WORD den; //������� �����
public:
	// ������������ � ����������
	Fraction() : num(), den() {};
	Fraction(long, WORD);
	~Fraction() {}

	// ������ ������
	long GetNum() { return num; }
	unsigned short GetDen() { return den; }

	virtual Fraction add(Fraction &obj) const; // ��������
	virtual Fraction mul(Fraction &obj) const; // ���������
	virtual Fraction sub(Fraction &obj) const; // ���������
	virtual Fraction div(Fraction &obj) const; // �������
	
	bool is_greater_than(Fraction &obj) const;
	bool is_less_than(Fraction &obj)	const;
	bool is_equal_to(Fraction &obj)		const;

	friend ostream &operator <<(ostream &os, const Fraction &obj);
	friend istream &operator >>(istream &os, Fraction &obj);
};
