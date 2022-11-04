#include "Form.h"

Form::Form() : _name("defaultForm"), _isSigned(false), _gradeSigned(150), _gradeExecute(150)
{
	std::cout << "Form default constructor" << std::endl;
}
Form::Form(const std::string &name, const int gradeSigned, const int gradeExecute) : _name(name), _isSigned(false)
			, _gradeSigned(gradeSigned), _gradeExecute(gradeExecute)
{
	std::cout << "Form parameters constructor" << std::endl;
	if (_gradeSigned > 150 || _gradeExecute > 150) throw GradeTooLowException();
	if (_gradeSigned < 1 || _gradeExecute < 1) throw GradeTooHighException();
}
Form::Form(const Form &copy) : _name(copy.getName()),
							_gradeSigned(copy.getGradeSigned()), _gradeExecute(copy.getGradeExecute())
{
	std::cout << "Form copy constructor" << std::endl;
	*this = copy;
}
Form &Form::operator=(const Form &otherForm)
{
	if (this == &otherForm) return *this;

	this->_isSigned = otherForm._isSigned;
	return *this;
}
Form::~Form()
{
	std::cout << "Form deconstruct" << std::endl;
}

const std::string &Form::getName() const
{
	return _name;
}
int Form::getGradeSigned() const
{
	return _gradeSigned;
}
int Form::getGradeExecute() const
{
	return _gradeExecute;
}
bool Form::checkIsSigned() const
{
	return _isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->checkIsSigned()) throw FormAlreadySigned();
	if (bureaucrat.getGrade() > this->_gradeSigned) throw GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}
const char* Form::FormAlreadySigned::what() const throw()
{
	return "it is already signed";
}

std::ostream& operator<< ( std::ostream &stream, const Form& form)
{
	std::cout << "Form " << form.getName() << std::endl;
	std::cout << "grade for sign: " << form.getGradeSigned() << std::endl;
	std::cout << "grade for execution: " << form.getGradeExecute() << std::endl;
	std::cout << (form.checkIsSigned() ? "Signed" : "Not Signed") << std::endl;

	return stream;
}