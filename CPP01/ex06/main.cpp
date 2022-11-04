#include "Harl.h"
#include "iostream"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "please, enter level" << std::endl;
		return (-1);
	}
	Harl harl;
	harl.harlFilter(argv[1]);
}
