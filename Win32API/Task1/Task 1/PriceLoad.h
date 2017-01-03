#pragma once
#include "Includes.h"
#include "PriceInfo.h"

class PriceLoad
{
	// Имя файла данных (это текстовый файл)
	wstring sFileName;

public:
	PriceLoad()
		: sFileName(_T("PriceLoad.txt")) {}
	PriceLoad(wstring fileName)
		: sFileName(fileName) {}
	
	~PriceLoad() {}

	void LoadFromFile();
	void ListView(HWND hListView);

	// Установка имени файла данных
	void SetFileName(wstring fName) { sFileName = fName;  }

	vector<PriceInfo> data;
};

