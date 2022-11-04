#include "Dog.h"
#include "../inc/Dog.h"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor" << std::endl;
}
Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor" << std::endl;
	*this = copy;
}
Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}
Dog &Dog::operator=(const Dog &variable)
{
	if (this == &variable) return *this;

	this->type = variable.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "bark!" << std::endl;
}
