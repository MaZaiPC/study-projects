#include "stdafx.h"
#include "Utils.h"

extern HANDLE h;

// внутренняя глобальная переменная для хранения атрибута знакоместа
WORD wColor = Black << 4 | Grey;


// Подготовка приложения к работе
void init() 
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	srand(GetTickCount());
	cout << fixed << setprecision(2) << boolalpha;

	h = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX cfi;
	
	cfi.cbSize       = sizeof cfi;
	cfi.nFont        = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 20;  // размер шрифта в пунктах
	cfi.FontFamily   = FF_DONTCARE;
	cfi.FontWeight   = FW_NORMAL /* FW_BOLD */;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(h, FALSE, &cfi);

	// Установить заголовок окна консоли
	// Текст заголовка - в кодировке UNICODE
	// L"текст" или _T("текст")
	SetConsoleTitle(_T("ООП и консоль cout с цветом"));

	// Установить размер окна консоли
	SetWindow(80, 25);
} // init


// Установить размер окна консоли, размеры буфера консоли, цвет консоли
void SetWindow(int Width, int Height, WORD Color)
{
	// Параметры буфера консоли
	COORD coord;
	coord.X = Width;   // ширина
	coord.Y = 300;     // высота буфера по умолчанию

	SMALL_RECT Rect;   // Размеры окна консоли - прямоугольник
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;   // высота окна
	Rect.Right = Width - 1;     // ширина окна

	SetConsoleScreenBufferSize(h, coord);  // Установить размер буфера консоли
	SetConsoleWindowInfo(h, TRUE, &Rect);  // Установить размер окна консоли

	// Установить цвет окна консоли
	wColor = Color;
	SetConsoleTextAttribute(h, wColor);

	COORD start = { 0, 0 };
	DWORD done;
	FillConsoleOutputAttribute(h, wColor, Width*coord.Y, start, &done);
} // SetWindow


double Random(double a, double b) {
	return a + (b - a) * rand() / (RAND_MAX + 1);
} // Random


int Random(int a, int b) {
	return a + rand() % (b - a + 1);
} // Random


WORD LastDay(WORD month, WORD year)
{
	WORD days[] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	if (isLeap(year)) days[1]++;

	return days[month - 1];
} // LastDay


bool isLeap(WORD year)
{
	if (year % 4 != 0) return false;
	if (year % 100 == 0 && year % 400 != 0) return false;
	return true;
} // isLeap


UINT getUINT(char *prompt, UINT min, UINT max)
{
	UINT x;
	while(true) {
		cout << prompt;
		cin >> x;
		
		// Проверка корректности типа ввода
		if (cin.fail()) {
			cin.clear();   // сброс ошибки ввода для потока
			cin.ignore();  // ???
			cerr << "\nОШИБКА: Вводите число, не символы.\n\n";
			_flushall();   // очистка буфера ввода
			continue;
		} // if

		// Если число не принадлежит диапазону допустимых значений,
		// сообщить об ошибке и повторить ввод
		if (x < min || x > max) {
			cerr << "\nОШИБКА: число должно быть в диапазоне от "
				<< min << " до " << max << ".\n\n";
			continue;
		} // if

		// Если оказались тут - число в корректном диапазоне
		// выполним сброс буфера ввода - почистим все символы после команды
		_flushall();
		break;
	} // while

	return x;
} // getUINT




