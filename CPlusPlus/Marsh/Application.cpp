#include "stdafx.h"
#include "Utils.h"
#include "Marsh.h"
#include "Application.h"
#include <fstream>

Application::Application() :a(new Marsh[N]), dbFileName("Marsh.bin")
{
	f = fopen(dbFileName, "rb+");
	if (f == nullptr) {
		f = fopen(dbFileName, "wb+");
		if (f == nullptr) {
			SetWindow(80, 25, 0x07);
			Clear();
			WriteXY(34, 12, "Аварийное завершение");
			GotoXY(0, 24);
		}
	}

	// Файл открыт - читаем из файла записи в массив a[]
	// Нет защиты (пока) от файлов с длиной < 8
	for (int i = 0; i < N; i++) a[i].Load(f);
} // Application::Application


Application::~Application()
{
	fclose(f);   // закрыть файл данных
	delete[] a;
} // Application::~Application

static void New();
static void Exit(bool saved);
static long GetFileSize(char *fName);

// Главный метод приложения - обработка команд пользователя  
void Application::Run()
{
	int number;
	GotoXY(2, 2); tMark(" Главное Меню ", 2, 2);
	long size = GetFileSize(dbFileName);
	(size > 0) ? cout << "|1| Новая база (перезаписать старую)\n" : cout << "\n\n|1| Новая база\n";
	cout << "|2| Загрузка \n";
	cout << "————————————————————————————————————————\n";
	cout << "|0| Выход \n\n";
	cin >> number;
	switch (number)
	{
	case 1: New(); break;
	case 2: system("cls"); Load(true); break;

	case 0: tMark("Завершение работы программы.", LtCyan); cout << endl; exit(1); break;
	default: cout << "Некорретный ввод \n"; break;
	}
} // Application::run

void Application::New()
{
	int number;
	long size = GetFileSize(dbFileName);
	if (size > 0) {
		system("cls");
		GotoXY(1, 2); tMark(" Предупреждение ", 2, LtCyan,2);
		tMark("Вы уверены что хотите перезаписать файл? Содержимое\nбудет удалено безвозвратно!\n", LtYellow);
		cout << "————————————————————————————————————————\n";
		
		cout << "<< 0 = Назад   ";
		cout << "1 = Продолжить >>\n\n";
		

		cin >> number;

		switch (number)
		{
		case 1: break;
		case 0: system("cls"); Run(); break;
		default: cout << "Некорретный ввод \n";
			WriteXY(36, 0, "Для возврата в меню нажмите любую клавишу . . .");
			system("pause > nul"); system("cls"); Run(); break;
		}
	}
	system("cls");

	bool flag = true;
	for (;;)
	{
		f = fopen(dbFileName, "wb+");
		GotoXY(2, 2); tMark(" Меню ", 2,2);
		cout << "|1| Ручной ввод данных о поездах\n";
		cout << "|2| Генерация случайных данных о поездах \n";
		cout << "|3| Вывод данных \n";
		cout << "|4| Сохранить \n";
		cout << "————————————————————————————————————————\n";
		cout << "|0| Выход \n\n";
		cin >> number;
		switch (number)
		{
		case 1: tMark("————————————————————————————————————————\n", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Input(i);
			}
			flag = false;
			break;
		case 2: for (WORD i = 1; i < N; i++) {
					a[i].Randomize();
		}
				flag = false;
				tMark("————————————————————————————————————————\n", White);
				tMark("Инфо", 1, LtCyan);
				tMark("\nТайминги, данные маршрутов/поездов успешно сгенерированны!\n", LtCyan);
				break;
		case 3: tMark("————————————————————————————————————————\n", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Show(i);
			}
			break;
		case 4: tMark("————————————————————————————————————————\n", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Save(f);
				flag = true;
			}
			tMark("Инфо", 1, LtCyan);
			tMark("\nДанные успешно сохранены!\n", LtCyan);
			break;
		case 0: Exit(flag); break;
		default: cout << "Некорретный ввод \n"; break;
		}
		Sleep(200);
		WriteXY(36, 0, "Для продолжения нажмите любую клавишу . . .");
		system("pause > nul");
		system("cls");
	}
	system("cls");
}

void Application::Load(bool flag)
{
	int number;
	for (;;)
	{
		GotoXY(2, 2); tMark(" Меню ", 2);
		cout << "\n\n|1| Ручной ввод данных о поездах\n";
		cout << "|2| Генерация случайных данных о поездах \n";
		cout << "|3| Вывод данных \n";
		cout << "|4| Сохранить \n";
		cout << "————————————————————————————————————————\n";
		cout << "|0| Выход \n\n";
		cin >> number;
		switch (number)
		{
		case 1: tMark("————————————————————————————————————————\n", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Input(i);
			}
			flag = false;
			break;
		case 2: for (WORD i = 1; i < N; i++) {
					a[i].Randomize();
		}
				flag = false;
				tMark("————————————————————————————————————————\n", White);
				tMark("Инфо", 1, LtCyan,1);
				tMark("Данные маршрутов успешно сгенерированны!\n", LtCyan);
				break;
		case 3: tMark("————————————————————————————————————————\n", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Show(i);
			}
			break;
		case 4: tMark("————————————————————————————————————————\n ", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Save(f);
				flag = true;
			}
			tMark("Инфо", 1, LtCyan,1);
			tMark("Данные успешно сохранены!\n", LtCyan);
			break;
		case 0: Exit(flag); break;
		default: cout << "Некорретный ввод \n"; break;
		}
		Sleep(200);
		WriteXY(36, 0, "Для продолжения нажмите любую клавишу . . .");
		system("pause > nul");
		system("cls");
	}
}

static long GetFileSize(char *fName)
{
	fstream fp(fName, fstream::in);
	fp.seekp(0, ios::end);
	long size = fp.tellp();
	fp.close();
	return size;
}

void Application::Exit(bool saved)
{
	system("cls");
	if (!saved) {
		int number;
		GotoXY(1, 2); tMark(" Предупреждение ", 2, LtCyan, 2);
		tMark("Данные были изменены! Выйти без сохранений?\n", LtYellow);
		cout << "————————————————————————————————————————\n";

		cout << "|1| Да \n";
		cout << "|0| Нет \n\n";


		cin >> number;

		switch (number)
		{
		case 1: break;
		case 0: system("cls"); Load(false); break;
		default: cout << "Некорретный ввод \n";
			WriteXY(36, 0, "Для возврата в меню нажмите любую клавишу . . .");
			system("pause > nul"); system("cls"); Load(false); break;
		}
	}

	tMark("Завершение работы программы.", LtCyan); cout << endl; exit(1);
}