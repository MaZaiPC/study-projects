#include "stdafx.h"
#include "Utils.h"
#include "Application.h"

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
			test_linear();
			break;
		case 2:
			test_square();
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


void Application::test_linear()
{
	pRoot = new Linear;

	GotoXY(5, 12);
	pRoot->Solve(Random(1., 10.), Random(1., 10.), Random(1., 10.));
	/*ПРОБЛЕМА*/ //cout << "Тестирование линейного уравнения: " << *pRoot << endl;
	cout << "Тут должен быть вывод результата на экран\n";

	delete pRoot;
} // Application::testDollar


void Application::test_square()
{
	pRoot = new Square;

	GotoXY(5, 12);
	pRoot->Solve(Random(1.,10.), Random(1., 10.), Random(1., 10.));
	/*ПРОБЛЕМА*/ //cout << "Тестирование квадратного уравнения: " << *pRoot << endl;
	cout << "Тут должен быть вывод результата на экран\n";

	delete pRoot;
} // Application::testEuro