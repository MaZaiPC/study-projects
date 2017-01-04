/*	

Main.cpp  
Главный файл - проверка операций с классом Rational

- метод инициализации Init()
- метод чтения с клавиатуры Read()
- метод вывода на экран Display()
- арифметические операции, 
- операции сравнения

*/

#include "stdafx.h"
#include "Utils.h"
#include "Rational.h"


HANDLE h;


int main(int argc, char *argv[])
{
	init();

	Rational a, b, c;
	cout << "Тестирование класса Rational\n\n";
	Sleep(1200);

	cout << "\nТест Init() и Display():\n";
	a.Init(1, 2);
	cout << "\nДробь a: "; a.Display();
	Sleep(1200);

	cout << "\n\nТест метода ввода Read():\n";
	b.Read();
	cout << "\nВы ввели: ";	b.Display();
	Sleep(1200);

	cout << "\n\nТест арифметических операций:\n";
	c = a.add(b);
	cout << "\nСложение : ";  a.Display();  cout << " + ";  b.Display();
	cout << " = "; c.Display();

	c = a.sub(b);
	cout << "\nВычитание: ";  a.Display(); cout << " - ";  b.Display();
	cout << " = "; c.Display();

	c = a.mul(b);
	cout << "\nУмножение: ";  a.Display(); cout << " * "; b.Display();
	cout << " = "; c.Display();

	c = a.div(b);
	cout << "\nДеление  : ";  a.Display(); cout << " / "; b.Display();
	cout << " = "; c.Display();
	Sleep(1200);
	cout << "\n\nТест арифметических операций:\n";
	c = a.greate(b);
	cout << "\nБольше  : ";  a.Display(); cout << " > "; b.Display();
	cout << " = "; c.Display();
	c = a.less(b);
	cout << "\nМеньше  : ";  a.Display(); cout << " < "; b.Display();
	cout << " = "; c.Display();
	c = a.equal(b);
	cout << "\nРавно  : ";  a.Display(); cout << " == "; b.Display();
	cout << " = "; c.Display();
	Sleep(1200);

	cout << "\n\nКонец работы. ";
	return 0;
} // main



