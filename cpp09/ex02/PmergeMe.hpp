#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <string>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdlib>

typedef std::vector<int> int_vector;

template<typename Container>
class PmergeMe
{
    public:
        typedef typename Container::value_type T;
        typedef typename Container::size_type size_type;
        typedef std::pair<T, T> type_pair;
        typedef std::vector<type_pair> vector_pair;
    private:
        Container _container; //_container
        T _value; //_value
        double _time;
        std::size_t _comparisons; // number of key comparisons performed by Ford-Johnson sort

        int        is_number(const std::string& s);
        vector_pair generate_pairs(Container &container);
        int_vector generate_indexes(size_t size);
    int binary_search_range(int left, int right, int target); // right is exclusive
        void sort_pairs(vector_pair &pairs);
        int ft_stoa(const char *str);
        // Wrapped comparison helpers to count key comparisons
        bool lessThan(const T &a, const T &b);
    // linear scan helper (does not count comparisons) to find current position of an element
    int find_position(const T &value) const;
    public:
        PmergeMe();
        explicit PmergeMe(char **argv);
        PmergeMe(const PmergeMe &pmergeMe);
        PmergeMe &operator=(const PmergeMe &pmergeMe);
        ~PmergeMe();
        void print()const;
        void sort_numbers();
        void benchmark()const;
        void Merge_Sorted_halves(vector_pair leftHalf, vector_pair rightHalf, vector_pair &pairs);
        std::size_t comparisons() const { return _comparisons; }

        




};




#endif