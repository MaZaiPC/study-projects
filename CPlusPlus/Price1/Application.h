#pragma once
#include "Price.h"

class Application
{
	static const int N_MAX = 1000;   // максимальное количество маршрутов в файле
	
	// "База данных" - файл с данными о маршрутах
	char *dbFileName;
	FILE *f;

	int numRecords();  // возвращает количество записей в файле данных

public:
	Application();      // Конструктор по умолчанию
	~Application();     // Деструктор

	void run();         // Главный метод приложения - обработка команд пользователя 
	void read();        // Метод для ввода данных в массив пунктов назначений
	void show();        // Метод для вывода данных из массива пунктов назначений  

	// Метод для сортировки данных в файле по возрастанию номеров маршрутов
	void sort(bool compare(const Price &, const Price &));        

}; // Application


inline bool cmpPrice(const Price &t1, const Price &t2);
inline bool cmpName(const Price &t1, const Price &t2);