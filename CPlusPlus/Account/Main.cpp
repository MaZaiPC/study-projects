// Laptev32P24.cpp: определяет точку входа для консольного приложения.
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
		tMark("Меню", 2);
		cout << "\n\n1 Ввод персональных данных\n";
		cout << "2 Вывод данных \n";
		cout << "3 Смена владельца банковского счёта \n";
		cout << "4 Снять сумму\n";
		cout << "5 Положить сумму \n";
		cout << "6 Перевод суммы в другую валюту\n";
		cout << "7 Распечатать сумму прописью \n"; 
		cout << "8 Начисление по процентам \n";
		cout << "0 Выход \n\n"; 
		cout << "Введите ваш вариант: \n"; 
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
			case 0: tMark("Завершение работы программы.", LtCyan); cout << endl; exit(1); break;
			default: cout << "Некорретный ввод \n"; break; 
		}  
		system("Pause");
		system("cls");
	}
    return 0;
}

