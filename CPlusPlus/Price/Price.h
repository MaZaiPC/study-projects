#pragma once

/**
1. Определить класс с именем Price, содержащий следующие поля:
	• название начального пункта маршрута;
	• название конечного пункта маршрута;
	• номер маршрута.
 Определить методы доступа к этим полям и перегруженные операции
 извлечения и вставки для объектов типа Price.
2. Написать программу, выполняющую следующие действия:
	• ввод с клавиатуры данных в массив, состоящий из восьми
	  объектов типа Price; записи должны быть упорядочены по номерам
	  маршрутов;
	• вывод на экран информации о маршруте, номер которого
	  введен с клавиатуры;
	• если таких маршрутов нет, выдать на дисплей соответствующее
	  сообщение.
**/

class Price
{
	string name; //start
	double price;
public:

	static const UINT LEN_NAME;
	static const UINT LEN_PRICE;

	static int recSize() { return LEN_NAME + LEN_PRICE; }

	Price();
	Price(double price, string name);
	Price(const Price & obj);
	~Price();

	// Сеттеры
	void setName(string nm);
	void setPrice(double pr);

	// Геттеры
	string getName() const { return name; }
	double getPrice() const { return price; }

	// Методы
	void Input(UINT n);
	void Show(UINT n);
	void Randomize();

	// Методы сериализации
	int Save(FILE * f, bool append = true);
	int Load(FILE * f);
};

