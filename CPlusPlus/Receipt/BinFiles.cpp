#include "stdafx.h"
#include "BinFiles.h"
#include "Utils.h"

void SplitFilename(const std::string& str)
{
	
}

BinDB::BinDB() : fileName("data0.bin")
{
	string CurrentPath = __argv[0];
	size_t found = CurrentPath.find_last_of("/\\");
	string filePath = CurrentPath.substr(0, found);
	found = filePath.find_last_of("/\\");
	filePath = filePath.substr(0, found);
	if (strcmp(fileName.c_str(), ""))
		filePath += "\\" + fileName;
	fileName = filePath;
}


BinDB::~BinDB()
{
}

void BinDB::Encode()
{
	string line;	 // сюда будут записываться строки из файла
	string all = ""; // а тут они будут накапливаться
	ifstream fin(fileName, ios::in); //Открываем файл только для чтения
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			all += line;
			all += "\n";
		}
	}
	cout  << "В файл записано: " << all;
	fin.close(); //Закрываем файл
	ofstream fout(fileName, ios::binary | ios::out); //Открываем файл в двоичном режиме только для записи
	if (fout.is_open())
	{
		fout.write((char*)&all, sizeof all);
	}
	fout.close(); //Закрываем файл
}

void BinDB::Decode()
{
	string line;	 // сюда будут записываться строки из файла
	string all = ""; // а тут они будут накапливаться
	ifstream fin(fileName, ios::binary | ios::out); //Открываем файл в двоичном режиме только для чтения
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			all += line;
			all += "\n";
		}
	}
	cout << "Из файла получено: " << all;
	fin.close(); //Закрываем файл
	ofstream fout(fileName, ios::out); //Открываем файл только для записи
	if (fout.is_open())
	{
		fout.write((char*)&all, sizeof all);
	}
	fout.close(); //Закрываем файл
}

void BinDB::SetFileName(string name)
{
	string CurrentPath = __argv[0];
	size_t found = CurrentPath.find_last_of("/\\");
	string filePath = CurrentPath.substr(0, found);
	found = filePath.find_last_of("/\\");
	filePath = filePath.substr(0, found);
	filePath += "\\" + name;
	fileName = filePath;
}

string BinDB::GetFileName() {
	size_t found = fileName.find_last_of("/\\");
	return fileName.substr(found + 1);
}

// ГЛАВНЫЕ ФУНКЦИИ
void BinDB::Read(LPCSTR section, LPCSTR paramName, LPCSTR defaultValue, LPSTR &returnWhere, DWORD nSize)
{
	//Decode();
	GetPrivateProfileStringA(section, paramName, defaultValue, returnWhere, nSize, fileName.c_str());
	//Encode();
}

void BinDB::Write(LPCSTR section, LPCSTR paramName, LPCSTR string)
{
	//Decode();
	WritePrivateProfileStringA(section, paramName, string, fileName.c_str());
	//Encode();
}





// ПЕРЕГРУЗКИ
void BinDB::Read(LPCSTR section, LPCSTR paramName, int defaultValue, LPSTR &returnWhere, DWORD nSize)
{
	Read(section, paramName, (char*)defaultValue, returnWhere, nSize);
}

void BinDB::Read(LPCSTR section, LPCSTR paramName, double defaultValue, LPSTR &returnWhere, DWORD nSize)
{
	Read(section, paramName, to_string(defaultValue), returnWhere, nSize);
}

void BinDB::Read(string section, string paramName, int defaultValue, LPSTR &returnWhere, DWORD nSize)
{
	Read(section.c_str(), paramName.c_str(), (char*)defaultValue, returnWhere, nSize);
}

void BinDB::Read(string section, string paramName, double defaultValue, LPSTR &returnWhere, DWORD nSize)
{
	Read(section, paramName, to_string(defaultValue), returnWhere, nSize);
}

void BinDB::Read(string section, string paramName, string defaultValue, LPSTR &returnWhere, DWORD nSize)
{
	Read(section.c_str(), paramName.c_str(), defaultValue.c_str(), returnWhere, nSize);
}


void BinDB::Write(string section, string paramName, string str)
{
	Write(section.c_str(), paramName.c_str(), str.c_str());
}