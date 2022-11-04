#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
//	std::cout << "RobotomyRequestForm default constructor" << std::endl;
	_target = "void";
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45)
{
//	std::cout << "RobotomyRequestForm parameters constructor" << std::endl;
	_target = target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy)
{
//	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = copy;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &otherRobotomyRequestForm)
{
	if (this == &otherRobotomyRequestForm) return *this;


	this->_target = otherRobotomyRequestForm.getTarget();
	Form *p1 = this;
	const Form *p2 = &otherRobotomyRequestForm;
	*p1 = *p2;
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
//	std::cout << "RobotomyRequestForm deconstruct" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::executeForm() const
{
	std::cout << "drrrrrrr..." << std::endl;
	srand(time(nullptr));
	if (rand() % 2 == 0)
		std::cout << "robotomy failed" << std::endl;
	else
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
}


