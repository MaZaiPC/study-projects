#include "stdafx.h"
#include "Rational.h"

Rational::Rational()
{
}

Rational::~Rational()
{
}

Rational Rational::add(Rational &x) const
{
    Rational s;
    
    if( this->b == x.b )
    {
        s.a = this->a + x.a;
        s.b = this->b;
    }
    else
    {
        s.b = this->b * x.b;
        s.a = (s.b / this->b * this->a ) + (s.b / x.b * x.a );
    }
    s.reduce();
    return s;
}
Rational Rational::sub(Rational &x) const
{
    Rational s;
    
    if( this->b == x.b )
    {
        s.a = this->a - x.a;
        s.b = this->b;
    }
    else
    {
        s.b = this->b * x.b;
        s.a = (s.b / this->b * this->a ) - (s.b / x.b * x.a );
    }
    s.reduce();
    return s;
}
Rational Rational::mul(Rational &x) const
{
    Rational s;
    s.a = this->a * x.a;
    s.b = this->b * x.b;
    s.reduce();
    return s;
}
Rational Rational::div(Rational &x) const
{
    Rational s;
    s.a = this->a * x.b;
    s.b = this->b * x.a;
    s.reduce();
    return s;
}
// РќР°С…РѕР¶РґРµРЅРёРµ РќРћР”Р°
static int NOD(const int& a1,const int& b1)
{
    int a = abs(a1), b = abs(b1);
    while(a!=0 && b!=0){
        if (a>=b)
            a = a%b;
        else
            b = b%a;
    }
    return a+b;
}
// РЎРѕРєСЂР°С‰РµРЅРёРµ РґСЂРѕР±Рё
void Rational::reduce()
{
    int nod = NOD(a,b);
    a = a/nod;
    b = b/nod;
}

// РћРїРµСЂР°С†РёСЏ РІРІРѕРґР°
istream &operator >>(istream &is, Rational &obj)
{
	int x, y;

	is >> x >> y;

	obj.a = x;
	obj.b = y;
	return is;
} // operator>>


// РџРµСЂРµРіСЂСѓР·РєР° РѕРїРµСЂР°С†РёРё РІС‹РІРѕРґР°
ostream &operator <<(ostream &os, const Rational &obj)
{
	if (obj.b == obj.a)
		os << obj.a;
	else
		os << obj.a << "/" << obj.b;
	return os;
} // operator<< 