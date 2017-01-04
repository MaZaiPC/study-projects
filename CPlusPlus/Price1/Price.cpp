#include "stdafx.h"
#include "Price.h"
#include "Utils.h"

const UINT Price::LEN_NAME = 45;    // 24 для имени начального пункта назначения, +1 для нул терминала
const UINT Price::LEN_PRICE = 6;    // 24 для имени конечного пункта назначения, +1 для нул терминала

// Конструктор по умолчанию
Price::Price():
name(new char[LEN_NAME]), price()
{
	// Обнуление полей для хранения имени пункта начального назначения и конечного назначения
	memset(name, 0, LEN_NAME);
}// Price()

// Конструктор с параметрами
Price::Price(char * name, UINT Price):
	name(new char[LEN_NAME]), price(Price)
{
	// Обнуление полей для хранения имени и счета 
	memset(this->name, 0, LEN_NAME);

	// Копирование значений из строк-параметров в поля класса
	strncpy(this->name, name, LEN_NAME - 1);

}// Price()

// Конструктор копирования
Price::Price(const Price & obj):
	name(new char[LEN_NAME]), price(obj.price)
{
	// Обнуление полей для хранения имени и счета 
	memset(name, 0, LEN_NAME);

	// Копирование значений из объекта-параметра в поля класса
	strcpy(name, obj.name);

}// Price(const Price & obj)

// Деструктор
Price::~Price()
{
	delete[] name;
}// ~Price()

// Сеттеры 

void Price::setName(char *name)
{
	if (!name) {
		cerr << "\n Название товара введено некорректно! Замена на ''Mountain Dew''\n";
		strcpy(name, "Mountain Dew");
		return;  // вернуться в точку вызова метода
	} // if

	  // копируем не больше LEN_NAME символов
	strncpy(this->name, name, LEN_NAME - 1);
} // setName

void Price::setPrice(UINT what)
{
	if (what < 0) {
		cerr << "\n Цена товара введена некорректно! Замена на 9 рублей.\n";
		price = 9;
		return;  // вернуться в точку вызова метода
	} // if

	price = what;

}// Price::setPrice

// Инициализация присваивания начальных значений
void Price::Init(char * name, UINT Price)
{

	setName(name);
	setPrice(price);
	
}// Price::Init

// Ввод значений полей с клавиатуры
void Price::Read(int x, int y)
{
	// вспомогательные переменные
	char *_name = new char[LEN_NAME];   // началтная точка
	UINT _price;                        // номер маршрута

	COORD Pos[2];
	// Вывод всех подсказок сразу
	WriteXY(x, y,     "Название товара :> "); Pos[0] = WhereXY();
	WriteXY(x, y + 1, "Цена            :> "); Pos[1] = WhereXY();

	// Организация ввода для каждого поля отдельно
	GotoXY(Pos[0].X,Pos[0].Y);
	cin >> _name;
	setName(name);

	GotoXY(Pos[1].X, Pos[1].Y);
	cin >> _price;
	setPrice(_price);
} //  Price::Read


// Вывод значений полей в консоль
void Price::Display(int &p1, int &p2, bool nl)
{
	cout << "  "; p1 = WhereXY().X; cout << left << setw(17) << name << "   "; p2 = WhereXY().X;
	cout << right << setw(3) << price;
	cout << (nl ? "\n" : "");
} // Price::Display


// Метод для записи в файл полей класса
// append == true (по умолчанию) - дозапись в файл
// append == false - перезаписать текущую информацию (текущую запись)
int Price::Save(FILE * f, bool append)
{
	int cc;
	if (append) fseek(f, 0, SEEK_END);
	cc = fwrite(name,   LEN_NAME, 1, f);
	if (cc != 1) return 1;

	cc = fwrite(&price, sizeof(price), 1, f);
	if (cc != 1) return 1;

	return 0;
} // Price::Save

// Метод для чтения из файла полей класса 
int Price::Load(FILE * f)
{
	fread(name, LEN_NAME, 1, f);
	fread(&price, sizeof(price), 1, f);
	return 0;
} // Price::Load

  // Возвращает строку, содержащую значения полей объекта

/*
  char * Price::toString()
  {
  	char *str = new char[100];
  
  	// sprintf(str, format, list_args);
  	// %lf - ожидается double
  	// %.3lf - целая часть выводится, как есть. В дробной части выводим 3 знака
  	// %d  - ожидается int
  	sprintf(str, "Поле x = %.3lf; поле y = %d", x, y);
  	return str;
  }// Price::toString()
  */