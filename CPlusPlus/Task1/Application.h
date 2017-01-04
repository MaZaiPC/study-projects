#pragma once
#include "Complex.h"
#include "Rational.h"
#include "Fraction.h"
#include "Money.h"

class Application
{
	Pair *pPair;

public:
	Application();      // Конструктор по умолчанию
	~Application();     // Деструктор

	void run();           // Главный метод для работы
	void testComplex();   // Тестирование класса Complex
	void testRational();   // Тестирование класса Rational

}; // Application



