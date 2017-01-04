#pragma once
#include "stdafx.h"

class DateTime
{
	WORD day;
	WORD month;
	WORD year;
	WORD hour;
	WORD minute;

public:
	DateTime();
	DateTime(WORD day, WORD month, WORD year, WORD hour, WORD minute);
	~DateTime() {}

	void Init(WORD day = 0, WORD month = 0, WORD year = 0, WORD hour = 60, WORD minute = 60);


	void setDay(WORD d)    { day = d; }
	void setMonth(WORD m)  { month = m; }
	void setYear(WORD y)   { year = y; }

	void setHour(WORD h)   { hour = h; }
	void setMinute(WORD m) { minute = m; }
	
	WORD getDay()	 const { return day; }
	WORD getMonth()  const { return month; }
	WORD getYear()   const { return year; }

	WORD getHour()	 const { return hour; }
	WORD getMinute() const { return minute; }

	int save(FILE *f, bool append = true);
	int load(FILE *f);

	friend ostream &operator<<(ostream &os, const DateTime &dt);
	friend istream &operator>>(istream &is, DateTime &dt);
};

