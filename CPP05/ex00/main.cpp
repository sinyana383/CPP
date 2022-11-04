#include "Bureaucrat.h"

int main()
{
	// Constructors/////
	try
	{
		Bureaucrat mavka("Mavka", 150);
		std::cout << mavka;
		Bureaucrat domovoi("Domovoi", 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat zemlya("Zemlya", 1);
		Bureaucrat perun("Perun", 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Gettters and inc/decrement///////
	try
	{
		Bureaucrat zemlya("Zemlya", 2);
		std::cout << zemlya;

		zemlya.incrementGrade();
		std::cout << zemlya;
		zemlya.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat ovinnik("Ovinnik", 149);

		ovinnik.decrementGrade();
		std::cout << ovinnik;
		ovinnik.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}