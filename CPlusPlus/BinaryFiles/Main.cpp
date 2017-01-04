// BinaryFilesLib.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "BinFiles.h"
#include "Utils.h"

/* ��� ������� ��������� ��������:

// ������ ����� �����
void load(char* fileName, char* &to)
{
	FILE * fin;
	fin = fopen(fileName, "rb");
	while (!feof(fin)) {
		fscanf(fin, "%s", &to);
	}
	fclose(fin);
}

// ������ ������ � ����
void write(char* fileName, char* &from)
{
	FILE * fout;
	fout = fopen(fileName, "wb");
	fprintf(fout, "%d\n", from);
	fclose(fout);
}
*/

HANDLE h;

int main() // ���� ������ ������ BinDB
{
	init();
	BinDB f;					// ������� ����
	f.SetFileName("test.bin");  // ��������������
	LPSTR output;				// ���������� ��� �������� ����������

	//		����. ������, p�,  Value
	f.Write("TestSection", 1, "Test String");
	//	    ����. ������, p�,  Default, ���� �������� ��������
	f.Read("TestSection", 1 ,  "NULL"  , output);

	cout << "Param1 = " << output << endl; // ����� ����������
	return 0;
}

