// Laptev25P23.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"


int main()
{
	SetConsoleOutputCP(1251);

	Triangle a(2., 3., 1.);
	Triangle b(5., 5., 5.);

	double area, perim;

	area = a.Area();
	perim = a.Perimeter();

	cout << area << ", " << perim << "\n";

	area = b.Area();
	perim = b.Perimeter();

	cout << area << ", " << perim << "\n";

    return 0;
}

