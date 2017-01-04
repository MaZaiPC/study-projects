﻿#pragma once
#include "stdafx.h"

class Triad
{
protected:
	/*
	по идее раз класс хранит всего 3 переменные числа,
	а в задаче не указан тип переменной, то пусть будет
	int как база. Будь чуть больше времени, можно было бы
	придумать что то типа динамического изменение типа
	переменной aka:

	//объявление
	void *data = (void *)(new int);

	//задание значения
	data = (void *)(new WORD);
	*(UINT *)data = 1.2;

	data = (void *)(new WORD);
	*(WORD *)data = 1.2;

	//чтение значения
	x = *(UINT *)data;
	y = *(WORD *)data;
	*/// P.S. - с таким вариантом пока не разобрался,
	  // пока пусть будет int
	int a, b, c;
public:
	// конструкторы и деструктор
	Triad();
	Triad(WORD a, WORD b, WORD c);
	Triad(const Triad &obj);
	~Triad();

	// перегрузка постфиксной формы инкремента
	Triad operator++();

	// перегрузка операций сравнения
	bool operator ==(const Triad &obj);
	bool operator <(const Triad &obj);
	bool operator >(const Triad &obj);

	// перегрузка оператора присваивания
    const Triad& operator =(const Triad &obj){
		a = obj.a;
		b = obj.b;
		c = obj.c;
        return *this;
    }

	// перегрузка потоковых операций
	friend ostream &operator<<(ostream &os, const Triad &obj);
};

class Time : Triad
{
	// Здесь ссылки реализуют модель синонимов
	int &h = a, &m = b, &s = c;
public:
	// конструкторы и деструктор
	Time();
	Time(WORD hour, WORD minute, WORD second);
	Time(const Time &obj);
	~Time() {}

	void init(WORD hour, WORD minute, WORD second);

	// Геттеры
	WORD get_H() const { return h; }
	WORD get_M() const { return m; }
	WORD get_S() const { return s; }

	// Сеттеры 
	void set_H(WORD h);
	void set_M(WORD m);
	void set_S(WORD s);

	bool operator <(const Time &obj);
	bool operator >(const Time &obj);

	// перегрузка потоковых операций
	friend ostream &operator<<(ostream &os, const Time &obj);
	friend istream &operator>>(istream &is, Time &obj);
};

class Date : Triad
{
	int &year = a, &month = b, &day = c; // установка синонимов
	UINT to_JDN() const;  // конвертация в юлианские дни
	Date to_GD(UINT JDN); // конвертация в григорианскую дату
public:
	// конструкторы и деструктор
	Date();
	Date(UINT y, UINT m, UINT d);
	Date(const Date &obj);
	~Date() {}

	// Геттеры
	UINT get_year() const { return year; }
	UINT get_month() const { return month; }
	UINT get_day() const { return day; }

	// Сеттеры
	void set_year(UINT y) { year = y; }
	void set_month(UINT m);
	void set_day(UINT d);

	void init(UINT year, UINT month, UINT day);

	Date operator+(const UINT &days);
	// перегрузка постфиксной формы инкремента
	Date operator++();

	bool operator <(const Date &obj);
	bool operator >(const Date &obj);

	// перегрузка потоковых операций
	friend ostream &operator<<(ostream &os, const Date &obj);
	friend istream &operator>>(istream &is, Date &obj);
};