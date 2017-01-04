#include "stdafx.h"
#include "Utils.h"
#include "Application.h"

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
			"1. Array 99\n"
			"2. Array 109\n"

			"0. �����\n"
			"   ��� ����� (0, ..., 2)? ";

	while (true) {
		Clear();
	
		cmd = getUINT(szMenu, 0, 2);

		switch (cmd) {
		case 1:
			Array99();
			break;
		case 2:
			Array109();
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

void Application::showVector(vector<int> v)
{
	const int M = 12;  // ������� M ��������� � ������
	const int W = 6;  // ������ ���� ������

	size_t i;
	for (i = 0; i < v.size(); i++)
	{
		cout << setw(W) << v[i];
		if ((i + 1) % M == 0) cout << "\n";
	} // for i

	if (i % M != 0) cout << "\n";
} // Application::showVector

void Application::fillVector(vector<int> &v, size_t qty, int min, int max)
{
	for (size_t i = 0; i < qty; i++)
		v.push_back(Random(min, max));
} // Application::fillVector

void Application::Array99()
{
	tMark("\n[Array 99]\n");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	vector<int> vec;

	// 1. ��������� ������ ���������� �������
	fillVector(vec, n, 0, 5);

	// 2. ������� ��� �� �����
	Clear();
	tMark("[Array 99]\n\n"
		  "������ ��:\n");
	showVector(vec);

	// 3. ������ ������������ ������
	for (auto i = vec.begin(); i != vec.end();)
	{
		if (count(vec.begin(), vec.end(), *i) > 2) // ����� ����� ������ ��� ��������?
			vec.erase(rfind(i+1,vec.end(),*i));	   // ����� ������� ��������� ��������� �����.
		else
			++i; // ����� ����������� ����� ��� ���������� ������,
				 // ����� ����� �������� ��������, �������� ���������
				 // �� �������������� �������.
	} // for i

	// ���� ������������� �������� � ���������� �����
	cout << "\n\n";
	CustomPause("����� (ANY_KEY) >>");

	// 4. ������� ��������� ���������
	Clear();
	tMark("[Array 99]\n\n"
		  "������ �����:\n");
	showVector(vec);
} // Application::Array99

void Application::Array109()
{
	tMark("\n[Array 109]\n");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	vector<int> vec;

	// 1. ��������� ������ ���������� �������
	fillVector(vec, n, -10, 10);

	// 2. ������� ��� �� �����
	Clear();
	tMark("[Array 109]\n\n"
		  "������ ��:\n");
	showVector(vec);

	// 3. ������ ������������ ������
	for (auto i = vec.begin(); i != vec.end();)
	{
		if (*i < 0) // ���� �������� ������������� - �������� 0 ����� ���.
			i = vec.insert(i, 0) + 2; // ��������� �������� �� ��� ������� ������.
		else						  // ��� ����� ��� ���������� ������, �����
			++i;					  // ����� ������� ��������, �������� ������ ����������.					  
	} // for i

	// ���� ������������� �������� � ���������� �����
	cout << "\n\n";
	CustomPause("����� (ANY_KEY) >>");

	// 4. ������� ��������� ���������
	Clear();
	tMark("[Array 109]\n\n"
		  "������ �����:\n");
	showVector(vec);
} // Application::Array109



