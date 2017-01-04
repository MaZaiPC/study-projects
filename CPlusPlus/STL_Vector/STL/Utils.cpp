#include "stdafx.h"
#include "Utils.h"

HANDLE h;

// ���������� ���������� ���������� ��� �������� �������� ����������
WORD wColor = Black << 4 | Grey;


// ���������� ���������� � ������
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
	cfi.dwFontSize.Y = 20;  // ������ ������ � �������
	cfi.FontFamily   = FF_DONTCARE;
	cfi.FontWeight   = FW_NORMAL /* FW_BOLD */;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(h, FALSE, &cfi);

	// ���������� ��������� ���� �������
	// ����� ��������� - � ��������� UNICODE
	// L"�����" ��� _T("�����")
	SetConsoleTitle(_T("STL - ���������� ���������."));

	// ���������� ������ ���� �������
	SetWindow(80, 25);
} // init


// ���������� ������ ���� �������, ������� ������ �������, ���� �������
void SetWindow(int Width, int Height, WORD Color)
{
	// ��������� ������ �������
	COORD coord;
	coord.X = Width;   // ������
	coord.Y = 300;     // ������ ������ �� ���������

	SMALL_RECT Rect;   // ������� ���� ������� - �������������
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;   // ������ ����
	Rect.Right = Width - 1;     // ������ ����

	SetConsoleScreenBufferSize(h, coord);  // ���������� ������ ������ �������
	SetConsoleWindowInfo(h, TRUE, &Rect);  // ���������� ������ ���� �������

	// ���������� ���� ���� �������
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

int test::Random(int nparams, ...)
{
	va_list agrs;
	nparams = abs(nparams);
	va_start(agrs, nparams);
	int end = 1 + rand() % (nparams - 1 + 1);
	int result;
	
	for (int i = 0; i < end; i++)
	{
		result = va_arg(agrs, int);
	}
	va_end(agrs);
	return result;
}

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
		
		// �������� ������������ ���� �����
		if (cin.fail()) {
			cin.clear();   // ����� ������ ����� ��� ������
			cin.ignore();  // ???
			cerr << "\n������: ������� �����, �� �������.\n\n";
			_flushall();   // ������� ������ �����
			system("pause");
			Clear();
			continue;
		} // if

		// ���� ����� �� ����������� ��������� ���������� ��������,
		// �������� �� ������ � ��������� ����
		if (x < min || x > max) {
			cerr << "\n������: ����� ������ ���� � ��������� �� "
				<< min << " �� " << max << ".\n\n";
			system("pause");
			Clear();
			continue;
		} // if

		// ���� ��������� ��� - ����� � ���������� ���������
		// �������� ����� ������ ����� - �������� ��� ������� ����� �������
		_flushall();
		break;
	} // while

	return x;
} // getUINT
namespace test
{
	UINT getUINT(int nparams, char *prompt, ...)
	{
		int &n = nparams;
		UINT x;
		while (true) {
			cout << prompt;
			cin >> x;

			// �������� ������������ ���� �����
			if (cin.fail()) {
				cin.clear();   // ����� ������ ����� ��� ������
				cin.ignore();  // ???
				cerr << "\n������: ������� �����, �� �������.\n\n";
				_flushall();   // ������� ������ �����
				system("pause");
				Clear();
				continue;
			} // if

			  // ���� ����� �� ����������� ��������� ���������� ��������,
			  // �������� �� ������ � ��������� ����

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
				cerr << "\n������: ���������� �����";
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

			  // ���� ��������� ��� - ����� � ���������� ���������
			  // �������� ����� ������ ����� - �������� ��� ������� ����� �������
			_flushall();
			break;
		} // while

		return x;
	} // test::getUINT
}

