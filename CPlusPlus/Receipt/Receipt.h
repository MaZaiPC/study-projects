#pragma once
#include "Goods.h"
#include "DateTime.h"

class Receipt
{
	UINT     number;  // Номер чека
	UINT     size;    // Фактическое количество товаров в чеке
	DateTime create;  // Дата и время создания чека
	Goods    *goods;  // Указатель на массив товаров в чеке

public:
	static const UINT LEN_GOODS;   // максимальное количество товаров в чеке
	static UINT counter;      // текущее количество созданных чеков - счетчик чеков
	static UINT makeNumber(); // создание номера чека

	Receipt();                          // Конструктор по умолчанию
	Receipt(int number, DateTime &dt);  // Конструктор с параметрами
	Receipt(const Goods &obj);          
	Receipt(const Receipt &obj);        // Конструктор копирования                                              
	~Receipt();                         // Деструктор

	// Геттеры
	int getNumber()  const { return number; }

	// Сеттеры

	// Методы
	// void Init(int number, int day, int  month, int year, int h, int m, int s); // Инициализация присваивания начальных значений
	int save();
	int load();

	// Операция присваивания - т.к. есть поля, память под которые выделяется 
	// динамически
	Receipt &operator=(const Receipt &obj);
	Receipt &operator=(const Goods &obj);

	// Добавление товара в чек
	//bool operator+(const Goods &obj);

	// Удаление товара из чека по индексу (nIndex) в массиве товаров goods 
	//bool operator-(UINT nIndex);
	
	// Изменение товара в массиве товаров goods
	//bool Change(Goods &obj);

	// Поиск товара по его коду
	//Goods &Find(UINT code);

	// Общая сумма покупки по чеку
	UINT Summa() const;

	// Перегрузка операций вывода и ввода
	friend ostream &operator<<(ostream &os, const Receipt &obj);
	friend istream &operator>>(istream &is, Receipt &obj);
};

