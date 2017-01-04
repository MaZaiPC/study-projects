#include "stdafx.h"
#include "Fraction.h"

Fraction::Fraction(long a, WORD b) : num(a), den(b)
{
}

Fraction Fraction::add(Fraction & obj) const
{
	Fraction  result;
	result.num = (num * obj.den) + (obj.num*den);
	result.den = den * obj.den;
	return result;
}

Fraction Fraction::mul(Fraction & obj) const
{
	Fraction  result;
	result.num = num * obj.num;
	result.den = den * obj.den;
	return result;
}

Fraction Fraction::sub(Fraction & obj) const
{
	Fraction  result;
	result.num = (num * obj.den) - (obj.num*den);
	result.den = den * obj.den;
}

Fraction Fraction::div(Fraction & obj) const
{
	Fraction result;
	result.num = num * obj.den;
	result.den = den * obj.num;
	return result;
}

bool Fraction::is_greater_than(Fraction &obj) const
{
	int f1;
	int f2;
	f1 = (num / den);
	f2 = (obj.num / obj.den);

	return f1 > f2;
}

bool Fraction::is_less_than(Fraction & obj) const
{
	return !is_greater_than(obj);
}

bool Fraction::is_equal_to(Fraction &obj) const
{
	return (num / den) == (obj.num / obj.den);
}

istream &operator >>(istream &os, Fraction &obj)
{
	string str;
	os >> str;
	// поиск в строке первой запятой
	std::size_t found = str.find_first_of("/");
	// до запятой - рубли, после - копейки
	obj.num = atoi(str.substr(0, found - 1).c_str());
	obj.den = atoi(str.substr(found + 1).c_str());
	return os;
}
// Перегрузка операции вывода
ostream &operator <<(ostream &os, const Fraction &obj)
{
	long num = obj.num;
	WORD den = obj.den;

	if (num>den || den>num)
	{
		for (int i = 2; i < (num>den ? den : num); i++)
		{
			while (num % i == 0 & den % i == 0)
			{
				num = (num / i);
				den = (den / i);
			} // while
		} // for
	} // if

	os << num << "/" << den;
	return os;
} // operator<< 