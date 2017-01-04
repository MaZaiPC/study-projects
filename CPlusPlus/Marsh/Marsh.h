#pragma once

/**
1. ќпределить класс с именем MARSH, содержащий следующие пол€:
	Х название начального пункта маршрута;
	Х название конечного пункта маршрута;
	Х номер маршрута.
 ќпределить методы доступа к этим пол€м и перегруженные операции
 извлечени€ и вставки дл€ объектов типа MARSH.
2. Ќаписать программу, выполн€ющую следующие действи€:
	Х ввод с клавиатуры данных в массив, состо€щий из восьми
	  объектов типа MARSH; записи должны быть упор€дочены по номерам
	  маршрутов;
	Х вывод на экран информации о маршруте, номер которого
	  введен с клавиатуры;
	Х если таких маршрутов нет, выдать на дисплей соответствующее
	  сообщение.
**/

class Marsh
{
	string routeNumber;
	string start;
	string dest;
public:
	Marsh();
	Marsh(string ser, string name);
	Marsh(const Marsh & obj);
	~Marsh();

	// —еттеры
	void setRouteNumber(string s);
	void setStart(string ns);
	void setDest(string ns);

	// √еттеры
	string getRouteNumber()		const { return routeNumber; }
	string getDest() const { return dest; }

	// ћетоды
	void Input(UINT n);
	void Show(UINT n);
	void Randomize();

	// ћетоды сериализации
	int Save(FILE *f);
	int Load(FILE *f);
};

