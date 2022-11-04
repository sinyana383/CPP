#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"


Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}
Intern::Intern(const Intern &copy) {
	std::cout << "Intern copy constructor" << std::endl;
	*this = copy;
}
Intern &Intern::operator=(const Intern &otherIntern)
{
	if (this == &otherIntern) return *this;
	return *this;
}
Intern::~Intern()
{
	std::cout << "Intern deconstruct" << std::endl;
}

Form *Intern::makeForm(const std::string &name, const std::string &target)
{
	Form 	*resultForm = nullptr;
	int		resultMassage = 4;

	std::string strs[5] =
			{
			"shrubbery creation",
			"robotomy request",
			"presidential pardon",

				"Intern creates ",
				"Intern couldn't create "
			};
	Form *forms [3] =
			{
			new ShrubberyCreationForm(target),
			new RobotomyRequestForm(target),
			new PresidentialPardonForm(target)
			};

	for (int i = 0; i < 3; ++i)
	{
		if (strs[i] == name)
		{
			resultForm = forms[i];
			resultMassage = 3;
			continue;
		}
		delete forms[i];
	}

	std::cout << strs[resultMassage] << name << std::endl;
	return resultForm;
}
