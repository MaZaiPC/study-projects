// Laptev32P24.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Application.h"
#include "Utils.h"

HANDLE h;

int main()
{
	init();

	Application *app = new Application();

	app->run();

	delete app;

    return 0;
}

