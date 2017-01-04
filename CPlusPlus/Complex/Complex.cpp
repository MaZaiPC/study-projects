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
    cout<<"Действительнвая часть: ";
    cin>>a;
    cout<<"Мнимая часть: ";
    cin>>b;
    Complex A=Complex(a,b);
    return A;
}

//-----------------------------------------------------------
// 					Реализация меню выбора
//-----------------------------------------------------------
void execute()
{   
    cout<<" Задание: \n"
		<<" Реализовать класс Complex для работы с комплексными числами.\n"
		<<" Комплексное число представляются парой действительных чисел (a, b), где\n"
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
    cout<<" Операции комплексными числами:\n"
		<<"\t1 - Сложение\n"
		<<"\t2 - Вычитание\n "
		<<"\t3 - Умножение\n"
		<<"\t4 - Деление\n"
		<<"\t5 - Сравнение\n"
		<<"\t6 - Сопряженное число\n"
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
        Complex a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Complex c=a+b;
        c.Display();
        break;
            }
    case 2:{  
        Complex a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Complex c=a-b;
        c.Display();
        break;
        }
    case 3 :{  
        Complex a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Complex c=a*b;
        c.Display();
        break;
            }
    case 4:{
        Complex a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        Complex c=a/b;
        c.Display();
        break;
           }
    case 5:{
        Complex a,b;
        cout<<"Первое число:\n";
        a=a.Read();
        cout<<"Второе число:\n";
        b=b.Read();
        if(a==b)
            cout<<"Колексные числа равны\n";
        else cout<<"Коплексные числа не равны\n";
        break;
           }
case 6:{
        Complex a;
        cout<<"Комплексное число : \n";
        a=a.Read();
        cout<<"Комплексное число : ";
        a.Display();
        Complex c=a.conj();
        cout<<"\nСопреженное комплексное число :";
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
//				Конец реализации меню выбора
//-----------------------------------------------------------

void Complex::Init()
{
    execute();
    cout<<"Демонстрация метода сложение\n";
    cout<<"(2+4j)+(2-7j)= ";
    Complex A,B,C;
    A=Complex(2,4);
    B=Complex(2,-7);
    C=A+B;
    C.Display();
    cout<<"\nДемонстрация метода вычитание\n";
    cout<<"(2+4j)-(2-7j)= ";
    C=A-B;
    C.Display();
    cout<<"\nДемонстрация метода умножение\n";
    cout<<"(2+4j)*(2-7j)= ";
    C=A*B;
    C.Display();
    Complex R,T,Y;
    R=Complex(-2,3);
    T=Complex(7,1);
    cout<<"\nДемонстрация метода деление\n";
    cout<<"(-2+3j)/(7+1j)= ";
    Y=R/T;
    Y.Display();
    cout<<"\nДемонстрация метода сопреженного числа\n";
    cout<<"-2+3j= ";
    Y=R.conj();
    Y.Display();
    cout<<"\nДемонстрация метода сравнение\n";
    cout<<"(-2+3j)==(7+1j)= ";
    if(R==T) 
        cout<<"Коплексные числа равны\n";
    else cout<<"Коплексные числа не равны\n";
    system("pause");
    system("cls");
    cout<<"\n   -------------------------------------------------------\n";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    choise();
}