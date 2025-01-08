/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:51:45 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/08 17:59:47 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _value;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed& other);
        ~Fixed();

        Fixed&              operator=(const Fixed& other);

        bool                operator>(const Fixed& other) const;
        bool                operator<(const Fixed& other) const;
        bool                operator>=(const Fixed& other) const;
        bool                operator<=(const Fixed& other) const;
        bool                operator==(const Fixed& other) const;
        bool                operator!=(const Fixed& other) const;

        Fixed               operator+(const Fixed& other) const;
        Fixed               operator-(const Fixed& other) const;
        Fixed               operator*(const Fixed& other) const;
        Fixed               operator/(const Fixed& other) const;

        Fixed&              operator++();
        Fixed               operator++(int);
        Fixed&              operator--();
        Fixed               operator--(int);

        static Fixed&       min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        float               toFloat(void) const;
        int                 toInt(void) const;
        int                 getRawBits(void) const;
        void                setRawBits(int const raw);
};

std::ostream&               operator<<(std::ostream& os, const Fixed& fixed);

#endif
