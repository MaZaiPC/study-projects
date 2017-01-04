#include "stdafx.h"
#include "DateTime.h"
#include "Utils.h"


DateTime::DateTime()
{
	Init();
} // DateTime::DateTime 


DateTime::DateTime(WORD day, WORD month, WORD year, WORD hour, WORD minute)
{
	Init(day, month, year, hour, minute);
} // DateTime::DateTime


void DateTime::Init(WORD day, WORD month, WORD year, WORD hour, WORD minute)
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	this->year   = (year == 0)?st.wYear:year;
	this->month  = (month < 1 || month > 12)? st.wMonth:month;
	this->day    = (day < 1 || day > LastDay(this->month, this->year)) ? st.wDay : day;
	this->hour   = (hour > 23) ? st.wHour : hour;
	this->minute = (minute > 59) ? st.wMinute : minute;
} // DateTime::Init


// Запись даты в файл в двоичном формате. Если не все данные
// записаны, то возвращается 1, если все записано, то возвращается 0
int DateTime::save(FILE *f, bool append)
{
	int cc;
	if (append) fseek(f, 0, SEEK_END);

	cc = fwrite(&day, sizeof(WORD), 5, f);
	return (int)(cc != 5);
} // DateTime::save


// Чтение даты из файла в двоичном формате, если не все данные
// прочитаныны, то возвращается 1, если все прочитано, то возвращается 0
int DateTime::load(FILE *f)
{
	int cc = fread(&day, sizeof(WORD), 5, f);
	return (int)(cc != 5);
} // DateTime::load


ostream &operator<<(ostream &os, const DateTime &dt)
{
	os  << setfill('0')
		<< "{ " << setw(2) << dt.day << "/" << setw(2) << dt.month << "/"
		<< setw(4) << dt.year << " "
		<< setw(2) << dt.hour << ":" << setw(2) << dt.minute << " }"
		<< setfill(' ');
	return os;
} // operator<<


istream &operator>>(istream &is, DateTime &dt)
{
	WORD d, mt, y, h, mn;
	is >> d >> mt >> y >> h >> mn;
	dt.Init(d, mt, y, h, mn);

	return is;
} // operator>>