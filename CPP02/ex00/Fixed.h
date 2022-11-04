#ifndef CPP02_FIXED_H
#define CPP02_FIXED_H
#include "iostream"

class Fixed
{
private:
	int	_rawNum;							// raw - как "сырое", тип заготовка
	static const int _nbFractionalBits;
public:
	Fixed();
	Fixed ( const Fixed& num );
	~Fixed();
	Fixed& operator=(const Fixed& num);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif //CPP02_FIXED_H
