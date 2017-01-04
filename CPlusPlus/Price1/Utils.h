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

// Функции управления консольным курсором
void GotoXY(UINT x, UINT y);
void WriteXY(UINT x, UINT y, char *text);
void WriteXY(UINT x, UINT y, string text);
COORD WhereXY();

void CustomPause(UINT x, UINT y, char *text);
void CustomPause(UINT x, UINT y, string text);

// Заголовки/цветной текст

// Перегрузки
// Если параметр border не по умолчанию (!0), так же можно указать количество пробелов после границы.
void tMark(char* text, int border, WORD wp);
void tMark(char* text, int border, CColor sClr, WORD wp);
void tMark(char* text, CColor sClr, CColor eClr);
void tMark(char* text, CColor sClr);
void tMark(string text, int border, WORD wp);
void tMark(string text, int border, CColor sClr, WORD wp);
void tMark(string text, CColor sClr, CColor eClr);
void tMark(string text, CColor sClr);
// Полные параметры
void tMark(char* text, int border = 1, CColor sClr = LtYellow, CColor eClr = LtWhite, WORD wp = 0);
void tMark(string text, int border = 1, CColor sClr = LtYellow, CColor eClr = LtWhite, WORD wp = 0);
// Где:
// border - Граница-украшение (как правило для стилизации заголовка)
// sClr и eClr - Начальный и конечный цвет текста (конечный - временная мера, чтобы выставить первоначальный цвет текста)
// wp - количество отступов после границы

// преобразование прописных (больших) букв в строчные (малые)
char *StrLower(char *Str);
char *StrUpper(char *Str);
char *StrInvert(char *Str);
char *StrUpperFirst(char *Str);

// Преобразование в string
// Пример использования:
// std::string str = Format( "%d", sum );
string Format(const char* frmt, ...);
