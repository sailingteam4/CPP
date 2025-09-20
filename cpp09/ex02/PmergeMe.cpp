#include "PmergeMe.hpp"

size_t PmergeMe::_comparisons = 0;

double PmergeMe::getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

void PmergeMe::resetComparisons()
{
    _comparisons = 0;
}

size_t PmergeMe::getComparisons()
{
    return _comparisons;
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> jacobsthal;
    if (n == 0)
        return jacobsthal;
    
    jacobsthal.push_back(1);
    if (n == 1)
        return jacobsthal;
    
    jacobsthal.push_back(1);
    if (n == 2)
        return jacobsthal;
    
    // J(n) = J(n-1) + 2*J(n-2)
    size_t prev2 = 1, prev1 = 1;
    for (size_t i = 2; i < n; ++i)
    {
        size_t current = prev1 + 2 * prev2;
        jacobsthal.push_back(current);
        prev2 = prev1;
        prev1 = current;
    }
    return jacobsthal;
}

void PmergeMe::validateInput(int argc, char** argv)
{
    if (argc < 2)
    {
        throw std::invalid_argument("Error: No arguments provided");
    }
}

std::vector<int> PmergeMe::parseArguments(int argc, char** argv)
{
    validateInput(argc, argv);
    std::vector<int> numbers;
    
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        
        if (arg.empty())
        {
            throw std::invalid_argument("Error: Empty argument provided");
        }
        
        size_t start = 0;
        if (arg[0] == '+')
        {
            start = 1;
            if (arg.length() == 1)
            {
                throw std::invalid_argument("Error: Invalid number format");
            }
        }
        
        for (size_t j = start; j < arg.length(); ++j)
        {
            if (!std::isdigit(arg[j]))
            {
                throw std::invalid_argument("Error: Invalid character in number");
            }
        }
        
        std::istringstream iss(arg);
        long num;
        if (!(iss >> num) || !iss.eof() || num < 0 || num > 2147483647)
        {
            throw std::invalid_argument("Error: Invalid positive integer");
        }
        
        numbers.push_back(static_cast<int>(num));
    }
    
    return numbers;
}

void PmergeMe::displaySequence(const std::string& label, const std::vector<int>& sequence)
{
    std::cout << label;
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        if (i > 0) std::cout << " ";
        std::cout << sequence[i];
    }
    std::cout << std::endl;
}

// Helper functions for vector
void PmergeMe::insertionSortVector(std::vector<int>& container, size_t start, size_t end)
{
    for (size_t i = start + 1; i < end; ++i)
    {
        int key = container[i];
        size_t j = i;
        while (j > start)
        {
            _comparisons++;
            if (container[j - 1] <= key)
                break;
            container[j] = container[j - 1];
            j--;
        }
        container[j] = key;
    }
}

size_t PmergeMe::binarySearchVector(const std::vector<int>& container, int value, size_t start, size_t end)
{
    while (start < end)
    {
        size_t mid = start + (end - start) / 2;
        _comparisons++;
        if (container[mid] < value)
        {
            start = mid + 1;
        } else
        {
            end = mid;
        }
    }
    return start;
}

void PmergeMe::insertionSortDeque(std::deque<int>& container, size_t start, size_t end)
{
    for (size_t i = start + 1; i < end; ++i)
    {
        int key = container[i];
        size_t j = i;
        while (j > start)
        {
            _comparisons++;
            if (container[j - 1] <= key)
                break;
            container[j] = container[j - 1];
            j--;
        }
        container[j] = key;
    }
}

