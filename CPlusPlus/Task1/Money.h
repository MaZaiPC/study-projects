#pragma once
#include "stdafx.h"
#include "Pair.h"

class Money : Pair
{
	long bucks, cents;
	
	static void repare(Money &what);
public:
	// ������������ � ����������
	Money();
	Money(long, long);
	~Money();

	// ����������� ������
	virtual Money add(Money &obj) const; // ��������
	virtual Money mul(Money &obj) const; // ���������
	virtual Money sub(Money &obj) const; // ���������
	virtual Money div(Money &obj) const; // �������

	friend istream &operator >>(istream &is, Money &obj);
	friend ostream &operator <<(ostream &os, const Money &obj);
};

