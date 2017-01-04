#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Stack.h"


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
			"1. Добавить в стек\n"
			"2. Извлечь из стека\n"
			"3. Показать стек\n"
			"0. Выход\n"
			"   Ваш выбор (0, ..., 3)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 3);

		switch (cmd) {
		case 1:
			testPush();
			break;
		case 2:
			testPop();
			break;
		case 3:
			showStack();
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


void Application::testPush()
{
	int x = Random(-5, 12);
	stack.push(x);
	GotoXY(1, 12); 
	cout << stack;
} // Application::testPush


void Application::testPop()
{
	stack.pop();
	GotoXY(1, 12);
	cout << stack;
} // Application::testPop


void Application::showStack()
{
	GotoXY(1, 12);
	cout << stack;
} // Application::showStack



