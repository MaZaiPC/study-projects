#pragma once
#include "Root.h"

class Application
{
	Root *pRoot;
public:
	Application() {}
	~Application() {}

	void run();
	
	void test_linear();
	void test_square();

}; // Application



