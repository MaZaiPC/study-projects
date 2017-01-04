#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Goods.h"
#include "Receipt.h"


// ���������� ���������� ������� � ����� ������
int Application::numRecords()
{
	// ������� � ����� ����� - ����������� ��������� ��������
	// �������� � ����� ����� - ������� fseek()
	// SEEK_END - ������������ ����� �����
	// SEEK_SET - ������������ ������ �����
	// SEEK_CUR - ������������ ������� ������� �����
	fseek(f, 0, SEEK_END);

	// ftell()   - ���������� �������� ������� ��������� �������� ��������
	// sizeof(x) - �������� ��������� ������� ������������ ������� x � ������ 

	// ���������� ������� � �����
	return ftell(f) / Goods::recSize();
}

Application::Application() :dbFileName("Goods.bin")
{
	// ����� ��������:
	// r - ������
	// r+ ������ � ������
	// b - �������� �����
	f = fopen(dbFileName, "rb+");

	// ���� ���� �� ������ - ���������� ������� ����
	if (f == nullptr) {
		// w - ������, ���� ����� ���, �� �� ���������
		//     ���� ���� ����, �� ��� ����� ������������ � 0 
		//     ���������� ����� ������������ ������������
		f = fopen(dbFileName, "wb+");
		if (f == nullptr) {
			SetWindow(80, 25, 0x07);
			Clear();
			WriteXY(34, 12, "��������� ����������");
			GotoXY(0, 24);
		} // if
	} // if
}// Application::Application


Application::~Application()
{
	fclose(f);   // ������� ���� ������
}// Application::~Application


// ������� ����� ���������� - ��������� ������ ������������  
void Application::run()
{
	UINT cmd;                // ������� ����
	bool flagExit = false;   // ���� ������ �� ������������ �����

	char *szMenu = "\t\t           ������� ����� 13 �� 28.09.15"
		"\n\n\t\t\t\t  *** � � � � ***\n"
		"\t\t         1) ���� ������ ��� ��������� ����\n"
		"\t\t         2) ����� �������� �����\n"
		"\t\t         3) �����\n"
		"\t\t         0) �����\n"
		"\t\t         ��� ����� (0, ..., 3)> ";

	while (true) {
		Clear();
		
		cmd = getUINT(szMenu, 0, 3);

		switch (cmd) {
		case 1:
			read();
			break;
		case 2:
			Clear();
			show();
			break;
		case 3:
			Sum();
			break;
		case 0:
			flagExit = true;
			break;
		} // switch
		cout << "\n\n\n";
		if (flagExit) break;
		system("pause");
	} // while

	// ���������� ����������� ��� ����
	// ������ 80 � 25, ����� ������� �� ������ ����
	SetWindow(80, 25, 0x07);
	cout << "\n����� ������\n";

}// Application::run


// ����� ��� ����� ������ ��� ����
void Application::read()
{
	receipt = new Receipt(); // ������� ����� ���
	cin >> *receipt;         // ������ ���
	receipt->save();        // ��������� ��� � ����� ������
	delete receipt;        // ���������� ������, ������� ���
}// Application::read

// ����� ��� ������ ������ ��� �����
void Application::show()
{
	
}// Application::show

// ����� ������� � ������, �� ����������(
void Application::Sum()
{
}// Application::Sum()



