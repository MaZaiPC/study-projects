#include "stdafx.h"
#include "Price.h"
#include "Utils.h"

const UINT Price::LEN_NAME = 45;    // 24 ��� ����� ���������� ������ ����������, +1 ��� ��� ���������
const UINT Price::LEN_PRICE = 6;    // 24 ��� ����� ��������� ������ ����������, +1 ��� ��� ���������

// ����������� �� ���������
Price::Price():
name(new char[LEN_NAME]), price()
{
	// ��������� ����� ��� �������� ����� ������ ���������� ���������� � ��������� ����������
	memset(name, 0, LEN_NAME);
}// Price()

// ����������� � �����������
Price::Price(char * name, UINT Price):
	name(new char[LEN_NAME]), price(Price)
{
	// ��������� ����� ��� �������� ����� � ����� 
	memset(this->name, 0, LEN_NAME);

	// ����������� �������� �� �����-���������� � ���� ������
	strncpy(this->name, name, LEN_NAME - 1);

}// Price()

// ����������� �����������
Price::Price(const Price & obj):
	name(new char[LEN_NAME]), price(obj.price)
{
	// ��������� ����� ��� �������� ����� � ����� 
	memset(name, 0, LEN_NAME);

	// ����������� �������� �� �������-��������� � ���� ������
	strcpy(name, obj.name);

}// Price(const Price & obj)

// ����������
Price::~Price()
{
	delete[] name;
}// ~Price()

// ������� 

void Price::setName(char *name)
{
	if (!name) {
		cerr << "\n �������� ������ ������� �����������! ������ �� ''Mountain Dew''\n";
		strcpy(name, "Mountain Dew");
		return;  // ��������� � ����� ������ ������
	} // if

	  // �������� �� ������ LEN_NAME ��������
	strncpy(this->name, name, LEN_NAME - 1);
} // setName

void Price::setPrice(UINT what)
{
	if (what < 0) {
		cerr << "\n ���� ������ ������� �����������! ������ �� 9 ������.\n";
		price = 9;
		return;  // ��������� � ����� ������ ������
	} // if

	price = what;

}// Price::setPrice

// ������������� ������������ ��������� ��������
void Price::Init(char * name, UINT Price)
{

	setName(name);
	setPrice(price);
	
}// Price::Init

// ���� �������� ����� � ����������
void Price::Read(int x, int y)
{
	// ��������������� ����������
	char *_name = new char[LEN_NAME];   // ��������� �����
	UINT _price;                        // ����� ��������

	COORD Pos[2];
	// ����� ���� ��������� �����
	WriteXY(x, y,     "�������� ������ :> "); Pos[0] = WhereXY();
	WriteXY(x, y + 1, "����            :> "); Pos[1] = WhereXY();

	// ����������� ����� ��� ������� ���� ��������
	GotoXY(Pos[0].X,Pos[0].Y);
	cin >> _name;
	setName(name);

	GotoXY(Pos[1].X, Pos[1].Y);
	cin >> _price;
	setPrice(_price);
} //  Price::Read


// ����� �������� ����� � �������
void Price::Display(int &p1, int &p2, bool nl)
{
	cout << "  "; p1 = WhereXY().X; cout << left << setw(17) << name << "   "; p2 = WhereXY().X;
	cout << right << setw(3) << price;
	cout << (nl ? "\n" : "");
} // Price::Display


// ����� ��� ������ � ���� ����� ������
// append == true (�� ���������) - �������� � ����
// append == false - ������������ ������� ���������� (������� ������)
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

// ����� ��� ������ �� ����� ����� ������ 
int Price::Load(FILE * f)
{
	fread(name, LEN_NAME, 1, f);
	fread(&price, sizeof(price), 1, f);
	return 0;
} // Price::Load

  // ���������� ������, ���������� �������� ����� �������

/*
  char * Price::toString()
  {
  	char *str = new char[100];
  
  	// sprintf(str, format, list_args);
  	// %lf - ��������� double
  	// %.3lf - ����� ����� ���������, ��� ����. � ������� ����� ������� 3 �����
  	// %d  - ��������� int
  	sprintf(str, "���� x = %.3lf; ���� y = %d", x, y);
  	return str;
  }// Price::toString()
  */