#include "stdafx.h"
#include "Marsh.h"
#include "Utils.h"

Marsh::Marsh()
{
	routeNumber = "X---";
	dest = ">Empty<";
}

Marsh::Marsh(string ser, string name)
{
	routeNumber = ser;
	dest = name;
}

Marsh::Marsh(const Marsh & obj)
{
	routeNumber = obj.routeNumber;
	dest = obj.dest;
}

Marsh::~Marsh()
{
}

// �������
void Marsh::setRouteNumber(string s)
{
	cin >> routeNumber;
}
void Marsh::setDest(string ns)
{
	cin >> dest;
}

// ������
void Marsh::Input(UINT n)
{
	string tmp = Format("����������� �������� %u", n);
	tMark(tmp, 1);
	cout << "\n������� �������� ����� ������: "; cin >> routeNumber;
	cout <<   "������� ����� ����������: "; cin >> dest;
}

void Marsh::Show(UINT n)
{
	string tmp = Format("������� %u", n);
	tMark(tmp, 1);
	cout << "\n����� ��������: " << routeNumber << endl;
	cout << "��������� �����: " << start << endl;
	cout << "����� ����������: " << dest << "\n\n";
}

void Marsh::Randomize()
{
	UINT a = Random(1, 999);
	char b;
	char e[4] = {'�', '�', '�', '�'};
	// ��������� ������ ����������� �������
	b = e[Random(1, 4)];
	
	string ser = Format("%u", a);
	ser = (Format("%c", b)+ser);

	routeNumber = ser;
	
	string city[] = { "������", "����", "������", "�����-���������", "�������", "���������", "������", "�����������", "�����", "������", "�����", "����������", "���", "�������", "��������", "������", "���������", "�����������", "�����", "�������" };
	WORD c = Random(1, 19);

	start = city[c];
cycle:;
	c = Random(1, 19);
	if (city[c] != start)
		dest = city[c];
	else
		goto cycle;

}

// ����� ��� ������ � ���� ����� ������ 
int Marsh::Save(FILE * f)
{
	fwrite(&routeNumber, 8, 1, f);
	fwrite(&start, 22, 1, f);
	fwrite(&dest, 22, 1, f);
	return 0;
} // Train::Save


// ����� ��� ������ �� ����� ����� ������ 
int Marsh::Load(FILE * f)
{
	fread(&routeNumber, 8, 1, f);
	fread(&start, 22, 1, f);
	fread(&dest, 22, 1, f);
	return 0;
} // Train::Load 