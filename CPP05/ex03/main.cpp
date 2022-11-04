#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"

int main()
{
	Intern someRandomIntern;
	Form *f = someRandomIntern.makeForm("shrubberii creation", "forest");
	(void)f;
		std::cout << std::endl;
	{
		Intern someRandomIntern;
		Form *f = someRandomIntern.makeForm("shrubbery creation", "forest");
		Bureaucrat bereginya("Bereginya", 137);

		bereginya.signForm(*f);
		bereginya.executeForm(*f);
		delete f;
	}
		std::cout << std::endl;
	{
		Intern someRandomIntern;
		Form *r = someRandomIntern.makeForm("robotomy request", "forest");
		Bureaucrat liho("Lihoradka", 45);

		liho.signForm(*r);
		liho.executeForm(*r);
		delete r;
	}
		std::cout << std::endl;
	{
		Intern someRandomIntern;
		Form *p = someRandomIntern.makeForm("presidential pardon", "forest");
		Bureaucrat perun("Perun", 5);

		perun.signForm(*p);
		perun.executeForm(*p);
		delete p;
	}
}