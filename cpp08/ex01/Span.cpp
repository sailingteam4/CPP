#include "Span.hpp"

Span::Span() : _maxSize(0) {
}

Span::Span(unsigned int n) : _maxSize(n) {
    _numbers.reserve(n);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    
    return *maxIt - *minIt;
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is already full";
}

const char* Span::NoSpanException::what() const throw() {
    return "Not enough numbers to calculate span";
}

unsigned int Span::size() const {
    return _numbers.size();
}

unsigned int Span::capacity() const {
    return _maxSize;
}
