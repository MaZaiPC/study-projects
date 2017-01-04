#pragma once

/**
1. ���������� ����� � ������ Price, ���������� ��������� ����:
	� �������� ���������� ������ ��������;
	� �������� ��������� ������ ��������;
	� ����� ��������.
 ���������� ������ ������� � ���� ����� � ������������� ��������
 ���������� � ������� ��� �������� ���� Price.
2. �������� ���������, ����������� ��������� ��������:
	� ���� � ���������� ������ � ������, ��������� �� ������
	  �������� ���� Price; ������ ������ ���� ����������� �� �������
	  ���������;
	� ����� �� ����� ���������� � ��������, ����� ��������
	  ������ � ����������;
	� ���� ����� ��������� ���, ������ �� ������� ���������������
	  ���������.
**/

class Price
{
	string name; //start
	double price;
public:

	static const UINT LEN_NAME;
	static const UINT LEN_PRICE;

	static int recSize() { return LEN_NAME + LEN_PRICE; }

	Price();
	Price(double price, string name);
	Price(const Price & obj);
	~Price();

	// �������
	void setName(string nm);
	void setPrice(double pr);

	// �������
	string getName() const { return name; }
	double getPrice() const { return price; }

	// ������
	void Input(UINT n);
	void Show(UINT n);
	void Randomize();

	// ������ ������������
	int Save(FILE * f, bool append = true);
	int Load(FILE * f);
};

