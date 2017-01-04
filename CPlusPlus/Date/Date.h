#pragma once

class Date
{
	UINT year;
	UINT month;
	UINT day;

	// ������:
	// ����������
	UINT toJDN();
	UINT toJDN(Date x);
	UINT toJDN(UINT day, UINT month, UINT year);
	Date toGD(UINT JDN);

	// ����������
	bool IsValidDate(UINT day, UINT month, UINT year);
public:
	// ������������ � ����������
	Date(UINT yyyy = 1974, UINT mm = 11, UINT dd = 23);
	Date(const Date &Date);
	~Date();

	// ������:
	// ��������������
	Date add(UINT days); // ��������
	Date sub(UINT days); // ���������
	Date diff(Date x);  // ������� ����� ������

	// ����������
	bool equal(Date x);        // �����?
	bool greate(Date x);       // ������?
	bool less(Date x);         // ������?
	bool IsLeapYear(UINT year); // ����������?

	// ������� � �������
	UINT getDay();
	UINT getMonth();
	UINT getYear();
	void setDay(UINT day);
	void setMonth(UINT month);
	void setYear(UINT year);
	void setDate(UINT day, UINT month, UINT year);
	void coutDate();

	// �������������
	void Init();
	void Init(int a, int b);
};

