/*	

Main.cpp  
������� ���� - �������� �������� � ������� Rational

- ����� ������������� Init()
- ����� ������ � ���������� Read()
- ����� ������ �� ����� Display()
- �������������� ��������, 
- �������� ���������

*/

#include "stdafx.h"
#include "Utils.h"
#include "Rational.h"


HANDLE h;


int main(int argc, char *argv[])
{
	init();

	Rational a, b, c;
	cout << "������������ ������ Rational\n\n";
	Sleep(1200);

	cout << "\n���� Init() � Display():\n";
	a.Init(1, 2);
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

	c = a.mul(b);
	cout << "\n���������: ";  a.Display(); cout << " * "; b.Display();
	cout << " = "; c.Display();

	c = a.div(b);
	cout << "\n�������  : ";  a.Display(); cout << " / "; b.Display();
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



