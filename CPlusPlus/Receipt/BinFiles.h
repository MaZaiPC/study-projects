#pragma once
class BinDB
{
	string fileName;
public:
	BinDB();
	~BinDB();
	
	// Манипуляции с кодированием
	void Encode();
	void Decode();

	// ГЕТТЕРЫ | СЕТТЕРЫ
	void SetFileName(string name);
	string GetFileName();

	// ГЛАВНЫЕ ФУНКЦИИ
	void Read(LPCSTR section, LPCSTR paramName, LPCSTR defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Write(LPCSTR section, LPCSTR paramName, LPCSTR string);
	



	// ПЕРЕГРУЗКИ
	void Read(LPCSTR section, LPCSTR paramName, int defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Read(LPCSTR section, LPCSTR paramName, double defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Read(string section, string paramName, int defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Read(string section, string paramName, double defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Read(string section, string paramName, string defaultValue, LPSTR &returnWhere, DWORD nSize);
	
	void Write(string section, string paramName, string str);
};

