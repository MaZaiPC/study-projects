#include "stdafx.h"
#include "Utils.h"

HANDLE h;

// внутренняя глобальная переменная для хранения атрибута знакоместа
WORD wColor = Black << 4 | Grey;


// Подготовка приложения к работе
void init() 
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(GetTickCount());
	cout << fixed << setprecision(3) << boolalpha;

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
	SetConsoleTitle(_T("ООП: Лаптев В.В., задача 32. Банковский аккаунт."));

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

char Random(char a, char b) {
	return a + rand() % (b - a + 1);
} // Random

void Wrap(UINT n)
{
	if (n > 0) n++;
	for (UINT i = 1; i < n; i++)
	{
		cout << endl;
	}
}

void Fill(char symbol, UINT n)
{
	if (n > 0) n++;
	for (UINT i = 1; i < n; i++)
	{
		cout << symbol;
	}
}

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
			system("pause");
			Clear();
			continue;
		} // if

		// Если число не принадлежит диапазону допустимых значений,
		// сообщить об ошибке и повторить ввод
		if (x < min || x > max) {
			cerr << "\nОШИБКА: число должно быть в диапазоне от "
				<< min << " до " << max << ".\n\n";
			system("pause");
			Clear();
			continue;
		} // if

		// Если оказались тут - число в корректном диапазоне
		// выполним сброс буфера ввода - почистим все символы после команды
		_flushall();
		break;
	} // while

	return x;
} // getUINT

UINT test::getUINT(int nparams, char *prompt, ...)
{
	int &n = nparams;
	UINT x;
	while (true) {
		cout << prompt;
		cin >> x;

		// Проверка корректности типа ввода
		if (cin.fail()) {
			cin.clear();   // сброс ошибки ввода для потока
			cin.ignore();  // ???
			cerr << "\nОШИБКА: Вводите число, не символы.\n\n";
			_flushall();   // очистка буфера ввода
			system("pause");
			Clear();
			continue;
		} // if

		  // Если число не принадлежит диапазону допустимых значений,
		  // сообщить об ошибке и повторить ввод
		
		va_list agrs;
		va_start(agrs, nparams);
		bool error = true;
		for (int i = 0; i<n; i++)
		{
			if (i == 0) va_arg(agrs, UINT);
			if (x == va_arg(agrs, UINT)) error = false;
		}
		va_end(agrs);
		if (error) {
			cerr << "\nОШИБКА: допустимые числа";
			va_start(agrs, nparams);
			for (int i = 0; i<n; i++)
			{
				if (i == 0) va_arg(agrs, UINT);
				cerr << " " << va_arg(agrs, UINT);
			}
			va_end(agrs);
			cerr << ".\n\n";
			system("pause");
			Clear();
			continue;
		} // if

		  // Если оказались тут - число в корректном диапазоне
		  // выполним сброс буфера ввода - почистим все символы после команды
		_flushall();
		break;
	} // while

	return x;
}




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
		cout << "\nОшибка! Заданый цвет не найден" << endl;
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

// преобразование строчных (малых) букв в прописные (большие)
char *StrUpper(char *Str)
{
	int i = 0;
	while (Str[i] != '\0') {
		if ((Str[i] >= 'a' && Str[i] <= 'z') || (Str[i] >= 'а' && Str[i] <= 'я'))
			Str[i] -= 32;
		i++;
	} // while

	return Str;
} // StrUpper

// преобразование первой буквы в заглавную
char *StrUpperFirst(char *Str)
{
	int i = 0;
	if ((Str[i] >= 'a' && Str[i] <= 'z') || (Str[i] >= 'а' && Str[i] <= 'я'))
		Str[i] -= 32;

	return Str;
} // StrUpperFirst

// инвертирование регистра строк
char *StrInvert(char *Str)
{
	int i = 0;
	while (Str[i] != '\0') {
		if ((Str[i] >= 'A' && Str[i] <= 'Z') || (Str[i] >= 'А' && Str[i] <= 'Я'))
			Str[i] += 32;
		else if ((Str[i] >= 'a' && Str[i] <= 'z') || (Str[i] >= 'а' && Str[i] <= 'я'))
			Str[i] -= 32;
		i++;
	} // while

	return Str;
} // StrInvert


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

void WriteXY(UINT x, UINT y, string text)
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
	GotoXY(coord);
} // GotoXY

void GotoXY(COORD coord)
{
	SetConsoleCursorPosition(h, coord);
}

COORD WhereXY()
{
	HANDLE hSTDOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	GetConsoleScreenBufferInfo(hSTDOut, &SBInfo);
	return SBInfo.dwCursorPosition;
}

// Выделяет текст цветом (доступно выделение границ текста знаками: < > = 2, << >> = 3)
void tMark(LPSTR text, CColor sClr, CColor eClr)
{
	SetForeColor(sClr);
	cout << text;
	SetForeColor(eClr);
} //tMark

// Перегрузка для string
void tMark(string text, CColor sClr, CColor eClr)
{
	SetForeColor(sClr);
	cout << text;
	SetForeColor(eClr);
} //tMark

string Format(const char* frmt, ...)
{
	static char buf[4096];
	buf[0] = 0;

	va_list args;
	va_start(args, frmt);
	vsnprintf(buf, 4096, frmt, args);
	va_end(args);

	return std::string(buf);
}

int CustomPause(UINT x, UINT y, LPCSTR text)
{
	WriteXY(x, y, text);
	int key = _getch();
	if (!key || key == 224) key = _getch();
	GotoXY(x, y); Fill(' ', strlen(text));
	return key;
} // CustomPause

  /*-------------------------Coord-------------------------*/
istream &operator >>(istream &is, Coord &obj)
{
	Checkpoint cpoint;
	cpoint++; is >> obj.x;
	GotoXY(cpoint[1]); is >> obj.y;
	return is;
}
ostream &operator <<(ostream &os, const Coord &obj)
{
	os << "[" << obj.x << ";" << obj.y << "]";
	return os;
}

/*------------------------Segment------------------------*/
istream &operator >>(istream &is, Segment &obj)
{
	Checkpoint cpoint;
	cpoint++; is >> obj.a;
	GotoXY(cpoint[1]); is >> obj.b;
	return is;
}
ostream &operator <<(ostream &os, const Segment &obj)
{
	os << obj.a << ", " << obj.b;
	return os;
}

/*----------------------Checkpoint-----------------------*/
Checkpoint::Checkpoint(const Checkpoint & obj)
{
	points = new COORD[obj.size + 1];
	for (UINT i = 0; i< obj.size; i++)
		points[i] = obj.points[i];
	size = obj.size;
}

const void Checkpoint::operator++(int)
{
	size++;
	COORD *tmp = new COORD[size + 1];
	for (UINT i = 0; i< size; i++)
		tmp[i] = points[i];
	delete[]points;
	points = new COORD[size + 1];
	for (UINT i = 0; i< size; i++)
		points[i] = tmp[i];
	delete[]tmp;
	points[size] = WhereXY();
}

COORD & Checkpoint::operator[](int i)
{
	return points[i];
}