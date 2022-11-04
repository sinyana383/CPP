#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string str(argv[i]);
		for (int j = 0; j < (int)str.length(); ++j)
			std::cout << (char)std::toupper(str.at(j));
	}
	std::cout << std::endl;
}