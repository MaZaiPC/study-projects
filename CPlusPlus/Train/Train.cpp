#include "stdafx.h"
#include "Train.h"
#include "Utils.h"

Train::Train()
{
	serial = "000X";
	nameStation = ">Empty<";
}

Train::Train(string ser, string name, Time time)
{
	serial = ser;
	nameStation = name;
	time_a = time;
}

Train::Train(const Train & obj)
{
	serial = obj.serial;
	nameStation = obj.nameStation;
}

Train::~Train()
{
}

// �������
void Train::setSerial(string s)
{
	cin >> serial;
}
void Train::setNameStation(string ns)
{
	cin >> nameStation;
}

// �� ������ ������ �� ����������� ������� ��������� �������
// �� ���������� ������ Time � ���� ������...
void Train::setH(int h)
{
	time_a.setH(h);
}
void Train::setM(int m)
{
	time_a.setM(m);
}

// ������
void Train::Input(UINT n)
{
	string tmp = Format("����������� �������� %u", n);
	tMark(tmp, 1);
	cout << "\n������� �������� ����� ������: "; cin >> serial;
	cout <<   "������� ����� ����������: "; cin >> nameStation;
	tMark("\n����� �����������\n", LtCyan);
	time_a.setH();
	time_a.setM();
}

void Train::Show(UINT n)
{
	string tmp = Format("����� %u", n);
	tMark(tmp, 1);
	cout << "\n�������� �����: " << setfill('0') << setw(4) << serial << setfill(' ') << endl;
	cout << "����� ����������: " << nameStation << endl;
	cout << "\n����� ����������� " << setfill('0') << setw(2) << time_a.getH() << ":" << setw(2) << time_a.getM() << setfill(' ') << "\n\n";
}

void Train::Randomize()
{
	UINT a = Random(1, 999);
	char b;
	do {
		b = Random('�', '�');
	// ������� �� �������� ��� ������� �����
	} while (b == '�' || b == '�' || b == '�' || b == '�' || b == '�' || b == '�');
	string ser = Format("%u", a);
	ser += Format("%c", b);

	serial = ser;
	
	string city[] = {"������", "����","������","�����-���������","�������","���������","������","�����������","�����","������","�����","����������","���","�������","��������","������","���������","�����������","�����","�������"};
	WORD c = Random(1, 19);
	
	nameStation = city[c];

	WORD hor = Random(0, 23);
	time_a.setH(hor);
	
	WORD tmp;
	do {
		tmp = Random(0, 59);
	//����� ������ ������ ���� ������ 5
	} while (tmp % 5 != 0);
	
	time_a.setM(tmp);
}