#include <iostream>
#include "Convert.h"

int errorPrint(const std::string &massage)
{
    std::cout << massage << std::endl;
    return (-1);
}

bool specialScalar(const std::string &scalar)
{
    std::string pLiterals[6] = { "-inff", "+inff", "nanf",
                                 "-inf", "+inf", "nan"};
    for (int i = 0; i < 6; ++i) {
        if (pLiterals[i] == scalar)
        {
            std::cout << "char: " << "impossible" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            std::cout << "float: " << pLiterals[i % 3] << std::endl;
            std::cout << "double: " << pLiterals[i % 3 + 3] << std::endl;
            return true;
        }
    }
    return false;
}

char getScalarType(std::string &scalar)
{
    bool dotFlag = false;

    if ((scalar[0] < '0' || scalar[0] > '9'))
    {
        if (!scalar[1])
            return 'c';
        if (scalar[0] != '-')
            return '\0';
    }
    for (unsigned int i = 1; scalar[i]; ++i) {
        if (scalar[i] < '0' || scalar[i] > '9')
        {
            if (scalar[i] == '.' && !dotFlag && 
            (scalar[i - 1] >= '0' && scalar[i - 1] <= '9') && (scalar[i + 1] >= '0' && scalar[i + 1] <= '9'))
            {
                dotFlag = true;
                continue;
            }
            if (!scalar[i + 1] && scalar[i] == 'f' && dotFlag)
                return 'f';
            return '\0';
        }
    }
    if (dotFlag)
        return 'd';
    return 'i';
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return errorPrint("wrong argument number");

    std::string scalar(argv[1]);
    if (specialScalar(scalar))
        return 1;

    Convert c;
    c.setType(getScalarType(scalar));

    try
    {
        switch (c.getType()) {
            case 'd':
            case 'f':
                c.convertFromFloating(scalar);
                break;
            case 'i':
                c.convertFromInt(scalar);
                break;
            case 'c':
                c.convertFromChar(scalar.c_str());
                break;
            default:
                return errorPrint("couldn't convert to anything");
        }
        c.printResult();
    }
    catch (const char *error)
    {
        std::cout << error << std::endl;
    }
}