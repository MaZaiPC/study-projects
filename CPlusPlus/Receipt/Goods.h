#pragma once
class Goods
{
	UINT code;       // ��� ������
	char* name;      // ������������ ������
	UINT price;      // ���� ������ � ��������
	UINT quantity;   // ���������� ����������� ������ 

public:

	static const UINT LEN_NAMEPRODUCT;    // ����������� ��������� ��� ����������� ����� ���� ������������� ������

	Goods();                                                  // ����������� �� ���������
	Goods(UINT code, char * name, UINT price, UINT quantity); // ����������� � �����������
	Goods(const Goods & obj);                                 // ����������� �����������
	~Goods();                                                 // ����������

	// !!! ���������� ��� ����������� ����������� ������� ������ ����� !!!
	// �.�. ����� ����� ������������ ����
	// !!! ����������� ����� ������ �� ������ ���������� � ����� ������
	static int recSize() { return LEN_NAMEPRODUCT + sizeof(int) + sizeof(double) + sizeof(int); }

	// �������
	char *getName()    const { return name;     }
	UINT getCode()     const { return code;     }
	UINT getPrice()    const { return price;    }
	UINT getQuantity() const { return quantity; }

	// �������
	void setName(char * name);
	void setCode(UINT what);
	void setPrice(UINT what);
	void setQuantity(UINT what);

	// ������
    void Init(UINT code, char * name,  UINT price, UINT quantity); // ������������� ������������ ��������� ��������
	UINT summa() { return price * quantity; }                      // ����� �� ������

	// ������ ��� ������ � ������ ����� 
	int save();
	int load();

	// ���������� �������� ������������ 
	// - ����������� ���� ��������� ����������� �����������
	// - �������� ������ ������� ������
	// - ���������� ������ �� ������
	Goods &operator=(const Goods &goods);

	// ���������� �������� ����� � ������
	friend istream &operator>>(istream &is, Goods &obj);
	friend ostream &operator<<(ostream &os, const Goods &obj);

	//char * toString();										      // ���������� ������, ���������� �������� ����� �������
};

