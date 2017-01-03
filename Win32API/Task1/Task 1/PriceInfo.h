#pragma once
#include "Includes.h"

class PriceInfo
{
public:
	PriceInfo() {}
	
	~PriceInfo() {}

	wstring ComputerType; // Тип компьютера
	UINT DiskSpace;		  // Емкость жесткого диска
	UINT Price;			  // Цена

	void SetFields(TCHAR *str);
};

