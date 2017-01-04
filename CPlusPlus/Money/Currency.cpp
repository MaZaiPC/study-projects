#include "stdafx.h"
#include "Currency.h"

/*----------------Abstractly Class Currency-----------------*/

Currency::Currency() : cash()
{
}

Currency::Currency(UINT unit, UINT cents) : cash(100*unit + cents)
{
}

Currency::~Currency()
{
}

istream &operator>>(istream &is, Currency &obj)
{
	return obj.Input(is);
}

ostream &operator>>(ostream &os, Currency &obj)
{
	return obj.Show(os);
}

/*----------------------Class Dollar------------------------*/

ostream &Dollar::Show(ostream &os) const
{
	os << (cash / 100) << "." << setfill('0') << setw(2) << (cash % 100) << setfill(' ');
	return os;
}

/*----------------------Class Euro------------------------*/

ostream &Euro::Show(ostream &os) const
{
	os << (cash / 100) << "." << setfill('0') << setw(2) << (cash % 100) << setfill(' ');
	return os;
}