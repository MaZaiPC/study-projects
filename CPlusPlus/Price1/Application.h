#pragma once
#include "Price.h"

class Application
{
	static const int N_MAX = 1000;   // ������������ ���������� ��������� � �����
	
	// "���� ������" - ���� � ������� � ���������
	char *dbFileName;
	FILE *f;

	int numRecords();  // ���������� ���������� ������� � ����� ������

public:
	Application();      // ����������� �� ���������
	~Application();     // ����������

	void run();         // ������� ����� ���������� - ��������� ������ ������������ 
	void read();        // ����� ��� ����� ������ � ������ ������� ����������
	void show();        // ����� ��� ������ ������ �� ������� ������� ����������  

	// ����� ��� ���������� ������ � ����� �� ����������� ������� ���������
	void sort(bool compare(const Price &, const Price &));        

}; // Application


inline bool cmpPrice(const Price &t1, const Price &t2);
inline bool cmpName(const Price &t1, const Price &t2);