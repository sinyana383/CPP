#include "Form.h"

int main()
{
	// Form Constructors/////////////////
	try
	{
		Form mavka("Mavka", 151, 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form mavka("Mavka", 150, 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form perun("Perun", 0, 2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form perun("Perun", 2, 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	// beSigned/ sign
	try
	{
		Form light("Lightning", 10, 5);
		Bureaucrat perun("Perun", 11);
		light.beSigned(perun);
		std::cout << light;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Form light("Lightning", 10, 5);
	Bureaucrat perun("Perun", 11);
	perun.signForm(light);
	perun.incrementGrade();
	std::cout << perun;
	perun.signForm(light);
	
	std::cout << "--------------------------------" << std::endl;
	Bureaucrat stribog("Stribog", 10);
	stribog.signForm(light);
	std::cout << light;
}