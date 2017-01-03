#pragma once
#include "Includes.h"

class Utils
{
public:
	explicit Utils() {}
	~Utils() {}

	static BOOL DrawRect(HDC hdc, const LPRECT lprect);
	static BOOL DrawLine(HDC hdc, int x1, int y1, int x2, int y2, LPPOINT lppt = NULL);
	static BOOL IsMouseOn(HWND hwnd, const LPRECT lprect);
	static HWND GetMouseHover(HWND hwnd);
};