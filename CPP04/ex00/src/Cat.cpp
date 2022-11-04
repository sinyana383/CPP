#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor" << std::endl;
}
Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = copy;
}
Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}
Cat &Cat::operator=(const Cat &variable)
{
	if (this == &variable) return *this;

	this->type = variable.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "purr" << std::endl;
}
