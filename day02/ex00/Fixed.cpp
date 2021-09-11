#include "Fixed.hpp"


Fixed::Fixed()
{
    std::cout << "Default constructor called\n"; 
    this->fixedPoint = 0;
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
    std::cout << "getRawBits member function called\n";
    return (this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    this->fixedPoint = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}