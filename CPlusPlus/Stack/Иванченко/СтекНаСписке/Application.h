#pragma once
#include "Stack.h"

class Application
{
	Stack stack;

public:
	Application();
	~Application();

	void run();
	void testPush();
	void testPop();
	void showStack();
}; // Application



