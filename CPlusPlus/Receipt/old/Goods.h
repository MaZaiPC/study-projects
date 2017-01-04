#pragma once

class Goods
{
	UINT code;
	string name;
	UINT price;
	WORD count;
public:
	static const UINT LEN_CODE;
	static const UINT LEN_NAME;
	static const UINT LEN_PRICE;
	static const UINT LEN_COUNT;

	// Конструкторы и деструктор
	Goods();
	Goods(int code); // можно придумать множество вариантов перегруженных конструкторов
	~Goods();

	// Перегрузки операторов
	friend istream &operator >>(istream &is, Goods &obj);
	friend ostream &operator <<(ostream &os, Goods &obj);
	const Goods& operator =(const Goods &c);
	
	// Геттеры
	int getCode() { return code; }
	int getPrice() { return price; }
	int getCount() { return count; }
	string getName() { return name; }
	int getSum();

	// Сеттеры
	void setCode(UINT code);
	void setPrice(UINT price);
	void setCount(UINT count);
	void setName(string name);

	// Операции с файлами
	void Save(string filePath);
	void Load(UINT i, string filePath);

	// Методы
	void Randomize();
	void Randomize(Goods *exclude, int N);
};

int ClearData(string fName);
