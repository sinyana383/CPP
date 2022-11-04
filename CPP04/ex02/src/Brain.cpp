#include "Brain.h"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}
Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = copy;
}
Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}
Brain &Brain::operator=(const Brain &variable)
{
	if (this == &variable) return *this;

	for (int i = 0; i < 100; ++i)
		this->setIdea(i, variable.getIdeas()[i]);
	return *this;
}

const std::string *Brain::getIdeas() const
{
	return ideas;
}
void Brain::setIdea(unsigned int index, const std::string &idea)
{
	if (index >= 100) std::cout << index << " index is wrong(more than 99)" << std::endl;
	ideas[index] = idea;
}
