#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Triad.h"

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
			"1. ������ 12\n"
			"2. ������ 14\n"

			"0. �����\n"
			"   ��� ����� (0, ..., 2)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 2);

		switch (cmd) {
		case 1:
			test_task12();
			break;
		case 2:
			test_task14();
			break;
		case 0:
			flagExit = true;
			break;
		} // switch
		if (flagExit) break;
		CustomPause(55,0,"������� ����� �������...");
	} // while

	// ���������� ����������� ��� ����
	// ������ 80 � 25, ����� ������� �� ������ ����
	SetWindow(80, 25, 0x07);
	Clear();
	WriteXY(34, 12, "����� ������");
	GotoXY(0, 24);
} // Application::run

void Application::test_task12()
{
	tMark("\n[������������ �� �����������!]\n", LtMagenta);
	return;

	tMark("\n[������ 12]\n");
	tMark("\n���� �������� ������ Triad\n", LtCyan);
	Triad triad(2,4,6);
	cout << "���� ������ �� �����:" << triad << endl;
	cout << "���� ������������ ����������:" << triad++ << endl;
	/*Triad triad2(4, 3, 7);
	cout << "triad =" << triad << endl;
	cout << "triad2 =" << triad2 << endl;
	cout << "���� ���������� �������� '==':" << triad == triad2 << endl;
	cout << "���� ���������� �������� '<':" << triad < triad2 << endl;
	cout << "���� ���������� �������� '>':" << triad > triad2 << endl;
	triad = triad2;
	cout << "���� �������� ������������:" << "triad = " << triad << endl;
	*/
	tMark("\n\n���� ������������ ������ Time\n", LtCyan);
}

void Application::test_task14()
{
	tMark("\n[������������ �� �����������!]\n", LtMagenta);
	return;

	tMark("\n[������ 14]\n");
	tMark("\n���� �������� ������ Triad\n", LtCyan);

	tMark("\n\n���� ������������ ������ Date\n", LtCyan);
	
}

/*
void Application::test_task10()
{
	tMark("\n[������ 10]\n");
	tMark("\n���� �������� ������ Triangle\n", LtCyan);
	double a(Random(1., 10.)), b(Random(1., 10.));
	Pair::Base bt(a, b); // ���������� � �������������
	cout << bt; // ����� ����� ������ �� �����

	tMark("\n���� ������������ ������ RightAngled\n", LtCyan);

	Pair::RightAngled rat(a,b); // ���������� � �������������
	cout << rat; // ����� ����� ������ �� �����
}
*/