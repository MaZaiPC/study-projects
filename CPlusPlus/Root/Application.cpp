#include "stdafx.h"
#include "Utils.h"
#include "Application.h"

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
			test_linear();
			break;
		case 2:
			test_square();
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


void Application::test_linear()
{
	pRoot = new Linear;

	GotoXY(5, 12);
	pRoot->Solve(Random(1., 10.), Random(1., 10.), Random(1., 10.));
	/*��������*/ //cout << "������������ ��������� ���������: " << *pRoot << endl;
	cout << "��� ������ ���� ����� ���������� �� �����\n";

	delete pRoot;
} // Application::testDollar


void Application::test_square()
{
	pRoot = new Square;

	GotoXY(5, 12);
	pRoot->Solve(Random(1.,10.), Random(1., 10.), Random(1., 10.));
	/*��������*/ //cout << "������������ ����������� ���������: " << *pRoot << endl;
	cout << "��� ������ ���� ����� ���������� �� �����\n";

	delete pRoot;
} // Application::testEuro