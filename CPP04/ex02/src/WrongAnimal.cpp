#include "WrongAnimal.h"

#include "iostream"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = copy;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &variable)
{
	if (this == &variable) return *this;

	this->type = variable.type;
	return *this;
}
WrongAnimal::WrongAnimal(const std::string &otherType) : type(otherType)
{
	std::cout << "WrongAnimal setting type constructor" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal default sound" << std::endl;
}