#include "Fixed.h"

const int Fixed::_nbFractionalBits = 8;

Fixed::Fixed() : _rawNum(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

Fixed &Fixed::operator=(const Fixed &num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &num) return *this;

	this->_rawNum = num.getRawBits();
	return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( _rawNum );
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawNum = raw;
}
