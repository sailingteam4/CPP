#include <iostream>
#include "iter.hpp"

// Test functions for different types
void printInt(int const &n)
{
    std::cout << n << " ";
}

void printChar(char const &c)
{
    std::cout << c;
}

void incrementInt(int &n)
{
    n++;
}

void toUpperChar(char &c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

// Function template for testing
template<typename T>
void printElement(T const &element)
{
    std::cout << element << " ";
}

int main()
{
    std::cout << "=== Testing iter function template ===" << std::endl;
    
    // Test with int array (const function)
    std::cout << "\n1. Testing with int array (const function):" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original array: ";
    iter(intArray, intArraySize, printInt);
    std::cout << std::endl;
    
    // Test with int array (non-const function)
    std::cout << "\n2. Testing with int array (non-const function - increment):" << std::endl;
    iter(intArray, intArraySize, incrementInt);
    std::cout << "After increment: ";
    iter(intArray, intArraySize, printInt);
    std::cout << std::endl;
    
    // Test with char array (const function)
    std::cout << "\n3. Testing with char array (const function):" << std::endl;
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t charArraySize = sizeof(charArray) / sizeof(charArray[0]);
    
    std::cout << "Original string: ";
    iter(charArray, charArraySize, printChar);
    std::cout << std::endl;
    
    // Test with char array (non-const function)
    std::cout << "\n4. Testing with char array (non-const function - to uppercase):" << std::endl;
    iter(charArray, charArraySize, toUpperChar);
    std::cout << "After uppercase: ";
    iter(charArray, charArraySize, printChar);
    std::cout << std::endl;
    
    // Test with function template
    std::cout << "\n5. Testing with function template:" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    
    std::cout << "Double array: ";
    iter(doubleArray, doubleArraySize, printElement<double>);
    std::cout << std::endl;
    
    // Test with const array
    std::cout << "\n6. Testing with const array:" << std::endl;
    const int constArray[] = {10, 20, 30, 40, 50};
    size_t constArraySize = sizeof(constArray) / sizeof(constArray[0]);
    
    std::cout << "Const array: ";
    iter(constArray, constArraySize, printInt);
    std::cout << std::endl;
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}
