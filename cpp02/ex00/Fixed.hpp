/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:34:15 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/08 17:25:39 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int              _value;
        static const int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed&          operator=(const Fixed& other);
        ~Fixed();

        int             getRawBits(void) const;
        void            setRawBits(int const raw);
};

#endif
