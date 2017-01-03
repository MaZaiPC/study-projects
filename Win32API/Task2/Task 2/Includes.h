#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define MAX_LOADSTRING 100

#define BACKGROUND RGB(240, 240, 240)
#define BACKGROUND_DARK RGB(40, 40, 40)
#define MAIN_WIDTH   840
#define MAIN_HEIGHT  550

#include <Windows.h>
#include <windowsx.h>

#include <CommCtrl.h>
#pragma comment (lib, "comctl32.lib")

#include <tchar.h>
#include <string>

#include <list>
#include <map>

#include <algorithm>
#include <fstream>

using namespace std;

#pragma warning(disable:4172 477 10 2)