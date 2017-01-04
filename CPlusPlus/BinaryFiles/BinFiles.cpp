#include "stdafx.h"
#include "BinFiles.h"
#include "Utils.h"

void SplitFilename(const std::string& str)
{
	
}

BinDB::BinDB() : fileName("data0.bin")
{
}


BinDB::~BinDB()
{
}

void BinDB::SetFileName(LPCSTR name)
{
	fileName = name;
}

LPCSTR BinDB::GetFileName() {
	return fileName;
}

// ������� �������
void BinDB::Read(LPCSTR section, WORD paramNumber, LPSTR defaultValue, LPSTR &returnWhere)
{
	FILE * fin;
	fin = fopen(fileName, "rb");
	RESULT finder = Find(section, paramNumber);
	if (finder.state) // ���� ����� ������ � �������� �������
	{
		fseek(fin, finder.seek, SEEK_SET);
		fscanf(fin, "%s", &returnWhere);
		return;
	} else {
		cout << "\n�������� #" << paramNumber << " � ������ \"" << section << "\" �� ������!\n"; 
		returnWhere = defaultValue;
	}
	
	fclose(fin);
}

void BinDB::Write(LPCSTR section, WORD paramNumber, LPCSTR string)
{
	FILE * fout;
	fout = fopen(fileName, "wb");
	RESULT finder = Find(section, paramNumber);
	if (finder.state) // ���� ����� ������ � �������� �������
	{
		fseek(fout, finder.seek, SEEK_SET);
		fprintf(fout, "%d\n", string);
		return;
	}
	if (finder.secState) // ���� ����� ������ ��� ������� � ��������� ��� ���
	{
		fseek(fout, finder.secSeek, SEEK_SET);
		int i = finder.secSeek;
		LPSTR str("");
		while (!feof(fout)) {
			i++;
			if (fgets(str, 250, fout) == "}")
			{
				fprintf(fout, "%d\n}", string);
				break;
			}
		}
		return;
	}
	fseek(fout, 0, SEEK_END);   // ����� ������ � ����� ����� ������
	fclose(fout);
}

BinDB::RESULT BinDB::Find(LPCSTR section, WORD what) const
{

	RESULT result;
	FILE * f;
	f = fopen(fileName, "rb");
	fseek(f, 0, SEEK_SET);   // � ������ ����� ������
	int i(0),j;
	// ���� - �� ������� � ����� - �������� ����� 
	LPSTR str("");
	LPSTR sec = (LPSTR)Format("%c%s", '{', section).c_str();
	// ������� ������
	while (!feof(f)) {
		i++;
		if (fgets(str, 250, f) == sec)
		{
			result.secState = true;
			result.secSeek  = i;
			break;
		}
		
	} // while i
	fseek(f, i, SEEK_SET);   // ������ ������ ������
	// ������� �������� � ������
	while (!feof(f)) {
		i++;
		fgets(str, 250, f);
		
		j = 0;
		// ������������ �������� ������ �� ������� '}' (����� ������)
		// ���� �� ��������� ����-�������� (��� ������ ���� ������� ������������)
		while (str[j] != '\0')
		{
			j++;
			if (str[j] == '}')
			{
				goto _break; // ����� �� ���� ��������� ������
			}
		} // while j

		// ���� �������� n ������ �������, �� ����������� ������ ���������
		if (i == result.secSeek+what)
		{
			result.str = str;
			result.seek = i;
			result.state = true;
			break;
		} // if

	} // while i
_break:; // ����� �������������� ��� ������ �� ���� ��������� ������,
		 // ����� ���� � � ������� ������� ������, �� ��� �������������
		 // � ���� ������ ��������.

	return result;
}