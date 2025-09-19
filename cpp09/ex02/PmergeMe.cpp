#include"PmergeMe.hpp"

template <typename Container>
std::string getContainerName();

template <>
std::string getContainerName<std::vector<int> >() {
    return "vector<int>";
}

template <>
std::string getContainerName<std::deque<int> >() {
    return "deque<int>";
}

template<typename Container>
PmergeMe<Container>::PmergeMe() : _container(), _value(-1), _time(0), _comparisons(0) {}


template <typename Container>
PmergeMe<Container>::PmergeMe(char **data) : _container() {

    _time = 0;
    _value = -1;
    _comparisons = 0;

    for(size_t i = 0; data[i]; i++) {
        if (is_number(data[i]) != 0) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        _container.push_back(ft_stoa(data[i]));
    }
}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other) {
    _container = other._container;
    _value = other._value;
    _time = other._time;
    _comparisons = other._comparisons;
}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other) {
    if (this != &other) {
        _container = other._container;
        _value = other._value;
        _time = other._time;
        _comparisons = other._comparisons;
    }
    return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}


template <typename Container>
void PmergeMe<Container>::sort_numbers() {

    std::clock_t start = std::clock();
    _comparisons = 0; // reset counter for this sorting run
    if (_container.size() <= 1) {
        _time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
        return;
    }

    // Step 1: create pairs and store larger element first
    vector_pair pairs = generate_pairs(_container);

    // Step 2: sort the pairs by their first (larger) element using merge-sort based on counted comparisons
    sort_pairs(pairs); // counts comparisons internally via lessThan

    // Step 3: build the main chain (larger elements) and pending (smaller elements)
    Container mainChain;
    Container pending;
    for (size_type i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);   // larger
        pending.push_back(pairs[i].second);    // smaller
    }

    // Insert first pending element in front (guaranteed smaller than its pair first)
    _container.clear();
    _container.push_back(pending[0]);
    for (size_type i = 0; i < mainChain.size(); ++i) {
        _container.push_back(mainChain[i]);
    }

    // Generate Jacobsthal order for remaining pending elements (excluding the first already inserted)
    int_vector indexes = generate_indexes(pending.size());

    for (size_t k = 0; k < indexes.size(); ++k) {
        size_t pendIdx = indexes[k] - 1; // our generate_indexes starts from 1
        if (pendIdx == 0 || pendIdx >= pending.size()) continue;

        // Boundaries: search only in range [0, position_of_pair_first)
        // Find current position of pair.first in the container
        T pairFirst = pairs[pendIdx].first;
        int upperBoundExclusive = find_position(pairFirst); // position of the larger element
        if (upperBoundExclusive < 0) upperBoundExclusive = _container.size();

        int insertPos = binary_search_range(0, upperBoundExclusive, pending[pendIdx]);
        _container.insert(_container.begin() + insertPos, pending[pendIdx]);
    }

    // If odd size original list, insert leftover value
    if (_value != -1) {
        int pos = binary_search_range(0, _container.size(), _value);
        _container.insert(_container.begin() + pos, _value);
    }

    _time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template <typename Container>
typename PmergeMe<Container>::vector_pair PmergeMe<Container>::generate_pairs(Container &data) {
    vector_pair pairs;

    // If the size of the data is odd, we need to store the last element
    if (data.size() % 2 != 0) {
        _value = data.back();
        data.pop_back();
    }

size_type i = 0;
    while(i < data.size())
    {
        if (lessThan(data[i], data[i + 1])) {
            std::swap(data[i], data[i + 1]);
        }

        pairs.push_back(std::make_pair(data[i], data[i + 1]));
        i += 2;
    }
    return pairs;
}

