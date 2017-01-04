#include "stdafx.h"
#include "Complex.h"
#include <cmath>

Complex Complex::operator +(const Complex &c){
    Complex d;
    d.comp.a=comp.a+c.comp.a;
    d.comp.b=comp.b+c.comp.b;
    return d;
} //add
Complex Complex::operator *(const Complex &c){
    Complex t;
    t.comp.a=comp.a*c.comp.a-comp.b*c.comp.b;
    t.comp.b=comp.a*c.comp.b+comp.b*c.comp.a;
    return t;
} //mul
Complex Complex::operator /(const Complex &c){
    Complex t;
    t.comp.a=(comp.a*c.comp.a+comp.b*c.comp.b)/(comp.a*comp.a+comp.b*comp.b);
    t.comp.b=(comp.b*c.comp.a-comp.a*c.comp.b)/(comp.a*comp.a+comp.b*comp.b);
    return t;
} //div
Complex Complex::operator -(const Complex &c){
    Complex y;
    y.comp.a=comp.a-c.comp.a;
    y.comp.b=comp.b-c.comp.b;
    return y;
} //sub
bool Complex::operator ==(const Complex &c){
        if((comp.a==c.comp.a)&&(comp.b==c.comp.b))
            return true;
        return false;
} //equ
Complex Complex::conj(){
    comp.a=comp.a;
    comp.b=-comp.b;
    return *this;
} //conj
void Complex::Display(){
        if(comp.b>=0)
            cout<<comp.a<<"+"<<comp.b<<"i\n";
        else
            cout<<comp.a<<comp.b<<"i\n";
}
Complex Complex::Read(){
    double a,b;
    cout<<"Р”РµР№СЃС‚РІРёС‚РµР»СЊРЅРІР°СЏ С‡Р°СЃС‚СЊ: ";
    cin>>a;
    cout<<"РњРЅРёРјР°СЏ С‡Р°СЃС‚СЊ: ";
    cin>>b;
    Complex A=Complex(a,b);
    return A;
}

//-----------------------------------------------------------
// 					Р РµР°Р»РёР·Р°С†РёСЏ РјРµРЅСЋ РІС‹Р±РѕСЂР°
//-----------------------------------------------------------
void execute()
{   
    cout<<" Р—Р°РґР°РЅРёРµ: \n"
		<<" Р РµР°Р»РёР·РѕРІР°С‚СЊ РєР»Р°СЃСЃ Complex РґР»СЏ СЂР°Р±РѕС‚С‹ СЃ РєРѕРјРїР»РµРєСЃРЅС‹РјРё С‡РёСЃР»Р°РјРё.\n"
		<<" РљРѕРјРїР»РµРєСЃРЅРѕРµ С‡РёСЃР»Рѕ РїСЂРµРґСЃС‚Р°РІР»СЏСЋС‚СЃСЏ РїР°СЂРѕР№ РґРµР№СЃС‚РІРёС‚РµР»СЊРЅС‹С… С‡РёСЃРµР» (a, b), РіРґРµ\n"
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
    cout<<" РћРїРµСЂР°С†РёРё РєРѕРјРїР»РµРєСЃРЅС‹РјРё С‡РёСЃР»Р°РјРё:\n"
		<<"\t1 - РЎР»РѕР¶РµРЅРёРµ\n"
		<<"\t2 - Р’С‹С‡РёС‚Р°РЅРёРµ\n "
		<<"\t3 - РЈРјРЅРѕР¶РµРЅРёРµ\n"
		<<"\t4 - Р”РµР»РµРЅРёРµ\n"
		<<"\t5 - РЎСЂР°РІРЅРµРЅРёРµ\n"
		<<"\t6 - РЎРѕРїСЂСЏР¶РµРЅРЅРѕРµ С‡РёСЃР»Рѕ\n"
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
        Complex a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        Complex c=a+b;
        c.Display();
        break;
            }
    case 2:{  
        Complex a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        Complex c=a-b;
        c.Display();
        break;
        }
    case 3 :{  
        Complex a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        Complex c=a*b;
        c.Display();
        break;
            }
    case 4:{
        Complex a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        Complex c=a/b;
        c.Display();
        break;
           }
    case 5:{
        Complex a,b;
        cout<<"РџРµСЂРІРѕРµ С‡РёСЃР»Рѕ:\n";
        a=a.Read();
        cout<<"Р’С‚РѕСЂРѕРµ С‡РёСЃР»Рѕ:\n";
        b=b.Read();
        if(a==b)
            cout<<"РљРѕР»РµРєСЃРЅС‹Рµ С‡РёСЃР»Р° СЂР°РІРЅС‹\n";
        else cout<<"РљРѕРїР»РµРєСЃРЅС‹Рµ С‡РёСЃР»Р° РЅРµ СЂР°РІРЅС‹\n";
        break;
           }
