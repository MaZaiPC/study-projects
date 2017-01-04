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
// Нахождение НОДа
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
// Сокращение дроби
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
// 					Реализация меню выбора
//-----------------------------------------------------------
void execute()
{   
    cout<<" Задание: \n"
		<<" Реализовать класс Rational для работы с дробными числами.\n"
		<<" Дробное число представляются парой действительных чисел (a, b), где\n"
		<<"\ta — действительная часть, b — мнимая часть. \n"
		<<" Реализовать операции:\n"
		<<"\t- сложения\n"
		<<"\t- вычитания\n"
		<<"\t- умножения\n"
		<<"\t- деления\n"
		<<"\t- сравнения\n"
		<<"\t- сопряжения\n\n";
}
int chois(){
    int chois_1;
    cout<<" Операции с дробными числами:\n"
		<<"\t1 - Сложение\n"
		<<"\t2 - Вычитание\n "
		<<"\t3 - Умножение\n"
		<<"\t4 - Деление\n"
		<<"\t5 - Больше\n"
		<<"\t6 - Меньше\n"
		<<"\t7 - Равно\n"
		<<"\t0 - Выход\n\n"
		<<"\n Выберите действие: \n";
    cin>>chois_1;
    while((chois_1<0) || chois_1>6){
        cout<<"     !!!Не корректные данные!!!\n";
        cout<<" Ведите заново: ";
        cin>>chois_1;
    }
    return chois_1;
}
void choise(){
    switch (chois()){
    case 1: {  
        Rational a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Rational c=a+b;
        c.Display();
        break;
            }
    case 2:{  
        Rational a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Rational c=a-b;
        c.Display();
        break;
        }
    case 3 :{  
        Rational a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Rational c=a*b;
        c.Display();
        break;
            }
    case 4:{
        Rational a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Rational c=a/b;
        c.Display();
        break;
           }
    case 5:{
        Rational a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        if(a>b)
            cout<<"Первое больше второго\n";
        else cout<<"Второе больше первого\n";
        break;
           }
case 6:{
        Rational a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        if(a<b)
            cout<<"Первое меньше второго\n";
        else cout<<"Второе меньше первого\n";
        break;
         }
case 7:{
        Rational a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        if(a==b)
            cout<<"Числа равны\n";
        else cout<<"Числа не равны\n";
        break;
         }
    default :exit(0);
    }
    system("pause");
    system("cls");
    choise();
 
}
//-----------------------------------------------------------
//				Конец реализации меню выбора
//-----------------------------------------------------------

void Rational::Init(int num, int den)
{
	a = num;
	b = den;
}