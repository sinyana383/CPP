#include <iostream>
#include "whatever.h"

int main()
{

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;

//	// swap /////////////
//	std::string a("a");
//	std::string b("b");
//
//	::swap(a, b);
//	std::cout << "a: " << a << std::endl;
//	std::cout << "b: " << b << std::endl;
//
//	float one = 1.1f;
//	float two = 2.2f;
//
//	::swap(one, two);
//	std::cout << "one: " << one << std::endl;
//	std::cout << "two: " << two << std::endl;
//	// //////////////////////

}
