#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Triad.h"

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
			"1. Задача 12\n"
			"2. Задача 14\n"

			"0. Выход\n"
			"   Ваш выбор (0, ..., 2)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 2);

		switch (cmd) {
		case 1:
			test_task12();
			break;
		case 2:
			test_task14();
			break;
		case 0:
			flagExit = true;
			break;
		} // switch
		if (flagExit) break;
		CustomPause(55,0,"Нажмите любую клавишу...");
	} // while

	// Возвращаем стандартный вид окну
	// размер 80 х 25, серые символы на черном фоне
	SetWindow(80, 25, 0x07);
	Clear();
	WriteXY(34, 12, "Конец работы");
	GotoXY(0, 24);
} // Application::run

void Application::test_task12()
{
	tMark("\n[Тестирование не реализовано!]\n", LtMagenta);
	return;

	tMark("\n[Задача 12]\n");
	tMark("\nТест базового класса Triad\n", LtCyan);
	Triad triad(2,4,6);
	cout << "Тест вывода на экран:" << triad << endl;
	cout << "Тест постфиксного инкремента:" << triad++ << endl;
	/*Triad triad2(4, 3, 7);
	cout << "triad =" << triad << endl;
	cout << "triad2 =" << triad2 << endl;
	cout << "Тест логической операции '==':" << triad == triad2 << endl;
	cout << "Тест логической операции '<':" << triad < triad2 << endl;
	cout << "Тест логической операции '>':" << triad > triad2 << endl;
	triad = triad2;
	cout << "Тест операции присваивания:" << "triad = " << triad << endl;
	*/
	tMark("\n\nТест производного класса Time\n", LtCyan);
}

void Application::test_task14()
{
	tMark("\n[Тестирование не реализовано!]\n", LtMagenta);
	return;

	tMark("\n[Задача 14]\n");
	tMark("\nТест базового класса Triad\n", LtCyan);

	tMark("\n\nТест производного класса Date\n", LtCyan);
	
}

/*
void Application::test_task10()
{
	tMark("\n[Задача 10]\n");
	tMark("\nТест базового класса Triangle\n", LtCyan);
	double a(Random(1., 10.)), b(Random(1., 10.));
	Pair::Base bt(a, b); // объявление и инициализация
	cout << bt; // вывод полей класса на экран

	tMark("\nТест производного класса RightAngled\n", LtCyan);

	Pair::RightAngled rat(a,b); // объявление и инициализация
	cout << rat; // вывод полей класса на экран
}
*/