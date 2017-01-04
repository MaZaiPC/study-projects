#include "stdafx.h"
#include "Price.h"
#include "Utils.h"

const UINT Price::LEN_NAME = 45;
const UINT Price::LEN_PRICE = 6;

Price::Price()
{
	price = 0.1;
	name = ">Empty<";
}

Price::Price(double price, string name)
{
	this->price = price;
	this->name = name;
}

Price::Price(const Price & obj)
{
	price = obj.price;
	name = obj.name;
}

Price::~Price()
{
}

// �������
void Price::setPrice(double pr)
{
	price = pr;
}
void Price::setName(string nm)
{
	name = nm;
}

// ������
void Price::Input(UINT n)
{
	string tmp = Format("���������� ������ �%u", n);
	tMark(tmp, 1);
	COORD Pos[3];
	cout << "\n�������� ������\t:> ";	Pos[0] = WhereXY();
	cout << "\n���������\t:> ";		Pos[1] = WhereXY(); cout << "\t\t���.";

	GotoXY(Pos[0].X, Pos[0].Y); getline(cin, name); getline(cin, name);
	GotoXY(Pos[1].X, Pos[1].Y); cin >> price;
}

void Price::Show(UINT n)
{
	string tmp = Format("����� �%u", n);
	tMark(tmp, 1);
	cout << "\n�������� ������: " << name << endl;
	cout << "���������: " << price << " ���." << "\n\n";
}

void Price::Randomize()
{	
	string goods[] = { "Lenovo B590", "LG Optimus L90 Dual", "������ Lacoste HH179LNTWT40", "HP EliteBook 850 G2", "���������� ���� Comfy Home Mateo", "���������� ������ AquaEl Pat Mini", "���������� Asus PCI-Ex GeForce GTX 980 Matrix 4GB", "Logitech Ultimate Ears 400vi", "Logitech Ultimate Ears 600vi", "���������������", "���������� Cannon", "Lenovo Tab 2", "Galaxy S6 Edge+", "�����", "�������", "���� DVD-R", "���� DVD-RW", "Logitech Keyboard", "GTA V - PC", "AWP Asimov" };
	double cost[] =  {	8199,		  3199,					  1836,							 30294,					1333,								236,								 18337,												  599,							  1455,							  233,				 8999,				  2249,			  23999,			 250,	  22,		 25,		   26,			  249,				   3399,		 1740		 };
	WORD c = Random(1, 19);

	name = goods[c];
	price = cost[c];
}

// ����� ��� ������ � ���� ����� ������ 
int Price::Save(FILE * f, bool append)
{
	int cc;
	if (append) fseek(f, 0, SEEK_END);
	cc = fwrite(&name, LEN_NAME, 1, f);
	if (cc != 1) return 1;

	cc = fwrite(&price, LEN_PRICE, 1, f);
	if (cc != 1) return 1;

	return 0;
} // Train::Save


// ����� ��� ������ �� ����� ����� ������ 
int Price::Load(FILE * f)
{
	fread(&name, LEN_NAME, 1, f);
	fread(&price, LEN_PRICE, 1, f);
	return 0;
} // Train::Load 