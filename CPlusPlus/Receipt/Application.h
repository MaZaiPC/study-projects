#pragma once
#include "Goods.h"
#include "Receipt.h"


class Application
{
	Goods   op, res;  // �������� � ���������
	Receipt *receipt;

	static const int N_MAX = 1000;   // ������������ ���������� ��������� � �����

									 // "���� ������" - ���� � ������� � ���������
	char *dbFileName;
	FILE *f;

	int numRecords();               // ���������� ���������� ������� � ����� ������

public:
	Application();
	~Application();

	void run();
	void read();        // ����� ��� ����� ������ � ������ ������� ����������
	void show();        // ����� ��� ������ ������ �� ������� ������� ����������
	void Sum();

	void show�heck();   // ����� ��� ������ ������ �� ������� ������� ����������
}; // Application



