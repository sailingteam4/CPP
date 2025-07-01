#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

void testMutantStack()
{
    std::cout << "Testing MutantStack" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Iterating through MutantStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    std::cout << "Copied stack size: " << s.size() << std::endl;
}

void testWithList()
{
    std::cout << "\nTesting with std::list (same behavior)" << std::endl;
    
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "Back element: " << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << "Size after pop: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    
    ++it;
    --it;
    
    std::cout << "Iterating through std::list:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void additionalTests()
{
    std::cout << "\nAdditional Tests" << std::endl;
    
    MutantStack<int, std::vector<int> > vstack;
    vstack.push(42);
    vstack.push(21);
    vstack.push(84);
    
    std::cout << "Vector-based MutantStack:" << std::endl;
    for (MutantStack<int, std::vector<int> >::iterator it = vstack.begin(); 
         it != vstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Reverse iteration:" << std::endl;
    for (MutantStack<int, std::vector<int> >::reverse_iterator rit = vstack.rbegin(); 
         rit != vstack.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    const MutantStack<int, std::vector<int> > const_stack(vstack);
    std::cout << "Const iteration:" << std::endl;
    for (MutantStack<int, std::vector<int> >::const_iterator cit = const_stack.begin(); 
         cit != const_stack.end(); ++cit)
    {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    
    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);
    
    MutantStack<int> copy(original);
    MutantStack<int> assigned;
    assigned = original;
    
    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
}

int main()
{
    testMutantStack();
    testWithList();
    additionalTests();
    
    return 0;
}
