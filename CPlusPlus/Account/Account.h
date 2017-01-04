#pragma once
#include "stdafx.h"

class Account 
{ 
private: 
    string name; 
    int number;
    int summa;
    int percent;
public:
    Account()  { number = 0; summa = 0; percent = 0; };
	Account(const Account &obj);
	
	~Account();
	
	// ������
    void Input(); 
    void Show();  
    void Chown(); // ����� ��������� 
    void Pull_of(); // ����� ����� 
    void Put(); // �������� 
    void Per(); 
    void Change(); 
    void Propis();
}; 

