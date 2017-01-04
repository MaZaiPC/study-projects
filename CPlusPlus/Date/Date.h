#pragma once

class Date
{
	UINT year;
	UINT month;
	UINT day;

	// Методы:
	// Конвертеры
	UINT toJDN();
	UINT toJDN(Date x);
	UINT toJDN(UINT day, UINT month, UINT year);
	Date toGD(UINT JDN);

	// Логические
	bool IsValidDate(UINT day, UINT month, UINT year);
public:
	// Конструкторы и деструктор
	Date(UINT yyyy = 1974, UINT mm = 11, UINT dd = 23);
	Date(const Date &Date);
	~Date();

	// Методы:
	// Арифметические
	Date add(UINT days); // Сложение
	Date sub(UINT days); // Вычитание
	Date diff(Date x);  // разница между датами

	// Логические
	bool equal(Date x);        // Равно?
	bool greate(Date x);       // Больше?
	bool less(Date x);         // Меньше?
	bool IsLeapYear(UINT year); // Високосный?

	// Геттеры и Сеттеры
	UINT getDay();
	UINT getMonth();
	UINT getYear();
	void setDay(UINT day);
	void setMonth(UINT month);
	void setYear(UINT year);
	void setDate(UINT day, UINT month, UINT year);
	void coutDate();

	// Инициализация
	void Init();
	void Init(int a, int b);
};

