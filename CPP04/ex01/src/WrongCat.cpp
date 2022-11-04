#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = copy;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &variable)
{
	if (this == &variable) return *this;

	this->type = variable.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "purr" << std::endl;
}
