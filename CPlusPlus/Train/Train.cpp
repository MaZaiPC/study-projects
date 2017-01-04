#include "stdafx.h"
#include "Train.h"
#include "Utils.h"

Train::Train()
{
	serial = "000X";
	nameStation = ">Empty<";
}

Train::Train(string ser, string name, Time time)
{
	serial = ser;
	nameStation = name;
	time_a = time;
}

Train::Train(const Train & obj)
{
	serial = obj.serial;
	nameStation = obj.nameStation;
}

Train::~Train()
{
}

// Сеттеры
void Train::setSerial(string s)
{
	cin >> serial;
}
void Train::setNameStation(string ns)
{
	cin >> nameStation;
}

// Не уверен стоило ли дублировать функцию получения времени
// из переменной класса Time в этом классе...
void Train::setH(int h)
{
	time_a.setH(h);
}
void Train::setM(int m)
{
	time_a.setM(m);
}

// Методы
void Train::Input(UINT n)
{
	string tmp = Format("Регистрация маршрута %u", n);
	tMark(tmp, 1);
	cout << "\nВведите серийный номер поезда: "; cin >> serial;
	cout <<   "Введите пункт назначения: "; cin >> nameStation;
	tMark("\nВремя отправления\n", LtCyan);
	time_a.setH();
	time_a.setM();
}

void Train::Show(UINT n)
{
	string tmp = Format("Поезд %u", n);
	tMark(tmp, 1);
	cout << "\nСерийный номер: " << setfill('0') << setw(4) << serial << setfill(' ') << endl;
	cout << "Пункт назначения: " << nameStation << endl;
	cout << "\nВремя отправления " << setfill('0') << setw(2) << time_a.getH() << ":" << setw(2) << time_a.getM() << setfill(' ') << "\n\n";
}

void Train::Randomize()
{
	UINT a = Random(1, 999);
	char b;
	do {
		b = Random('А', 'Я');
	// Убираем не красивые для индекса буквы
	} while (b == 'З' || b == 'Ъ' || b == 'Ь' || b == 'О' || b == 'Ы' || b == 'Й');
	string ser = Format("%u", a);
	ser += Format("%c", b);

	serial = ser;
	
	string city[] = {"Москва", "Рига","Казань","Санкт-Петербург","Ташкент","Волгоград","Донецк","Симферополь","Минск","Алматы","Прага","Кисловодск","Уфа","Луганск","Смоленск","Ростов","Хабаровск","Владивосток","Брист","Варшава"};
	WORD c = Random(1, 19);
	
	nameStation = city[c];

	WORD hor = Random(0, 23);
	time_a.setH(hor);
	
	WORD tmp;
	do {
		tmp = Random(0, 59);
	//Время выезда должно быть кратно 5
	} while (tmp % 5 != 0);
	
	time_a.setM(tmp);
}