// Laptev32P24.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Account.h"
#include "Utils.h"

HANDLE h;

int main()
{
	init();
    Account account;  
    int number; 
 
    for( ; ;) 
    {
		tMark("����", 2);
		cout << "\n\n1 ���� ������������ ������\n";
		cout << "2 ����� ������ \n";
		cout << "3 ����� ��������� ����������� ����� \n";
		cout << "4 ����� �����\n";
		cout << "5 �������� ����� \n";
		cout << "6 ������� ����� � ������ ������\n";
		cout << "7 ����������� ����� �������� \n"; 
		cout << "8 ���������� �� ��������� \n";
		cout << "0 ����� \n\n"; 
		cout << "������� ��� �������: \n"; 
		cin >> number; 
	 
		switch(number) 
		{ 
			case 1: account.Input(); break;
			case 2: account.Show(); break; 
			case 3: account.Chown(); break; 
			case 4: account.Pull_of(); break; 
			case 5: account.Put(); break; 
			case 6: account.Change(); break; 
			case 7: account.Propis(); break;
			case 8: account.Per(); break;
			case 0: tMark("���������� ������ ���������.", LtCyan); cout << endl; exit(1); break;
			default: cout << "����������� ���� \n"; break; 
		}  
		system("Pause");
		system("cls");
	}
    return 0;
}

