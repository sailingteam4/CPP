#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
