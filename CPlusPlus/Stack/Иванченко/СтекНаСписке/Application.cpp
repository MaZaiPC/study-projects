#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Stack.h"


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
			"1. �������� � ����\n"
			"2. ������� �� �����\n"
			"3. �������� ����\n"
			"0. �����\n"
			"   ��� ����� (0, ..., 3)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 3);

		switch (cmd) {
		case 1:
			testPush();
			break;
		case 2:
			testPop();
			break;
		case 3:
			showStack();
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


void Application::testPush()
{
	int x = Random(-5, 12);
	stack.push(x);
	GotoXY(1, 12); 
	cout << stack;
} // Application::testPush


void Application::testPop()
{
	stack.pop();
	GotoXY(1, 12);
	cout << stack;
} // Application::testPop


void Application::showStack()
{
	GotoXY(1, 12);
	cout << stack;
} // Application::showStack



