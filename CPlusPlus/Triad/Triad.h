#pragma once
#include "stdafx.h"

class Triad
{
protected:
	/*
	�� ���� ��� ����� ������ ����� 3 ���������� �����,
	� � ������ �� ������ ��� ����������, �� ����� �����
	int ��� ����. ���� ���� ������ �������, ����� ���� ��
	��������� ��� �� ���� ������������� ��������� ����
	���������� aka:

	//����������
	void *data = (void *)(new int);

	//������� ��������
	data = (void *)(new WORD);
	*(UINT *)data = 1.2;

	data = (void *)(new WORD);
	*(WORD *)data = 1.2;

	//������ ��������
	x = *(UINT *)data;
	y = *(WORD *)data;
	*/// P.S. - � ����� ��������� ���� �� ����������,
	  // ���� ����� ����� int
	int a, b, c;
public:
	// ������������ � ����������
	Triad();
	Triad(WORD a, WORD b, WORD c);
	Triad(const Triad &obj);
	~Triad();

	// ���������� ����������� ����� ����������
	Triad operator++();

	// ���������� �������� ���������
	bool operator ==(const Triad &obj);
	bool operator <(const Triad &obj);
	bool operator >(const Triad &obj);

	// ���������� ��������� ������������
    const Triad& operator =(const Triad &obj){
		a = obj.a;
		b = obj.b;
		c = obj.c;
        return *this;
    }

	// ���������� ��������� ��������
	friend ostream &operator<<(ostream &os, const Triad &obj);
};

class Time : Triad
{
	// ����� ������ ��������� ������ ���������
	int &h = a, &m = b, &s = c;
public:
	// ������������ � ����������
	Time();
	Time(WORD hour, WORD minute, WORD second);
	Time(const Time &obj);
	~Time() {}

	void init(WORD hour, WORD minute, WORD second);

	// �������
	WORD get_H() const { return h; }
	WORD get_M() const { return m; }
	WORD get_S() const { return s; }

	// ������� 
	void set_H(WORD h);
	void set_M(WORD m);
	void set_S(WORD s);

	bool operator <(const Time &obj);
	bool operator >(const Time &obj);

	// ���������� ��������� ��������
	friend ostream &operator<<(ostream &os, const Time &obj);
	friend istream &operator>>(istream &is, Time &obj);
};

class Date : Triad
{
	int &year = a, &month = b, &day = c; // ��������� ���������
	UINT to_JDN() const;  // ����������� � ��������� ���
	Date to_GD(UINT JDN); // ����������� � ������������� ����
public:
	// ������������ � ����������
	Date();
	Date(UINT y, UINT m, UINT d);
	Date(const Date &obj);
	~Date() {}

	// �������
	UINT get_year() const { return year; }
	UINT get_month() const { return month; }
	UINT get_day() const { return day; }

	// �������
	void set_year(UINT y) { year = y; }
	void set_month(UINT m);
	void set_day(UINT d);

	void init(UINT year, UINT month, UINT day);

	Date operator+(const UINT &days);
	// ���������� ����������� ����� ����������
	Date operator++();

	bool operator <(const Date &obj);
	bool operator >(const Date &obj);

	// ���������� ��������� ��������
	friend ostream &operator<<(ostream &os, const Date &obj);
	friend istream &operator>>(istream &is, Date &obj);
};