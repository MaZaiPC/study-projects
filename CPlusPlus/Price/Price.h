#pragma once

/**
1. ќпределить класс с именем Price, содержащий следующие пол€:
	Х название начального пункта маршрута;
	Х название конечного пункта маршрута;
	Х номер маршрута.
 ќпределить методы доступа к этим пол€м и перегруженные операции
 извлечени€ и вставки дл€ объектов типа Price.
2. Ќаписать программу, выполн€ющую следующие действи€:
	Х ввод с клавиатуры данных в массив, состо€щий из восьми
	  объектов типа Price; записи должны быть упор€дочены по номерам
	  маршрутов;
	Х вывод на экран информации о маршруте, номер которого
	  введен с клавиатуры;
	Х если таких маршрутов нет, выдать на дисплей соответствующее
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

	// —еттеры
	void setName(string nm);
	void setPrice(double pr);

	// √еттеры
	string getName() const { return name; }
	double getPrice() const { return price; }

	// ћетоды
	void Input(UINT n);
	void Show(UINT n);
	void Randomize();

	// ћетоды сериализации
	int Save(FILE * f, bool append = true);
	int Load(FILE * f);
};

