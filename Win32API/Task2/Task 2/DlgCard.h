#pragma once
#include "Includes.h"

BOOL CALLBACK DlgCard(HWND, UINT, WPARAM, LPARAM);
BOOL CardOnInitDialog(HWND, HWND, LPARAM);
void CardOnCommand(HWND, int, HWND, UINT);