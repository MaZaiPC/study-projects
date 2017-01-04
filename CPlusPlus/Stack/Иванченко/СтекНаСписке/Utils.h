/*	���������� UTILS

	��������:
		��� ���������� ���������� �������, ������� ����� ����������� � ���������� ���������,
		� ��� ����� � ��������� �������������� �������.
	
	������ ���������:
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

	�������� ������� API:

		// ������� INIT //

			void init();

		��������:
			��������� ��������� ��������� ����� ���:
				� ���������
					1251 - �������� �� ���������

				� �������������� ������:
					- fixed
					- precision = 3
					- boolalpha

				� ��������� ������:
					- cbSize		:	������
					- nFont			:	�����
					- dwFontSize	:	������ ������ � �������
					- FontFamily	:	��������� ������
					- FontWeight	:	��� ������ (FW_NORMAL, FW_BOLD)

				� ��������� ��������� ���� �������
					SetConsoleTitle(_T("��������� ����"));

				� ��������� ������� �������:
					SetWindow(������, ������);

		// ������� SET WINDOW //

			void SetWindow(int Width, int Height, WORD Attrib = 0x1f);

		��������:
			� Width		-	������
			� Height	-	������
			� Attrib	-	����

		��������:
			������������� ������ ���� �������, ������� ������ �������, ���� �������.
		
		// ������� RANDOM //

			int Random(int a, int b);

		����������:
			double Random(double a, double b);
			char Random(char a, char b);
		��������:
			� a	- ���������� ���������� �����
			� b	- ����������� ���������� �����
		��������:
			���������� ��������� �������� � ��������� �� a �� b.

		// ������� IS LEAP YEAR //

			bool isLeap(WORD year);

		��������:
			� year - ���

		��������:
			���������� true ���� ��� �������� ����������.

		// ������� LAST DAY //
		
			WORD LastDay(WORD month, WORD year);

		��������:
			� month - �����
			� year - ���

		��������:
			���������� ��������� ���� � ������.

		// ������� GET UINT //
		
			UINT getUINT(char *prompt, UINT min, UINT max);

		��������:
			� *promt	-	���������
			� min		-	����������� �����
			� max		-	������������ �����

		��������:
			��������� ��������� �� ����� � ���������� ��������� (�� min �� max).

		// ������� WRAP //

			void Wrap(int n);

		��������:
			� n	- ���������� ��������� ������

		��������:
			������ �������� ������ � ���������� n.
		
		// COLORS //

		Black		-	������
		Blue		-	�����
		Green		-	�����-�������
		Cyan		-	�����-���������
		Red			-	�����-�������
		Magenta		-	����������
		Yellow		-	�����-������
		Grey		-	�����
		White		-	�����
		LtBlue		-	�������
		LtGreen		-	�������
		LtCyan		-	���������
		LtRed		-	�������
		LtMagenta	-	�������
		LtYellow	-	������
		LtWhite		-	����-�����

		// ������� ������ � ������ //

			void SetBkColor(CColor color);
			void SetForeColor(CColor color);

		��������:
			� color - ����

		�������� �� ���������:
			BkColor::color	 = Black
			ForeColor::color = Grey

		��������:
			� SetBkColor :>
				������������� ���� ����.

			� SetForeColor :>
				������������� ���� ������.

		// ������� CLEAR //

			void Clear(char fill);

		��������:
			� fill - ���������� ��������

		�������� �� ���������:
			fill = ' ' (������)

		��������:
			������� �����.

		// ������� GO TO X,Y //

			void GotoXY(UINT x, UINT y);

		��������:
			� x - ����������
			� y - ����������

		��������:
			��������� ���������� ������ � ������� XY �� ������.

		// ������� WRITE TO X,Y //

			void WriteXY(UINT x, UINT y, char *text);

		����������:
			void WriteXY(UINT x, UINT y, string text);

		��������:
			� x		-	����������
			� y		-	����������
			� text	-	�����, ��������� �� ����� ��������� XY

		��������:
			������� ����� � ������� XY �� ������.

		// ������� WHERE X,Y //

			COORD WhereXY();

		������������ ��������:
			� X	- ����������
			� Y	- ����������

		��������:
			���������� X � Y ���������� ������� ������� ����������� �������.
		
		������ �������������:
			int x = WhereXY().X;
			int y = WhereXY().Y;
			cout << x << y;
			
			COORD crd = WhereXY();
			cout << crd.X << crd.Y;

		// ������� MARKED TEXT //

			void tMark(char* text, int border = 1, CColor sClr = LtYellow, CColor eClr = LtWhite, WORD wp = 0);
			void tMark(string text, int border = 1, CColor sClr = LtYellow, CColor eClr = LtWhite, WORD wp = 0);

		����������:
			void tMark(char* text, int border, WORD wp);
			void tMark(char* text, int border, CColor sClr, WORD wp);
			void tMark(char* text, CColor sClr, CColor eClr);
			void tMark(char* text, CColor sClr);
			void tMark(string text, int border, WORD wp);
			void tMark(string text, int border, CColor sClr, WORD wp);
			void tMark(string text, CColor sClr, CColor eClr);
			void tMark(string text, CColor sClr);

		��������:
			� text		-	���������� �����
			� border	-	������������ ������� (�������� �� 0-�� �� 2-�)
			� sClr		-	���� ����������� ������
			� eClr		-	�������� ���� ����������� ������
			� wp		-	���������� �������� ����� ������������ �������
		
		�������� �� ���������:
			border	=	1
			sClr	=	LtYellow
			eClr	=	LtWhite
			wp		=	0

		��������:
			������� ����� ����� sClr, � ����������� ��������� �� ��������� border,
			� ���-��� ��������� ������ wp ����� ������������ �������.
		
		�������� border:
		0 = none
		1 =  <...>
		2 = <<...>>

		// ������� ���������� ��������� //

			char *StrLower(char *Str);
			char *StrUpper(char *Str);
			char *StrInvert(char *Str);
			char *StrUpperFirst(char *Str);
	
		��������:
			� *Str - ��������� �� ���������� char

		��������:
			� StrLower :>
				������������� ��������� � �������� �����.

			� StrUpper :>
				������������� �������� � ��������� �����.

			� StrUpperFirst :>
				������������� ������ ����� ������ � �������.

			� StrInvert :>
				����������� ������� ����.

		// ������� FORMAT TO STRING //

			string Format(const char* frmt, ...);

		��������:
			� frmt - ������ ��� �������������� + ������� ��������������
			� agrs - ����������

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

		��������:
			�������������� � string ���������� ������ �����.

		������ �������������:
			std::string str = Format( "%d", sum );

		// ������� WRAP //

		void Wrap(UINT n);

		��������:
			��������� ������ n ���.

		// ������� FILL CHAR //

		void Fill(char symbol, UINT n);

		��������:
			��������� ������ �������� char � ���������� n.

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
char Random(char a, char b);

bool isLeap(WORD year);
WORD LastDay(WORD month, WORD year);

UINT getUINT(char *prompt, UINT min = 0, UINT max = UINT_MAX);
namespace test
{
	UINT getUINT(int nparams, char *prompt, ...);
}

void Wrap(UINT n);
void Fill(char symbol, UINT n);

// ��� ������ - ������������ ��� ������� ����� � �������
enum CColor {
	Black, Blue, Green, Cyan, Red, Magenta, Yellow, Grey, 
	White, LtBlue, LtGreen, LtCyan, LtRed, LtMagenta, LtYellow, LtWhite
};

// ������� ��� ���������� ������ � �������
void Color(char *color);
void SetBkColor(CColor color = Black);
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

// �������������� � string
// ������ �������������:
// std::string str = Format( "%d", sum );
string Format(const char* frmt, ...);

// ����� ��������� ��������� text � ���������� ������ x, y
// �������� ������� �� ����� �������
int CustomPause(UINT x, UINT y, LPCSTR text);

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