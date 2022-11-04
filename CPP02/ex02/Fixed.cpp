#include "Fixed.h"

const int Fixed::_nbFractionalBits = 8;	// используй только с побитовым сдвигом!!!

Fixed::Fixed() : _rawNum(0)
{
	//std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int intNum) : _rawNum(intNum << _nbFractionalBits)
{
	//std::cout << "Int constructor called" << std::endl;
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
	//std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &num)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = num;
}
Fixed::~Fixed() { //std::cout << "Destructor called" << std::endl;
	}

Fixed &Fixed::operator=(const Fixed &num)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this == &num) return *this;

	this->setRawBits(num.getRawBits());
	return *this;
}


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

Fixed Fixed::operator++(int)
{
	Fixed old = *this;

	++(*this);
	return old;
}
Fixed Fixed::operator++()
{
	++_rawNum;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed old = *this;

	--(*this);
	return old;
}
Fixed Fixed::operator--()
{
	--_rawNum;
	return *this;
}

Fixed Fixed::operator+(const Fixed &num) const
{
//	res.setRawBits(this->getRawBits() + num.getRawBits());
	return (this->toFloat() + num.toFloat());
}
Fixed Fixed::operator-(const Fixed &num) const
{
//	res.setRawBits(this->getRawBits() - num.getRawBits());
	return (this->toFloat() - num.toFloat());
}
Fixed Fixed::operator*(const Fixed &num) const
{
//	res.setRawBits(this->getRawBits() * num.getRawBits() >> _nbFractionalBits);
	return (this->toFloat() * num.toFloat());
}
Fixed Fixed::operator/(const Fixed &num) const
{
	return (this->toFloat() / num.toFloat());
}

bool Fixed::operator<(const Fixed &num) const
{
	return (this->getRawBits() < num.getRawBits());
}
bool Fixed::operator>(const Fixed &num) const
{
	return (this->getRawBits() > num.getRawBits());
}
bool Fixed::operator<=(const Fixed &num) const
{
	return (this->getRawBits() <= num.getRawBits());
}
bool Fixed::operator>=(const Fixed &num) const
{
	return (this->getRawBits() >= num.getRawBits());
}
bool Fixed::operator==(const Fixed &num) const
{
	return (this->getRawBits() == num.getRawBits());
}
bool Fixed::operator!=(const Fixed &num) const
{
	return (this->getRawBits() != num.getRawBits());
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}
Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}
const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	return (num1.getRawBits() < num2.getRawBits() ? num1 : num2);
}
const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	return (num1.getRawBits() > num2.getRawBits() ? num1 : num2);
}

std::ostream& operator<< (std::ostream& stream, const Fixed& num)
{
	stream << num.toFloat();
	return (stream);
}