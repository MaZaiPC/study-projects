#include "stdafx.h"
#include "Triad.h"
#include "Utils.h"

/*-----------------------class # Triad--------------------------*/
Triad::Triad() : a(), b(), c()
{
}

Triad::Triad(WORD a, WORD b, WORD c) : a(a), b(b), c(c)
{
	
}

Triad::Triad(const Triad &obj)
{
	*(this) = *(&obj);
	/*a = obj.a;
	b = obj.b;
	c = obj.c;*/
	cout << "\nВызов конструктора копирования Triad.\n";
} // Triad::Triad

Triad::~Triad()
{
}

Triad Triad::operator++()
{
	a++; b++; c++;
	return *this;
} // Triad::operator++

bool Triad::operator ==(const Triad &obj)
{
	return a + b + c == obj.a + obj.b + obj.c;
} // Triad::operator ==

bool Triad::operator <(const Triad &obj)
{
	return a + b + c < obj.a + obj.b + obj.c;
} // Triad::operator <

bool Triad::operator >(const Triad &obj)
{
	return a + b + c > obj.a + obj.b + obj.c;
} // Triad::operator >

ostream &operator<<(ostream &os, const Triad &obj)
{
	os << "a[" << obj.a << "], b[" << obj.b << "], c[" << obj.c << "]";
	return os;
} // operator<<

/*-----------------------class # Time--------------------------*/

Time::Time() : Triad()
{
	
}

Time::Time(WORD a, WORD b, WORD c) : Triad(a,b,c)
{
	init(a,b,c);
}

Time::Time(const Time &obj) : Triad((Triad &) obj)
{
	cout << "\nВызов конструктора копирования Time.\n";
}

void Time::init(WORD hour, WORD minute, WORD second)
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	h   = (hour > 23) ? st.wHour : hour;
	m   = (minute > 59) ? st.wMinute : minute;
	s   = (second > 59) ? st.wSecond : second;
}

void Time::set_H(WORD h)
{
	if (h < 0) {
		cout << "\n Не вверно введеный час ! Замена на 9\n";
		h = 9;
	} // if

	if (h > 24) {
		h = 0;
	}// if

	this->h = h;

}// Time::setH

void Time::set_M(WORD m)
{
	if (m < 0) {
		cout << "\n Не вверно введеные минуты ! Замена на 24\n";
		m = 24;
	} // if

	if (m > 59) {
		h++;
		m = 0;
	} // if

	this->m = m;
}// Time::setM

void Time::set_S(WORD s)
{
	if (s < 0) {
		cout << "\n Не вверно введеные минуты ! Замена на 24\n";
		s = 34;
	} // if

	if (s > 59) {
		m++;
		s = 0;
	} // if

	this->s = s;
}// Time::setS

bool Time::operator <(const Time &obj)
{
	UINT sec_first = h*3600 + m*60 + s;
	UINT sec_sacond = obj.h*3600 + obj.m*60 + obj.s;

	return sec_first < sec_sacond;
} // Time::operator <

bool Time::operator >(const Time &obj)
{
	UINT sec_first = h*3600 + m*60 + s;
	UINT sec_sacond = obj.h*3600 + obj.m*60 + obj.s;

	return sec_first > sec_sacond;
} // Time::operator >

ostream &operator<<(ostream &os, const Time &obj)
{
	os  << setfill('0')
		<< setw(2) << obj.a << ":" << setw(2) << obj.b << ":" << obj.c
		<< setfill(' ');
	return os;
} // operator<<


istream &operator>>(istream &is, Time &obj)
{
	WORD h, mn, sec;
	is >> h >> mn >> sec;
	obj.init(h, mn, sec);

	return is;
} // operator>>

/*-----------------------class # Date--------------------------*/

UINT Date::to_JDN() const
{
	UINT a = 14 - month / 12;
	UINT y = year + 4800 - a;
	UINT m = month + (12 * a) - 3;
	UINT b = (153 * m + 2) / 5;
	UINT JDN = day + b + (365 * y) + (y / 4) - (y / 100) + (y / 400) - 32045;
	return JDN;
}

Date Date::to_GD(UINT JDN)
{
	UINT a = JDN + 32044;
	UINT b = (4 * a + 3) / 146097;
	UINT c = a - (146097 * b) / 4;
	UINT d = (4 * c + 3) / 1461;
	UINT e = c - (1461 * d) / 4;
	UINT m = (5 * e + 2) / 153;

	year = 100 * b + d - 4800 + (m / 10);
	month = m + 3 - 12 * (m / 10);
	day = e - (153 * m + 2) / 5 + 1;
	return *this;
}

Date::Date() : Triad()
{
	
}

Date::Date(UINT a, UINT b, UINT c) : Triad(a,b,c)
{
	init(a,b,c);
}

Date::Date(const Date &obj) : Triad((Triad &)obj)
{
	cout << "\nВызов конструктора копирования Date.\n";
}


// Сеттеры
void Date::set_day(UINT day)
{
	if (day < 1) {
		cout << "\nDate: Недопустимый день, зачение " << day << " игнорируется\n";
		return;
	} // if

	// Перевод дней в месяца если достигнут предел
	if (day > LastDay(month, year))
	{
		this->day = day - LastDay(month, year);
		month++;
		goto first; // пропускаем первое вхождение в цикл
		do
		{
			this->day -= LastDay(month, year);
			month++;
		first:;
		}
		// если переменная класса все еще хранит значение
		// больше чем 1 месяц в днях, то сводим к допустимому
		// числу дней
		while (this-> day > LastDay(month, year));
	} // if

	this->day = day;
} // Date::setDay


void Date::set_month(UINT month)
{
	if (month < 1) {
		cout << "\nDate: Недопустимый месяц, зачение " << month << " игнорируется\n";
		return;
	} // if

	// Перевод месяцев в год если достигнут предел
	if (month > 12)
	{
		this->month = month - 12;
		year++;
		goto first; // пропускаем первое вхождение в цикл
		do 
		{
			this->month -= 12;
			year++;
		first:;
		// если переменная класса все еще хранит значение
		// больше чем 1 год в месяцах, то сводим к допустимому
		// числу месяцев
		} while (this->month > 12);
	} // if

	this->month = month;
} // Date::setMonth


 // Служебные методы
void Date::init(UINT y, UINT m, UINT d) // Инициализация.
{
	set_year(y);
	set_month(m);
	set_day(d);
}// Date::Init

Date Date::operator+(const UINT &days)
{
	UINT t = to_JDN() + days;
	//to_GD(t);
	//return *this;
	return to_GD(t);
} // Date::add

Date Date::operator++()
{
	init(year+1, month+1, day+1);
	return *this;
} // Date::operator ++

bool Date::operator <(const Date &obj)
{
	UINT Jd1 = to_JDN();
	UINT Jd2 = obj.to_JDN();
	return Jd1 < Jd2;
} // Date::operator <

bool Date::operator >(const Date &obj)
{
	UINT Jd1 = to_JDN();
	UINT Jd2 = obj.to_JDN();
	return Jd1 > Jd2;
} // Date::operator >

ostream &operator<<(ostream &os, const Date &obj)
{
	os << setfill('0') << setw(2) << obj.day << '/'
		<< setw(2) << obj.month << '/'
		<< obj.year << setfill(' ');
	return os;
} // operator<<


istream &operator>>(istream &is, Date &obj)
{
	WORD y, m, d;
	is >> y >> m >> d;
	obj.init(y, m, d);

	return is;
} // operator>>