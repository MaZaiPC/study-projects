#pragma once
#include "stdafx.h"

class Point
{
public:
	Point() :x(), y() {}
	Point(double x, double y) :x(x), y(y) {}
	~Point() {}

	double x;
	double y;

	bool operator<(const Point &obj);
	bool operator>(const Point &obj);

	friend ostream &operator<<(ostream &os, const Point &point);
	friend istream &operator>>(istream &is, Point &point);
};

class Shape
{
protected:
	UINT uNumVertex;  // количество вершин
	Point *pPoints;   // массив координат вершин

public:
	static bool IsLinesCross(Point a, Point b, Point a1, Point b1);
	template <class X, class Y> static bool IsIntersect(const X &T1, const Y &T2);

	Shape();
	Shape(UINT uNumVertex);
	Shape(Point *pPoints, UINT uNumVertex);
	Shape(const Shape &obj);
	~Shape();

	Shape &operator=(const Shape &obj);
	void Move(double deltaX, double deltaY);
	

	friend ostream &operator<<(ostream &os, const Shape &obj);
	friend istream &operator>>(istream &is, Shape &obj);
};

class Square : public Shape
{
public:
	Square() :Shape(4) {}
	Square(Point *pPoints) : Shape(pPoints, 4) {}
	Square(const Square &obj) : Shape(obj) {}
	~Square() {}
};

class Pentagon :public Shape
{
public:
	Pentagon() :Shape(5) {}
	Pentagon(Point *pPoints) : Shape(pPoints, 5) {}
	Pentagon(const Pentagon &obj) : Shape(obj) {}
	~Pentagon() {}
};
