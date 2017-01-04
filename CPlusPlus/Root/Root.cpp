#include "stdafx.h"
#include "Root.h"

/*--------------Abstractly Base Class of Root---------------*/


ostream &operator<<(ostream &os, Root &obj)
{
	return obj.Show(os);
}

/*-------------------Class Linear---------------------*/

void Linear::Solve(double a, double b, double c)
{
    if (a == 0)
    {
        res = false;
        return ;
    }
 
    res = true;
    x = -b / a;
}

ostream &Linear::Show(ostream &os) const
{
	if (res) os << x; else os << "Уравнение не имеет корней!";
	return os;
}

/*-------------------Class Square---------------------*/

void Square::Solve(double a, double b, double c)
{
	const double D = b*b - 4 * a*c;

	if (D < 0) { res = false; return; }
	res = true;

	x1 = (-b - sqrt(D)) / (2 * a);
	x2 = (-b + sqrt(D)) / (2 * a);
}

ostream &Square::Show(ostream &os) const
{
	if (res)
		os << "x1: " << x1 << "\nx2: " << x2;
	else
		os << "Уравнение не имеет корней!";
	return os;
}