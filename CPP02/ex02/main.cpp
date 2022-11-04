#include "Fixed.h"
#include <iostream>

int main( void ) {
// Inc/Dec ////////////////////////////////////
	Fixed a;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;

	Fixed aa;
	std::cout << --aa << std::endl; // -0.00390625
	std::cout << aa << std::endl;
	std::cout << aa-- << std::endl; //0.00390625
	std::cout << aa << std::endl;   // -0.00390625
	std::cout << std::endl;

// +,-,*,/ /////////////////////////////////////////////
	Fixed e( Fixed( 5.05f ) + Fixed( 2 ) );
	std::cout << e << std::endl;

	e = Fixed(9.23f) - Fixed(10);
	std::cout << e << std::endl;

	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << b << std::endl;

	e = Fixed(5.5f) / Fixed(2);
	std::cout << e << std::endl;

// <, >, <=, >=, ==, != /////////////////////////////////////

	std::cout << (Fixed(5.05f) < Fixed(5) ? "true" : "false") << std::endl;
	std::cout << (Fixed(5.05f) > Fixed(5) ? "true" : "false") << std::endl;
	std::cout << std::endl;

	std::cout << (Fixed(5.05f) <= Fixed(5) ? "true" : "false") << std::endl;
	std::cout << (Fixed(5.05f) >= Fixed(5) ? "true" : "false") << std::endl;
	std::cout << (Fixed(5.05f) >= Fixed(5.05f) ? "true" : "false") << std::endl;
	std::cout << std::endl;

	std::cout << (Fixed(5.05f) == Fixed(5.05f) ? "true" : "false") << std::endl;
	std::cout << (Fixed(5.05f) != Fixed(5.055f) ? "true" : "false") << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	Fixed a1( 42.42f);
	Fixed a2( 3.33f );
	Fixed::max( a1, a2 ) = e; // можно приравнять, если без const

	std::cout << e << std::endl;
	std::cout << a1 << std::endl;
	return 0;
}