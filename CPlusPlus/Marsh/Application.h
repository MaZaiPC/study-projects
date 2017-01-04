#pragma once
#include "Marsh.h"

class Application
{
	static const int N = 9;

	Marsh *a;

	char *dbFileName;
	FILE *f;

	void Exit(bool saved);
public:
	Application();
	~Application();

	void Run();
	void New();
	void Load(bool flag);

}; // Application