template <typename Container>
void PmergeMe<Container>::sort_pairs(vector_pair &pairs) {
    if (pairs.size() <= 1) {
        return; // Base case: Nothing to sort
    }

    // Divide the vector into two halves
    size_type middle = pairs.size() / 2;
    vector_pair left(pairs.begin(), pairs.begin() + middle);
    vector_pair right(pairs.begin() + middle, pairs.end());

    // Recursively sort the two halves
    sort_pairs(left);
    sort_pairs(right);

   // Merge the sorted halves
    Merge_Sorted_halves(left, right, pairs);
}

template <typename Container>
void   PmergeMe<Container>::Merge_Sorted_halves( vector_pair leftHalf, vector_pair rightHalf, vector_pair &pairs)
{
    size_type leftIdx = 0;
    size_type rightIdx = 0;
    size_type idx = 0;

    while (leftIdx < leftHalf.size() && rightIdx < rightHalf.size()) {
        // compare the first elements of the pair (these are the larger elements of original pairs)
        if (lessThan(leftHalf[leftIdx].first, rightHalf[rightIdx].first)) {
            pairs[idx++] = leftHalf[leftIdx++];
        } else {
            pairs[idx++] = rightHalf[rightIdx++];
        }
    }

    while (leftIdx < leftHalf.size()) {
        pairs[idx++] = leftHalf[leftIdx++];
    }

    while (rightIdx < rightHalf.size()) {
        pairs[idx++] = rightHalf[rightIdx++];
    }
}

template <typename Container>
int PmergeMe<Container>::binary_search_range(int left, int rightExclusive, int target) {
    // classic lower_bound in [left, rightExclusive)
    while (left < rightExclusive) {
        int mid = left + (rightExclusive - left) / 2;
        if (lessThan(_container[mid], target)) {
            left = mid + 1;
        } else {
            // no equality branch to avoid second comparison
            rightExclusive = mid;
        }
    }
    return left;
}

template <typename Container>
int_vector PmergeMe<Container>::generate_indexes(size_t size) {
    int_vector indexes;
    int jacobsthalSequence[size + 1];

    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int lastJacobsthalNumber = 2;

    for (size_t i = 2; indexes.size() < size; i++)
    {
        // Generate the next Jacobsthal number
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

        if(i != 2)
        {
            indexes.push_back(jacobsthalSequence[i]);

        }

        // Push back the indexes between the last Jacobsthal number and the current one
        for (int j = jacobsthalSequence[i] - 1; j > lastJacobsthalNumber; j--)
            indexes.push_back(j);

        // Update the last Jacobsthal number
        lastJacobsthalNumber = jacobsthalSequence[i];
    }
    return (indexes);
}

template<typename Container>
void PmergeMe<Container>::print() const {
    for (size_t i = 0; i < _container.size(); i++) {
        std::cout << _container[i] << " ";
    }
    std::cout << std::endl;
}

template<typename Container>
void PmergeMe<Container>::benchmark() const {
    std::cout
            <<	"Time to process a range of " << _container.size()
            << " elements with std::" << getContainerName< Container >()
            << " : " << std::fixed << std::setprecision(5) << _time << " us"
            << std::endl;
}

template<typename Container>
bool PmergeMe<Container>::lessThan(const T &a, const T &b) {
    ++_comparisons;
    return a < b;
}

template<typename Container>
int PmergeMe<Container>::find_position(const T &value) const {
    for (size_t i = 0; i < _container.size(); ++i) {
        if (_container[i] == value) return static_cast<int>(i);
    }
    return -1;
}

template<typename Container>
int PmergeMe<Container>::ft_stoa(const char *str) {
    std::istringstream  ss(str);
    int                 number;

    ss >> number; // Convert the string

    return (number);
}

template<typename Container>
int PmergeMe<Container>::is_number(const std::string& s)
{
    if (s.empty() || s[0] == '-') {
        return (1);
    }

    size_t i = 0;

    if (s[0] == '+' && s.length() == 1) {
        return (1);
    } else if (s[0] == '+') {
        i++;
    }

    for (; i < s.length(); i++) {
        if (!std::isdigit(s[i])) {
            return (1);
        }
    }

    return (0);
}

template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;