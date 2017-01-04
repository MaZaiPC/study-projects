#include "stdafx.h"
#include "Receipt.h"
#include "Utils.h"
#include "Goods.h"

UINT Receipt::counter = 0;  // начальное значение счетчика чеков


// Формирование номера чека в формате YYMMDDNNNN
UINT Receipt::makeNumber()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	return (st.wYear % 100) * 1000000000 + st.wMonth + 1000000 + st.wDay * 10000 + counter;
} // Receipt::makeNumber


// Receipt::Receipt: Конструктор по умолчанию
Receipt::Receipt() : number(makeNumber()), size(1), create(), goods(new Goods[size])
{ 
	counter++;
} // Receipt::Receipt


Receipt::~Receipt()
{
	delete[] goods;
} // Receipt::~Receipt

bool Receipt::operator -(UINT nIndex)
{
	if (nIndex > 0)
	{
		goods[nIndex];
		return true;
	}
} //add

void Receipt::Save(UINT gooideNum, string filePath)
{
	string section = Format("Receipt#%u", number);
	string _gooideNum = to_string(gooideNum);
	string _gooideDesc = Format("Gooide[%u]", size);
	WritePrivateProfileStringA(section.c_str(), _gooideDesc.c_str(), _gooideNum.c_str(), filePath.c_str());
}

void Receipt::Load(UINT i, string recFilePath, string dbFilePath)
{
	string section = Format("Receipt#%u", number);
	string _gooideDesc = Format("Gooide[%u]", i);
	static char buf[100];
	GetPrivateProfileStringA(section.c_str(), _gooideDesc.c_str(), "0", buf, 100, recFilePath.c_str());
	goods[i].Load((UINT)buf, dbFilePath);
}