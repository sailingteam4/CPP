#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	
	int random = std::rand() % 3;
	
	switch (random)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception& e) {}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception& e) {}
	
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception& e) {}
	
	std::cout << "Unknown type" << std::endl;
}
