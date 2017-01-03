#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#define BACKGROUND RGB(240, 240, 240)
#define BACKGROUND_DARK RGB(40, 40, 40)
#define MAIN_WIDTH   ((int)0x80000000)
#define MAIN_HEIGHT  ((int)0x80000000)

#define MAX_LOADSTRING 100

#include <Windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <CommCtrl.h>
#include <Shlobj.h>
#pragma comment(lib,"Comctl32.lib")
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <string>
#include <vector>
#include <algorithm>


using std::wstring;
using std::vector;