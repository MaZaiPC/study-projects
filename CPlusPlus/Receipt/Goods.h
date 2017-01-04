#pragma once
class Goods
{
	UINT code;       // Код товара
	char* name;      // Наименование товара
	UINT price;      // Цена товара в копейках
	UINT quantity;   // Количество покупаемого товара 

public:

	static const UINT LEN_NAMEPRODUCT;    // статическая константа для определения длины поля наименнования товара

	Goods();                                                  // Конструктор по умолчанию
	Goods(UINT code, char * name, UINT price, UINT quantity); // Конструктор с параметрами
	Goods(const Goods & obj);                                 // Конструктор копирования
	~Goods();                                                 // Деструктор

	// !!! Необходима для правильного определения размера записи файла !!!
	// т.к. класс имеет динамические поля
	// !!! Статический метод класса не должен обращаться к полям класса
	static int recSize() { return LEN_NAMEPRODUCT + sizeof(int) + sizeof(double) + sizeof(int); }

	// Геттеры
	char *getName()    const { return name;     }
	UINT getCode()     const { return code;     }
	UINT getPrice()    const { return price;    }
	UINT getQuantity() const { return quantity; }

	// Сеттеры
	void setName(char * name);
	void setCode(UINT what);
	void setPrice(UINT what);
	void setQuantity(UINT what);

	// Методы
    void Init(UINT code, char * name,  UINT price, UINT quantity); // Инициализация присваивания начальных значений
	UINT summa() { return price * quantity; }                      // Сумма по товару

	// Методы для записи и чтения файла 
	int save();
	int load();

	// Перегрузка операции присваивания 
	// - выполянется если необходим конструктор копирования
	// - возможна только методом класса
	// - возвращает ссылку на объект
	Goods &operator=(const Goods &goods);

	// Перегрузка операций ввода и вывода
	friend istream &operator>>(istream &is, Goods &obj);
	friend ostream &operator<<(ostream &os, const Goods &obj);

	//char * toString();										      // Возвращает строку, содержащую значения полей объекта
};

