#ifndef CPP05_BUREAUCRAT_H
#define CPP05_BUREAUCRAT_H
#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat& bureaucrat);
	Bureaucrat(const std::string &name, int grade);

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<< ( std::ostream &stream, const Bureaucrat& bureaucrat);
#endif
