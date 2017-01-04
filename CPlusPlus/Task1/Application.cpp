#include "stdafx.h"
#include "Utils.h"
#include "Application.h"

Application::Application(): pPair(nullptr)
{
} // Application::Application

Application::~Application()
{
} // Application::~Application

// ������� ����� ���������� - ��������� ������ ������������  
void Application::run()
{
	UINT cmd;                // ������� ����
	bool flagExit = false;   // ���� ������ �� ������������ �����
	char *szMenu = "\t\t\t\t *** � � � � ***\n"
			"\t\t\t    1. �������� ������ Complex\n"
			"\t\t\t    0. �����\n"
			"\t\t\t    ��� ����� (0, ..., 2)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 1);

		switch (cmd) {
		case 1:
			testComplex();
			break;
		case 0:
			flagExit = true;
			break;
		} // switch
		if (flagExit) break;
		GotoXY(0, 24);
		system("pause");
	} // while

	// ���������� ����������� ��� ����
	// ������ 80 � 25, ����� ������� �� ������ ����
	SetWindow(80, 25, 0x07);
	Clear();
	WriteXY(34, 12, "����� ������");
	GotoXY(0, 24);
} // Application::run

// ������������ ������ Complex
void Application::testComplex()
{

	WriteXY(26, 10, "������������ ������ Complex");
	
	Complex a;
	cout << "������� ����������� ����� a: "; cin >> a;
	cout << "a == " << a << endl;
	Complex b(2, 3);
	cout << "b == " << b << endl;
	cout << "a + b " << a.add(b) << endl;
	Sleep(500);
	cout << "a - b " << a.sub(b) << endl;
	Sleep(500);
	cout << "a * b " << a.mul(b) << endl;
	Sleep(500);
	cout << "a / b " << a.div(b) << endl;
}// Application::testEllipse

// ������������ ������ Rational
void Application::testRational()
{

	WriteXY(26, 10, "������������ ������ Rational");

	Rational a;
	cout << "������� ������������ ����� ����� a: "; cin >> a;
	cout << "a == " << a << endl;
	Rational b(2, 3);
	cout << "b == " << b << endl;
	cout << "a + b " << a.add(b) << endl;
	Sleep(500);
	cout << "a - b " << a.sub(b) << endl;
	Sleep(500);
	cout << "a * b " << a.mul(b) << endl;
	Sleep(500);
	cout << "a / b " << a.div(b) << endl;
}// Application::testEllipse