// Функция для управления цветом в консоли
void Color(char *color)
{
	// Все это будет на синем фоне
	const WORD BLACK = BACKGROUND_BLUE;		// Черный
	const WORD BLUE = FOREGROUND_BLUE + FOREGROUND_INTENSITY + BACKGROUND_BLUE;						// Синий
	const WORD GREEN = FOREGROUND_GREEN + FOREGROUND_INTENSITY + BACKGROUND_BLUE;					// Зеленый
	const WORD CYAN = FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY + BACKGROUND_BLUE;	// Голубой
	const WORD RED = FOREGROUND_RED + FOREGROUND_INTENSITY + BACKGROUND_BLUE;						// Красный
	const WORD PURPLE = FOREGROUND_RED + FOREGROUND_BLUE + FOREGROUND_INTENSITY + BACKGROUND_BLUE;	// Лиловый, фиолетовый
	const WORD YELLOW = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_INTENSITY + BACKGROUND_BLUE;	// Желтый
	const WORD WHITE = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY + BACKGROUND_BLUE;	// Белый
	const WORD GRAY = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE + BACKGROUND_BLUE;		// Серый
	

	// Все это будет на черном фоне
/*	const WORD BLACK = 0;		// Черный
	const WORD BLUE = FOREGROUND_BLUE + FOREGROUND_INTENSITY;										// Синий
	const WORD GREEN = FOREGROUND_GREEN + FOREGROUND_INTENSITY;										// Зеленый
	const WORD CYAN = FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY;					// Голубой
	const WORD RED = FOREGROUND_RED + FOREGROUND_INTENSITY;											// Красный
	const WORD PURPLE = FOREGROUND_RED + FOREGROUND_BLUE + FOREGROUND_INTENSITY;					// Лиловый, фиолетовый
	const WORD YELLOW = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_INTENSITY;					// Желтый
	const WORD WHITE = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY;	// Белый
	const WORD GRAY = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE;							// Серый
*/	



	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	const int N = 9;
	char *setcolor[] = { "black", "blue", "green", "cyan", "red", "purple", "yellow", "white", "gray" };
	int action;

	char *temp = new char[strlen(color) + 1];
	strcpy(temp, color);
	StrLower(temp);

	for (int i = 0; i < N; i++) {
		if (strcmp(temp, setcolor[i]) == 0) {
			action = i;
			break;
		} else
			action = -1;
	} // for i

	switch (action) {
	case 0:
		SetConsoleTextAttribute(h, BLACK);
		break;
	case 1:
		SetConsoleTextAttribute(h, BLUE);
		break;
	case 2:
		SetConsoleTextAttribute(h, GREEN);
		break;
	case 3:
		SetConsoleTextAttribute(h, CYAN);
		break;
	case 4:
		SetConsoleTextAttribute(h, RED);
		break;
	case 5:
		SetConsoleTextAttribute(h, PURPLE);
		break;
	case 6:
		SetConsoleTextAttribute(h, YELLOW);
		break;
	case 7:
		SetConsoleTextAttribute(h, WHITE);
		break;
	case 8:
		SetConsoleTextAttribute(h, GRAY);
		break;
	default:
		SetConsoleTextAttribute(h, RED);
		cout << "\nОшибка! Заданый цвет не найлен" << endl;
		SetConsoleTextAttribute(h, GRAY);
		break;
	} // switch


	delete[] temp;

} // Color


  // преобразование прописных (больших) букв в строчные (малые)
char *StrLower(char *Str)
{
	int i = 0;
	while (Str[i] != '\0') {
		if ((Str[i] >= 'A' && Str[i] <= 'Z') || (Str[i] >= 'А' && Str[i] <= 'Я'))
			Str[i] += 32;
		i++;
	} // while

	return Str;
} // StrLower


// Задать цвет фона консоли
void SetBkColor(CColor color)
{
	wColor &= 0x0f;
	wColor |= (color << 4);
	SetConsoleTextAttribute(h, wColor);
} // SetBkColor


// Задать цвет символов консоли
void SetForeColor(CColor color)
{
	wColor &= 0xf0;
	wColor |= color;
	SetConsoleTextAttribute(h, wColor);
} // SetForeColor


// Очистка экрана консоли - заполнение буфера консоли символом "пробел"
// с атрибутом wColor, перемещение курсора в начало экрана
void Clear(char fill)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(h, &info);

	// Установить цвет окна консоли
	SetConsoleTextAttribute(h, wColor);

	COORD start = { 0, 0 };
	DWORD done;
	DWORD nLength = info.dwSize.X * info.dwSize.Y;
	FillConsoleOutputAttribute(h, wColor, nLength, start, &done);
	FillConsoleOutputCharacterA(h, fill, nLength, start, &done);

	// Переход курсора в начало экрана
	GotoXY(0, 0);
} // Clear


// Вывод текста в заданную позицию курсора
void WriteXY(UINT x, UINT y, char *text)
{
	GotoXY(x, y);
	cout << text;
} // WriteXY


// Позиционирование курсора в заданную позицию экрана
void GotoXY(UINT x, UINT y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(h, coord);
} // GotoXY