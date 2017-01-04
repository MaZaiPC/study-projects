#include "stdafx.h"
#include "Goods.h"
#include "Utils.h"
#include <istream>
#include "BinFiles.h"

const UINT Goods::LEN_NAMEPRODUCT = 31;    // 10 для имени названия товара, +1 для нул терминала

Goods::Goods():
	code(), name(new char[LEN_NAMEPRODUCT]), price(), quantity()
{
	// Обнуление полей для хранения имени товара 
	memset(name, 0, LEN_NAMEPRODUCT);	
}// Goods::Goods(): Конструктор по умолчанию


// Конструктор с параметрами
Goods::Goods(UINT code, char * name, UINT price, UINT quantity):
	code(code), name(new char[LEN_NAMEPRODUCT]), price(price), quantity(quantity)
{
	// Обнуление поля для хранения наименования товара 
	memset(this->name, 0, LEN_NAMEPRODUCT);
	
	// Копирование значений из строк-параметров в поля класса
	strncpy(this->name, name, LEN_NAMEPRODUCT - 1);
}// Goods::Goods: Конструктор с параметрами

 
// Конструктор копирования
Goods::Goods(const Goods & obj) :
	name(new char[LEN_NAMEPRODUCT]), code(obj.code), price(obj.price), quantity(obj.quantity)
{
	// Обнуление поля для хранения наименования товара 
	memset(name, 0, LEN_NAMEPRODUCT);
	
	// Копирование значений из объекта-параметра в поля класса
	strcpy(name, obj.name);
	
}// Goods::Goods: Конструктор копирования


// Деструктор
Goods::~Goods()
{
	delete[] name;
}//Goods::~Goods

// Сеттеры

void Goods::setName(char * name)
{
	if (!name || strlen(name) == 0) {
		cerr << "\n Название товара введено некорректно! Замена наименования товара на \"Кофе\"\n";
		strcpy(name, "Кофе");
		return;  // вернуться в точку вызова метода
	} // if

	// копируем не больше LEN_NAMEPRODUCT символов
	strncpy(this->name, name, LEN_NAMEPRODUCT - 1);
} // Goods::setName


void Goods::setCode(UINT what)
{
	if (what == 0) {
		cerr << "\n Код товара введен не коректно! Замена кода товара на 249654\n";
		what = 249654;
		return;  // вернуться в точку вызова метода
	} // if

	code = what;
}// Goods::setCode


void Goods::setPrice(UINT what)
{
	if (what == 0) {
		cerr << "\n Цена товара введенна не коректно! Замена цены товара на 24.60\n";
		what = 2460;
		return;  // вернуться в точку вызова метода
	} // if

	price = what;
}// Goods::setPrice


void Goods::setQuantity(UINT what)
{
	if (what == 0) {
		cerr << "\n Количество товара введенно не коректно! Замена количества товара на 3\n";
		what = 3;
		return;  // вернуться в точку вызова метода
	} // if

	quantity = what;

}// Goods::setQuantityGoods

// Методы

// Инициализация присваивания начальных значений
void Goods::Init(UINT code, char * name, UINT price, UINT quantity)
{
	setCode(code);
	setName(name);
	setPrice(price);
	setQuantity(quantity);

}// Goods::Init


// Перегрузка операции присваивания
Goods &Goods::operator=(const Goods &goods)
{
	// Присваивание полей, память под которые распределется статически
	code = goods.code;
	price = goods.price;
	quantity = goods.quantity;

	// Обнуление поля для хранения наименования товара 
	memset(name, 0, LEN_NAMEPRODUCT);

	// Копирование полей, память под которые распределяется динамически
	// Копирование значений из объекта-параметра в поля класса
	strcpy(name, goods.name);

	// Возврат ссылки на объект
	return *this;
} // Goods::operator=


// Перегрузка операции ввода
istream &operator>>(istream &is, Goods &obj)
{
	char *n = new char[Goods::LEN_NAMEPRODUCT];
	UINT c, p, qg;
	// _flushall();

	WriteXY(13, 13, "Введите данные для товарного чека");
	WriteXY(13, 14, "Наименование товара             >                   ");
	WriteXY(13, 15, "Код товара                      >                   ");
	WriteXY(13, 16, "Цена единицы товара (в копейках)>                   ");
	WriteXY(13, 17, "Количество товара               >                   ");	

	GotoXY(48, 14);   is >> n;
	GotoXY(48, 15);   is >> c;
	GotoXY(48, 16);   is >> p;
	GotoXY(48, 17);   is >> qg;
	
	obj.Init(c, n, p, qg);
	return is;
} // operator>>


// Перегрузка операции вывода
ostream &operator<<(ostream &os, const Goods &obj)
{
	os << setw(24) << obj.name << setw(15) << obj.code 
	   <<  setw(17) << obj.price << setw(12) << obj.quantity;
	return os;
} // operator<<


// Метод для записи в файл полей класса
// append == true (по умолчанию) - дозапись в файл
// append == false - перезаписать текущую информацию (текущую запись)
int Goods::save()
{
	BinDB goods;
	goods.SetFileName("goods.bin");
	string section = Format("Section%d", code);
	goods.Write(section, "Code", to_string(code));
	goods.Write(section, "Name",  name);
	goods.Write(section, "Price", to_string(price));
	goods.Write(section, "Count", to_string(quantity));

	return 0;
} // PRICE::save


// Метод для чтения из файла полей класса 
int Goods::load()
{
	BinDB goods;
	goods.SetFileName("goods.bin");
	LPSTR tmp;
	string section = Format("Section%d", code);
	goods.Read(section, "Code", 0, tmp, 350);
	code = (UINT)tmp;
	goods.Read(section, "Name", "None", tmp, 350);
	name = tmp;
	goods.Read(section, "Price", 0, tmp, 350);
	price = (UINT)tmp;
	goods.Read(section, "Count", 0, tmp, 350);
	quantity = (UINT)tmp;
	return 0;
} // PRICE::load


 // Возвращает строку, содержащую значения полей объекта

 /*
 char * Marsh::toString()
 {
 char *str = new char[100];

 // sprintf(str, format, list_args);
 // %lf - ожидается double
 // %.3lf - целая часть выводится, как есть. В дробной части выводим 3 знака
 // %d  - ожидается int
 sprintf(str, "Поле x = %.3lf; поле y = %d", x, y);
 return str;
 }// Marsh::toString()
 */
