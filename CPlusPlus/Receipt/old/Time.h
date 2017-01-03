#pragma once
#include "stdafx.h"

class Time
{
	WORD day;
	WORD month;
	WORD year;
	WORD hour;
	WORD minute;

public:
	Time();
	Time(WORD day, WORD month, WORD year, WORD hour, WORD minute);
	~Time() {}

	void Init(WORD day = 0, WORD month = 0, WORD year = 0, WORD hour = 60, WORD minute = 60);

	friend ostream &operator<<(ostream &os, const Time &dt);
	friend istream &operator>>(istream &is, Time &dt);
};

