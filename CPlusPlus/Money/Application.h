#pragma once


class Application
{
	Currency *pCurrency;
public:
	Application();
	~Application();

	void run();
	
	void test_dollar();
	void test_euro();

}; // Application



