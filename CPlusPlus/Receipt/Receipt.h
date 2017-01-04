#pragma once
#include "Goods.h"
#include "DateTime.h"

class Receipt
{
	UINT     number;  // ����� ����
	UINT     size;    // ����������� ���������� ������� � ����
	DateTime create;  // ���� � ����� �������� ����
	Goods    *goods;  // ��������� �� ������ ������� � ����

public:
	static const UINT LEN_GOODS;   // ������������ ���������� ������� � ����
	static UINT counter;      // ������� ���������� ��������� ����� - ������� �����
	static UINT makeNumber(); // �������� ������ ����

	Receipt();                          // ����������� �� ���������
	Receipt(int number, DateTime &dt);  // ����������� � �����������
	Receipt(const Goods &obj);          
	Receipt(const Receipt &obj);        // ����������� �����������                                              
	~Receipt();                         // ����������

	// �������
	int getNumber()  const { return number; }

	// �������

	// ������
	// void Init(int number, int day, int  month, int year, int h, int m, int s); // ������������� ������������ ��������� ��������
	int save();
	int load();

	// �������� ������������ - �.�. ���� ����, ������ ��� ������� ���������� 
	// �����������
	Receipt &operator=(const Receipt &obj);
	Receipt &operator=(const Goods &obj);

	// ���������� ������ � ���
	//bool operator+(const Goods &obj);

	// �������� ������ �� ���� �� ������� (nIndex) � ������� ������� goods 
	//bool operator-(UINT nIndex);
	
	// ��������� ������ � ������� ������� goods
	//bool Change(Goods &obj);

	// ����� ������ �� ��� ����
	//Goods &Find(UINT code);

	// ����� ����� ������� �� ����
	UINT Summa() const;

	// ���������� �������� ������ � �����
	friend ostream &operator<<(ostream &os, const Receipt &obj);
	friend istream &operator>>(istream &is, Receipt &obj);
};

