#pragma once
#include "Receipt.h"

class Application
{
	static const int N = 9;


	char *dbFileName;

	void ChoiseSort();
	void Exit();
public:

	static const string PAUSE_MSG;
	static const string PAUSE_BACK_MSG;
	static const string REC_PATCH;
	static const string DB_PATCH;

	Application();
	~Application();

	int numRecords();

	// Ёлементы меню
	void Run();
	void SubMenu();

	// ќперации с чеками
	void rec_new();
	void rec_load();
	void rec_rename();

	void rec_delete();
	void rec_add_gooide();

	// ќперации с товарами
	void gooide_add();
	void gooide_remove();

	void sort(bool compare(const Receipt &, const Receipt &));
}; // Application

inline bool cmpReceipt(const Receipt &t1, const Receipt &t2);
inline bool cmpName(const Receipt &t1, const Receipt &t2);
