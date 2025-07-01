#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    
    int shortestSpan() const;
    int longestSpan() const;

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    unsigned int size() const;
    unsigned int capacity() const;
};

template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    size_t distance = std::distance(begin, end);
    if (_numbers.size() + distance > _maxSize) {
        throw SpanFullException();
    }
    _numbers.insert(_numbers.end(), begin, end);
}

#endif
