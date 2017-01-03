#pragma once
#include "Includes.h"

enum SORT_MODE
{
	SORT_PRICE,
	SORT_HARD
};

BOOL CALLBACK DlgChoose(HWND, UINT, WPARAM, LPARAM);
BOOL ChooseOnInitDialog(HWND, HWND, LPARAM);
void ChooseOnCommand(HWND, int, HWND, UINT);