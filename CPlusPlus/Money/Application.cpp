#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Currency.h"


Application::Application()
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
	char *szMenu = "\t*** � � � � ***\n"
			"1. ������������ ������ Dollar\n"
			"2. ������������ ������ Euro\n"
			"0. �����\n"
			"   ��� ����� (0, ..., 2)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 2);

		switch (cmd) {
		case 1:
			test_dollar();
			break;
		case 2:
			test_euro();
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


//// ��� ������� ������ ������� ��� ������
//void Application::TestShape()
//{
//	Shape shape, *pShape = &shape;
//	
//	// ��� �� ����������� (�����������) ������, �.�. ��� ���������
//	// � ��� ����������� ������� �������� �� ����� ���������� 
//	pShape->Input();
//	pShape->Show();
//
//	delete pShape;
//} // Application::TestShape


void Application::test_dollar()
{
	pCurrency = new Dollar(100, 0);

	GotoXY(5, 12); cout << *pCurrency;
	UINT rubles = pCurrency->to_RUB(65.5);
	cout << " == ";
	cout << (rubles / 100) << "." << setfill('0') << setw(2) << (rubles % 100) << setfill(' ') << " RUR";
	
	delete pCurrency;
} // Application::testDollar


void Application::test_euro()
{
	pCurrency = new Euro(100, 0);

	GotoXY(5, 12);
	cout << *pCurrency;
	UINT rubles = pCurrency->to_RUB(75.5);
	cout << " == ";
	cout << (rubles / 100) << "." << setfill('0') << setw(2) << (rubles % 100) << setfill(' ') << " RUR";

	delete pCurrency;
} // Application::testEuro