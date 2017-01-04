#include "stdafx.h"
#include "Marsh.h"
#include "Utils.h"

Marsh::Marsh()
{
	routeNumber = "X---";
	dest = ">Empty<";
}

Marsh::Marsh(string ser, string name)
{
	routeNumber = ser;
	dest = name;
}

Marsh::Marsh(const Marsh & obj)
{
	routeNumber = obj.routeNumber;
	dest = obj.dest;
}

Marsh::~Marsh()
{
}

// Сеттеры
void Marsh::setRouteNumber(string s)
{
	cin >> routeNumber;
}
void Marsh::setDest(string ns)
{
	cin >> dest;
}

// Методы
void Marsh::Input(UINT n)
{
	string tmp = Format("Регистрация маршрута %u", n);
	tMark(tmp, 1);
	cout << "\nВведите серийный номер поезда: "; cin >> routeNumber;
	cout <<   "Введите пункт назначения: "; cin >> dest;
}

void Marsh::Show(UINT n)
{
	string tmp = Format("Маршрут %u", n);
	tMark(tmp, 1);
	cout << "\nНомер маршрута: " << routeNumber << endl;
	cout << "Стартовый пункт: " << start << endl;
	cout << "Пункт назначения: " << dest << "\n\n";
}

void Marsh::Randomize()
{
	UINT a = Random(1, 999);
	char b;
	char e[4] = {'М', 'Е', 'Р', 'А'};
	// Оставляем только разрешенные индексы
	b = e[Random(1, 4)];
	
	string ser = Format("%u", a);
	ser = (Format("%c", b)+ser);

	routeNumber = ser;
	
	string city[] = { "Москва", "Рига", "Казань", "Санкт-Петербург", "Ташкент", "Волгоград", "Донецк", "Симферополь", "Минск", "Алматы", "Прага", "Кисловодск", "Уфа", "Луганск", "Смоленск", "Ростов", "Хабаровск", "Владивосток", "Брист", "Варшава" };
	WORD c = Random(1, 19);

	start = city[c];
cycle:;
	c = Random(1, 19);
	if (city[c] != start)
		dest = city[c];
	else
		goto cycle;

}

// Метод для записи в файл полей класса 
int Marsh::Save(FILE * f)
{
	fwrite(&routeNumber, 8, 1, f);
	fwrite(&start, 22, 1, f);
	fwrite(&dest, 22, 1, f);
	return 0;
} // Train::Save


// Метод для чтения из файла полей класса 
int Marsh::Load(FILE * f)
{
	fread(&routeNumber, 8, 1, f);
	fread(&start, 22, 1, f);
	fread(&dest, 22, 1, f);
	return 0;
} // Train::Load 