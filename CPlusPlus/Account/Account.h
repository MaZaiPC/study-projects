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
	
	// Методы
    void Input(); 
    void Show();  
    void Chown(); // смена владельца 
    void Pull_of(); // снять сумму 
    void Put(); // положить 
    void Per(); 
    void Change(); 
    void Propis();
}; 