size_t PmergeMe::binarySearchDeque(const std::deque<int>& container, int value, size_t start, size_t end)
{
    while (start < end)
    {
        size_t mid = start + (end - start) / 2;
        _comparisons++;
        if (container[mid] < value)
        {
            start = mid + 1;
        } else
        {
            end = mid;
        }
    }
    return start;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& container)
{
    size_t n = container.size();
    if (n <= 1)
        return;
    
    if (n == 2)
    {
        _comparisons++;
        if (container[0] > container[1])
        {
            std::swap(container[0], container[1]);
        }
        return;
    }
    
    if (n == 3)
    {
        _comparisons++;
        if (container[0] > container[1])
        {
            std::swap(container[0], container[1]);
        }
        _comparisons++;
        if (container[1] > container[2])
        {
            std::swap(container[1], container[2]);
            _comparisons++;
            if (container[0] > container[1])
            {
                std::swap(container[0], container[1]);
            }
        }
        return;
    }
    
    // Ford-Johnson merge-insertion algorithm for n >= 4
    bool hasOdd = (n % 2 == 1);
    int oddElement = hasOdd ? container[n - 1] : 0;
    size_t pairCount = n / 2;
    
    // Step 1: Pair elements and find larger/smaller elements
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < pairCount; ++i)
    {
        _comparisons++;
        if (container[2 * i] > container[2 * i + 1])
        {
            pairs.push_back(std::make_pair(container[2 * i], container[2 * i + 1]));
        } else
        {
            pairs.push_back(std::make_pair(container[2 * i + 1], container[2 * i]));
        }
    }
    
    // Step 2: Sort larger elements recursively
    if (pairs.size() > 1)
    {
        std::vector<int> largerElements;
        for (size_t i = 0; i < pairs.size(); ++i)
        {
            largerElements.push_back(pairs[i].first);
        }
        
        fordJohnsonSortVector(largerElements);
        
        // Reorder pairs based on sorted larger elements
        std::vector<std::pair<int, int> > sortedPairs(pairs.size());
        for (size_t i = 0; i < largerElements.size(); ++i)
        {
            for (size_t j = 0; j < pairs.size(); ++j)
            {
                if (pairs[j].first == largerElements[i])
                {
                    sortedPairs[i] = pairs[j];
                    pairs[j].first = -1;
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }
    
    // Step 3: Build main chain
    std::vector<int> mainChain;
    
    // Insert first smaller element (guaranteed smallest)
    if (!pairs.empty())
    {
        mainChain.push_back(pairs[0].second);
    }
    
    // Insert all larger elements
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
    }
    
    // Step 4: Insert remaining smaller elements using Jacobsthal order
    if (pairs.size() > 1)
    {
        std::vector<size_t> jacobsthal = generateJacobsthalSequence(pairs.size() + 2);
        std::vector<bool> inserted(pairs.size(), false);
        inserted[0] = true;
        
        for (size_t jIdx = 2; jIdx < jacobsthal.size(); ++jIdx)
        {
            size_t jacobsthalNum = jacobsthal[jIdx];
            size_t prevJacobsthal = jacobsthal[jIdx - 1];
            
            // Insert in reverse order within Jacobsthal group
            for (size_t pos = std::min(jacobsthalNum, pairs.size()); pos > prevJacobsthal && pos > 0; --pos)
            {
                size_t idx = pos - 1;
                if (idx < pairs.size() && !inserted[idx])
                {
                    // Find upper bound (position of corresponding larger element)
                    size_t upperBound = mainChain.size();
                    for (size_t k = 0; k < mainChain.size(); ++k)
                    {
                        if (mainChain[k] == pairs[idx].first)
                        {
                            upperBound = k;
                            break;
                        }
                    }
                    
                    size_t insertPos = binarySearchVector(mainChain, pairs[idx].second, 0, upperBound);
                    mainChain.insert(mainChain.begin() + insertPos, pairs[idx].second);
                    inserted[idx] = true;
                }
            }
        }
        
        // Insert any remaining elements
        for (size_t i = 1; i < pairs.size(); ++i)
        {
            if (!inserted[i])
            {
                size_t upperBound = mainChain.size();
                for (size_t k = 0; k < mainChain.size(); ++k)
                {
                    if (mainChain[k] == pairs[i].first)
                    {
                        upperBound = k;
                        break;
                    }
                }
                
                size_t insertPos = binarySearchVector(mainChain, pairs[i].second, 0, upperBound);
                mainChain.insert(mainChain.begin() + insertPos, pairs[i].second);
            }
        }
    }
    
    // Step 5: Insert odd element if it exists
    if (hasOdd)
    {
        size_t insertPos = binarySearchVector(mainChain, oddElement, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + insertPos, oddElement);
    }
    
    container = mainChain;
}

// Ford-Johnson algorithm implementation for std::deque
void PmergeMe::fordJohnsonSortDeque(std::deque<int>& container)
{
    size_t n = container.size();
    if (n <= 1)
        return;
    
    // Handle base cases with known optimal comparison counts
    if (n == 2)
    {
        _comparisons++;
        if (container[0] > container[1])
        {
            std::swap(container[0], container[1]);
        }
        return;
    }
    
    if (n == 3)
    {
        _comparisons++;
        if (container[0] > container[1])
        {
            std::swap(container[0], container[1]);
        }
        _comparisons++;
        if (container[1] > container[2])
        {
            std::swap(container[1], container[2]);
            _comparisons++;
            if (container[0] > container[1])
            {
                std::swap(container[0], container[1]);
            }
        }
        return;
    }
    
    // Ford-Johnson merge-insertion algorithm for n >= 4
    bool hasOdd = (n % 2 == 1);
    int oddElement = hasOdd ? container[n - 1] : 0;
    size_t pairCount = n / 2;
    
    // Step 1: Pair elements and find larger/smaller elements
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < pairCount; ++i)
    {
        _comparisons++;
        if (container[2 * i] > container[2 * i + 1])
        {
            pairs.push_back(std::make_pair(container[2 * i], container[2 * i + 1]));
        } else
        {
            pairs.push_back(std::make_pair(container[2 * i + 1], container[2 * i]));
        }
    }
    
    // Step 2: Sort larger elements recursively
    if (pairs.size() > 1)
    {
        std::deque<int> largerElements;
        for (size_t i = 0; i < pairs.size(); ++i)
        {
            largerElements.push_back(pairs[i].first);
        }
        
        fordJohnsonSortDeque(largerElements);
        
        // Reorder pairs based on sorted larger elements
        std::vector<std::pair<int, int> > sortedPairs(pairs.size());
        for (size_t i = 0; i < largerElements.size(); ++i)
        {
            for (size_t j = 0; j < pairs.size(); ++j)
            {
                if (pairs[j].first == largerElements[i])
                {
                    sortedPairs[i] = pairs[j];
                    pairs[j].first = -1;
                    break;
                }
            }
        }
        pairs = sortedPairs;
    }
    
    // Step 3: Build main chain
    std::deque<int> mainChain;
    
    // Insert first smaller element (guaranteed smallest)
    if (!pairs.empty())
    {
        mainChain.push_back(pairs[0].second);
    }
    
    // Insert all larger elements
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
    }
    
    // Step 4: Insert remaining smaller elements using Jacobsthal order
    if (pairs.size() > 1)
    {
        std::vector<size_t> jacobsthal = generateJacobsthalSequence(pairs.size() + 2);
        std::vector<bool> inserted(pairs.size(), false);
        inserted[0] = true; // First element already inserted
        
        for (size_t jIdx = 2; jIdx < jacobsthal.size(); ++jIdx)
        {
            size_t jacobsthalNum = jacobsthal[jIdx];
            size_t prevJacobsthal = jacobsthal[jIdx - 1];
            
            // Insert in reverse order within Jacobsthal group
            for (size_t pos = std::min(jacobsthalNum, pairs.size()); pos > prevJacobsthal && pos > 0; --pos)
            {
                size_t idx = pos - 1;
                if (idx < pairs.size() && !inserted[idx])
                {
                    // Find upper bound (position of corresponding larger element)
                    size_t upperBound = mainChain.size();
                    for (size_t k = 0; k < mainChain.size(); ++k)
                    {
                        if (mainChain[k] == pairs[idx].first)
                        {
                            upperBound = k;
                            break;
                        }
                    }
                    
                    size_t insertPos = binarySearchDeque(mainChain, pairs[idx].second, 0, upperBound);
                    mainChain.insert(mainChain.begin() + insertPos, pairs[idx].second);
                    inserted[idx] = true;
                }
            }
        }
        
        // Insert any remaining elements
        for (size_t i = 1; i < pairs.size(); ++i)
        {
            if (!inserted[i])
            {
                size_t upperBound = mainChain.size();
                for (size_t k = 0; k < mainChain.size(); ++k)
                {
                    if (mainChain[k] == pairs[i].first)
                    {
                        upperBound = k;
                        break;
                    }
                }
                
                size_t insertPos = binarySearchDeque(mainChain, pairs[i].second, 0, upperBound);
                mainChain.insert(mainChain.begin() + insertPos, pairs[i].second);
            }
        }
    }
    
    // Step 5: Insert odd element if it exists
    if (hasOdd)
    {
        size_t insertPos = binarySearchDeque(mainChain, oddElement, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + insertPos, oddElement);
    }
    
    container = mainChain;
}

