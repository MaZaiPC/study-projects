#pragma once
#include "Goods.h"
#include "Time.h"

class Receipt
{
	UINT     number;  // Номер чека
	UINT     size;    // Фактическое количество товаров в чеке
	Time	 create;  // Дата и время создания чека
	Goods    *goods;  // Указатель на массив товаров в чеке

public:
	static UINT counter;      // текущее количество созданных чеков - счетчик чеков
	static UINT makeNumber(); // создание номера чека

	Receipt();                          // Конструктор по умолчанию
	Receipt(int number, Time &dt);  // Конструктор с параметрами
	Receipt(const Goods &obj);          
	Receipt(const Receipt &obj);        // Конструктор копирования                                              
	~Receipt();                         // Деструктор

	// Геттеры
	int getNumber()  const { return number; }

	// Сеттеры
	void setNumber(int what);

	// Методы
	void Init(int number, int day, int  month, int year, int h, int m, int s); // Инициализация присваивания начальных значений
	bool operator-(UINT nIndex);	// Удаление товара из чека по индексу (nIndex) в массиве товаров goods 
	bool Change(Goods &obj);		// Изменение товара в массиве товаров goods
	Goods &Find(UINT code);			// Поиск товара по его коду
	UINT Summa();					// Общая сумма покупки по чеку

	// Операции с файлами
	void Save(string filePath);
	void Save(UINT gooideNum, string filePath);
	void Load(UINT i, string recFilePath, string dbFilePath);

	// Перегрузка операций вывода и ввода
	friend ostream &operator<<(ostream &os, const Receipt &obj);
	friend istream &operator>>(istream &is, Receipt &obj);
};

