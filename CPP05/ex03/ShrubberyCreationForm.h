#ifndef CPP05_SHRUBBERYCREATIONFORM_H
#define CPP05_SHRUBBERYCREATIONFORM_H
#include "Form.h"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;

	void executeForm() const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &otherShrubberyCreationForm);

	class unableToOpenFile : public std::exception
	{
		virtual const char* what() const throw();
	};

	const std::string &getTarget() const;
};


#endif //CPP05_SHRUBBERYCREATIONFORM_H