// ������� ��� ���������� ������ � �������
void Color(char *color)
{
	// ��� ��� ����� �� ����� ����
	const WORD BLACK = BACKGROUND_BLUE;		// ������
	const WORD BLUE = FOREGROUND_BLUE + FOREGROUND_INTENSITY + BACKGROUND_BLUE;						// �����
	const WORD GREEN = FOREGROUND_GREEN + FOREGROUND_INTENSITY + BACKGROUND_BLUE;					// �������
	const WORD CYAN = FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY + BACKGROUND_BLUE;	// �������
	const WORD RED = FOREGROUND_RED + FOREGROUND_INTENSITY + BACKGROUND_BLUE;						// �������
	const WORD PURPLE = FOREGROUND_RED + FOREGROUND_BLUE + FOREGROUND_INTENSITY + BACKGROUND_BLUE;	// �������, ����������
	const WORD YELLOW = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_INTENSITY + BACKGROUND_BLUE;	// ������
	const WORD WHITE = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY + BACKGROUND_BLUE;	// �����
	const WORD GRAY = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE + BACKGROUND_BLUE;		// �����
	

	// ��� ��� ����� �� ������ ����
/*	const WORD BLACK = 0;		// ������
	const WORD BLUE = FOREGROUND_BLUE + FOREGROUND_INTENSITY;										// �����
	const WORD GREEN = FOREGROUND_GREEN + FOREGROUND_INTENSITY;										// �������
	const WORD CYAN = FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY;					// �������
	const WORD RED = FOREGROUND_RED + FOREGROUND_INTENSITY;											// �������
	const WORD PURPLE = FOREGROUND_RED + FOREGROUND_BLUE + FOREGROUND_INTENSITY;					// �������, ����������
	const WORD YELLOW = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_INTENSITY;					// ������
	const WORD WHITE = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY;	// �����
	const WORD GRAY = FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE;							// �����
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
		cout << "\n������! ������� ���� �� ������" << endl;
		SetConsoleTextAttribute(h, GRAY);
		break;
	} // switch


	delete[] temp;

} // Color


  // �������������� ��������� (�������) ���� � �������� (�����)
char *StrLower(char *Str)
{
	int i = 0;
	while (Str[i] != '\0') {
		if ((Str[i] >= 'A' && Str[i] <= 'Z') || (Str[i] >= '�' && Str[i] <= '�'))
			Str[i] += 32;
		i++;
	} // while

	return Str;
} // StrLower

// �������������� �������� (�����) ���� � ��������� (�������)
char *StrUpper(char *Str)
{
	int i = 0;
	while (Str[i] != '\0') {
		if ((Str[i] >= 'a' && Str[i] <= 'z') || (Str[i] >= '�' && Str[i] <= '�'))
			Str[i] -= 32;
		i++;
	} // while

	return Str;
} // StrUpper

// �������������� ������ ����� � ���������
char *StrUpperFirst(char *Str)
{
	int i = 0;
	if ((Str[i] >= 'a' && Str[i] <= 'z') || (Str[i] >= '�' && Str[i] <= '�'))
		Str[i] -= 32;

	return Str;
} // StrUpperFirst

// �������������� �������� �����
char *StrInvert(char *Str)
{
	int i = 0;
	while (Str[i] != '\0') {
		if ((Str[i] >= 'A' && Str[i] <= 'Z') || (Str[i] >= '�' && Str[i] <= '�'))
			Str[i] += 32;
		else if ((Str[i] >= 'a' && Str[i] <= 'z') || (Str[i] >= '�' && Str[i] <= '�'))
			Str[i] -= 32;
		i++;
	} // while

	return Str;
} // StrInvert


// ������ ���� ���� �������
void SetBgColor(CColor color)
{
	wColor &= 0x0f;
	wColor |= (color << 4);
	SetConsoleTextAttribute(h, wColor);
} // SetBkColor


// ������ ���� �������� �������
void SetForeColor(CColor color)
{
	wColor &= 0xf0;
	wColor |= color;
	SetConsoleTextAttribute(h, wColor);
} // SetForeColor


// ������� ������ ������� - ���������� ������ ������� �������� "������"
// � ��������� wColor, ����������� ������� � ������ ������
void Clear(char fill)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(h, &info);

	// ���������� ���� ���� �������
	SetConsoleTextAttribute(h, wColor);

	COORD start = { 0, 0 };
	DWORD done;
	DWORD nLength = info.dwSize.X * info.dwSize.Y;
	FillConsoleOutputAttribute(h, wColor, nLength, start, &done);
	FillConsoleOutputCharacterA(h, fill, nLength, start, &done);

	// ������� ������� � ������ ������
	GotoXY(0, 0);
} // Clear

// ����� ������ � �������� ������� �������
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

  // ���������������� ������� � �������� ������� ������
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

// �������� ����� ������ (�������� ��������� ������ ������ �������: < > = 2, << >> = 3)
void tMark(LPSTR text, CColor sClr, CColor eClr)
{
	SetForeColor(sClr);
	cout << text;
	SetForeColor(eClr);
} //tMark

// ���������� ��� string
void tMark(string text, CColor sClr, CColor eClr)
{
	SetForeColor(sClr);
	cout << text;
	SetForeColor(eClr);
} //tMark

char *Format(const char* frmt, ...)
{
	static char buf[4096];
	buf[0] = 0;

	va_list args;
	va_start(args, frmt);
	vsnprintf(buf, 4096, frmt, args);
	va_end(args);

	return buf;
}

int CustomPause(UINT x, UINT y, LPCSTR text)
{
	GotoXY(x, y);
	return CustomPause(text);
} // CustomPause

int CustomPause(LPCSTR text)
{
	const COORD cp = WhereXY();
	cout << text;
	int key = _getch();
	if (!key || key == 224) key = _getch();
	GotoXY(cp); Fill(' ', strlen(text)); GotoXY(cp);
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

/*----------------------Latency-----------------------*/

UINT test::Latency::getLatency()
{
	if (!order) End(); // ���� ����� End() �� ������������ - ������������� ��� �����

	int start = p_start.wHour * 3600000 +
				p_start.wMinute * 60000 +
				p_start.wSecond * 1000  +
				p_start.wMilliseconds;
	int end   = p_end.wHour * 3600000 +
				p_end.wMinute * 60000 +
				p_end.wSecond * 1000  +
				p_end.wMilliseconds;

	return end - start; // ~ �������� � �������������
}