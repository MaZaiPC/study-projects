#pragma once

/**
1. ���������� ����� � ������ MARSH, ���������� ��������� ����:
	� �������� ���������� ������ ��������;
	� �������� ��������� ������ ��������;
	� ����� ��������.
 ���������� ������ ������� � ���� ����� � ������������� ��������
 ���������� � ������� ��� �������� ���� MARSH.
2. �������� ���������, ����������� ��������� ��������:
	� ���� � ���������� ������ � ������, ��������� �� ������
	  �������� ���� MARSH; ������ ������ ���� ����������� �� �������
	  ���������;
	� ����� �� ����� ���������� � ��������, ����� ��������
	  ������ � ����������;
	� ���� ����� ��������� ���, ������ �� ������� ���������������
	  ���������.
**/

class Marsh
{
	string routeNumber;
	string start;
	string dest;
public:
	Marsh();
	Marsh(string ser, string name);
	Marsh(const Marsh & obj);
	~Marsh();

	// �������
	void setRouteNumber(string s);
	void setStart(string ns);
	void setDest(string ns);

	// �������
	string getRouteNumber()		const { return routeNumber; }
	string getDest() const { return dest; }

	// ������
	void Input(UINT n);
	void Show(UINT n);
	void Randomize();

	// ������ ������������
	int Save(FILE *f);
	int Load(FILE *f);
};

