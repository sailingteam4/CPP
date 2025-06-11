#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "=== Array Template Tests ===" << std::endl;
    
    std::cout << "\n1. Testing empty array construction:" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    std::cout << "\n2. Testing array construction with size:" << std::endl;
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    std::cout << "\n3. Testing default initialization:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    
    std::cout << "\n4. Testing element assignment:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i * 10;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    
    std::cout << "\n5. Testing copy constructor:" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Copy array size: " << copyArray.size() << std::endl;
    for (unsigned int i = 0; i < copyArray.size(); i++)
    {
        std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
    }
    
    std::cout << "\n6. Testing independence of copies:" << std::endl;
    copyArray[0] = 999;
    std::cout << "After modifying copyArray[0] to 999:" << std::endl;
    std::cout << "intArray[0] = " << intArray[0] << std::endl;
    std::cout << "copyArray[0] = " << copyArray[0] << std::endl;
    
    std::cout << "\n7. Testing assignment operator:" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
    for (unsigned int i = 0; i < assignedArray.size(); i++)
    {
        std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
    }
    
    std::cout << "\n8. Testing independence after assignment:" << std::endl;
    assignedArray[1] = 888;
    std::cout << "After modifying assignedArray[1] to 888:" << std::endl;
    std::cout << "intArray[1] = " << intArray[1] << std::endl;
    std::cout << "assignedArray[1] = " << assignedArray[1] << std::endl;
    
    std::cout << "\n9. Testing out of bounds access:" << std::endl;
    try
    {
        std::cout << "Trying to access intArray[10]..." << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: Out of bounds access detected!" << std::endl;
    }
    
    std::cout << "\n10. Testing empty array access:" << std::endl;
    try
    {
        std::cout << "Trying to access emptyArray[0]..." << std::endl;
        std::cout << emptyArray[0] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: Empty array access detected!" << std::endl;
    }
    
    std::cout << "\n11. Testing with different types:" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    std::cout << "String array: ";
    for (unsigned int i = 0; i < stringArray.size(); i++)
    {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    
    Array<double> doubleArray(3);
    doubleArray[0] = 3.14;
    doubleArray[1] = 2.71;
    doubleArray[2] = 1.41;
    std::cout << "Double array: ";
    for (unsigned int i = 0; i < doubleArray.size(); i++)
    {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}
