#pragma once
class Price
{
	char   *name;       // ��������� �������
	UINT    price;       // ����� ��������

public:

	static const UINT LEN_NAME;    // ����������� ��������� ��� ����������� ����� ���� ���������� ��������
	static const UINT LEN_PRICE;      // ����������� ��������� ��� ����������� ����� ���� ��������� ��������

	Price();                                                                    // ����������� �� ���������
	explicit Price(char *name, UINT price);   // ����������� � �����������
	Price(const Price &obj);                                                    // ����������� �����������
	~Price();      // ����������

	// !!! ���������� ��� ����������� ����������� ������� ������ ����� !!!
	// �.�. ����� ����� ������������ ����
	// !!! ����������� ����� ������ �� ������ ���������� � ����� ������
	static int recSize() { return LEN_NAME + LEN_PRICE + sizeof(int); }

	// �������
	char *getName()   const { return name; }
	int  getPrice()   const { return price; }

	// �������
	void setName(char * name);
	void setPrice(UINT price);

	// ������
	void Init(char * name, UINT price);      // ������������� ������������ ��������� ��������
	void Read(int x, int y);                                                   // ���� �������� ����� � ����������
	void Display(int &p1, int &p2, bool nl = false);                                           // ����� �������� ����� � �������

	//char * toString();													   // ���������� ������, ���������� �������� ����� �������

	// ������ ��� ������ � ����/������ �� �����
	// (������������ �������)
	int Save(FILE * f, bool append = true);                                                         // ����� ��� ������ � ���� ����� ������ 
	int Load(FILE * f);                                                         // ����� ��� ������ �� ����� ����� ������ 
	
};

