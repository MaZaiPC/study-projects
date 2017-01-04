#include "stdafx.h"
#include "Time.h"
#include "Utils.h"

// ������������� ������������ ���� (����������)
char Time::delimeter = '.';

// ����������� �� ���������
Time::Time() {
	h = 0; 
	m = 0;
}


// ����������� � �����������
Time::Time(int h, int m)
{
	setH(h);
	setM(m);
}// Time::Time - ����������� � �����������

// ���������� �����������
Time::Time(const Time & obj)
{

	h = obj.h;        // ���������� ����������� ��������
	m = obj.m;        // ���������� ����������� ��������

}// Time::Time - ���������� �����������


// �������
void Time::setH(int h)
{
	if (h < 0) {
		cout << "\n �� ������ �������� ��� ! ������ �� 9\n";
		h = 9;
	} // if

	if (h > 23) {
		h = 0;
	}// if

	this-> h = h;

}// Time::setH

void Time::setM(int m)
{
	if (m < 0) {
		cout << "\n �� ������ �������� ������ ! ������ �� 24\n";
		m = 24;
	} // if

	if ( m > 59) {
		h++;
		m = 0;
	} // if

	this->m = m;
}// Time::setM

void Time::setH()
{
	UINT H;
	cout << "������� ����: "; cin >> H; 
	if (h < 0) {
		cout << "\n �� ������ �������� ��� ! ������ �� 9\n";
		h = 9;
	} // if

	if (h > 23) {
		h = 0;
	}// if
	setH(H);
}// Time::setH

void Time::setM()
{
	UINT M;
	cout << "������� ������: "; cin >> M;
	if (m < 0) {
		cout << "\n �� ������ �������� ������ ! ������ �� 24\n";
		m = 24;
	} // if

	if (m > 59) {
		h++;
		m = 0;
	} // if
	setM(M);
}// Time::setM

// ������

void Time::Init(int h, int m)
{
	setH(h);
	setM(m);

}// Time::Init

void Time::Read()
{
	cout << "\n ������� ���(�)   :> ";
	cin >> h;
	
	cout << "\n ������� ������(�)  :> ";
	cin >> m;

	setH(h);
	setM(m);

}// Time::Read

void Time::Display(bool nl)
{
	// setfill() - ���������� ������� �������� �������� ���������
	cout << "\n ����� : " << setfill('0') << setw(2) << h << delimeter
		<< setw(2) << m << setfill(' ') << (nl ? "\n" : "");

}// Time::Display(bool nl)



// ������� ������ � ���� � ������
void Time::toHM(int t)
{
	h = t / 3600;
	t -= 3600 * h;

	m = t / 60;
} // Time::toHM


// ���������� ������� ����� ����� ��������� �������
int Time::DifferenceSeconds(Time ti)
{

	int Ti1 = ToSeconds();
	int Ti2 = ti.ToSeconds();

	return ((Ti2 > Ti2)?Ti2 - Ti1 : Ti1 - Ti2);
}// Time::DifferenceSeconds(Time ti)


// �������� ��������� ��������� ������� 
void Time::Add(const Time &time)
{
	int t = ToSeconds() + time.ToSeconds();
	toHM(t);
}// Time::Add


// ��������� ��������� ��������� ������� 
void Time::Sub(const Time &time)
{
	int t = abs(ToSeconds() - time.ToSeconds());
	toHM(t);
}// Time::Sub()

 // ��������� ���� �������� �������
int Time::Compare(Time ti)
{
	int Ti1 = ToSeconds();
	int Ti2 = ti.ToSeconds();

	if (Ti1 < Ti2) return -1;
	if (Ti1 > Ti2) return 1;

	return 0;
}// Time::Compare(Time ti)





