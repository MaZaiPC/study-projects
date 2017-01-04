#pragma once

/**
1. Определить класс с именем MARSH, содержащий следующие поля:
	• название начального пункта маршрута;
	• название конечного пункта маршрута;
	• номер маршрута.
 Определить методы доступа к этим полям и перегруженные операции
 извлечения и вставки для объектов типа MARSH.
2. Написать программу, выполняющую следующие действия:
	• ввод с клавиатуры данных в массив, состоящий из восьми
	  объектов типа MARSH; записи должны быть упорядочены по номерам
	  маршрутов;
	• вывод на экран информации о маршруте, номер которого
	  введен с клавиатуры;
	• если таких маршрутов нет, выдать на дисплей соответствующее
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

	// Сеттеры
	void setRouteNumber(string s);
	void setStart(string ns);
	void setDest(string ns);

	// Геттеры
	string getRouteNumber()		const { return routeNumber; }
	string getDest() const { return dest; }

	// Методы
	void Input(UINT n);
	void Show(UINT n);
	void Randomize();

	// Методы сериализации
	int Save(FILE *f);
	int Load(FILE *f);
};

