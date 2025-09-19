#include "PmergeMe.hpp"

#include <algorithm>
#include <ctime>
#include <climits>
#include <cstddef>
#include <iostream>

static std::vector<std::size_t> buildJacobsthalOrder(std::size_t m)
{
    // J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    std::vector<std::size_t> j; j.reserve(32);
    j.push_back(0); // J0
    j.push_back(1); // J1
    while (true)
    {
        std::size_t n = j.size();
        std::size_t next = j[n-1] + 2 * j[n-2];
        if (next > m)
            break;
        j.push_back(next);
    }
    std::vector<std::size_t> order;
    std::size_t prev = 1;
    for (std::size_t idx = 2; idx < j.size(); ++idx)
    {
        std::size_t cur = j[idx];
        if (cur > m)
            cur = m;
        for (std::size_t t = cur; t-- > prev; )
        {
            order.push_back(t);
        }
        prev = j[idx];
    }
    for (std::size_t k = prev; k < m; ++k)
        order.push_back(k);
    return order;
}

static bool pairFirstLess(const std::pair<unsigned int, unsigned int>& x, const std::pair<unsigned int, unsigned int>& y)
{
    return x.first < y.first;
}

static void printPairsMinMax(const char* tag, const std::vector< std::pair<unsigned int,unsigned int> >& pairs, bool hasStraggler, unsigned int straggler)
{
    std::cout << tag;
    for (std::size_t i = 0; i < pairs.size(); ++i)
    {
        std::cout << ' ' << pairs[i].second << ' ' << pairs[i].first;
    }
    if (hasStraggler)
        std::cout << ' ' << straggler;
    std::cout << std::endl;
}

// -------------------- Vector --------------------

