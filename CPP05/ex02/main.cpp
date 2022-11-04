#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"

int main()
{
	// ExecuteForm /////////////////////////
	try
	{
		ShrubberyCreationForm f("forest");
		Bureaucrat mavka("Mavka", 145);

		mavka.executeForm(f);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		ShrubberyCreationForm f("forest");
		Bureaucrat mavka("Mavka", 145);

		mavka.signForm(f);
		mavka.executeForm(f);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	{
		ShrubberyCreationForm f("forest");
		Bureaucrat bereginya("Bereginya", 137);

		bereginya.signForm(f);
		bereginya.executeForm(f);
	}
		std::cout << std::endl;
	{
		RobotomyRequestForm r("forest");
		Bureaucrat liho("Lihoradka", 45);

		liho.signForm(r);
		liho.executeForm(r);
	}
		std::cout << std::endl;
	{
		PresidentialPardonForm p("human");
		Bureaucrat perun("Perun", 5);

		perun.signForm(p);
		perun.executeForm(p);
	}
}