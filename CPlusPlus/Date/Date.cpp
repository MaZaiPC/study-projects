#include "stdafx.h"
#include "Date.h"
#include "Utils.h"

// Конструкторы и деструктор

Date::Date(UINT yyyy = 1974, UINT mm = 11, UINT dd = 23)
{
	setDate(yyyy, mm, dd);
	cout << "Конструктор" << endl;
}

Date::Date(const Date &Date)
{
	setDate(Date.day, Date.month, Date.year);
	cout << "Копирующий конструктор" << endl;
}

Date::~Date()
{

}

// МЕТОДЫ
// Арифметические
Date Date::add(UINT days)
{
	UINT a = toJDN();
	return toGD(a + days);
}
Date Date::sub(UINT days)
{
	UINT a = toJDN();
	return toGD(a - days);
}
Date Date::diff(Date x)
{
	UINT a = toJDN();
	UINT b = toJDN(x);
	return a > b ? a - b : b - a;
}

// Логические
bool Date::equal(Date x)
{
	UINT a = toJDN(year, month, day);
	UINT b = toJDN(x.year, x.month, x.day);
	return a == b;
}

bool Date::greate(Date x)
{
	UINT a = toJDN(year, month, day);
	UINT b = toJDN(x.year, x.month, x.day);
	return a > b;
}

bool Date::less(Date x)
{
	UINT a = toJDN(year, month, day);
	UINT b = toJDN(x.year, x.month, x.day);
	return a < b;
}

// Проверяет дату на корректность.
bool Date::IsValidDate(UINT day, UINT month, UINT year) {
	return day > 0 && month > 0 && month < 13 && year > 0;
}

// Проверяет является ли год високосным.
bool Date::IsLeapYear(UINT year) {
	return (year % 100 == 0) ? (year % 400 == 0) : (year % 4 == 0);
}

// Геттеры и Сеттеры
UINT Date::getDay() {
	return day;
}

UINT Date::getMonth() {
	return month;
}

UINT Date::getYear() {
	return year;
}

void Date::setDay(UINT day) {
	this->day = day;
}

void Date::setMonth(UINT month) {
	this->month = month;
}

void Date::setYear(UINT year) {
	this->year = year;
}

void Date::setDate(UINT day, UINT month, UINT year) { // setDate - Альтернативное название для Init
	if (IsValidDate(day, month, year))
	{
		setDay(day); setMonth(month); setYear(year);
	}
	else
	{
		throw string("Not valid Date!");
	}
}

void Date::coutDate() {
	cout << day << '/'
		<< month << '/'
		<< year << endl;
}

// Конвертеры
UINT Date::toJDN()
{
	return toJDN(day, month, year);
}

UINT Date::toJDN(Date x)
{
	return toJDN(x.day, x.month, x.year);
}

UINT Date::toJDN(UINT day, UINT month, UINT year)
{
	UINT a = 14 - month / 12;
	UINT y = year + 4800 - a;
	UINT m = month + (12 * a) - 3;
	UINT b = (153 * m + 2) / 5;
	UINT JDN = day + b + (365 * y) + (y / 4) - (y / 100) + (y / 400) - 32045;
	return JDN;
}

Date Date::toGD(UINT JDN)
{
	Date t;
	UINT a = JDN + 32044;
	UINT b = (4 * a + 3) / 146097;
	UINT c = a - (146097 * b) / 4;
	UINT d = (4 * c + 3) / 1461;
	UINT e = c - (1461 * d) / 4;
	UINT m = (5 * e + 2) / 153;

	t.year = 100 * b + d - 4800 + (m / 10);
	t.month = m + 3 - 12 * (m / 10);
	t.day = e - (153 * m + 2) / 5 + 1;
	return t;
}

//Инициализация.
void Date::Init()
{
	Init(1974, 2015);
}

void Date::Init(int a, int b)
{
	UINT yyyy = Random(a, b);
	UINT mm = Random(1, 12);
	UINT ArrD[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (!IsLeapYear(yyyy))
		ArrD[2] = 28;
	UINT dd = Random(1, ArrD[mm]);
	year = yyyy;
	month = mm;
	day = dd;
}