/*	БИБЛИОТЕКА UTILS

	Описание:
		Эта библиотека объединяет функции, которые часто повторяются в программах студентов,
		в том числе и различные дополнительные функции.
	
	Список изменений:
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

	Описание функций API:

		// Функция INIT //

			void init();

		Описание:
			Применяет стартовые настройки такие как:
				• Кодировка
					1251 - значение по умолчанию

				• Форматирование текста:
					- fixed
					- precision = 3
					- boolalpha

				• Настройка шрифта:
					- cbSize		:	размер
					- nFont			:	шрифт
					- dwFontSize	:	размер шрифта в пунктах
					- FontFamily	:	семейство шрифта
					- FontWeight	:	тип шрифта (FW_NORMAL, FW_BOLD)

				• Установка заголовка окна консоли
					SetConsoleTitle(_T("Заголовок окна"));

				• Установка размера консоли:
					SetWindow(Ширина, Высота);

		// Функция SET WINDOW //

			void SetWindow(int Width, int Height, WORD Attrib = 0x1f);

		Атрибуты:
			• Width		-	ширина
			• Height	-	высота
			• Attrib	-	цвет

		Описание:
			Устанавливает размер окна консоли, размеры буфера консоли, цвет консоли.
		
		// Функция RANDOM //

			int Random(int a, int b);

		Перегрузки:
			double Random(double a, double b);
			char Random(char a, char b);
		Атрибуты:
			• a	- минимально допустимое число
			• b	- максимально допустимое число
		Описание:
			Возвращает случайное значение в диапазоне от a до b.

		// Функция IS LEAP YEAR //

			bool isLeap(WORD year);

		Атрибуты:
			• year - год

		Описание:
			Возвращает true если год является високосным.

		// Функция LAST DAY //
		
			WORD LastDay(WORD month, WORD year);

		Атрибуты:
			• month - месяц
			• year - год

		Описание:
			Возвращает последний день в месяце.

		// Функция GET UINT //
		
			UINT getUINT(char *prompt, UINT min, UINT max);

		Атрибуты:
			• *promt	-	подсказка
			• min		-	минимальное число
			• max		-	максимальное число

		Описание:
			Проверяет находится ли число в корректном диапазоне (от min до max).

		// Функция WRAP //

			void Wrap(int n);

		Атрибуты:
			• n	- количество переносов строки

		Описание:
			Делает переносы строки в количестве n.
		
		// COLORS //

		Black		-	Черный
		Blue		-	Синий
		Green		-	Темно-зеленый
		Cyan		-	Темно-бирюзовый
		Red			-	Темно-красный
		Magenta		-	Фиолетовый
		Yellow		-	Темно-желтый
		Grey		-	Белый
		White		-	Серый
		LtBlue		-	Голубой
		LtGreen		-	Зеленый
		LtCyan		-	Бирюзовый
		LtRed		-	Красный
		LtMagenta	-	Розовый
		LtYellow	-	Желтый
		LtWhite		-	Ярко-белый

		// Функции работы с цветом //

			void SetBkColor(CColor color);
			void SetForeColor(CColor color);

		Атрибуты:
			• color - цвет

		Значения по умолчанию:
			BkColor::color	 = Black
			ForeColor::color = Grey

		Описание:
			• SetBkColor :>
				Устанавливает цвет фона.

			• SetForeColor :>
				Устанавливает цвет текста.

		// Функция CLEAR //

			void Clear(char fill);

		Атрибуты:
			• fill - заполнение символом

		Значения по умолчанию:
			fill = ' ' (пробел)

		Описание:
			Очищает экран.

		// Функция GO TO X,Y //

			void GotoXY(UINT x, UINT y);

		Атрибуты:
			• x - координата
			• y - координата

		Описание:
			Переводит консольный курсор в позицию XY на экране.

		// Функция WRITE TO X,Y //

			void WriteXY(UINT x, UINT y, char *text);

		Перегрузки:
			void WriteXY(UINT x, UINT y, string text);

		Атрибуты:
			• x		-	координата
			• y		-	координата
			• text	-	текст, выводимый по месту координат XY

		Описание:
			Выводит текст в позицию XY на экране.

		// Функция WHERE X,Y //

			COORD WhereXY();

		Возвращаемые значения:
			• X	- координата
			• Y	- координата

		Описание:
			Возвращает X и Y координаты текущей позиции консольного курсора.
		
		Пример использования:
			int x = WhereXY().X;
			int y = WhereXY().Y;
			cout << x << y;
			
			COORD crd = WhereXY();
			cout << crd.X << crd.Y;

		// Функция MARKED TEXT //

			void tMark(char* text, int border = 1, CColor sClr = LtYellow, CColor eClr = LtWhite, WORD wp = 0);
			void tMark(string text, int border = 1, CColor sClr = LtYellow, CColor eClr = LtWhite, WORD wp = 0);

		Перегрузки:
			void tMark(char* text, int border, WORD wp);
			void tMark(char* text, int border, CColor sClr, WORD wp);
			void tMark(char* text, CColor sClr, CColor eClr);
			void tMark(char* text, CColor sClr);
			void tMark(string text, int border, WORD wp);
			void tMark(string text, int border, CColor sClr, WORD wp);
			void tMark(string text, CColor sClr, CColor eClr);
			void tMark(string text, CColor sClr);

		Атрибуты:
			• text		-	выделяемый текст
			• border	-	декоративная граница (значение от 0-ля до 2-х)
			• sClr		-	цвет выделяемого текста
			• eClr		-	основной цвет консольного текста
			• wp		-	количество отступов после декоративной границы
		
		Значения по умолчанию:
			border	=	1
			sClr	=	LtYellow
			eClr	=	LtWhite
			wp		=	0

		Описание:
			Выводит текст цвета sClr, с стилизацией заголовка по умолчанию border,
			с кол-вом переносов строки wp после декоративной границы.
		
		Варианты border:
		0 = none
		1 =  <...>
		2 = <<...>>

		// Функции управления регистром //

			char *StrLower(char *Str);
			char *StrUpper(char *Str);
			char *StrInvert(char *Str);
			char *StrUpperFirst(char *Str);
	
		Атрибуты:
			• *Str - указатель на переменную char

		Описание:
			• StrLower :>
				Преобразовует ПРОПИСНЫЕ в строчные буквы.

			• StrUpper :>
				Преобразовует строчные в ПРОПИСНЫЕ буквы.

			• StrUpperFirst :>
				Преобразовует первую букву строки в большую.

			• StrInvert :>
				Инвертирует регистр букв.

		// Функция FORMAT TO STRING //

			string Format(const char* frmt, ...);

		Атрибуты:
			• frmt - строка для форматирования + команды форматирования
			• agrs - переменные

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

		Описание:
			Преобразование в string переменных других типов.

		Пример использования:
			std::string str = Format( "%d", sum );

		// Функция WRAP //

		void Wrap(UINT n);

		Описание:
			Переносит строку n раз.

		// Функция FILL CHAR //

		void Fill(char symbol, UINT n);

		Описание:
			Заполняет строку символом char в количестве n.

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

// Преобразование в string
// Пример использования:
// std::string str = Format( "%d", sum );
string Format(const char* frmt, ...);

// Вывод заданного сообщения text в координаты экрана x, y
// Ожидание нажатия на любую клавишу
int CustomPause(UINT x, UINT y, LPCSTR text);

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