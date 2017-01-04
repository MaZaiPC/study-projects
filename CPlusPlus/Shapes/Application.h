#pragma once
#include "Shapes.h"

class Application
{
	Square *pObj1;
	Pentagon *pObj2;

public:
	Application();
	~Application();

	void run();
	void testQuadrat();
	void testPentagon();
	void testIsIntersect();
}; // Application



