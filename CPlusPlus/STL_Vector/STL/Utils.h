/*	БИБЛИОТЕКА UTILS

	Описание:
		Эта библиотека объединяет функции, которые часто повторяются в программах студентов,
		в том числе и различные дополнительные функции.
	
	Список изменений:
		2015.11.28 :>
			• Добавлена шаблонная функция <T>Random(T a,T b).
			• Добавлен класс test::Latency - вычисляющий примерную задержку в исполнении определенного участка кода (ms).
			• Функция Format(...) - тип возвращаемого значения заменен с string на char* в связи с простотой
			  преобразования char* в string.
			• Функция SetBkColor(..) переименована в SetBgColor(..) в связи с большей информативнотью нового названия.
		2015.11.18 :>
			• Добавлена перегрузка функции GotoXY(...), принимающая одно значение типа COORD.
			• Добавлен класс Checkpoint. Позволяющий делать чекпоинты координат курсора, для дальнейшего
			  возврата в соответствующую позицию функцией GotoXY.
			• Добавлен класс Coord(double x, double y) + Перегруженные потоковые операции. Так же отличается от стандартного
			  COORD осями типа double.
			• Добавлен класс Segment(Coord x, Coord y) + Перегруженные потоковые операции.
			• Добавлен тестовый вариант функции getUINT(...) в пространство имен test, разница в том что он принимает только
			  определенные значения, указать которые нужно в месте вызова, в списке параметров функции.
			• Фикс функции getUINT(...), теперь после ввода неверного значения меню не дублируется ниже а заменяет старое.
		2015.11.03 :>
			• Удалены ненужные параметры из tMark (оптимизировано).
			• Добавлены синонимы для длинных типов данных:
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
			• Добавлена функция Fill(...), заполняющая строку символом char в количестве n.
			• Переделана функция CustomPause(...)
				- Реализовано через _getch()
				- Теперь функция возвращает код нажатой клавиши
				- После нажатия клавиши текст удаляется автоматически
			• Незначительные фиксы

		2015.09.18 :>
			• Библиотека больше не требует HANDLE h, расположенный в main.cpp.
			• Добавлена функция CustomPause(...), устанавливающая в позицию XY паузу с вашим текстом описания.
			• Незначительные фиксы

		2015.09.16 :>
			• Добавлена функция WhereXY() для получения координат текущей позиции консольного курсора
			• Оптимизирована функция tMark(...), удалены лишние перегрузки, задействованы параметры функции
			  по умолчанию

		2015.09.13 :>
			• Добавлена функция Format(.., agrs) для преобразования в string
			• Добавлена функция Wrap(..) для переноса строк консоли в количестве N
			• Улучшена функция tMark(...),
			  добавлены перегрузки + поддержка string.

		2015.09.9 :>
			• Добавлены функции изменения регистра текста:
				- StrUpper()
				- StrInvert()
				- StrUpperFirst()
			• Добавлена функция tMark()

		Ранее :>
			• Создана библиотека
			• Добавлены основные функции:
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
	
	Подсказки:
		Команды форматирования:
			%с	Символ типа char
			%d	Десятичное число целого типа со знаком
			%i	Десятичное число целого типа со знаком
			%е	Научная нотация (е нижнего регистра)
			%Е	Научная нотация (Е верхнего регистра)
			%f	Десятичное число с плавающей точкой
			%g	Использует код %е или %f — тот из них, который короче
				(при использовании %g используется е нижнего регистра)
			%G	Использует код %Е или %f — тот из них, который короче
				(при использовании %G используется Е верхнего регистра)
			%о	Восьмеричное целое число без знака
			%s	Строка символов
			%u	Десятичное число целого типа без знака
			%х	Шестнадцатиричное целое число без знака (буквы нижнего регистра)
			%Х	Шестнадцатиричное целое число без знака (буквы верхнего регистра)
			%р	Выводит на экран значение указателя
			%n	Ассоциированный аргумент — это указатель на переменную целого типа,
				в которую помещено количество символов, записанных на данный момент
			%%	Выводит символ %

		Кроме того, к командам формата могут быть применены модификаторы l и h:
			%ld	 печать long int
			%hu  печать short unsigned
			%Lf  печать long double
*/

#pragma once
#include "stdafx.h"

using namespace std;

/************СОКРАЩЕНИЯ*************/
typedef unsigned char		uchar;
typedef unsigned int		uint;
typedef unsigned short		ushort;
typedef unsigned short int	usint;

typedef short int			sint;

typedef long double			ldouble;
typedef long int			lint;
typedef long long int		llint;

/**************ФУНКЦИИ**************/


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

// Тип данных - перечисление для задания цвета в консоли
enum CColor {
	Black, Blue, Green, Cyan, Red, Magenta, Yellow, Grey,
	White, LtBlue, LtGreen, LtCyan, LtRed, LtMagenta, LtYellow, LtWhite
};

// Функции для управления цветом в консоли
void Color(char *color);
void SetBgColor(CColor color = Black);
void SetForeColor(CColor color = Grey);
void Clear(char fill = ' ');

// Функции управления консольным курсором
void GotoXY(UINT x, UINT y);
void GotoXY(COORD coord);
void WriteXY(UINT x, UINT y, char *text);
void WriteXY(UINT x, UINT y, string text);
COORD WhereXY();

// Заголовки/цветной текст
void tMark(char* text, CColor sClr = LtYellow, CColor eClr = LtWhite);
void tMark(string text, CColor sClr = LtYellow, CColor eClr = LtWhite);
// Где:
// sClr и eClr - Начальный и конечный цвет текста (конечный - временная мера, чтобы выставить первоначальный цвет текста)

// преобразование прописных (больших) букв в строчные (малые)
char *StrLower(char *Str);
char *StrUpper(char *Str);
char *StrInvert(char *Str);
char *StrUpperFirst(char *Str);

// Пример использования:
// char *str = Format("%d", sum);
// WriteXY(0, 6, Format("%d", sum));
char *Format(const char* frmt, ...);

// Вывод заданного сообщения text в координаты экрана x, y
// Ожидание нажатия на любую клавишу
int CustomPause(UINT x, UINT y, LPCSTR text);
int CustomPause(LPCSTR text);

// Классы и структуры

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

// Здесь размещаются тестовые функции/классы
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

// Функция для поиска последнего вхождения значения, которую
// так и не потрудились разместить в библиотеку STL алгоритмов.
template<class _InIt, class _Ty>
inline _InIt rfind(_InIt _First, _InIt _Last, const _Ty& _Val)
{	// find last matching _Val
	_DEBUG_RANGE(_First, _Last);
	_InIt res;
	for (_InIt i = _First; i != _Last; i++)
		if (*i == _Val) res = i;
	return res;
} // rfind