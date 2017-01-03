#pragma once
#include "Includes.h"
#include "ApartamentInfo.h"

class ApartamentsLoader
{
	fstream *fs; // Указатель на файл данных.
public:
	ApartamentsLoader() {}
	explicit ApartamentsLoader(fstream &fs) : fs(&fs) {}
	~ApartamentsLoader() {}

	void Load();
	void Save(bool clearold = false);
	void ListView(HWND hListView1, HWND hListView2);

	list<APARTAMENTS_PAIR> data;
};