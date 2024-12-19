#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    value = n << fractionalBits;
}

Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    value = roundf(n * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return value >> fractionalBits;
}

int Fixed::getRawBits(void) const {
    return value;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.value = this->value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.value = this->value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.value = (this->value * other.value) >> fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    if (other.value != 0) {
        result.value = (this->value << fractionalBits) / other.value;
    }
    return result;
}

Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->value++;
    return tmp;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->value--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
