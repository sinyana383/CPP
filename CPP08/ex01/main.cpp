#include "Span.h"
#include <iomanip>

int  main()
{
	std::cout << std::setfill('-') << std::setw(50) << "subject check" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::setfill('-') << std::setw(50)  <<  "addNumber, shortestSpan, longestSpan" << std::endl;
	{
		const unsigned int size = 10;
		Span sp(size);

		std::cout << sp;
		std::cout << std::endl;
		for (unsigned i = 0; i < size / 2; ++i)
			sp.addNumber(i);
		sp.addNumber(-10);
		std::cout << sp;
		std::cout << "shortest: " << sp.longestSpan() << std::endl;
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << std::endl;

		std::cout << std::setfill('-') << std::setw(50)  <<  "exceptions" << std::endl;
		try
		{
			for (unsigned i = size / 2; i < size - 1; ++i)
				sp.addNumber(i);
			std::cout << sp;
			sp.addNumber(11);
		}
		catch (std::exception &e)
		{
			std::cout << "addNumber: " << e.what() << std::endl;
		}
		std::cout << std::endl;

		try
		{
			Span s(10);
			s.addNumber(22);
			s.addNumber(23);

			std::vector<int> temp(8, -1);
			std::cout << s;
			s.addRange(temp.begin(), temp.end());
			std::cout << s;
			s.addRange(temp.begin(), temp.end());
		}
		catch (std::exception &e)
		{
			std::cout << "addRange: " << e.what() << std::endl;
		}
		std::cout << std::endl;

		try
		{
			Span s(10);

			s.addNumber(1);
			std::cout << s;
			s.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << "shortestSpan: " << e.what() << std::endl;
		}
		std::cout << std::endl;

		try
		{
			Span s(10);

			std::cout << s;
			s.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << "longestSpan: " << e.what() << std::endl;
		}
	}
	{
		Span s(20000);

		for (unsigned int i = 0; i < 20000; i++)
			s.addNumber(i);
		std::cout << s;
	}
}
