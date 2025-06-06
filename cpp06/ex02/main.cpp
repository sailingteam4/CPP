#include "functions.hpp"
#include "Base.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing identify real type ===" << std::endl;
	
	for (int i = 0; i < 6; i++)
	{
		std::cout << "\nTest " << (i + 1) << ":" << std::endl;
		
		Base* ptr = generate();
		
		std::cout << "Identify by pointer: ";
		identify(ptr);
		
		std::cout << "Identify by reference: ";
		identify(*ptr);
		
		delete ptr;
	}
	
	return 0;
}
