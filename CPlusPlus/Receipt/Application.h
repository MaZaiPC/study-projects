#pragma once
#include "Goods.h"
#include "Receipt.h"


class Application
{
	Goods   op, res;  // операнды и результат
	Receipt *receipt;

	static const int N_MAX = 1000;   // максимальное количество магазинов в файле

									 // "База данных" - файл с данными о маршрутах
	char *dbFileName;
	FILE *f;

	int numRecords();               // возвращает количество записей в файле данных

public:
	Application();
	~Application();

	void run();
	void read();        // Метод для ввода данных в массив пунктов назначений
	void show();        // Метод для вывода данных из массива пунктов назначений
	void Sum();

	void showСheck();   // Метод для вывода данных из массива пунктов назначений
}; // Application



