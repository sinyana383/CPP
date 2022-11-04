#ifndef CPP05_FORM_H
#define CPP05_FORM_H
#include <string>
#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int 			_gradeSigned;
	const int 			_gradeExecute;
public:
	Form();
	Form(const std::string &name, const int gradeSigned, const int gradeExecute);
	Form(const Form &copy);
	~Form();
	Form &operator=(const Form &otherForm);

	const std::string &getName() const;
	int getGradeSigned() const;
	int getGradeExecute() const;
	bool checkIsSigned() const;

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormAlreadySigned : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream& operator<< ( std::ostream &stream, const Form& form);

#endif
