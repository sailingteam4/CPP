#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

void testBasicFunctionality() {
    std::cout << "Test from subject" << std::endl;
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

void testExceptions() {
    std::cout << "Exception Tests" << std::endl;
    
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    try {
        Span sp(5);
        sp.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    try {
        Span sp(5);
        sp.addNumber(42);
        sp.longestSpan();
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testIteratorRange() {
    std::cout << "Iterator Range Test" << std::endl;
    
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i * 2);
    }
    
    Span sp1(15);
    sp1.addNumbers(vec.begin(), vec.end());
    sp1.addNumber(100);
    
    std::cout << "After adding vector range + one number:" << std::endl;
    std::cout << "Size: " << sp1.size() << "/" << sp1.capacity() << std::endl;
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    
    std::list<int> lst;
    lst.push_back(50);
    lst.push_back(25);
    lst.push_back(75);
    
    Span sp2(20);
    sp2.addNumbers(lst.begin(), lst.end());
    sp2.addNumbers(vec.begin(), vec.begin() + 5);
    
    std::cout << "\nAfter adding list + partial vector:" << std::endl;
    std::cout << "Size: " << sp2.size() << "/" << sp2.capacity() << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    
    try {
        Span sp3(5);
        sp3.addNumbers(vec.begin(), vec.end());
    } catch (const std::exception& e) {
        std::cout << "\nCaught expected exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testLargeSpan() {
    std::cout << "Large Span Test" << std::endl;
    
    const int SIZE = 10000;
    Span sp(SIZE);
    
    std::srand(std::time(0));
    std::vector<int> numbers;
    for (int i = 0; i < SIZE; ++i) {
        numbers.push_back(std::rand() % 100000);
    }
    
    sp.addNumbers(numbers.begin(), numbers.end());
    
    std::cout << "Added " << sp.size() << " random numbers" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "Copy Constructor and Assignment Test" << std::endl;
    
    Span original(10);
    original.addNumber(1);
    original.addNumber(5);
    original.addNumber(10);
    original.addNumber(20);
    
    Span copy(original);
    std::cout << "Original - Size: " << original.size() << ", Shortest: " << original.shortestSpan() << std::endl;
    std::cout << "Copy - Size: " << copy.size() << ", Shortest: " << copy.shortestSpan() << std::endl;
    
    Span assigned(5);
    assigned = original;
    std::cout << "Assigned - Size: " << assigned.size() << ", Shortest: " << assigned.shortestSpan() << std::endl;
    
    original.addNumber(100);
    std::cout << "\nAfter modifying original:" << std::endl;
    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
    std::cout << std::endl;
}

void testEdgeCases() {
    std::cout << "Edge Cases Test" << std::endl;
    
    Span sp1(5);
    sp1.addNumber(-10);
    sp1.addNumber(-5);
    sp1.addNumber(0);
    sp1.addNumber(5);
    sp1.addNumber(10);
    
    std::cout << "With negative numbers:" << std::endl;
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    
    Span sp2(3);
    sp2.addNumber(42);
    sp2.addNumber(42);
    sp2.addNumber(42);
    
    std::cout << "\nWith identical numbers:" << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    
    Span sp3(2);
    sp3.addNumber(1);
    sp3.addNumber(1000);
    
    std::cout << "\nWith only two numbers:" << std::endl;
    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    
    std::cout << std::endl;
}

int main() {
    testBasicFunctionality();
    testExceptions();
    testIteratorRange();
    testLargeSpan();
    testCopyAndAssignment();
    testEdgeCases();
    
    return 0;
}
