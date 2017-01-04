#include "stdafx.h"
#include "Money.h"

// ������� ������� ������ � �����
void Money::repare(Money &obj)
{
	obj.bucks = obj.bucks + (obj.cents / 100);
	obj.cents = obj.cents % 100;
}

Money::Money()
{
}

Money::Money(long a, long b) : bucks(a), cents(b)
{
}


Money::~Money()
{
}

Money Money::add(Money & obj) const
{
	Money result;
	result.bucks = bucks + obj.bucks;
	result.cents = cents + obj.cents;
	
	repare(result);
	return Money();
}

Money Money::mul(Money & obj) const
{
	Money result;
	result.bucks = bucks * obj.bucks;
	result.cents = cents * obj.cents;

	repare(result);
}

Money Money::sub(Money & obj) const
{
	Money result;
	result.bucks = bucks - obj.bucks;
	result.cents = cents - obj.cents;

	repare(result);
}

Money Money::div(Money & obj) const
{
	Money result;
	result.bucks = bucks / obj.bucks;
	result.cents = cents / obj.cents;

	repare(result);
}

// �������� �����
istream &operator >>(istream &is, Money &obj)
{
	string str;
	is >> str;
	// ����� � ������ ������ �������
	std::size_t found = str.find_first_of(",./");
	// �� ������� - �����, ����� - �������
	long a = atoi(str.substr(0, found - 1).c_str());
	long b = atoi(str.substr(found + 1).c_str());
	// ������� ������� ������ � ����� � ������������
	obj.bucks = a + (b / 100);
	obj.cents = b % 100;
	return is;
} // operator>>


  // ���������� �������� ������
ostream &operator <<(ostream &os, const Money &obj)
{
	if (obj.cents == 0)
		os << obj.bucks;
	else
		os << obj.bucks << ',' << obj.cents;
	return os;
} // operator<< 