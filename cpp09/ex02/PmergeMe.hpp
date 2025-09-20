#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <stdexcept>

class PmergeMe
{
    private:
        static size_t _comparisons;
        
        static std::vector<size_t> generateJacobsthalSequence(size_t n);
        
        static void fordJohnsonSortVector(std::vector<int>& container);
        static void fordJohnsonSortDeque(std::deque<int>& container);
        
        static void insertionSortVector(std::vector<int>& container, size_t start, size_t end);
        static size_t binarySearchVector(const std::vector<int>& container, int value, size_t start, size_t end);
        
        static void insertionSortDeque(std::deque<int>& container, size_t start, size_t end);
        static size_t binarySearchDeque(const std::deque<int>& container, int value, size_t start, size_t end);
        
        static void validateInput(int argc, char** argv);
        static std::vector<int> parseArguments(int argc, char** argv);
        
        static double getCurrentTime();
        
    public:
        static std::vector<int> sortWithVector(const std::vector<int>& input, double& timeElapsed);
        static std::deque<int> sortWithDeque(const std::vector<int>& input, double& timeElapsed);
        
        static void displaySequence(const std::string& label, const std::vector<int>& sequence);
        static size_t getComparisons();
        static void resetComparisons();
        
        static void run(int argc, char** argv);
};

#endif
