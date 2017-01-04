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

void Wrap(int n);

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
COORD WhereXY();

void CustomPause(UINT x, UINT y, char *text);
void CustomPause(UINT x, UINT y, string text);

// ���������/������� �����

// ����������
// ���� �������� border �� �� ��������� (!0), ��� �� ����� ������� ���������� �������� ����� �������.
void tMark(char* text, int border, WORD wp);
void tMark(char* text, int border, CColor sClr, WORD wp);
void tMark(char* text, CColor sClr, CColor eClr);
void tMark(char* text, CColor sClr);
void tMark(string text, int border, WORD wp);
void tMark(string text, int border, CColor sClr, WORD wp);
void tMark(string text, CColor sClr, CColor eClr);
void tMark(string text, CColor sClr);
// ������ ���������
void tMark(char* text, int border = 1, CColor sClr = LtYellow, CColor eClr = LtWhite, WORD wp = 0);
void tMark(string text, int border = 1, CColor sClr = LtYellow, CColor eClr = LtWhite, WORD wp = 0);
// ���:
// border - �������-��������� (��� ������� ��� ���������� ���������)
// sClr � eClr - ��������� � �������� ���� ������ (�������� - ��������� ����, ����� ��������� �������������� ���� ������)
// wp - ���������� �������� ����� �������

// �������������� ��������� (�������) ���� � �������� (�����)
char *StrLower(char *Str);
char *StrUpper(char *Str);
char *StrInvert(char *Str);
char *StrUpperFirst(char *Str);

// �������������� � string
// ������ �������������:
// std::string str = Format( "%d", sum );
string Format(const char* frmt, ...);
