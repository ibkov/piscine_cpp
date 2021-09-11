#include "Fixed.hpp"

const int Fixed::numFractionalBits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called\n"; 
    this->fixedPoint = 0;
}

Fixed::Fixed(const int nbr)
{
    std::cout << "Int constructor called\n"; 
    this->fixedPoint = nbr * (1 << this->numFractionalBits);
}

Fixed::Fixed(const float nbr)
{
    std::cout << "Float constructor called\n"; 
    this->fixedPoint = roundf(nbr * (1 << this->numFractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignation operator called\n";
    if (this != &other)
        this->fixedPoint = other.getRawBits();
    return *(this);
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called\n";
    return (this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    this->fixedPoint = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

float Fixed::toFloat( void ) const
{
    return (float)(this->fixedPoint / (float)(1 << this->numFractionalBits));
}

int Fixed::toInt( void ) const
{
    return this->fixedPoint / (1 << this->numFractionalBits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}