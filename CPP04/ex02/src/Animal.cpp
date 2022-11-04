#include "Animal.h"
#include "iostream"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor" << std::endl;
}
Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = copy;
}
Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}
Animal &Animal::operator=(const Animal &variable)
{
	if (this == &variable) return *this;

	this->type = variable.type;
	return *this;
}
Animal::Animal(const std::string &otherType) : type(otherType)
{
	std::cout << "Animal setting type constructor" << std::endl;
}

const std::string &Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal default sound" << std::endl;
}