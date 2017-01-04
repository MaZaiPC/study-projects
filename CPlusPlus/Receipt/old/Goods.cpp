#include "stdafx.h"
#include "Goods.h"
#include "Utils.h"

const UINT Goods::LEN_CODE = 6;
const UINT Goods::LEN_NAME = 45;
const UINT Goods::LEN_PRICE = 6;
const UINT Goods::LEN_COUNT = 4;


Goods::Goods() : code(0), name("Unknown"), price(0), count(0)
{
}

// ����������� � �����������
Goods::Goods(int code)
{
	setCode(code);
}


Goods::~Goods()
{
}

// �������� �����
istream &operator >>(istream &is, Goods &obj)
{
	COORD Pos[4];
	cout << "\n��� ������\t:> ";		Pos[0] = WhereXY();
	cout << "\n�������� ������\t:> ";	Pos[1] = WhereXY();
	cout << "\n���������\t:> ";			Pos[2] = WhereXY();
	cout << "\n���-��\t:> ";			Pos[3] = WhereXY();

	GotoXY(Pos[0].X, Pos[0].Y); is >> obj.code;
	GotoXY(Pos[1].X, Pos[1].Y); is >> obj.name;
	GotoXY(Pos[2].X, Pos[2].Y); is >> obj.price;
	GotoXY(Pos[3].X, Pos[3].Y); is >> obj.count;
	return is;
} // operator>>


// ���������� �������� ������
ostream &operator <<(ostream &os, Goods &obj)
{
	os << "\n��� ������:\t "	 << obj.code;
	os << "\n�������� ������: "  << obj.name;
	os << "\n���������:\t "		 << obj.price;
	os << "\n���-��:\t\t "		 << obj.count;
	return os;
} // operator<< 

void Goods::Save(string filePath)
{
	string section = Format("Section%d", code);
	string _code = to_string(code);
	string _price = to_string(price);
	string _count = to_string(count);
	WritePrivateProfileStringA(section.c_str(), "Code", _code.c_str(), filePath.c_str());
	WritePrivateProfileStringA(section.c_str(), "Name", name.c_str(), filePath.c_str());
	WritePrivateProfileStringA(section.c_str(), "Price", _price.c_str(), filePath.c_str());
	WritePrivateProfileStringA(section.c_str(), "Count", _count.c_str(), filePath.c_str());
}

void Goods::Load(UINT i, string filePath)
{
	string section = Format("Section%d", i);
	static char buf[100];
	GetPrivateProfileStringA(section.c_str(), "Code", "0", buf, 100, filePath.c_str());
	this->code = (UINT)buf;
	GetPrivateProfileStringA(section.c_str(), "Name", "_Undefined_", buf, 100, filePath.c_str());
	name = (string)buf;
	GetPrivateProfileStringA(section.c_str(), "Price", "0", buf, 100, filePath.c_str());
	price = (UINT)buf;
	GetPrivateProfileStringA(section.c_str(), "Count", "0", buf, 100, filePath.c_str());
	price = (WORD)buf;
}

int ClearData(string filePath)
{
	ifstream f(filePath);
	f.open(filePath, ios_base::trunc);
	f.close();
	return 0;
}

const Goods& Goods::operator =(const Goods &c)
{
	code = c.code;
	name = c.name;
	price = c.price;
	count = c.count;
	return *this;
}

void Goods::setCode(UINT code)
{
	this->code = code;
}

void Goods::setPrice(UINT price)
{
	this->price = price;
}

void Goods::setCount(UINT count)
{
	this->count = count;
}

void Goods::setName(string name)
{
	this->name = name;
}

void Goods::Randomize()
{
	string goods[20] = { "Lenovo B590", "LG Optimus L90 Dual", "������ Lacoste HH179LNTWT40", "HP EliteBook 850 G2", "���������� ���� Comfy Home Mateo", "���������� ������ AquaEl Pat Mini", "���������� Asus PCI-Ex GeForce GTX 980 Matrix 4GB", "Logitech Ultimate Ears 400vi", "Logitech Ultimate Ears 600vi", "���������������", "���������� Cannon", "Lenovo Tab 2", "Galaxy S6 Edge+", "�����", "�������", "���� DVD-R", "���� DVD-RW", "Logitech Keyboard", "GTA V - PC", "AWP Asimov" };
	UINT cost[20] = { 8199, 3199, 1836, 30294, 1333, 236, 18337, 599, 1455, 233, 8999, 2249, 23999, 250, 22, 25, 26, 249, 3399, 1740 };
	
	int c = Random(1, 100000);
	code = c;
	c = Random(1, 19);
	name = goods[c];
	price = cost[c];
	c = price;
	c = (-(c - 30304) / 1050);
	c = c == 0 ? 3 : Random(c-5,c+5);
	count = c;
}

void Goods::Randomize(Goods *exclude, int N)
{
	string goods[20] = { "Lenovo B590", "LG Optimus L90 Dual", "������ Lacoste HH179LNTWT40", "HP EliteBook 850 G2", "���������� ���� Comfy Home Mateo", "���������� ������ AquaEl Pat Mini", "���������� Asus PCI-Ex GeForce GTX 980 Matrix 4GB", "Logitech Ultimate Ears 400vi", "Logitech Ultimate Ears 600vi", "���������������", "���������� Cannon", "Lenovo Tab 2", "Galaxy S6 Edge+", "�����", "�������", "���� DVD-R", "���� DVD-RW", "Logitech Keyboard", "GTA V - PC", "AWP Asimov" };
	UINT cost[20] = { 8199, 3199, 1836, 30294, 1333, 236, 18337, 599, 1455, 233, 8999, 2249, 23999, 250, 22, 25, 26, 249, 3399, 1740 };

	int c = Random(1, 100000);
	code = c;
	c = Random(1, 19);
	for (int i = 0; i < sizeof(exclude)/sizeof(exclude[0]); i++)
	{
		if (goods[c] == exclude[i].getName())
			c = Random(1, 19);
	}
	name = goods[c];
	price = cost[c];
	c = price;
	c = (-(c - 30304) / 1050);
	c = c == 0 ? 3 : Random(c - 5, c + 5);
	count = c;
}