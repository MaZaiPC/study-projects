#include "stdafx.h"
#include "Utils.h"
#include "Price.h"
#include "Application.h"
#include <fstream>

const string Application::PAUSE_MSG = "Для продолжения нажмите любую клавишу . . .";
const string Application::PAUSE_BACK_MSG = "Для возврата в меню нажмите любую клавишу . . .";

// возвращает количество записей в файле данных
int Application::numRecords()
{
	fseek(f, 0, SEEK_END);
	return ftell(f) / Price::recSize();
} // Application::numRecords

Application::Application() :a(new Price[N]), dbFileName("Price.bin")
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
	case 2: system("cls"); Load(); break;

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
			CustomPause(36, 0, PAUSE_BACK_MSG); system("cls"); Run(); break;
		}
	}
	system("cls");

	for (;;)
	{
		f = fopen(dbFileName, "wb+");
		GotoXY(2, 2); tMark(" Меню ", 2,2);
		cout << "|1| Ручное добавление товаров\n";
		cout << "|2| Генерация случайных данных о товарах \n";
		cout << "|3| Отсортировать данные \n";
		cout << "|4| Вывод данных \n";
		cout << "————————————————————————————————————————\n";
		cout << "|0| Выход \n\n";
		cin >> number;
		switch (number)
		{
		case 1: tMark("————————————————————————————————————————\n", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Input(i);
				a[i].Save(f);
			}
			break;
		case 2: for (WORD i = 1; i < N; i++) {
					a[i].Randomize();
					a[i].Save(f);
		}
				tMark("————————————————————————————————————————\n", White);
				tMark("Инфо", 1, LtCyan);
				tMark("\nТайминги, данные маршрутов/поездов успешно сгенерированны!\n", LtCyan);
				break;
		case 3: tMark("————————————————————————————————————————\n", White);
			ChoiseSort();
			break;
		case 4: tMark("————————————————————————————————————————\n", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Load(f);
				a[i].Show(i);
			}
			break;
		case 0: Exit(); break;
		default: cout << "Некорретный ввод \n"; break;
		}
		Sleep(200);
		CustomPause(36, 0, PAUSE_MSG);
		system("cls");
	}
	system("cls");
} // Application::New()

void Application::Load()
{
	int number;
	for (;;)
	{
		GotoXY(2, 2); tMark(" Меню ", 2);
		cout << "\n\n|1| Ручной ввод данных о поездах\n";
		cout << "|2| Генерация случайных данных о поездах \n";
		cout << "|3| Отсортировать данные \n";
		cout << "|4| Вывод данных \n";
		cout << "————————————————————————————————————————\n";
		cout << "|0| Выход \n\n";
		cin >> number;
		switch (number)
		{
		case 1: tMark("————————————————————————————————————————\n", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Input(i);
				a[i].Save(f);
			}
			break;
		case 2: for (WORD i = 1; i < N; i++) {
					a[i].Randomize();
					a[i].Save(f);
		}
				tMark("————————————————————————————————————————\n", White);
				tMark("Инфо", 1, LtCyan,1);
				tMark("Данные маршрутов успешно сгенерированны!\n", LtCyan);
				break;
		case 3: tMark("————————————————————————————————————————\n", White);
			ChoiseSort();
			break;
		case 4: tMark("————————————————————————————————————————\n", White);
			for (WORD i = 1; i < N; i++) {
				a[i].Load(f);
				a[i].Show(i);
			}
			break;
		case 0: Exit(); break;
		default: cout << "Некорретный ввод \n"; break;
		}
		Sleep(200);
		CustomPause(36, 0, PAUSE_MSG);
		system("cls");
	}
} // Application::Load

static long GetFileSize(char *fName)
{
	fstream fp(fName, fstream::in);
	fp.seekp(0, ios::end);
	long size = fp.tellp();
	fp.close();
	return size;
} // GetFileSize

void Application::ChoiseSort()
{
	system("cls");
	int number;
	COORD Pos[4];
	GotoXY(1, 2); tMark(" Выберите действие ", 2, 2);
	Pos[0] = WhereXY(); cout << "|1| Отсортировать по названию\n";
	Pos[1] = WhereXY(); cout << "|2| Отсортировать по цене\n";
	cout << "|0| Назад \n\n";


	cin >> number;

	switch (number)
	{
	case 1:
		Pos[3] = WhereXY(); GotoXY(Pos[0].X, Pos[0].Y); tMark("|1|", LtGreen); GotoXY(Pos[3].X, Pos[3].Y);
		sort(cmpName);
		break;
	case 2:
		Pos[3] = WhereXY(); GotoXY(Pos[1].X, Pos[1].Y); tMark("|2|", LtGreen); GotoXY(Pos[3].X, Pos[3].Y);
		sort(cmpPrice);
		break;
	case 0: system("cls"); Load(); break;
	default: cout << "Некорретный ввод \n";
		CustomPause(36, 0, PAUSE_BACK_MSG); system("cls"); ChoiseSort(); break;
	}
	tMark("Инфо", 1, LtCyan, 1);
	tMark("Данные успешно отсортированы!\n", LtCyan);
	Sleep(200);
	CustomPause(36, 0, PAUSE_MSG);
	system("cls");
} // Application::ChoiseSort

void Application::Exit()
{
	system("cls");
	
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
	case 0: system("cls"); Load(); break;
	default: cout << "Некорретный ввод \n";
		CustomPause(36, 0, PAUSE_BACK_MSG); system("cls"); Load(); break;
	}

	tMark("Завершение работы программы.", LtCyan); cout << endl; exit(1);
} // Application::Exit

// Метод для сортировки данных в файле по возрастанию номеров маршрутов
void Application::sort(bool compare(const Price &, const Price &))
{
	int n = numRecords(), rec_size = Price::recSize();
	int i, j;
	Price t1, t2;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			fseek(f, j*rec_size, SEEK_SET); // перейти к j-й записи файла
			t1.Load(f);   // j-я запись прочитана, автом. сместились на j+1
			t2.Load(f);   // j+1-я запись прочитана

			// Если пара не упорядочена, то поменять записи в файле местами
			if (compare(t1, t2)) {
				fseek(f, j*rec_size, SEEK_SET); // перейти к j-й записи файла
				t2.Save(f, false); // j-я позиция -- пишем t2 
				t1.Save(f, false); // j+1-я позиция -- пишем t1
			} // if
		} // for j
	} // for i
} // Application::sort

// Возвращает true, если номер маршрута1 > номера маршрута2
// т.е. пара не упорядочена, тркбуется обмен местами
inline bool cmpPrice(const Price &t1, const Price &t2)
{
	return t1.getPrice() > t2.getPrice();
} //  cmpNumber

// Возвращает true, если пункт отправления1 > пункта отправления2
// т.е. пара не упорядочена, тркбуется обмен местами
inline bool cmpName(const Price &t1, const Price &t2)
{
	return strcmp(t1.getName().c_str(), t2.getName().c_str()) == 1;
} //  cmpStart