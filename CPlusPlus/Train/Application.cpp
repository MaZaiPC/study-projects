#include "stdafx.h"
#include "Utils.h"
#include "Train.h"
#include "Application.h"



Application::Application()
{
} // Application::Application


Application::~Application()
{
} // Application::~Application

static Time StartTime();
static void Case3(Train *trn);

// Главный метод приложения - обработка команд пользователя  
void Application::run()
{
	Train trn[9];  
    int number;
    for( ; ;) 
    {
		GotoXY(2,2); tMark(" Меню ", 2);
		cout << "\n\n|1| Ручной ввод данных о поездах\n";
		cout << "|2| Генерация случайных данных о поездах \n";
		cout << "|3| Вывод данных \n";
		cout << "————————————————————————————————————————\n";
		cout << "|0| Выход \n\n";
		cin >> number;
		switch(number) 
		{ 
			case 1: tMark("————————————————————————————————————————\n", White);
					for (WORD i = 1; i < 9; i++) {
						trn[i].Input(i);}
					break;
			case 2: for (WORD i = 1; i < 9; i++) {
						trn[i].Randomize();}
					tMark("————————————————————————————————————————\n", White);
					tMark("Инфо", 1, LtCyan);
					tMark("\nТайминги, данные маршрутов/поездов успешно сгенерированны!\n", LtCyan);
					break;
			case 3: cout << "————————————————————————————————————————\n";
					Case3(trn);
					break;
			case 0: tMark("Завершение работы программы.", LtCyan); cout << endl; exit(1); break;
			default: cout << "Некорретный ввод \n"; break; 
		}
		Sleep(200);
		WriteXY(36, 0, "Для продолжения нажмите любую клавишу . . .");
		system("pause > nul");
		system("cls");
	}
} // Application::run


static Time StartTime()
{
	Time t;
	tMark("Фильтр", 1);
	tMark("\nВведите минимальное время отправки поезда\n\n", LtCyan);
	t.setH();
	t.setM();
	tMark("————————————————————————————————————————\n", White);
	return t;
}

static void Case3(Train *trn)
{
	int num;
	tMark("Вывод данных", 1);
	cout << "\n\n|1| Вывести всё\n";
	cout << "|2| Отфильтровать по времени \n";
	cout << "————————————————————————————————————————\n";
	cout << "<< Назад '0' \n\n";
	cin >> num;
	tMark("————————————————————————————————————————\n", White);
	Time t;
	switch (num)
	{
	case 1: for (WORD i = 1; i < 9; i++) {
				trn[i].Show(i);}
			break;
	case 2: t = StartTime();
			for (WORD i = 1; i < 9; i++) {
			if (trn[i].Compare(t) == 1)
				trn[i].Show(i);}
			break;
	case 0: system("cls"); break;
	default: cout << "Некорретный ввод \n"; break;
	}
}