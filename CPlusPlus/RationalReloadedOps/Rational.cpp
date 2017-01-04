#include "stdafx.h"
#include "Rational.h"
#include <cmath>

Rational::Rational()
{
}

Rational::~Rational()
{
}

Rational operator+( Rational x)
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
Rational operator-( Rational x)
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
Rational operator*( Rational x)
{
    Rational s;
    s.a = this->a * x.a;
    s.b = this->b * x.b;
    s.reduce();
    return s;
}
Rational operator/( Rational x)
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

bool Rational::operator < (const Rational & f) const { return a * f.b < f.a * b; }
bool Rational::operator > (const Rational & f) const { return a * f.b > f.a * b; }
bool Rational::operator == (const Rational & f) const { return a == f.b && b == f.b; }

//-----------------------------------------------------------
// 					Р РµР°Р»РёР·Р°С†РёСЏ РјРµРЅСЋ РІС‹Р±РѕСЂР°
//-----------------------------------------------------------
void execute()
{   
    cout<<" Р—Р°РґР°РЅРёРµ: \n"
		<<" Р РµР°Р»РёР·РѕРІР°С‚СЊ РєР»Р°СЃСЃ Rational РґР»СЏ СЂР°Р±РѕС‚С‹ СЃ РґСЂРѕР±РЅС‹РјРё С‡РёСЃР»Р°РјРё.\n"
		<<" Р”СЂРѕР±РЅРѕРµ С‡РёСЃР»Рѕ РїСЂРµРґСЃС‚Р°РІР»СЏСЋС‚СЃСЏ РїР°СЂРѕР№ РґРµР№СЃС‚РІРёС‚РµР»СЊРЅС‹С… С‡РёСЃРµР» (a, b), РіРґРµ\n"
		<<"\ta вЂ” РґРµР№СЃС‚РІРёС‚РµР»СЊРЅР°СЏ С‡Р°СЃС‚СЊ, b вЂ” РјРЅРёРјР°СЏ С‡Р°СЃС‚СЊ. \n"
		<<" Р РµР°Р»РёР·РѕРІР°С‚СЊ РѕРїРµСЂР°С†РёРё:\n"
		<<"\t- СЃР»РѕР¶РµРЅРёСЏ\n"
		<<"\t- РІС‹С‡РёС‚Р°РЅРёСЏ\n"
		<<"\t- СѓРјРЅРѕР¶РµРЅРёСЏ\n"
		<<"\t- РґРµР»РµРЅРёСЏ\n"
		<<"\t- СЃСЂР°РІРЅРµРЅРёСЏ\n"
		<<"\t- СЃРѕРїСЂСЏР¶РµРЅРёСЏ\n\n";
}
int chois(){
    int chois_1;
    cout<<" РћРїРµСЂР°С†РёРё СЃ РґСЂРѕР±РЅС‹РјРё С‡РёСЃР»Р°РјРё:\n"
		<<"\t1 - РЎР»РѕР¶РµРЅРёРµ\n"
		<<"\t2 - Р’С‹С‡РёС‚Р°РЅРёРµ\n "
		<<"\t3 - РЈРјРЅРѕР¶РµРЅРёРµ\n"
		<<"\t4 - Р”РµР»РµРЅРёРµ\n"
		<<"\t5 - Р‘РѕР»СЊС€Рµ\n"
		<<"\t6 - РњРµРЅСЊС€Рµ\n"
		<<"\t7 - Р Р°РІРЅРѕ\n"
		<<"\t0 - Р’С‹С…РѕРґ\n\n"
		<<"\n Р’С‹Р±РµСЂРёС‚Рµ РґРµР№СЃС‚РІРёРµ: \n";
    cin>>chois_1;
    while((chois_1<0) || chois_1>6){
        cout<<"     !!!РќРµ РєРѕСЂСЂРµРєС‚РЅС‹Рµ РґР°РЅРЅС‹Рµ!!!\n";
        cout<<" Р’РµРґРёС‚Рµ Р·Р°РЅРѕРІРѕ: ";
        cin>>chois_1;
    }
    return chois_1;
}
void choise(){
    switch (chois()){
    case 1: {  
        Rational a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        Rational c=a+b;
        c.Display();
        break;
            }
    case 2:{  
        Rational a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        Rational c=a-b;
        c.Display();
        break;
        }
    case 3 :{  
        Rational a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        Rational c=a*b;
        c.Display();
        break;
            }
    case 4:{
        Rational a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        Rational c=a/b;
        c.Display();
        break;
           }
    case 5:{
        Rational a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        if(a>b)
            cout<<"РџРµСЂРІРѕРµ Р±РѕР»СЊС€Рµ РІС‚РѕСЂРѕРіРѕ\n";
        else cout<<"Р’С‚РѕСЂРѕРµ Р±РѕР»СЊС€Рµ РїРµСЂРІРѕРіРѕ\n";
        break;
           }
case 6:{
        Rational a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        if(a<b)
            cout<<"РџРµСЂРІРѕРµ РјРµРЅСЊС€Рµ РІС‚РѕСЂРѕРіРѕ\n";
        else cout<<"Р’С‚РѕСЂРѕРµ РјРµРЅСЊС€Рµ РїРµСЂРІРѕРіРѕ\n";
        break;
         }
case 7:{
        Rational a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        if(a==b)
            cout<<"Р§РёСЃР»Р° СЂР°РІРЅС‹\n";
        else cout<<"Р§РёСЃР»Р° РЅРµ СЂР°РІРЅС‹\n";
        break;
         }
    default :exit(0);
    }
    system("pause");
    system("cls");
    choise();
 
}
//-----------------------------------------------------------
//				РљРѕРЅРµС† СЂРµР°Р»РёР·Р°С†РёРё РјРµРЅСЋ РІС‹Р±РѕСЂР°
//-----------------------------------------------------------

void Rational::Init(int num, int den)
{
	a = num;
	b = den;
}