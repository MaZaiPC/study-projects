#include "stdafx.h"
#include "Time.h"
#include "Utils.h"


Time::Time()
{
	Init();
} // Time::Time 


Time::Time(WORD day, WORD month, WORD year, WORD hour, WORD minute)
{
	Init(day, month, year, hour, minute);
} // Time::Time


void Time::Init(WORD day, WORD month, WORD year, WORD hour, WORD minute)
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	this->year   = (year == 0)?st.wYear:year;
	this->month  = (month < 1 || month > 12)? st.wMonth:month;
	this->day    = (day < 1 || day > LastDay(this->month, this->year)) ? st.wDay : day;
	this->hour   = (hour > 23) ? st.wHour : hour;
	this->minute = (minute > 59) ? st.wMinute : minute;
} // Time::Init


ostream &operator<<(ostream &os, const Time &dt)
{
	os  << setfill('0')
		<< setw(2) << dt.day << "/" << setw(2) << dt.month << "/"
		<< setw(4) << dt.year << " "
		<< setw(2) << dt.hour << ":" << dt.minute
		<< setfill(' ');
	return os;
} // operator<<


istream &operator>>(istream &is, Time &dt)
{
	WORD d, mt, y, h, mn;
	is >> d >> mt >> y >> h >> mn;
	dt.Init(d, mt, y, h, mn);
	return is;
} // operator>>