#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
	_target = "void";
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm parameters constructor" << std::endl;
	_target = target;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy)
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = copy;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &otherPresidentialPardonForm)
{
	if (this == &otherPresidentialPardonForm) return *this;


	this->_target = otherPresidentialPardonForm.getTarget();
	Form *p1 = this;
	const Form *p2 = &otherPresidentialPardonForm;
	*p1 = *p2;
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstruct" << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::executeForm() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}