#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Currency.h"


Application::Application()
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
	char *szMenu = "\t*** М Е Н Ю ***\n"
			"1. Тестирование класса Dollar\n"
			"2. Тестирование класса Euro\n"
			"0. Выход\n"
			"   Ваш выбор (0, ..., 2)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 2);

		switch (cmd) {
		case 1:
			test_dollar();
			break;
		case 2:
			test_euro();
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


//// Это обычные вызовы методов для класса
//void Application::TestShape()
//{
//	Shape shape, *pShape = &shape;
//	
//	// Это не виртуальные (полиморфные) вызовы, т.к. тип указателя
//	// и тип адресуемого объекта известны на этапе компиляции 
//	pShape->Input();
//	pShape->Show();
//
//	delete pShape;
//} // Application::TestShape


void Application::test_dollar()
{
	pCurrency = new Dollar(100, 0);

	GotoXY(5, 12); cout << *pCurrency;
	UINT rubles = pCurrency->to_RUB(65.5);
	cout << " == ";
	cout << (rubles / 100) << "." << setfill('0') << setw(2) << (rubles % 100) << setfill(' ') << " RUR";
	
	delete pCurrency;
} // Application::testDollar


void Application::test_euro()
{
	pCurrency = new Euro(100, 0);

	GotoXY(5, 12);
	cout << *pCurrency;
	UINT rubles = pCurrency->to_RUB(75.5);
	cout << " == ";
	cout << (rubles / 100) << "." << setfill('0') << setw(2) << (rubles % 100) << setfill(' ') << " RUR";

	delete pCurrency;
} // Application::testEuro