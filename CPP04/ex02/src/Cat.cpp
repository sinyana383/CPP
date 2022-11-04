#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat default constructor" << std::endl;
}
Cat::Cat(const Cat &copy) : brain(new Brain)
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = copy;
}
Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete brain;
}
Cat &Cat::operator=(const Cat &variable)
{
	if (this == &variable) return *this;

	this->type = variable.type;
	*this->brain = *(variable.brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "purr" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brain;
}
