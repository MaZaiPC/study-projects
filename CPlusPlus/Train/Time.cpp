#include "stdafx.h"
#include "Time.h"
#include "Utils.h"

// Инициализация статического поля (переменная)
char Time::delimeter = '.';

// Конструктор по умолчанию
Time::Time() {
	h = 0; 
	m = 0;
}


// Конструктор с параметрами
Time::Time(int h, int m)
{
	setH(h);
	setM(m);
}// Time::Time - Конструктор с параметрами

// Копирующий конструктор
Time::Time(const Time & obj)
{

	h = obj.h;        // собственно копирование значения
	m = obj.m;        // собственно копирование значения

}// Time::Time - Копирующий конструктор


// Сеттеры
void Time::setH(int h)
{
	if (h < 0) {
		cout << "\n Не вверно введеный час ! Замена на 9\n";
		h = 9;
	} // if

	if (h > 23) {
		h = 0;
	}// if

	this-> h = h;

}// Time::setH

void Time::setM(int m)
{
	if (m < 0) {
		cout << "\n Не вверно введеные минуты ! Замена на 24\n";
		m = 24;
	} // if

	if ( m > 59) {
		h++;
		m = 0;
	} // if

	this->m = m;
}// Time::setM

void Time::setH()
{
	UINT H;
	cout << "Введите часы: "; cin >> H; 
	if (h < 0) {
		cout << "\n Не вверно введеный час ! Замена на 9\n";
		h = 9;
	} // if

	if (h > 23) {
		h = 0;
	}// if
	setH(H);
}// Time::setH

void Time::setM()
{
	UINT M;
	cout << "Введите минуты: "; cin >> M;
	if (m < 0) {
		cout << "\n Не вверно введеные минуты ! Замена на 24\n";
		m = 24;
	} // if

	if (m > 59) {
		h++;
		m = 0;
	} // if
	setM(M);
}// Time::setM

// Методы

void Time::Init(int h, int m)
{
	setH(h);
	setM(m);

}// Time::Init

void Time::Read()
{
	cout << "\n Введите Час(ы)   :> ";
	cin >> h;
	
	cout << "\n Введите Минуту(ы)  :> ";
	cin >> m;

	setH(h);
	setM(m);

}// Time::Read

void Time::Display(bool nl)
{
	// setfill() - заполнение ведущих пробелов заданным значением
	cout << "\n Время : " << setfill('0') << setw(2) << h << delimeter
		<< setw(2) << m << setfill(' ') << (nl ? "\n" : "");

}// Time::Display(bool nl)



// Перевод секунд в часы и минуты
void Time::toHM(int t)
{
	h = t / 3600;
	t -= 3600 * h;

	m = t / 60;
} // Time::toHM


// Вычисление разницы между двумя моментами времени
int Time::DifferenceSeconds(Time ti)
{

	int Ti1 = ToSeconds();
	int Ti2 = ti.ToSeconds();

	return ((Ti2 > Ti2)?Ti2 - Ti1 : Ti1 - Ti2);
}// Time::DifferenceSeconds(Time ti)


// Сложение заданного колчиства времени 
void Time::Add(const Time &time)
{
	int t = ToSeconds() + time.ToSeconds();
	toHM(t);
}// Time::Add


// Вычитание заданного колчиства времени 
void Time::Sub(const Time &time)
{
	int t = abs(ToSeconds() - time.ToSeconds());
	toHM(t);
}// Time::Sub()

 // Сравнение двух моментов времени
int Time::Compare(Time ti)
{
	int Ti1 = ToSeconds();
	int Ti2 = ti.ToSeconds();

	if (Ti1 < Ti2) return -1;
	if (Ti1 > Ti2) return 1;

	return 0;
}// Time::Compare(Time ti)