case 6:{
        Complex a;
        cout<<"РљРѕРјРїР»РµРєСЃРЅРѕРµ С‡РёСЃР»Рѕ : \n";
        a=a.Read();
        cout<<"РљРѕРјРїР»РµРєСЃРЅРѕРµ С‡РёСЃР»Рѕ : ";
        a.Display();
        Complex c=a.conj();
        cout<<"\nРЎРѕРїСЂРµР¶РµРЅРЅРѕРµ РєРѕРјРїР»РµРєСЃРЅРѕРµ С‡РёСЃР»Рѕ :";
        c.Display();
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

void Complex::Init()
{
    execute();
    cout<<"Р”РµРјРѕРЅСЃС‚СЂР°С†РёСЏ РјРµС‚РѕРґР° СЃР»РѕР¶РµРЅРёРµ\n";
    cout<<"(2+4j)+(2-7j)= ";
    Complex A,B,C;
    A=Complex(2,4);
    B=Complex(2,-7);
    C=A+B;
    C.Display();
    cout<<"\nР”РµРјРѕРЅСЃС‚СЂР°С†РёСЏ РјРµС‚РѕРґР° РІС‹С‡РёС‚Р°РЅРёРµ\n";
    cout<<"(2+4j)-(2-7j)= ";
    C=A-B;
    C.Display();
    cout<<"\nР”РµРјРѕРЅСЃС‚СЂР°С†РёСЏ РјРµС‚РѕРґР° СѓРјРЅРѕР¶РµРЅРёРµ\n";
    cout<<"(2+4j)*(2-7j)= ";
    C=A*B;
    C.Display();
    Complex R,T,Y;
    R=Complex(-2,3);
    T=Complex(7,1);
    cout<<"\nР”РµРјРѕРЅСЃС‚СЂР°С†РёСЏ РјРµС‚РѕРґР° РґРµР»РµРЅРёРµ\n";
    cout<<"(-2+3j)/(7+1j)= ";
    Y=R/T;
    Y.Display();
    cout<<"\nР”РµРјРѕРЅСЃС‚СЂР°С†РёСЏ РјРµС‚РѕРґР° СЃРѕРїСЂРµР¶РµРЅРЅРѕРіРѕ С‡РёСЃР»Р°\n";
    cout<<"-2+3j= ";
    Y=R.conj();
    Y.Display();
    cout<<"\nР”РµРјРѕРЅСЃС‚СЂР°С†РёСЏ РјРµС‚РѕРґР° СЃСЂР°РІРЅРµРЅРёРµ\n";
    cout<<"(-2+3j)==(7+1j)= ";
    if(R==T) 
        cout<<"РљРѕРїР»РµРєСЃРЅС‹Рµ С‡РёСЃР»Р° СЂР°РІРЅС‹\n";
    else cout<<"РљРѕРїР»РµРєСЃРЅС‹Рµ С‡РёСЃР»Р° РЅРµ СЂР°РІРЅС‹\n";
    system("pause");
    system("cls");
    cout<<"\n   -------------------------------------------------------\n";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    choise();
}