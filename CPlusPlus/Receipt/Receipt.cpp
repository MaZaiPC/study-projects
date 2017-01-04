#include "stdafx.h"
#include "Receipt.h"
#include "Utils.h"
#include "Goods.h"
#include "BinFiles.h"

const UINT Receipt::LEN_GOODS = 7;
UINT Receipt::counter = 0;  // ��������� �������� �������� �����


// ������������ ������ ���� � ������� YYMMDDNNNN
UINT Receipt::makeNumber()
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	return (st.wYear % 100) * 10000000 + st.wMonth * 100000 + st.wDay * 1000 + counter;
} // Receipt::makeNumber


// ����������� �� ���������
Receipt::Receipt():size(), create(), goods(new Goods[LEN_GOODS]) 
{ 
	counter++;             // ������� ��������� �����
	number = makeNumber(); // ����� ����
} // Receipt::Receipt


// ����������� � �����������
Receipt::Receipt(int number, DateTime &dt):size(), create(dt), goods(new Goods[LEN_GOODS])
{
	counter++;             // ������� ��������� �����
	number = makeNumber(); // ����� ����
} // Receipt::Receipt


// ����������� � ���������� - �����
Receipt::Receipt(const Goods &obj): size(1), create(), goods(new Goods[LEN_GOODS])
{
	counter++;             // ������� ��������� �����
	number = makeNumber(); // ����� ����

	// ����������� ������ ������ � ������
	goods[0] = obj;
} // Receipt::Receipt


// ���������� �����������
Receipt::Receipt(const Receipt &obj): size(obj.size), create(obj.create),
	goods(new Goods[LEN_GOODS])
{
	counter++;             // ������� ��������� �����
	number = makeNumber(); // ����� ����

	// ����������� ������� � ����� ������
	for (UINT i = 0; i < size; i++) goods[i] = obj.goods[i];
} // Receipt::Receipt


Receipt::~Receipt()
{
	delete[] goods;
} // Receipt::~Receipt


// ������������ ��� �����
Receipt &Receipt::operator=(const Receipt &obj)
{
	number = obj.number;
	size = obj.size;
	create = obj.create;

	for (UINT i = 0; i < size; i++) goods[i] = obj.goods[i];
	return *this;
} // Receipt::operator=


// ������������ ������ - �������� ������ ������� � ���� �� ���� 
// �������� �����
Receipt &Receipt::operator=(const Goods &obj)
{
	size = 1;
	goods[0] = obj;
	return *this;
} // Receipt::operator=


// ����� �� ����
UINT Receipt::Summa() const
{
	UINT sum = 0;
	for (UINT i = 0; i < size; i++) {
		sum += goods[i].summa();
	} // for i

	return sum;
} // Receipt::Summa


// ��������� ��� � ����� ������ -- ��������� �����
int Receipt::save()
{
	BinDB receipt;
	receipt.SetFileName("receipts.bin");
	string section = Format("Section%d", number);
	receipt.Write(section, "Number", to_string(number));
	receipt.Write(section, "Size", to_string(size));
	receipt.Write(section, "d", to_string(create.getDay()));
	receipt.Write(section, "m", to_string(create.getMonth()));
	receipt.Write(section, "y", to_string(create.getYear()));

	receipt.Write(section, "hr", to_string(create.getHour()));
	receipt.Write(section, "mn", to_string(create.getMinute()));
	string gooide;
	for (int i = 0; i < LEN_GOODS; i++)
	{
		gooide = Format("Gooide%d", i);
		receipt.Write(section, gooide, to_string(goods[i].getCode()));
	}

	return 0;
} // Receipt::save


// ������ ��� �� ����� ������ - ��������� �����
int Receipt::load()
{
	BinDB receipt;
	receipt.SetFileName("receipts.bin");
	LPSTR tmp;
	string section = Format("Section%d", number);
	receipt.Read(section, "Number", 0, tmp, 350);
	number = (UINT)tmp;
	receipt.Read(section, "Size", 0, tmp, 350);
	size = (UINT)tmp;

	receipt.Read(section, "d", 0, tmp, 350);
	create.setDay((WORD)tmp);
	receipt.Read(section, "m", 0, tmp, 350);
	create.setMonth((WORD)tmp);
	receipt.Read(section, "y", 0, tmp, 350);
	create.setYear((WORD)tmp);
	receipt.Read(section, "hr", 0, tmp, 350);
	create.setHour((WORD)tmp);
	receipt.Read(section, "mn", 0, tmp, 350);
	create.setMinute((WORD)tmp);

	string gooide;
	for (int i = 0; i < LEN_GOODS; i++)
	{
		gooide = Format("Gooide%d", i);
		receipt.Read(section, "Gooide", 0, tmp, 350);
		goods[i].setCode((UINT)tmp);
		goods[i].load();
	}
	return 0;
} // Receipt::load

//////////////////////////////////////////////////////////////////////////////

// ���������� �������� ������
ostream &operator<<(ostream &os, const Receipt &obj)
{
	os << "\t�������� ��� No " << obj.number << " �� " << obj.create << "\n";
	for (UINT i = 0; i < obj.size; i++) {
		os << setw(2) << i << " : " << obj.goods[i] << "\n";
	} // for i
	os << "\t\t\t����� �� ����: " << obj.Summa() << "\n";
	return os;
} // operator<<


// ���������� �������� �����
istream &operator>>(istream &is, Receipt &obj)
{
	Goods goods;
	char *reply = new char[100];

	WriteXY(13, 9, "�������� ��� "); cout << obj.number << " �� " << obj.create;

	for (UINT i = 1; i <= obj.LEN_GOODS; i++) {
		WriteXY(13, 11, "����� No "); cout << i;

		is >> goods;
		obj.goods[i - 1] = goods;
		goods.save();

		WriteXY(13, 23, "���������� ���� (��/���)? ");
		is>>reply;
		WriteXY(39, 23, "               ");
		if (strcmp(reply, "��") != 0) break;
	} // for i

	delete[] reply;
	return is;
} // operator>>