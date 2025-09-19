#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe
{
    public:
        static void sortVector(const std::vector<unsigned int>& input, std::vector<unsigned int>& output, double& timeMicroseconds);
        static void sortDeque(const std::deque<unsigned int>& input, std::deque<unsigned int>& output, double& timeMicroseconds);

    private:
        static void fordJohnsonVector(const std::vector<unsigned int>& input, std::vector<unsigned int>& output);
        static std::vector<std::size_t> buildJacobsthalOrderVector(std::size_t m);
        static void binaryInsertVector(std::vector<unsigned int>& chain, unsigned int value, std::size_t upperBoundExclusive);

        static void fordJohnsonDeque(const std::deque<unsigned int>& input, std::deque<unsigned int>& output);
        static std::vector<std::size_t> buildJacobsthalOrderDeque(std::size_t m);
        static void binaryInsertDeque(std::deque<unsigned int>& chain, unsigned int value, std::size_t upperBoundExclusive);
};

#endif
