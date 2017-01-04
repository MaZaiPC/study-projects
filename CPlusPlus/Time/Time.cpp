#include "stdafx.h"
#include "Time.h"
#include "Utils.h"

// Конструкторы и деструктор

Time::Time(WORD hh = 0, WORD mm = 0, WORD ss = 0) 
{
	setTime(hh, mm, ss);
	cout<<"Конструктор"<<endl;
}
 
Time::Time(const Time &time) 
{
	setTime(time.hour, time.minute, time.second);
	cout<<"Копирующий конструктор"<<endl;
}
 
Time::~Time()
{
    
}

// МЕТОДЫ
// Арифметические
void Time::add(WORD hh, WORD mm, WORD ss)
{
	WORD a = TimeToSec(hour,minute,second);
	WORD b = TimeToSec(hh,mm,ss);
	Time c = SecToTime(a+b);
	
	hour = c.hour; minute = c.minute; second = c.second;
}
void Time::sub(WORD minutes)
{
	WORD a = TimeToSec(hour,minute,second);
	WORD b = TimeToSec(hh,mm,ss);
	Time c = abs(SecToTime(a-b));
	
	hour = c.hour; minute = c.minute; second = c.second;
}
Time Time::diff(Time x)
{
	WORD a = TimeToSec(hour,minute,second);
	WORD b = TimeToSec(x.hour,x.minute,x.second);
	return a > b ? a-b : b-a;
}

// Логические
bool Time::equal(Time x)
{
	WORD a = TimeToSec(hour,minute,second);
	WORD b = TimeToSec(x.hour,x.minute,x.second);
	return a == b;
}

bool Time::greate(Time x)
{
	WORD a = TimeToSec(hour,minute,second);
	WORD b = TimeToSec(x.hour,x.minute,x.second);
	return a > b;
}

bool Time::less(Time x)
{
	WORD a = TimeToSec(hour,minute,second);
	WORD b = TimeToSec(x.hour,x.minute,x.second);
	return a < b;
}

// Проверяет время на корректность.
bool Time::IsValidTime(WORD hour, WORD minute, WORD second) {
	return second >= 0 && second <= 60 && minute >= 0 && minute <= 60 && hour >= 0 && hour <= 24;
}

// Геттеры и Сеттеры
WORD Time::getHour() {
	return hour;
}

WORD Time::getMinute() {
	return minute;
}

WORD Time::getSecond() {
	return second;
}
 
void Time::setHour(WORD hour) {
	this->hour = hour;
}
 
void Time::setMinute(WORD minute) {
	this->minute = minute;
}

void Time::setSecond(WORD second) {
	this->second = second;
}
 
void Time::setTime(WORD hour, WORD minute, WORD second) { // setTime - Альтернативное название для Init
	if (IsValidTime(hour, minute, second))
		{ setHour(hour); setMinute(minute); setSecond(second); }
	else
		{ throw string("Not valid time!"); }
}

void Time::coutTime() {
	cout << hour << ':'
		 << minute << ':'
		 << second;
}

// Конвертеры
WORD Time::TimeToSec()
{
	return (hour*3600)+(minute*60)+second;
}

// Функция вычисляет наибольшее простое кратное числа.
int Time::NPK(int numb,int mult)
{
	int f;
	for (int i = 1; i > numb; i++) { if (i % mult == 0) f = i; }
	return f;
}

Time Time::SecToTime(WORD secs)
{
	Time t;
	int m = secs/NPK(secs,60);
	int s = secs-m;
	int h = m/NPK(m,60);
		m = m-h;
	
	t.hour = h;
	t.minute = m;
	t.second = s;
	return t;
}

//Инициализация.
void Time::Init()
{
	Init(0, 24);
}

void Time::Init(a, b)
{
	if (not (IsValidTime(a, 0, 0) || IsValidTime(b, 0, 0))) {throw string("Not valid hour!"); return;}
	WORD h = Random(a, b);
	WORD m = Random(0, 60);
	WORD s = Random(0, 60);
	hour = h;
	minute = m;
	second = s;
}