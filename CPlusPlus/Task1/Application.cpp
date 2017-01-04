#include "stdafx.h"
#include "Utils.h"
#include "Application.h"

Application::Application(): pPair(nullptr)
{
} // Application::Application

Application::~Application()
{
} // Application::~Application

// Главный метод приложения - обработка команд пользователя  
void Application::run()
{
	UINT cmd;                // Команда меню
	bool flagExit = false;   // Флаг выхода из бесконечного цикла
	char *szMenu = "\t\t\t\t *** М Е Н Ю ***\n"
			"\t\t\t    1. Проверка класса Complex\n"
			"\t\t\t    0. Выход\n"
			"\t\t\t    Ваш выбор (0, ..., 2)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 1);

		switch (cmd) {
		case 1:
			testComplex();
			break;
		case 0:
			flagExit = true;
			break;
		} // switch
		if (flagExit) break;
		GotoXY(0, 24);
		system("pause");
	} // while

	// Возвращаем стандартный вид окну
	// размер 80 х 25, серые символы на черном фоне
	SetWindow(80, 25, 0x07);
	Clear();
	WriteXY(34, 12, "Конец работы");
	GotoXY(0, 24);
} // Application::run

// Тестирование класса Complex
void Application::testComplex()
{

	WriteXY(26, 10, "Тестирование класса Complex");
	
	Complex a;
	cout << "Введите комплексное число a: "; cin >> a;
	cout << "a == " << a << endl;
	Complex b(2, 3);
	cout << "b == " << b << endl;
	cout << "a + b " << a.add(b) << endl;
	Sleep(500);
	cout << "a - b " << a.sub(b) << endl;
	Sleep(500);
	cout << "a * b " << a.mul(b) << endl;
	Sleep(500);
	cout << "a / b " << a.div(b) << endl;
}// Application::testEllipse

// Тестирование класса Rational
void Application::testRational()
{

	WriteXY(26, 10, "Тестирование класса Rational");

	Rational a;
	cout << "Введите рациональную дробь число a: "; cin >> a;
	cout << "a == " << a << endl;
	Rational b(2, 3);
	cout << "b == " << b << endl;
	cout << "a + b " << a.add(b) << endl;
	Sleep(500);
	cout << "a - b " << a.sub(b) << endl;
	Sleep(500);
	cout << "a * b " << a.mul(b) << endl;
	Sleep(500);
	cout << "a / b " << a.div(b) << endl;
}// Application::testEllipse