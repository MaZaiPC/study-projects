/*	Main.cpp  ������� ����

=====================================================================================
								����������� �������:
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
	cout << "\n���������� ����������� ����������!\n��������: " << e.what();
}
catch (...)
{
	cout << "\n��� �� ����� �� ���...\n";
}