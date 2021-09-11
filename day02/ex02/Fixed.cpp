#include "Fixed.hpp"

const int Fixed::numFractionalBits = 8;

// constractors

Fixed::Fixed()
{
    // std::cout << "Default constructor called\n"; 
    this->fixedPoint = 0;
}

Fixed::Fixed(const int nbr)
{
    // std::cout << "Int constructor called\n"; 
    this->fixedPoint = nbr * (1 << this->numFractionalBits);
}

Fixed::Fixed(const float nbr)
{
    // std::cout << "Float constructor called\n"; 
    this->fixedPoint = roundf(nbr * (1 << this->numFractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called\n";
    *this = other;
}

// overload operators

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Assignation operator called\n";
    if (this != &other)
        this->fixedPoint = other.getRawBits();
    return *(this);
}

// overload operators (float)

float Fixed::operator+(const Fixed &other)
{
    float nbr;
    nbr = (this->toFloat() + other.toFloat());
    return nbr;
}

float Fixed::operator-(const Fixed &other)
{
    float nbr;
    nbr = (this->toFloat() - other.toFloat());
    return nbr;
}

float Fixed::operator*(const Fixed &other)
{
    float nbr;
    nbr = (this->toFloat() * other.toFloat());
    return nbr;
}

float Fixed::operator/(const Fixed &other)
{
    float nbr;
    nbr = (this->toFloat() / other.toFloat());
    return nbr;
}

float Fixed::min(Fixed &a, Fixed &b)
{
    if (a.fixedPoint < b.fixedPoint)
        return a.toFloat();
    else 
        return b.toFloat();
}

float Fixed::max(Fixed &a, Fixed &b)
{
    if (a.fixedPoint > b.fixedPoint)
        return a.toFloat();
    else 
        return b.toFloat();
}

float Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.fixedPoint < b.fixedPoint)
        return a.toFloat();
    else 
        return b.toFloat();
}

float Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.fixedPoint > b.fixedPoint)
        return a.toFloat();
    else 
        return b.toFloat();
}

// overload operators (bool)

bool Fixed::operator ==(const Fixed &other)
{
    if (this->fixedPoint == other.fixedPoint)
        return true;
    else
        return false;
}

bool Fixed::operator !=(const Fixed &other)
{
    if (this->fixedPoint != other.fixedPoint)
        return true;
    else
        return false;
}

bool Fixed::operator >(const Fixed &other)
{
    if (this->fixedPoint > other.fixedPoint)
        return true;
    else
        return false;
}

bool Fixed::operator >=(const Fixed &other)
{
    if (this->fixedPoint >= other.fixedPoint)
        return true;
    else
        return false;
}

bool Fixed::operator <=(const Fixed &other)
{
    if (this->fixedPoint <= other.fixedPoint)
        return true;
    else
        return false;
}

// overload operators (Fixed)

Fixed &Fixed::operator++()
{
    this->fixedPoint++;
    return *this;
}


Fixed &Fixed::operator--()
{
    this->fixedPoint--;
    return *this;
}

Fixed Fixed::operator++(__unused int nbr)
{
    Fixed tmp_nbr(*this);

    this->fixedPoint++;
    return tmp_nbr;
}

Fixed Fixed::operator--(__unused int nbr)
{
    Fixed tmp_nbr(*this);

    this->fixedPoint--;
    return tmp_nbr;
}

// functions 

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called\n";
    return (this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    this->fixedPoint = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)(this->fixedPoint / (float)(1 << this->numFractionalBits));
}

int Fixed::toInt( void ) const
{
    return this->fixedPoint / (1 << this->numFractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

// destructor

Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";
}