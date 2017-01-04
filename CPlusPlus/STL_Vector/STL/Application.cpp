#include "stdafx.h"
#include "Utils.h"
#include "Application.h"

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
			"1. Array 99\n"
			"2. Array 109\n"

			"0. Выход\n"
			"   Ваш выбор (0, ..., 2)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 2);

		switch (cmd) {
		case 1:
			Array99();
			break;
		case 2:
			Array109();
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

void Application::showVector(vector<int> v)
{
	const int M = 12;  // выводим M элементов в строку
	const int W = 6;  // ширина поля вывода

	size_t i;
	for (i = 0; i < v.size(); i++)
	{
		cout << setw(W) << v[i];
		if ((i + 1) % M == 0) cout << "\n";
	} // for i

	if (i % M != 0) cout << "\n";
} // Application::showVector

void Application::fillVector(vector<int> &v, size_t qty, int min, int max)
{
	for (size_t i = 0; i < qty; i++)
		v.push_back(Random(min, max));
} // Application::fillVector

void Application::Array99()
{
	tMark("\n[Array 99]\n");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	vector<int> vec;

	// 1. Заполняем вектор случайными числами
	fillVector(vec, n, 0, 5);

	// 2. Выводим его на экран
	Clear();
	tMark("[Array 99]\n\n"
		  "Вектор до:\n");
	showVector(vec);

	// 3. Решаем поставленную задачу
	for (auto i = vec.begin(); i != vec.end();)
	{
		if (count(vec.begin(), vec.end(), *i) > 2) // Таких чисел больше чем положено?
			vec.erase(rfind(i+1,vec.end(),*i));	   // Тогда удаляем последнее вхождение числа.
		else
			++i; // Такая конструкция нужна для устранения ошибки,
				 // когда после удаления элемента, итератор ссылается
				 // на несуществующий элемент.
	} // for i

	// Ждем подтверждения перехода к следующему этапу
	cout << "\n\n";
	CustomPause("Далее (ANY_KEY) >>");

	// 4. Выводим результат обработки
	Clear();
	tMark("[Array 99]\n\n"
		  "Вектор после:\n");
	showVector(vec);
} // Application::Array99

void Application::Array109()
{
	tMark("\n[Array 109]\n");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	vector<int> vec;

	// 1. Заполняем вектор случайными числами
	fillVector(vec, n, -10, 10);

	// 2. Выводим его на экран
	Clear();
	tMark("[Array 109]\n\n"
		  "Вектор до:\n");
	showVector(vec);

	// 3. Решаем поставленную задачу
	for (auto i = vec.begin(); i != vec.end();)
	{
		if (*i < 0) // если значение отрицательное - вставить 0 перед ним.
			i = vec.insert(i, 0) + 2; // Переводим итератор на две позиции вперед.
		else						  // Это нужно для устранения ошибки, когда
			++i;					  // после вставки элемента, итератор теряет валидность.					  
	} // for i

	// Ждем подтверждения перехода к следующему этапу
	cout << "\n\n";
	CustomPause("Далее (ANY_KEY) >>");

	// 4. Выводим результат обработки
	Clear();
	tMark("[Array 109]\n\n"
		  "Вектор после:\n");
	showVector(vec);
} // Application::Array109



