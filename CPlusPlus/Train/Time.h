#pragma once

class Time
{
	int h;      // ����
	int m;      // ������

	static char delimeter;  // ����������� �����, �����, ������

public:
	Time();                           // ����������� �� ���������
	Time(int h, int m);        // ����������� � �����������
	Time(const Time &obj);            // ���������� �����������
	~Time() {}                        // ����������

	// �������
	int getH() const { return h; }
	int getM() const { return m; }

	// ������� 
	void setH(int h);
	void setM(int m);
	void setH();
	void setM();

	// ������

	void Init(int h, int m);     // ������������� -  h,m
	void Read();                        // ���� � ����������
	void Display(bool nl = false);      // ����� �� �����
	int ToSeconds() const { return h * 3600 + m * 60; }  // ������� ������� � �������
	void toHM(int t);                  // ������� ������ � �������� � ����, ������, ������� 
	int DifferenceSeconds(Time ti);     // ���������� ������� ����� ����� ��������� �������
	void Add(const Time &time);         // �������� ��������� ��������� ������� 
	void Sub(const Time &time);         // ��������� ��������� ��������� ������� 
	int Compare(Time ti);               // ��������� ���� �������� �������
	int ToMinutes() const { return ToSeconds() / 60; }  // ������� ������� � ������
};
