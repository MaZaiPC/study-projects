#pragma once
class Price
{
	char   *name;       // Начальный маршрут
	UINT    price;       // Номер маршрута

public:

	static const UINT LEN_NAME;    // статическая константа для определения длины поля начального маршрута
	static const UINT LEN_PRICE;      // статическая константа для определения длины поля конечного маршрута

	Price();                                                                    // Конструктор по умолчанию
	explicit Price(char *name, UINT price);   // Конструктор с параметрами
	Price(const Price &obj);                                                    // Конструктор копирования
	~Price();      // Деструктор

	// !!! Необходима для правильного определения размера записи файла !!!
	// т.к. класс имеет динамические поля
	// !!! Статический метод класса не должен обращаться к полям класса
	static int recSize() { return LEN_NAME + LEN_PRICE + sizeof(int); }

	// Геттеры
	char *getName()   const { return name; }
	int  getPrice()   const { return price; }

	// Сеттеры
	void setName(char * name);
	void setPrice(UINT price);

	// Методы
	void Init(char * name, UINT price);      // Инициализация присваивания начальных значений
	void Read(int x, int y);                                                   // Ввод значений полей с клавиатуры
	void Display(int &p1, int &p2, bool nl = false);                                           // Вывод значений полей в консоль

	//char * toString();													   // Возвращает строку, содержащую значения полей объекта

	// Методы для записи в файл/чтения из файла
	// (сериализация объекта)
	int Save(FILE * f, bool append = true);                                                         // Метод для записи в файл полей класса 
	int Load(FILE * f);                                                         // Метод для чтения из файла полей класса 
	
};