static void pairAndSortVector(const std::vector<unsigned int>& in, std::vector< std::pair<unsigned int,unsigned int> >& pairs, bool& hasStraggler, unsigned int& straggler)
{
    pairs.clear();
    hasStraggler = (in.size() % 2 != 0);
    std::size_t limit = in.size() - (hasStraggler ? 1 : 0);
    pairs.reserve(limit/2);
    for (std::size_t i = 0; i < limit; i += 2)
    {
        unsigned int a = in[i];
        unsigned int b = in[i+1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    if (hasStraggler)
        straggler = in.back();
}

static void buildInitialChainVector(const std::vector< std::pair<unsigned int,unsigned int> >& pairs, std::vector<unsigned int>& chain, std::vector<unsigned int>& pend)
{
    chain.clear();
    pend.clear();
    if (pairs.empty())
        return;
    // S (main) gets the first pair's larger; P (pend) gets the smaller
    chain.reserve(pairs.size());
    pend.reserve(pairs.size());
    chain.push_back(pairs[0].first);
    pend.push_back(pairs[0].second);
    for (std::size_t i = 1; i < pairs.size(); ++i)
    {
        chain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
}

void PmergeMe::binaryInsertVector(std::vector<unsigned int>& chain, unsigned int value, std::size_t upperBoundExclusive)
{
    std::size_t left = 0;
    std::size_t right = std::min(upperBoundExclusive, chain.size());
    while (left < right)
    {
        std::size_t mid = left + (right - left) / 2;
        if (value <= chain[mid])
            right = mid; else left = mid + 1;
    }
    chain.insert(chain.begin() + left, value);
}

std::vector<std::size_t> PmergeMe::buildJacobsthalOrderVector(std::size_t m)
{
    return buildJacobsthalOrder(m);
}

void PmergeMe::fordJohnsonVector(const std::vector<unsigned int>& input, std::vector<unsigned int>& output)
{
    if (input.size() <= 1)
    {
        output = input; return;
    }

    // Step 1: pair and sort pairs by their max elements
    std::vector< std::pair<unsigned int,unsigned int> > pairs;
    bool hasStraggler = false;
    unsigned int straggler = 0;
    pairAndSortVector(input, pairs, hasStraggler, straggler);

    std::vector< std::pair<unsigned int,unsigned int> > guidePairs = pairs;

    printPairsMinMax("[vector] step 1:", guidePairs, hasStraggler, straggler);

    // Step 2: for each adjacent pair-of-pairs, sort by max (first) ascending
    for (std::size_t i = 0; i + 1 < guidePairs.size(); i += 2)
    {
        if (guidePairs[i].first > guidePairs[i+1].first)
        {
            std::pair<unsigned int,unsigned int> tmp = guidePairs[i];
            guidePairs[i] = guidePairs[i+1];
            guidePairs[i+1] = tmp;
        }
    }
    printPairsMinMax("[vector] step 2:", guidePairs, hasStraggler, straggler);

    // Step 3: for each full block of 4 pairs, swap halves (keep internal order)
    std::vector< std::pair<unsigned int,unsigned int> > next = guidePairs;
    for (std::size_t j = 0; j + 3 < guidePairs.size(); j += 4)
    {
        next[j + 0] = guidePairs[j + 2];
        next[j + 1] = guidePairs[j + 3];
        next[j + 2] = guidePairs[j + 0];
        next[j + 3] = guidePairs[j + 1];
    }
    guidePairs.swap(next);

    printPairsMinMax("[vector] step 3:", guidePairs, hasStraggler, straggler);

    std::sort(pairs.begin(), pairs.end(), pairFirstLess);

    printPairsMinMax("[vector] step 4:", guidePairs, hasStraggler, straggler);

    // Step 2: build initial chain S from larger elements and pend from smaller
    std::vector<unsigned int> chain;
    std::vector<unsigned int> pend;
    buildInitialChainVector(pairs, chain, pend);

    std::cout << "[vector] initial main:";
    for (std::size_t i = 0; i < chain.size(); ++i)
        std::cout << ' ' << chain[i];
    std::cout << std::endl;
    std::cout << "[vector] initial pend:";
    for (std::size_t i = 0; i < pend.size(); ++i)
        std::cout << ' ' << pend[i];
    std::cout << std::endl;
    if (hasStraggler)
        std::cout << "[vector] straggler: " << straggler << std::endl;

    // Step 3: insert pend elements (the smaller elements) in Jacobsthal order.
    if (!pend.empty())
    {
        std::vector<std::size_t> order = buildJacobsthalOrderVector(pend.size());
        for (std::size_t k = 0; k < order.size(); ++k)
        {
            std::size_t pIndex = order[k];
            if (pIndex >= pend.size())
                continue;

            unsigned int big = pairs[pIndex].first;

            std::size_t posBig = 0;
            while (posBig < chain.size() && chain[posBig] != big)
                ++posBig;
            if (posBig == chain.size())
                posBig = chain.size();

            binaryInsertVector(chain, pend[pIndex], posBig);
        }
    }

    // Step 4: insert straggler if exists (full range)
    if (hasStraggler)
    {
        binaryInsertVector(chain, straggler, chain.size());
    }

    output.swap(chain);
}

void PmergeMe::sortVector(const std::vector<unsigned int>& input, std::vector<unsigned int>& output, double& timeMicroseconds)
{
    std::clock_t start = std::clock();
    fordJohnsonVector(input, output);
    std::clock_t end = std::clock();
    timeMicroseconds = (double)(end - start) * 1e6 / (double)CLOCKS_PER_SEC;
}

// -------------------- Deque --------------------

static void pairAndSortDeque(const std::deque<unsigned int>& in, std::vector< std::pair<unsigned int,unsigned int> >& pairs, bool& hasStraggler, unsigned int& straggler)
{
    pairs.clear();
    hasStraggler = (in.size() % 2 != 0);
    std::size_t limit = in.size() - (hasStraggler ? 1 : 0);
    pairs.reserve(limit/2);
    for (std::size_t i = 0; i < limit; i += 2)
    {
        unsigned int a = in[i];
        unsigned int b = in[i+1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    if (hasStraggler)
        straggler = in.back();
}

static void buildInitialChainDeque(const std::vector< std::pair<unsigned int,unsigned int> >& pairs, std::deque<unsigned int>& chain, std::deque<unsigned int>& pend)
{
    chain.clear();
    pend.clear();
    if (pairs.empty())
        return;
    chain.push_back(pairs[0].first);
    pend.push_back(pairs[0].second);
    for (std::size_t i = 1; i < pairs.size(); ++i)
    {
        chain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
}

void PmergeMe::binaryInsertDeque(std::deque<unsigned int>& chain, unsigned int value, std::size_t upperBoundExclusive)
{
    std::size_t left = 0;
    std::size_t right = std::min(upperBoundExclusive, chain.size());
    while (left < right)
    {
        std::size_t mid = left + (right - left) / 2;
        if (value <= chain[mid])
            right = mid; else left = mid + 1;
    }
    chain.insert(chain.begin() + left, value);
}

std::vector<std::size_t> PmergeMe::buildJacobsthalOrderDeque(std::size_t m)
{
    return buildJacobsthalOrder(m);
}

void PmergeMe::fordJohnsonDeque(const std::deque<unsigned int>& input, std::deque<unsigned int>& output)
{
    if (input.size() <= 1)
    {
        output = input; return;
    }

    std::vector< std::pair<unsigned int,unsigned int> > pairs;
    bool hasStraggler = false;
    unsigned int straggler = 0;
    pairAndSortDeque(input, pairs, hasStraggler, straggler);

    std::vector< std::pair<unsigned int,unsigned int> > guidePairs = pairs;

    printPairsMinMax("[deque ] step 1:", guidePairs, hasStraggler, straggler);

    for (std::size_t i = 0; i + 1 < guidePairs.size(); i += 2)
    {
        if (guidePairs[i].first > guidePairs[i+1].first)
        {
            std::pair<unsigned int,unsigned int> tmp = guidePairs[i];
            guidePairs[i] = guidePairs[i+1];
            guidePairs[i+1] = tmp;
        }
    }

    printPairsMinMax("[deque ] step 2:", guidePairs, hasStraggler, straggler);

    std::vector< std::pair<unsigned int,unsigned int> > next = guidePairs;
    for (std::size_t j = 0; j + 3 < guidePairs.size(); j += 4)
    {
        next[j + 0] = guidePairs[j + 2];
        next[j + 1] = guidePairs[j + 3];
        next[j + 2] = guidePairs[j + 0];
        next[j + 3] = guidePairs[j + 1];
    }
    guidePairs.swap(next);

    printPairsMinMax("[deque ] step 3:", guidePairs, hasStraggler, straggler);

    std::sort(pairs.begin(), pairs.end(), pairFirstLess);

    printPairsMinMax("[deque ] step 4:", guidePairs, hasStraggler, straggler);

    std::deque<unsigned int> chain;
    std::deque<unsigned int> pend;
    buildInitialChainDeque(pairs, chain, pend);

    // Debug: print initial main chain (S), pend elements (P), and straggler before insertions
    std::cout << "[deque ] initial main:";
    for (std::size_t i = 0; i < chain.size(); ++i)
        std::cout << ' ' << chain[i];
    std::cout << std::endl;
    std::cout << "[deque ] initial pend:";
    for (std::size_t i = 0; i < pend.size(); ++i)
        std::cout << ' ' << pend[i];
    std::cout << std::endl;
    if (hasStraggler)
        std::cout << "[deque ] straggler: " << straggler << std::endl;

    if (!pend.empty())
    {
        std::vector<std::size_t> order = buildJacobsthalOrderDeque(pend.size());
        for (std::size_t k = 0; k < order.size(); ++k)
        {
            std::size_t pIndex = order[k];
            if (pIndex >= pend.size())
                continue;

            unsigned int big = pairs[pIndex].first;
            std::size_t posBig = 0;
            while (posBig < chain.size() && chain[posBig] != big)
                ++posBig;
            if (posBig == chain.size())
                posBig = chain.size();

            binaryInsertDeque(chain, pend[pIndex], posBig);
        }
    }

    if (hasStraggler)
    {
        binaryInsertDeque(chain, straggler, chain.size());
    }

    output.swap(chain);
}

void PmergeMe::sortDeque(const std::deque<unsigned int>& input, std::deque<unsigned int>& output, double& timeMicroseconds)
{
    std::clock_t start = std::clock();
    fordJohnsonDeque(input, output);
    std::clock_t end = std::clock();
    timeMicroseconds = (double)(end - start) * 1e6 / (double)CLOCKS_PER_SEC;
}
