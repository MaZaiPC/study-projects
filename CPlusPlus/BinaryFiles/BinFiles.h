#pragma once

class BinDB
{
	LPCSTR fileName;

	struct RESULT // ��������� ��� �������� ����������� ������
	{
		RESULT() : str("NULL"), seek(), secSeek(), state(false), secState(false) {}
		LPSTR str;
		UINT seek;
		UINT secSeek;
		bool state;
		bool secState;
	};
public:
	BinDB();
	~BinDB();

	// ������� | �������
	void SetFileName(LPCSTR name);
	LPCSTR GetFileName();

	// ������� �������
	void Read(LPCSTR section, WORD paramNumber, LPSTR defaultValue, LPSTR &returnWhere);
	void Write(LPCSTR section, WORD paramNumber, LPCSTR string);

	RESULT Find(LPCSTR section, WORD what) const;
};

