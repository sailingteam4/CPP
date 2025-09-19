#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <climits>
#include <cctype>
#include "PmergeMe.hpp"

static bool parseArgs(int argc, char** argv, std::vector<unsigned int>& vec, std::deque<unsigned int>& deq)
{
    vec.clear();
    deq.clear();
    for (int i = 1; i < argc; ++i)
    {
        std::string s(argv[i]);
        if (s.empty())
            return false;
        for (size_t k = 0; k < s.size(); ++k)
        {
            if (!std::isdigit(static_cast<unsigned char>(s[k])))
            {
                return false;
            }
        }
        unsigned long long v = 0ULL;
        std::istringstream iss(s);
        iss >> v;
        if (!iss || !iss.eof())
            return false;
        if (v > UINT_MAX)
            return false;
        vec.push_back(static_cast<unsigned int>(v));
        deq.push_back(static_cast<unsigned int>(v));
    }
    return true;
}

static void printSeq(const std::vector<unsigned int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i)
            std::cout << ' ';
        std::cout << v[i];
    }
}

int main(int argc, char** argv)
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        std::vector<unsigned int> inputVec;
        std::deque<unsigned int> inputDeq;
        if (!parseArgs(argc, argv, inputVec, inputDeq))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        std::cout << "Before: ";
        printSeq(inputVec);
        std::cout << std::endl;

        std::vector<unsigned int> sortedVec;
        std::deque<unsigned int> sortedDeq;
        double timeVecUs = 0.0, timeDeqUs = 0.0;

        PmergeMe::sortVector(inputVec, sortedVec, timeVecUs);
        //PmergeMe::sortDeque(inputDeq, sortedDeq, timeDeqUs);

        std::cout << "After:  ";
        printSeq(sortedVec);
        std::cout << std::endl;

        std::cout.setf(std::ios::fixed);
        std::cout.precision(6);
        std::cout << "Time to process a range of " << inputVec.size()
                  << " elements with std::vector : " << timeVecUs << " us" << std::endl;
        //std::cout << "Time to process a range of " << inputDeq.size()
        //          << " elements with std::deque  : " << timeDeqUs << " us" << std::endl;

        return (0);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
}
