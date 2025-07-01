#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::cout << "Testing easyfind with std::vector" << std::endl;
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value 3 at position: " << std::distance(vec.begin(), it) << std::endl;

        it = easyfind(vec, 1);
        std::cout << "Found value 1 at position: " << std::distance(vec.begin(), it) << std::endl;

        it = easyfind(vec, 5);
        std::cout << "Found value 5 at position: " << std::distance(vec.begin(), it) << std::endl;

        std::cout << "Trying to find value 42..." << std::endl;
        easyfind(vec, 42);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTesting easyfind with std::list" << std::endl;
    try {
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);

        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found value 20 at position: " << std::distance(lst.begin(), it) << std::endl;

        std::cout << "Trying to find value 100..." << std::endl;
        easyfind(lst, 100);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTesting easyfind with std::deque" << std::endl;
    try {
        std::deque<int> deq;
        deq.push_back(7);
        deq.push_back(14);
        deq.push_back(21);
        deq.push_back(28);

        std::deque<int>::iterator it = easyfind(deq, 14);
        std::cout << "Found value 14 at position: " << std::distance(deq.begin(), it) << std::endl;

        deq.push_back(14);
        it = easyfind(deq, 14);
        std::cout << "Found first occurrence of 14 at position: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTesting with empty container" << std::endl;
    try {
        std::vector<int> empty_vec;
        std::cout << "Trying to find value 1 in empty container..." << std::endl;
        easyfind(empty_vec, 1);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
