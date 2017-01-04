#pragma once

class Date
{
	WORD hour;
	WORD minute;
	WORD second;
	
	// Методы:
	// Конвертеры
	WORD TimeToMin();
	Date MinToTime(WORD JDN);
	
	// Логические
	bool IsValidDate(WORD hour, WORD minute, WORD second);
	
	// Служебные
	int NPK(int numb,int mult);
public:
	// Конструкторы и деструктор
	Date(WORD hh = 0, WORD mm = 0, WORD ss = 0);
	Date(const Date &date);
	~Date();

	// Методы:
	// Арифметические
	Date add(WORD days); // Сложение
	Date sub(WORD days); // Вычитание
	Date diff(Date x);  // разница между временем
	
	// Логические
	bool equal(Date x);        // Равно?
	bool greate(Date x);       // Больше?
	bool less(Date x);         // Меньше?
	
	// Геттеры и Сеттеры
	WORD getHour();
	WORD getMinute();
	WORD getSecond();
	void setHour(WORD hour);
	void setMinute(WORD minute);
	void setSecond(WORD second);
	void setTime(WORD hour, WORD minute, WORD second);
	void coutTime();
	
	// Инициализация
	void Init();
	void Init(a, b);
};

