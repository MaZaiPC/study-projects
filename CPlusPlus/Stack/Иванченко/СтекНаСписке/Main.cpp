/*	Main.cpp  ������� ����

=====================================================================================
								����������� �������:
=====================================================================================



*/

#include "stdafx.h"
#include "Utils.h"
#include "Application.h"


int main(int argc, char *argv[])
{
	init();

	Application *app = new Application();

	app->run();

	delete app;

	return 0;
} // main



