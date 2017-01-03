#pragma once
#include "Includes.h"

BOOL CALLBACK DlgSrcResults(HWND, UINT, WPARAM, LPARAM);
BOOL ResultsOnInitDialog(HWND, HWND, LPARAM);
void ResultsOnCommand(HWND, int, HWND, UINT);
void ResultsOnSize(HWND hwnd, UINT state, int cx, int cy);

extern void CreateListView(HWND hwnd, HWND *lpHwndLV, HINSTANCE hInstance);