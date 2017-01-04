#pragma once
class BinDB
{
	string fileName;
public:
	BinDB();
	~BinDB();
	
	// ����������� � ������������
	void Encode();
	void Decode();

	// ������� | �������
	void SetFileName(string name);
	string GetFileName();

	// ������� �������
	void Read(LPCSTR section, LPCSTR paramName, LPCSTR defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Write(LPCSTR section, LPCSTR paramName, LPCSTR string);
	



	// ����������
	void Read(LPCSTR section, LPCSTR paramName, int defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Read(LPCSTR section, LPCSTR paramName, double defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Read(string section, string paramName, int defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Read(string section, string paramName, double defaultValue, LPSTR &returnWhere, DWORD nSize);
	void Read(string section, string paramName, string defaultValue, LPSTR &returnWhere, DWORD nSize);
	
	void Write(string section, string paramName, string str);
};

