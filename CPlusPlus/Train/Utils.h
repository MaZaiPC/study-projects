#pragma once
#include "stdafx.h"

void init();
void SetWindow(int Width, int Height, WORD Attrib = 0x1f);

double Random(double a, double b);
int Random(int a, int b);
char Random(char a, char b);

bool isLeap(WORD year);
WORD LastDay(WORD month, WORD year);

UINT getUINT(char *prompt, UINT min = 0, UINT max = UINT_MAX);


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
void WriteXY(UINT x, UINT y, char *text);
void WriteXY(UINT x, UINT y, string text);
// COORD WhereXY();

// ���������/������� �����

// ����������
void tMark(char* text);
void tMark(char* text, int border);
void tMark(char* text, int border, CColor sClr);
void tMark(char* text, CColor sClr, CColor eClr);
void tMark(char* text, CColor sClr);
void tMark(string text);
void tMark(string text, int border);
void tMark(string text, int border, CColor sClr);
void tMark(string text, CColor sClr, CColor eClr);
void tMark(string text, CColor sClr);
// ������ ���������
void tMark(char* text, int border, CColor sClr, CColor eClr);
void tMark(string text, int border, CColor sClr, CColor eClr);

// �������������� ��������� (�������) ���� � �������� (�����)
char *StrLower(char *Str);
char *StrUpper(char *Str);
char *StrInvert(char *Str);
char *StrUpperFirst(char *Str);

// �������������� � string
// ������ �������������:
// std::string str = Format( "%d", sum );
string Format(const char* frmt, ...);

