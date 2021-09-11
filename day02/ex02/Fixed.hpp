#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPoint;
        static const int numFractionalBits;
    public:
        Fixed();
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed(const Fixed &other);

        bool operator <(const Fixed &other);
        bool operator >(const Fixed &other);
        bool operator <=(const Fixed &other);
        bool operator >=(const Fixed &other);
        bool operator ==(const Fixed &other);
        bool operator !=(const Fixed &other);

        static float min(Fixed &a, Fixed &b);
        static float max(Fixed &a, Fixed &b);
        static float min(const Fixed &a, const Fixed &b);
        static float max(const Fixed &a, const Fixed &b);

        Fixed &operator ++();
        Fixed &operator --();
        Fixed operator ++(int nbr);
        Fixed operator --(int nbr);

        Fixed & operator = (const Fixed &other);
        float operator + (const Fixed &other);
        float operator - (const Fixed &other);
        float operator * (const Fixed &other);
        float operator / (const Fixed &other);
        

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        ~Fixed();
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif