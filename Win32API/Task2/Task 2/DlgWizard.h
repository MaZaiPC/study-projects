#pragma once
#include "Includes.h"

#define WZ_CANCEL   0
#define WZ_DONE		1

#define WZ_UNSAVED	2
#define WZ_READY	3

#define ED_OFFER	1
#define ED_NEED		2

enum SORT_MODE
{
	SORT_PRICE,
	SORT_HARD
};

BOOL CALLBACK DlgWizard(HWND, UINT, WPARAM, LPARAM);
BOOL WizardOnInitDialog(HWND, HWND, LPARAM);
void WizardOnCommand(HWND, int, HWND, UINT);
void CmdUpdateGraphState(HWND, int);
void WizardDlgClose(HWND, INT_PTR);
void WizardOnPaint(HWND hWnd);

void InitStage1(HWND);
void InitStage2(HWND);
void InitStage3(HWND);

BOOL CheckFields(HWND);
void SaveFields(HWND, INT32);