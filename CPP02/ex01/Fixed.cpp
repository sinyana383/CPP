#include "Fixed.h"

const int Fixed::_nbFractionalBits = 8;	// используй только с побитовым сдвигом!!!

Fixed::Fixed() : _rawNum(0) { std::cout << "Default constructor called" << std::endl; }
Fixed::Fixed(const int intNum) : _rawNum(intNum << _nbFractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}
/*
 в десятичном представлении это было бы так:
 12,123456789 * 10^8(8 разрядов) == 1212345678,9
 roundd(1212345678,9) == 1212345679 - сырое число с неопределенной запятой
 мы договорились, что будем показывать до 8 разрядов.
 При выводе мы уже знаем что запятая будет подставляться на восьмое место с конца
 12,12345679
 Внизу же все просто двоично
*/
Fixed::Fixed(const float floatNum) : _rawNum( roundf(floatNum * (1 << _nbFractionalBits)) )
{
	std::cout << "Float constructor called" << std::endl;
}
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
	return ( _rawNum );
}
void Fixed::setRawBits(const int raw)
{
	_rawNum = raw;
}

int Fixed::toInt(void) const { return ( getRawBits() >> _nbFractionalBits ); }
float Fixed::toFloat(void) const { return ((float)((float)getRawBits() / (1 << _nbFractionalBits) )); }

std::ostream& operator<< (std::ostream& stream, const Fixed& num)
{
	stream << num.toFloat();
	return (stream);
}