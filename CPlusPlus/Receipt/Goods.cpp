#include "stdafx.h"
#include "Goods.h"
#include "Utils.h"
#include <istream>
#include "BinFiles.h"

const UINT Goods::LEN_NAMEPRODUCT = 31;    // 10 ��� ����� �������� ������, +1 ��� ��� ���������

Goods::Goods():
	code(), name(new char[LEN_NAMEPRODUCT]), price(), quantity()
{
	// ��������� ����� ��� �������� ����� ������ 
	memset(name, 0, LEN_NAMEPRODUCT);	
}// Goods::Goods(): ����������� �� ���������


// ����������� � �����������
Goods::Goods(UINT code, char * name, UINT price, UINT quantity):
	code(code), name(new char[LEN_NAMEPRODUCT]), price(price), quantity(quantity)
{
	// ��������� ���� ��� �������� ������������ ������ 
	memset(this->name, 0, LEN_NAMEPRODUCT);
	
	// ����������� �������� �� �����-���������� � ���� ������
	strncpy(this->name, name, LEN_NAMEPRODUCT - 1);
}// Goods::Goods: ����������� � �����������

 
// ����������� �����������
Goods::Goods(const Goods & obj) :
	name(new char[LEN_NAMEPRODUCT]), code(obj.code), price(obj.price), quantity(obj.quantity)
{
	// ��������� ���� ��� �������� ������������ ������ 
	memset(name, 0, LEN_NAMEPRODUCT);
	
	// ����������� �������� �� �������-��������� � ���� ������
	strcpy(name, obj.name);
	
}// Goods::Goods: ����������� �����������


// ����������
Goods::~Goods()
{
	delete[] name;
}//Goods::~Goods

// �������

void Goods::setName(char * name)
{
	if (!name || strlen(name) == 0) {
		cerr << "\n �������� ������ ������� �����������! ������ ������������ ������ �� \"����\"\n";
		strcpy(name, "����");
		return;  // ��������� � ����� ������ ������
	} // if

	// �������� �� ������ LEN_NAMEPRODUCT ��������
	strncpy(this->name, name, LEN_NAMEPRODUCT - 1);
} // Goods::setName


void Goods::setCode(UINT what)
{
	if (what == 0) {
		cerr << "\n ��� ������ ������ �� ��������! ������ ���� ������ �� 249654\n";
		what = 249654;
		return;  // ��������� � ����� ������ ������
	} // if

	code = what;
}// Goods::setCode


void Goods::setPrice(UINT what)
{
	if (what == 0) {
		cerr << "\n ���� ������ �������� �� ��������! ������ ���� ������ �� 24.60\n";
		what = 2460;
		return;  // ��������� � ����� ������ ������
	} // if

	price = what;
}// Goods::setPrice


void Goods::setQuantity(UINT what)
{
	if (what == 0) {
		cerr << "\n ���������� ������ �������� �� ��������! ������ ���������� ������ �� 3\n";
		what = 3;
		return;  // ��������� � ����� ������ ������
	} // if

	quantity = what;

}// Goods::setQuantityGoods

// ������

// ������������� ������������ ��������� ��������
void Goods::Init(UINT code, char * name, UINT price, UINT quantity)
{
	setCode(code);
	setName(name);
	setPrice(price);
	setQuantity(quantity);

}// Goods::Init


// ���������� �������� ������������
Goods &Goods::operator=(const Goods &goods)
{
	// ������������ �����, ������ ��� ������� ������������� ����������
	code = goods.code;
	price = goods.price;
	quantity = goods.quantity;

	// ��������� ���� ��� �������� ������������ ������ 
	memset(name, 0, LEN_NAMEPRODUCT);

	// ����������� �����, ������ ��� ������� �������������� �����������
	// ����������� �������� �� �������-��������� � ���� ������
	strcpy(name, goods.name);

	// ������� ������ �� ������
	return *this;
} // Goods::operator=


// ���������� �������� �����
istream &operator>>(istream &is, Goods &obj)
{
	char *n = new char[Goods::LEN_NAMEPRODUCT];
	UINT c, p, qg;
	// _flushall();

	WriteXY(13, 13, "������� ������ ��� ��������� ����");
	WriteXY(13, 14, "������������ ������             >                   ");
	WriteXY(13, 15, "��� ������                      >                   ");
	WriteXY(13, 16, "���� ������� ������ (� ��������)>                   ");
	WriteXY(13, 17, "���������� ������               >                   ");	

	GotoXY(48, 14);   is >> n;
	GotoXY(48, 15);   is >> c;
	GotoXY(48, 16);   is >> p;
	GotoXY(48, 17);   is >> qg;
	
	obj.Init(c, n, p, qg);
	return is;
} // operator>>


// ���������� �������� ������
ostream &operator<<(ostream &os, const Goods &obj)
{
	os << setw(24) << obj.name << setw(15) << obj.code 
	   <<  setw(17) << obj.price << setw(12) << obj.quantity;
	return os;
} // operator<<


// ����� ��� ������ � ���� ����� ������
// append == true (�� ���������) - �������� � ����
// append == false - ������������ ������� ���������� (������� ������)
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


// ����� ��� ������ �� ����� ����� ������ 
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


 // ���������� ������, ���������� �������� ����� �������

 /*
 char * Marsh::toString()
 {
 char *str = new char[100];

 // sprintf(str, format, list_args);
 // %lf - ��������� double
 // %.3lf - ����� ����� ���������, ��� ����. � ������� ����� ������� 3 �����
 // %d  - ��������� int
 sprintf(str, "���� x = %.3lf; ���� y = %d", x, y);
 return str;
 }// Marsh::toString()
 */
