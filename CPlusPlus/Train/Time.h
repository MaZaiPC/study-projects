#pragma once

class Time
{
	int h;      // Часы
	int m;      // Минуты

	static char delimeter;  // Разделитель часов, минут, секунд

public:
	Time();                           // Конструктор по умолчанию
	Time(int h, int m);        // Конструктор с параметрами
	Time(const Time &obj);            // Копирующий конструктор
	~Time() {}                        // Деструктор

	// Геттеры
	int getH() const { return h; }
	int getM() const { return m; }

	// Сеттеры 
	void setH(int h);
	void setM(int m);
	void setH();
	void setM();

	// Методы

	void Init(int h, int m);     // Инициализация -  h,m
	void Read();                        // Ввод с клавиатуры
	void Display(bool nl = false);      // Вывод на экран
	int ToSeconds() const { return h * 3600 + m * 60; }  // Перевод времени в секунды
	void toHM(int t);                  // Перевод времни в секундах в часы, минуты, секунды 
	int DifferenceSeconds(Time ti);     // Вычисление разницы между двумя моментами времени
	void Add(const Time &time);         // Сложение заданного колчиства времени 
	void Sub(const Time &time);         // Вычитание заданного колчиства времени 
	int Compare(Time ti);               // Сравнение двух моментов времени
	int ToMinutes() const { return ToSeconds() / 60; }  // Перевод времени в минуты
};
