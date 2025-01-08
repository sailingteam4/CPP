/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:24:51 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/08 17:33:37 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int              _value;
        static const int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed& other);
        Fixed&          operator=(const Fixed& other);
        ~Fixed();

        float           toFloat(void) const;
        int             toInt(void) const;

        int             getRawBits(void) const;
        void            setRawBits(int const raw);
};

std::ostream&           operator<<(std::ostream& os, const Fixed& fixed);

#endif
