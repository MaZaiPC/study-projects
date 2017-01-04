#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Complex.h"

void execute();
int chois();
void choise();

Application::Application()
{
}

Application::~Application()
{
}

void Application::run()
{
	execute();
	cout << "Демонстрация метода сложение\n";
	cout << "(2+4j)+(2-7j)= ";
	Complex A, B, C;
	A = Complex(2, 4);
	B = Complex(2, -7);
	C = A + B;
	cout << C << "\n\nДемонстрация метода вычитание\n";
	cout << "(2+4j)-(2-7j)= ";
	C = A - B;
	cout << C << "\n\nДемонстрация метода умножение\n";
	cout << "(2+4j)*(2-7j)= ";
	C = A*B;
	cout << C;
	Complex R, T, Y;
	R = Complex(-2, 3);
	T = Complex(7, 1);
	cout << "\n\nДемонстрация метода деление\n";
	cout << "(-2+3j)/(7+1j)= ";
	Y = R / T;
	cout << Y << "\n\nДемонстрация метода сопреженного числа\n";
	cout << "-2+3j= ";
	Y = R.conj();
	cout << Y << "\n\nДемонстрация метода сравнение\n";
	cout << "(-2+3j)==(7+1j)= ";
	if (R == T)
		cout << "Коплексные числа равны\n";
	else cout << "Коплексные числа не равны\n";
	Wrap(2);
	system("pause");
	system("cls");
	cout << "\n   -------------------------------------------------------\n";
	Wrap(12);
	choise();
}

//-----------------------------------------------------------
// 					Реализация меню выбора
//-----------------------------------------------------------
void execute()
{
	tMark(" Задание: \n");
	cout << " Реализовать класс Complex для работы с комплексными числами.\n"
		<< " Комплексное число представляются парой действительных чисел (a, b), где\n"
		<< "\ta — действительная часть, b — мнимая часть. \n"
		<< " Реализовать операции:\n"
		<< "\t- сложения\n"
		<< "\t- вычитания\n"
		<< "\t- умножения\n"
		<< "\t- деления\n"
		<< "\t- сравнения\n"
		<< "\t- сопряжения\n\n";
}
int chois(){
	int chois_1;
	tMark(" Операции комплексными числами:\n");
	cout << "\t1 - Сложение\n"
		<< "\t2 - Вычитание\n "
		<< "\t3 - Умножение\n"
		<< "\t4 - Деление\n"
		<< "\t5 - Сравнение\n"
		<< "\t6 - Сопряженное число\n"
		<< "\t0 - Выход\n\n"
		<< "\n Выберите действие: \n";
	cin >> chois_1;
	while ((chois_1<0) || chois_1>6){
		cout << "     !!!Не корректные данные!!!\n";
		cout << " Ведите заново: ";
		cin >> chois_1;
	}
	return chois_1;
}
void choise(){
	switch (chois()){
	case 1: {
				Complex a, b;
				cout << "Первое число :> ";
				cin >> a;
				cout << "Второе число :> ";
				cin >> b;
				Complex c = a + b;
				cout << c;
				break;
	}
	case 2:{
			   Complex a, b;
			   cout << "Первое число :> ";
			   cin >> a;
			   cout << "Второе число :> ";
			   cin >> b;
			   Complex c = a - b;
			   cout << c;
			   break;
	}
	case 3:{
			   Complex a, b;
			   cout << "Первое число :> ";
			   cin >> a;
			   cout << "Второе число :> ";
			   cin >> b;
			   Complex c = a*b;
			   cout << c;
			   break;
	}
	case 4:{
			   Complex a, b;
			   cout << "Первое число :> ";
			   cin >> a;
			   cout << "Второе число :> ";
			   cin >> b;
			   Complex c = a / b;
			   cout << c;
			   break;
	}
	case 5:{
			   Complex a, b;
			   cout << "Первое число :> ";
			   cin >> a;
			   cout << "Второе число :> ";
			   cin >> b;
			   if (a == b)
				   cout << "Колексные числа равны\n";
			   else cout << "Коплексные числа не равны\n";
			   break;
	}
	case 6:{
			   Complex a;
			   cout << "Комплексное число :> ";
			   cin >> a;
			   cout << "\nКомплексное число: " << a;
			   cout << "\nСопреженное комплексное число: "
				    << a.conj();
			   Wrap(3);
			   break;
	}
	default:exit(0);
	}
	system("pause");
	system("cls");
	choise();

}
//-----------------------------------------------------------
//				Конец реализации меню выбора
//-----------------------------------------------------------