#pragma once
#include "stdafx.h"

void init(string head);
void SetWindow(int Width, int Height, WORD Attrib = 0x1f);

double Random(double a, double b);
int Random(int a, int b);

bool isLeap(WORD year);
WORD LastDay(WORD month, WORD year);

UINT getUINT(char *prompt, UINT min = 0, UINT max = UINT_MAX);


// Тип данных - перечисление для задания цвета в консоли
enum CColor {
	Black, Blue, Green, Cyan, Red, Magenta, Yellow, Grey, 
	White, LtBlue, LtGreen, LtCyan, LtRed, LtMagenta, LtYellow, LtWhite
};

// Функции для управления цветом в консоли
void Color(char *color);
void SetBkColor(CColor color = Black);
void SetForeColor(CColor color = Grey);
void Clear(char fill = ' ');
void GotoXY(UINT x, UINT y);
void WriteXY(UINT x, UINT y, char *text);
// ‡аголовки/–ветной текст
void h1(string text, CColor sClr = Yellow, CColor eClr = White);
void h2(string text, CColor sClr = Yellow, CColor eClr = White);
void h3(string text, CColor sClr = Yellow, CColor eClr = White);

// преобразование прописных (больших) букв в строчные (малые)
char *StrLower(char *Str);