std::vector<int> PmergeMe::sortWithVector(const std::vector<int>& input, double& timeElapsed)
{
    double startTime = getCurrentTime();
    
    std::vector<int> result = input;
    fordJohnsonSortVector(result);
    
    double endTime = getCurrentTime();
    timeElapsed = endTime - startTime;
    
    return result;
}

std::deque<int> PmergeMe::sortWithDeque(const std::vector<int>& input, double& timeElapsed)
{
    double startTime = getCurrentTime();
    
    std::deque<int> result(input.begin(), input.end());
    fordJohnsonSortDeque(result);
    
    double endTime = getCurrentTime();
    timeElapsed = endTime - startTime;
    
    return result;
}

void PmergeMe::run(int argc, char** argv)
{
    try
    {
        std::vector<int> numbers = parseArguments(argc, argv);
        
        displaySequence("Before: ", numbers);
        
        resetComparisons();
        double vectorTime;
        std::vector<int> vectorResult = sortWithVector(numbers, vectorTime);
        size_t vectorComparisons = getComparisons();
        
        resetComparisons();
        double dequeTime;
        std::deque<int> dequeResult = sortWithDeque(numbers, dequeTime);
        size_t dequeComparisons = getComparisons();
        
        std::vector<int> dequeResultVector(dequeResult.begin(), dequeResult.end());
        
        displaySequence("After:  ", vectorResult);
        
        std::cout << "Time to process a range of " << numbers.size() 
                  << " elements with std::vector : " << vectorTime << " us" << std::endl;
        std::cout << "Time to process a range of " << numbers.size() 
                  << " elements with std::deque  : " << dequeTime << " us" << std::endl;
        
        std::cout << "Number of comparisons: " << std::max(vectorComparisons, dequeComparisons) << std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
