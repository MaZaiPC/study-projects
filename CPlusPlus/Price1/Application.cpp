#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Price.h"


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
	return ftell(f) / Price::recSize();
}

Application::Application() :dbFileName("Price.bin")
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
} // Application::Application


Application::~Application() 
{
	fclose(f);   // ������� ���� ������
} // Application::~Application


// ������� ����� ���������� - ��������� ������ ������������  
void Application::run()
{
	UINT cmd;                // ������� ����
	bool flagExit = false;   // ���� ������ �� ������������ �����
	char *szMenu = "\t  ������� 18, ������� 6 �� �������� ���������� �.�., ����� �.�."
		"\n\n\n\n\n\n\t\t  *** � � � � ***\n"
		"\t     1) �������� ����� �����\n"
		"\t     2) ����� �������, ������������� �� ����\n"
		"\t     3) ����� �������, ������������� �� ��������\n"
		"\t     0) �����\n"
		"\t     ��� ����� (0, ..., 2)> ";

	while (true) {
		Clear();

		cmd = getUINT(szMenu, 0, 3);
		
		switch (cmd) {
		case 1:
			read();
			break;
		// ����� � ��������������� �� ������ ��������
		case 2:
			sort(cmpPrice);
			show();
			break;
		// ����� � ��������������� �� ������ �����������
		case 3:
			sort(cmpName);
			show();
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

	// ���������� ������, ������� ��������� �������������� �������
	//if (s) delete[] s;
} // Application::run


// ����� ��� ����� ������ � ������ ������� ����������
void Application::read()
{
	Price Price;

	WriteXY(22, 12, "������� ������ ������� ��������");
	Price.Read(12, 14);   // ���� � ����������
	Price.Save(f);        // ���������� � ����
	
	// ��������� � ��������� ���� - ��� ������ � ���� ������� �����
	// ���� �������� ������ - ��������� ���������� ���������
	fclose(f);
	f = fopen(dbFileName, "rb+");
	if (f == nullptr) {
		SetWindow(80, 25, 0xce);
		WriteXY(20, 12, "������ ������� � ����� ������");
		GotoXY(0, 24);
		exit(1);
	} // if
} // Application::read


// ����� ��� ������ ������ �� ������� ������� ����������
void Application::show()
{
	Price Price;

	Clear();

	int n = numRecords();

	fseek(f, 0, SEEK_SET);
	GotoXY(0, 3);
	int Pos[3];
	for (int i = 0; i < n; i++) {
		// ������ �� ����� ��������� ������, ��������� ������������ �� �����
		Price.Load(f); 
		Price.Display(Pos[0], Pos[1], true);
	} // for i
	Pos[2] = WhereXY().Y;
	WriteXY(Pos[0], 1, "�����");
	WriteXY(Pos[1], 1, "����");
	GotoXY(0, Pos[2]);
} // Application::show


// ����� ��� ���������� ������ � ����� �� ����������� ������� ���������
void Application::sort(bool compare(const Price &, const Price &))
{
	int n = numRecords(), rec_size = Price::recSize();
	int i, j;      
	Price t1, t2;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			fseek(f, j*rec_size, SEEK_SET); // ������� � j-� ������ �����
			t1.Load(f);   // j-� ������ ���������, �����. ���������� �� j+1
			t2.Load(f);   // j+1-� ������ ���������

			// ���� ���� �� �����������, �� �������� ������ � ����� �������
			if (compare(t1, t2)) {
				fseek(f, j*rec_size, SEEK_SET); // ������� � j-� ������ �����
				t2.Save(f, false); // j-� ������� -- ����� t2 
				t1.Save(f, false); // j+1-� ������� -- ����� t1
			} // if
		} // for j
	} // for i
} // Application::sort


// �� ����������� ����� ������
// ���������� true, ���� ����� ��������1 > ������ ��������2
// �.�. ���� �� �����������, ��������� ����� �������
inline bool cmpPrice(const Price &t1, const Price &t2)
{
	return t1.getPrice() > t2.getPrice();
} //  cmpNumber


// ���������� true, ���� ����� �����������1 > ������ �����������2
// �.�. ���� �� �����������, ��������� ����� �������
inline bool cmpName(const Price &t1, const Price &t2)
{
	return strcmp(t1.getName(), t2.getName()) == 1;
} //  cmpNumber






