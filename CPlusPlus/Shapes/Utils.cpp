#include "stdafx.h"
#include "Utils.h"

extern HANDLE h;

// ���������� ���������� ���������� ��� �������� �������� ����������
WORD wColor = Black << 4 | Grey;


// ���������� ���������� � ������
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
	cfi.dwFontSize.Y = 20;  // ������ ������ � �������
	cfi.FontFamily   = FF_DONTCARE;
	cfi.FontWeight   = FW_NORMAL /* FW_BOLD */;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(h, FALSE, &cfi);

	// ���������� ��������� ���� �������
	// ����� ��������� - � ��������� UNICODE
	// L"�����" ��� _T("�����")
	SetConsoleTitle(_T("��� � ������� cout � ������"));

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
			continue;
		} // if

		// ���� ����� �� ����������� ��������� ���������� ��������,
		// �������� �� ������ � ��������� ����
		if (x < min || x > max) {
			cerr << "\n������: ����� ������ ���� � ��������� �� "
				<< min << " �� " << max << ".\n\n";
			continue;
		} // if

		// ���� ��������� ��� - ����� � ���������� ���������
		// �������� ����� ������ ����� - �������� ��� ������� ����� �������
		_flushall();
		break;
	} // while

	return x;
} // getUINT




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


// ������ ���� ���� �������
void SetBkColor(CColor color)
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


// ���������������� ������� � �������� ������� ������
void GotoXY(UINT x, UINT y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(h, coord);
} // GotoXY