/*	���������� UTILS

	��������:
		��� ���������� ���������� �������, ������� ����� ����������� � ���������� ���������,
		� ��� ����� � ��������� �������������� �������.
	
	������ ���������:
		2015.11.28 :>
			� ��������� ��������� ������� <T>Random(T a,T b).
			� �������� ����� test::Latency - ����������� ��������� �������� � ���������� ������������� ������� ���� (ms).
			� ������� Format(...) - ��� ������������� �������� ������� � string �� char* � ����� � ���������
			  �������������� char* � string.
			� ������� SetBkColor(..) ������������� � SetBgColor(..) � ����� � ������� ��������������� ������ ��������.
		2015.11.18 :>
			� ��������� ���������� ������� GotoXY(...), ����������� ���� �������� ���� COORD.
			� �������� ����� Checkpoint. ����������� ������ ��������� ��������� �������, ��� �����������
			  �������� � ��������������� ������� �������� GotoXY.
			� �������� ����� Coord(double x, double y) + ������������� ��������� ��������. ��� �� ���������� �� ������������
			  COORD ����� ���� double.
			� �������� ����� Segment(Coord x, Coord y) + ������������� ��������� ��������.
			� �������� �������� ������� ������� getUINT(...) � ������������ ���� test, ������� � ��� ��� �� ��������� ������
			  ������������ ��������, ������� ������� ����� � ����� ������, � ������ ���������� �������.
			� ���� ������� getUINT(...), ������ ����� ����� ��������� �������� ���� �� ����������� ���� � �������� ������.
		2015.11.03 :>
			� ������� �������� ��������� �� tMark (��������������).
			� ��������� �������� ��� ������� ����� ������:
				unsigned char		=	uchar;
				unsigned int		=	uint;
				unsigned short		=	ushort;
				unsigned short int	=	usint;

				short int			=	sint;

				long double			=	ldouble;
				long int			=	lint;
				long long int		=	llint;
				long float			=	lfloat;

		2015.10.05 :>
			� ��������� ������� Fill(...), ����������� ������ �������� char � ���������� n.
			� ���������� ������� CustomPause(...)
				- ����������� ����� _getch()
				- ������ ������� ���������� ��� ������� �������
				- ����� ������� ������� ����� ��������� �������������
			� �������������� �����

		2015.09.18 :>
			� ���������� ������ �� ������� HANDLE h, ������������� � main.cpp.
			� ��������� ������� CustomPause(...), ��������������� � ������� XY ����� � ����� ������� ��������.
			� �������������� �����

		2015.09.16 :>
			� ��������� ������� WhereXY() ��� ��������� ��������� ������� ������� ����������� �������
			� �������������� ������� tMark(...), ������� ������ ����������, ������������� ��������� �������
			  �� ���������

		2015.09.13 :>
			� ��������� ������� Format(.., agrs) ��� �������������� � string
			� ��������� ������� Wrap(..) ��� �������� ����� ������� � ���������� N
			� �������� ������� tMark(...),
			  ��������� ���������� + ��������� string.

		2015.09.9 :>
			� ��������� ������� ��������� �������� ������:
				- StrUpper()
				- StrInvert()
				- StrUpperFirst()
			� ��������� ������� tMark()

		����� :>
			� ������� ����������
			� ��������� �������� �������:
				- init()

				- isLeap(..)
				- Color(..)
				- SetBkColor(..)
				- SetForeColor(..)
				- Clear(..)
				- *StrLower(..)

				- SetWindow(...)
				- Random(...)
				- getUINT(...)
				- LastDay(...)
				- GotoXY(...)
				- WriteXY(...)
	
	���������:
		������� ��������������:
			%�	������ ���� char
			%d	���������� ����� ������ ���� �� ������
			%i	���������� ����� ������ ���� �� ������
			%�	������� ������� (� ������� ��������)
			%�	������� ������� (� �������� ��������)
			%f	���������� ����� � ��������� ������
			%g	���������� ��� %� ��� %f � ��� �� ���, ������� ������
				(��� ������������� %g ������������ � ������� ��������)
			%G	���������� ��� %� ��� %f � ��� �� ���, ������� ������
				(��� ������������� %G ������������ � �������� ��������)
			%�	������������ ����� ����� ��� �����
			%s	������ ��������
			%u	���������� ����� ������ ���� ��� �����
			%�	����������������� ����� ����� ��� ����� (����� ������� ��������)
			%�	����������������� ����� ����� ��� ����� (����� �������� ��������)
			%�	������� �� ����� �������� ���������
			%n	��������������� �������� � ��� ��������� �� ���������� ������ ����,
				� ������� �������� ���������� ��������, ���������� �� ������ ������
			%%	������� ������ %

		����� ����, � �������� ������� ����� ���� ��������� ������������ l � h:
			%ld	 ������ long int
			%hu  ������ short unsigned
			%Lf  ������ long double
*/

