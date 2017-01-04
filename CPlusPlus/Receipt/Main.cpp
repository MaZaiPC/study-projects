/*	Main.cpp  Главный файл

=====================================================================================
								Техническое задание:
=====================================================================================



*/

#include "stdafx.h"
#include "Utils.h"
#include "Application.h"

HANDLE h;


int main(int argc, char *argv[])
{
	init();

	Application *app = new Application();

	app->run();

	delete app;

	return 0;
} // main



