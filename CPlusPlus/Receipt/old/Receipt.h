#pragma once
#include "Goods.h"
#include "Time.h"

class Receipt
{
	UINT     number;  // ����� ����
	UINT     size;    // ����������� ���������� ������� � ����
	Time	 create;  // ���� � ����� �������� ����
	Goods    *goods;  // ��������� �� ������ ������� � ����

public:
	static UINT counter;      // ������� ���������� ��������� ����� - ������� �����
	static UINT makeNumber(); // �������� ������ ����

	Receipt();                          // ����������� �� ���������
	Receipt(int number, Time &dt);  // ����������� � �����������
	Receipt(const Goods &obj);          
	Receipt(const Receipt &obj);        // ����������� �����������                                              
	~Receipt();                         // ����������

	// �������
	int getNumber()  const { return number; }

	// �������
	void setNumber(int what);

	// ������
	void Init(int number, int day, int  month, int year, int h, int m, int s); // ������������� ������������ ��������� ��������
	bool operator-(UINT nIndex);	// �������� ������ �� ���� �� ������� (nIndex) � ������� ������� goods 
	bool Change(Goods &obj);		// ��������� ������ � ������� ������� goods
	Goods &Find(UINT code);			// ����� ������ �� ��� ����
	UINT Summa();					// ����� ����� ������� �� ����

	// �������� � �������
	void Save(string filePath);
	void Save(UINT gooideNum, string filePath);
	void Load(UINT i, string recFilePath, string dbFilePath);

	// ���������� �������� ������ � �����
	friend ostream &operator<<(ostream &os, const Receipt &obj);
	friend istream &operator>>(istream &is, Receipt &obj);
};

