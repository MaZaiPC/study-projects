#pragma once
#include "Time.h"

/**
1. Определить класс с именем TRAIN, содержащий следующие поля:
	• название пункта назначения;
	• номер поезда;
	• время отправления.
Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа TRAIN.
2. Написать программу, выполняющую следующие действия:
	• ввод с клавиатуры данных в массив, состоящий из восьми объектов типа TRAIN;
	  записи должны быть размещены в алфавитном порядке по названиям пунктов назначения;
	• вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени;
	• если таких поездов нет, выдать на дисплей соответствующее сообщение.
**/

class Train
{
	string serial;
	string nameStation;
	Time time_a;
public:
	Train();
	Train(string ser, string name, Time time);
	Train(const Train & obj);
	~Train();

	// Сеттеры
	void setSerial(string s);
	void setNameStation(string ns);
	void setH(int h);
	void setM(int m);

	// Геттеры
	string getSerial()		const { return serial; }
	string getNameStation() const { return nameStation; }
	int getH()				const { return time_a.getH(); }
	int getM()				const { return time_a.getM(); }

	// Методы
	void Input(UINT n);
	void Show(UINT n);
	void Randomize();

	int Compare(Time ti) { return time_a.Compare(ti); }
};

