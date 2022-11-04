#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : _name("defaultBureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	std::cout << "Bureaucrat name & grade constructor" << std::endl;
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = copy;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this == &bureaucrat) return *this;

	this->_grade = bureaucrat.getGrade();
	return *this;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat deconstruct" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (getGrade() <= 1) throw  Bureaucrat::GradeTooHighException();
	--_grade;
}
void Bureaucrat::decrementGrade()
{
	if (getGrade() >= 150) throw  Bureaucrat::GradeTooLowException();
	++_grade;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName()
					<< " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::ostream& operator<< ( std::ostream &stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return stream;
}