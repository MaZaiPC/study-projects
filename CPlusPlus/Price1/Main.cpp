/*


*/

#include "stdafx.h"
#include "Utils.h"
#include "Application.h"

HANDLE h;

int main()
{
	init();

	Application *app = new Application();

	app->run();

	delete app;

	return 0;
} // main

