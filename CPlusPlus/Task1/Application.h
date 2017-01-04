#pragma once
#include "Complex.h"
#include "Rational.h"
#include "Fraction.h"
#include "Money.h"

class Application
{
	Pair *pPair;

public:
	Application();      // ����������� �� ���������
	~Application();     // ����������

	void run();           // ������� ����� ��� ������
	void testComplex();   // ������������ ������ Complex
	void testRational();   // ������������ ������ Rational

}; // Application



