/*	

Main.cpp  
������� ���� - �������� �������� � ������� Date

- ����� ������������� Init()
- ������ ������ � ����������
- ������ ������ �� �����
- �������������� ��������, 
- �������� ���������

*/

#include "stdafx.h"
#include "Utils.h"
#include "Date.h"


HANDLE h;


int main(int argc, char *argv[])
{
	init();

	Date a, b, c;
	cout << "������������ ������ Date\n\n";
	Sleep(1200);

	cout << "\n���� Init() � Display():\n";
	a.Init();
	cout << "\n����� a: "; a.Display();
	Sleep(1200);

	cout << "\n\n���� ������ ����� Read():\n";
	b.Read();
	cout << "\n�� �����: ";	b.Display();
	Sleep(1200);

	cout << "\n\n���� �������������� ��������:\n";
	c = a.add(b);
	cout << "\n�������� : ";  a.Display();  cout << " + ";  b.Display();
	cout << " = "; c.Display();

	c = a.sub(b);
	cout << "\n���������: ";  a.Display(); cout << " - ";  b.Display();
	cout << " = "; c.Display();
	Sleep(1200);
	cout << "\n\n���� �������������� ��������:\n";
	c = a.greate(b);
	cout << "\n������  : ";  a.Display(); cout << " > "; b.Display();
	cout << " = "; c.Display();
	c = a.less(b);
	cout << "\n������  : ";  a.Display(); cout << " < "; b.Display();
	cout << " = "; c.Display();
	c = a.equal(b);
	cout << "\n�����  : ";  a.Display(); cout << " == "; b.Display();
	cout << " = "; c.Display();
	Sleep(1200);

	cout << "\n\n����� ������. ";
	return 0;
} // main