#pragma once
#include "stdafx.h"

using namespace std;

/************����������*************/
typedef unsigned char		uchar;
typedef unsigned int		uint;
typedef unsigned short		ushort;
typedef unsigned short int	usint;

typedef short int			sint;

typedef long double			ldouble;
typedef long int			lint;
typedef long long int		llint;

/**************�������**************/


void init();
void SetWindow(int Width, int Height, WORD Attrib = 0x1f);

double Random(double a, double b);
int Random(int a, int b);
template<class T = int> inline T Random(T a, T b)
{
	return a + (b - a) * rand() / (RAND_MAX + 1);
}

bool isLeap(WORD year);
WORD LastDay(WORD month, WORD year);

UINT getUINT(char *prompt, UINT min = 0, UINT max = UINT_MAX);

void Wrap(UINT n);
void Fill(char symbol, UINT n);

// ��� ������ - ������������ ��� ������� ����� � �������
enum CColor {
	Black, Blue, Green, Cyan, Red, Magenta, Yellow, Grey,
	White, LtBlue, LtGreen, LtCyan, LtRed, LtMagenta, LtYellow, LtWhite
};

// ������� ��� ���������� ������ � �������
void Color(char *color);
void SetBgColor(CColor color = Black);
void SetForeColor(CColor color = Grey);
void Clear(char fill = ' ');

// ������� ���������� ���������� ��������
void GotoXY(UINT x, UINT y);
void GotoXY(COORD coord);
void WriteXY(UINT x, UINT y, char *text);
void WriteXY(UINT x, UINT y, string text);
COORD WhereXY();

// ���������/������� �����
void tMark(char* text, CColor sClr = LtYellow, CColor eClr = LtWhite);
void tMark(string text, CColor sClr = LtYellow, CColor eClr = LtWhite);
// ���:
// sClr � eClr - ��������� � �������� ���� ������ (�������� - ��������� ����, ����� ��������� �������������� ���� ������)

// �������������� ��������� (�������) ���� � �������� (�����)
char *StrLower(char *Str);
char *StrUpper(char *Str);
char *StrInvert(char *Str);
char *StrUpperFirst(char *Str);

// ������ �������������:
// char *str = Format("%d", sum);
// WriteXY(0, 6, Format("%d", sum));
char *Format(const char* frmt, ...);

// ����� ��������� ��������� text � ���������� ������ x, y
// �������� ������� �� ����� �������
int CustomPause(UINT x, UINT y, LPCSTR text);
int CustomPause(LPCSTR text);

// ������ � ���������

struct Coord
{
	double x, y;
public:
	friend istream &operator >>(istream &is, Coord &obj);
	friend ostream &operator <<(ostream &os, const Coord &obj);
};
struct Segment
{
	Coord a, b;
public:
	friend istream &operator >>(istream &is, Segment &obj);
	friend ostream &operator <<(ostream &os, const Segment &obj);
};

class Checkpoint
{
	uint size = 0;
	COORD *points;
public:
	Checkpoint() : points(new COORD[size + 1]) {}
	Checkpoint(const Checkpoint &obj);
	~Checkpoint() { delete[]points; }
	const void operator++(int);
	COORD &operator[](int i);
};

// ����� ����������� �������� �������/������
namespace test
{
	UINT getUINT(int nparams, char *prompt, ...);
	int Random(int nparams, ...);

	class Latency
	{
		SYSTEMTIME p_start;
		SYSTEMTIME p_end;
		bool order;
	public:
		inline Latency() : order(false) { GetSystemTime(&p_start); }
		inline void End() { GetSystemTime(&p_end); order = true; }
		UINT getLatency();
	};
}

// ������� ��� ������ ���������� ��������� ��������, �������
// ��� � �� ����������� ���������� � ���������� STL ����������.
template<class _InIt, class _Ty>
inline _InIt rfind(_InIt _First, _InIt _Last, const _Ty& _Val)
{	// find last matching _Val
	_DEBUG_RANGE(_First, _Last);
	_InIt res;
	for (_InIt i = _First; i != _Last; i++)
		if (*i == _Val) res = i;
	return res;
} // rfind