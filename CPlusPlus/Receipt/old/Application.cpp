#include "stdafx.h"
#include "Utils.h"
#include "Receipt.h"
#include "Application.h"


const string Application::PAUSE_MSG = "Для продолжения нажмите любую клавишу . . .";
const string Application::PAUSE_BACK_MSG = "Для возврата в меню нажмите любую клавишу . . .";

Application::Application() :dbFileName("Receipt.bin")
{
	char CurrentPath[_MAX_PATH];
	_getcwd(CurrentPath, _MAX_PATH);
	string filePath = Format("%s\\receipts.dat", CurrentPath);
	const string REC_PATCH = filePath;
	filePath = Format("%s\\dbase.dat", CurrentPath);
	const string DB_PATCH = filePath;
} // Application::Application


Application::~Application()
{
} // Application::~Application

static void New();
static void Exit(bool saved);

// Главный метод приложения - обработка команд пользователя  
void Application::Run()
{
	char ch;
	int code;
	GotoXY(2, 2); tMark(" Главное Меню ", 0, 2);
	cout << "|1| Новый чек\n"
		 << "|2| Загрузить чек\n"
		 << "|3| Добавить товар в базу\n"
		 << "————————————————————————————————————————\n"
		 << "|0| Выход \n\n";
loop:;
	ch = _getch();
	code = static_cast<int>(ch);
	switch (ch)
	{
	case 49: rec_new(); break;
	case 50: system("cls"); rec_load(); break;
	case 51: system("cls"); gooide_add(); break;
	case 48: tMark("Завершение работы программы.", LtCyan); cout << endl; exit(1); break;
	default: goto loop; break;
	}
} // Application::run


void Application::SubMenu()
{
	char ch;
	int code;
	GotoXY(2, 2); tMark(" Главное Меню -> Работа с чеком ", 0, 2);
	cout << "|1| Переименовать чек\n"
		 << "|2| Удалить чек\n"
		 << "|3| Добавить товар в чек\n"
		 << "————————————————————————————————————————\n"
		 << "|0| Выход \n\n";
loop:;
	ch = _getch();
	code = static_cast<int>(ch);
		switch (ch)
	{
		case 49: rec_rename(); break;
		case 50: system("cls"); rec_delete(); break;
		case 51: system("cls"); rec_add_gooide(); break;
		case 48: tMark("Завершение работы программы.", LtCyan); cout << endl; exit(1); break;
		default: goto loop; break;
	}
}

// Операции с чеками
void Application::rec_new()
{
	char ch;
	int code;
	COORD w;
	w = WhereXY();
	cout << "Сгенерировать номер чека автоматически? ";
loop:;
	ch = _getch();
	code = static_cast<int>(ch);
	Receipt _new;
	UINT num;
	switch (ch)
	{
	case 'y': 
		cout << "Чек записан! Номер чека: " << _new.getNumber; break;
	case 'n': cin >> num; _new.setNumber(num); Save();
		cout << "Чек записан! Номер чека: " << _new.getNumber; break;
	default: goto loop; break;
	}
	
	
} // Application::New()

void Application::rec_load()
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

void Application::rec_rename()
{

}

void Application::rec_delete()
{

}

void Application::rec_add_gooide()
{

}

// Операции с товарами
void Application::gooide_add()
{

}

void Application::gooide_remove()
{

}

/* Сортировка
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
		sort(cmpReceipt);
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


// Метод для сортировки данных в файле по возрастанию номеров маршрутов
void Application::sort(bool compare(const Receipt &, const Receipt &))
{
	int n = numRecords(), rec_size = Receipt::recSize();
	int i, j;
	Receipt t1, t2;

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
inline bool cmpReceipt(const Receipt &t1, const Receipt &t2)
{
	return t1.getReceipt() > t2.getReceipt();
} //  cmpNumber

// Возвращает true, если пункт отправления1 > пункта отправления2
// т.е. пара не упорядочена, тркбуется обмен местами
inline bool cmpName(const Receipt &t1, const Receipt &t2)
{
	return strcmp(t1.getName().c_str(), t2.getName().c_str()) == 1;
} //  cmpStart
*/// Конец сортировки