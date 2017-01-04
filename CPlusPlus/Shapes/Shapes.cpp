#include "stdafx.h"
#include "Shapes.h"

/*----------------------Class Point------------------------*/

bool Point::operator<(const Point & obj)
{
	return x < obj.x && y < obj.y;
}

bool Point::operator>(const Point & obj)
{
	return false;
}

// Вывод координат точки
ostream &operator<<(ostream &os, const Point &point)
{
	os << "[" << point.x << "; " << point.y << "]";
	return os;
} // operator<<


  // Ввод координат точки
istream &operator>>(istream &is, Point &point)
{
	is >> point.x >> point.y;
	return is;
} // operator>>

/*----------------------Class Shape------------------------*/

// Пересекается ли отрезок AB с A1B1 ?
bool Shape::IsLinesCross(Point a, Point b, Point a1, Point b1)
{
	double maxx1 = max(a.x, b.x), maxy1 = max(a.y, b.y);
	double minx1 = min(a.x, b.x), miny1 = min(a.y, b.y);
	double maxx2 = max(a1.x, b1.x), maxy2 = max(a1.y, b1.y);
	double minx2 = min(a1.x, b1.x), miny2 = min(a1.y, b1.y);

	if (minx1 > maxx2 || maxx1 < minx2 || miny1 > maxy2 || maxy1 < miny2)
		return false;  // Момент, когда линии имеют одну общую вершину.


	double dx1 = b.x - a.x, dy1 = b.y - a.y;		// Длина проекций первой линии на ось x и y
	double dx2 = b1.x - a1.x, dy2 = b1.y - a1.y;	// Длина проекций второй линии на ось x и y
	double dxx = a.x - a1.x, dyy = a.y - a1.y;
	double div, mul;

	if ((div = (dy2*dx1 - dx2*dy1)) == 0)
		return false; // Линии параллельны...
	if (div > 0)
	{
		if ((mul = (dx1*dyy - dy1*dxx)) < 0 || mul > div)
			return false; // Первый отрезок пересекается за своими границами.
		if ((mul = (dx2*dyy - dy2*dxx)) < 0 || mul > div)
			return false; // Второй отрезок пересекается за своими границами.
	}

	if ((mul = -(dx1*dyy - dy1*dxx)) < 0 || mul > -div)
		return false; // Первый отрезок пересекается за своими границами.
	if ((mul = -(dx2*dyy - dy2*dxx)) < 0 || mul > -div)
		return false; // Второй отрезок пересекается за своими границами.

	return true;
} // Shape::IsLinesCross

// Проверка пересечения фигур.
// Проверяет каждое ребро одного полигона на пересечение
// со всеми ребрами другого полигона.
/*
bool Shape::IsIntersect(const Shape &T1, const Shape &T2)
{
	for (WORD i = 0; i < T1.uNumVertex-1; i++)
	{
		for (WORD j = 0; j < T2.uNumVertex-1; j++)
		{
			if (IsLinesCross(T1.pPoints[i], T1.pPoints[i + 1], T2.pPoints[j], T2.pPoints[j + 1]))
				return true;
		} // for j
	} // for i
	return false;
} // Shape::IsIntersect
*/

template <class X, class Y>
bool Shape::IsIntersect(const X & T1, const Y & T2)
{
	for (WORD i = 0; i < T1.uNumVertex - 1; i++)
	{
		for (WORD j = 0; j < T2.uNumVertex - 1; j++)
		{
			if (IsLinesCross(T1.pPoints[i], T1.pPoints[i + 1], T2.pPoints[j], T2.pPoints[j + 1]))
				return true;
		} // for j
	} // for i
	return false;
}

// Квадарат - создаем по умолчанию
Shape::Shape() : uNumVertex(3), pPoints(new Point[uNumVertex])
{
	memset(pPoints, 0, uNumVertex * sizeof(Point));
} // Shape::Shape


Shape::Shape(UINT uNumVertex) : uNumVertex(uNumVertex < 3 ? 3 : uNumVertex), pPoints(new Point[uNumVertex])
{
	memset(pPoints, 0, uNumVertex * sizeof(Point));
} // Shape::Shape


Shape::Shape(Point * pPoints, UINT uNumVertex): uNumVertex(uNumVertex), pPoints(new Point[uNumVertex])
{
	memcpy(this->pPoints, pPoints, uNumVertex * sizeof(Point));
} // Shape::Shape


Shape::Shape(const Shape & obj) :uNumVertex(obj.uNumVertex), pPoints(new Point[uNumVertex])
{
	memcpy(this->pPoints, obj.pPoints, uNumVertex * sizeof(Point));
} // Shape::Shape


Shape::~Shape()
{
	delete[] pPoints;
} // Shape::~Shape


Shape & Shape::operator=(const Shape & obj)
{
	uNumVertex = obj.uNumVertex;
	memcpy(this->pPoints, obj.pPoints, uNumVertex * sizeof(Point));

	return *this;
} // Shape::operator=

// Перемещение по плоскости
void Shape::Move(double deltaX, double deltaY)
{
	for (UINT i = 0; i < uNumVertex; i++) {
		pPoints[i].x += deltaX;
		pPoints[i].y += deltaY;
	} // for i
} // Shape::Move


ostream &operator<<(ostream &os, const Shape &obj)
{
	os << "[ ";
	for (UINT i = 0; i < obj.uNumVertex; i++) {
		os << obj.pPoints[i] << (i == obj.uNumVertex - 1 ? "" : ";");
	} // for i
	os << "]";
	return os;
} // operator<<


  // Нужен контроль - образуют ли точки квадрат
istream &operator>>(istream &is, Shape &obj)
{
	for (UINT i = 0; i < obj.uNumVertex; i++)
		is >> obj.pPoints[i];
	return is;
} // operator>>