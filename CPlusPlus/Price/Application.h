#pragma once
#include "Price.h"

class Application
{
	static const int N = 9;

	Price *a;

	char *dbFileName;
	FILE *f;

	void ChoiseSort();
	void Exit();
public:

	static const string PAUSE_MSG;
	static const string PAUSE_BACK_MSG;

	Application();
	~Application();

	int numRecords();

	void Run();
	void New();
	void Load();

	void sort(bool compare(const Price &, const Price &));
}; // Application

inline bool cmpPrice(const Price &t1, const Price &t2);
inline bool cmpName(const Price &t1, const Price &t2);
