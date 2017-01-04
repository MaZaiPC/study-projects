/*	Main.cpp  Главный файл

=====================================================================================
								Техническое задание:
=====================================================================================



*/

#include "stdafx.h"
#include "Utils.h"
#include "Application.h"

int main(int argc, char *argv[]) try 
{
	init();

	Application *app = new Application();

	app->run();

	delete app;

	return 0;
} // main
catch (const exception &e)
{
	cout << "\nОбнаружено стандартное исключение!\nПолучено: " << e.what();
}
catch (...)
{
	cout << "\nЧто то пошло не так...\n";
}