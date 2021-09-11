#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixedPoint;
        static const int numFractionalBits;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed & operator = (const Fixed &other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif