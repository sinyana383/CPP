#include "Dog.h"

#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain)
{
	std::cout << "Dog default constructor" << std::endl;
}
Dog::Dog(const Dog &copy) : brain(new Brain)
{
	std::cout << "Dog copy constructor" << std::endl;
	*this = copy;
}
Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	delete brain;
}
Dog &Dog::operator=(const Dog &variable)
{
	if (this == &variable) return *this;

	this->type = variable.type;
	*this->brain = *(variable.brain);
	return *this;
}

Brain *Dog::getBrain() const
{
	return brain;
}

void Dog::makeSound() const
{
	std::cout << "bark!" << std::endl;
}

