//
// Created by 1 on 27.10.2022.
//

#include "Convert.h"

Convert::Convert() : _type('\0'), _charNum(0), _intNum(0), _floatNum(0.0f), _doubleNum(0.0),
                    _charPossible(true), _intPossible(true), _floatPossible(true){
}
Convert::Convert(const Convert &copy) {
    *this = copy;
}
Convert::~Convert() {
}
Convert &Convert::operator=(const Convert &otherInstance) {
    if (this == &otherInstance) return *this;

    this->_type = otherInstance.getType();

    this->_charNum = otherInstance.getCharNum();
    this->_intNum = otherInstance.getIntNum();
    this->_floatNum = otherInstance.getFloatNum();
    this->_doubleNum = otherInstance.getDoubleNum();

	this->_charPossible = otherInstance._charPossible;
	this->_intPossible = otherInstance._intPossible;
	this->_floatPossible = otherInstance._floatPossible;
    return *this;
}

char Convert::getType() const {
    return _type;
}
char Convert::getCharNum() const {
    return _charNum;
}
int Convert::getIntNum() const {
    return _intNum;
}
float Convert::getFloatNum() const {
    return _floatNum;
}
double Convert::getDoubleNum() const {
    return _doubleNum;
}

void Convert::setType(char type) {
    _type = type;
}

void Convert::convertFromFloating(std::string &scalar) {
    _doubleNum = strtod(scalar.c_str(), NULL); // f может не принять

    if (_doubleNum == HUGE_VAL || _doubleNum == -HUGE_VAL)
        throw ("floating type overflow");

    if ( _doubleNum < static_cast<double>(-std::numeric_limits<float>::max())  ||
         _doubleNum > static_cast<double>(std::numeric_limits<float>::max()))
    {
        if (getType() == 'f') throw ("float overflow");

        _charPossible = false;
        _intPossible = false;
        _floatPossible = false;
        return ;
    }

    _floatNum = static_cast<float>(_doubleNum);
    if (_doubleNum < static_cast<double>(std::numeric_limits<int>::min()) ||
	    _doubleNum > static_cast<double>(std::numeric_limits<int>::max()))
    {
        _charPossible = false;
        _intPossible = false;
        return;
    }

    _intNum = static_cast<int>(_doubleNum);
    if (_doubleNum < static_cast<double>(std::numeric_limits<char>::min()) ||
	    _doubleNum > static_cast<double>(std::numeric_limits<char>::max()))
    {
        _charPossible = false;
        return;
    }

    _charNum = static_cast<char>(_doubleNum);
}

void Convert::convertFromInt(std::string &scalar) {

    long int intRes = strtol(scalar.c_str(), NULL, 10);

    if (intRes < static_cast<long int>(std::numeric_limits<int>::min())
        || intRes > static_cast<long int>(std::numeric_limits<int>::max()))
        throw ("int overflowed");

    _intNum = static_cast<int>(intRes);
    if (_intNum < static_cast<int>(std::numeric_limits<char>::min()) ||
        _intNum > static_cast<int>(std::numeric_limits<char>::max()))
        _charPossible = false;
    else
        _charNum = static_cast<char>(_intNum);

    _floatNum = static_cast<float>(_intNum);
    _doubleNum = static_cast<double>(_intNum);
}

void Convert::convertFromChar(const char *scalar) {

    if (scalar[0] < 32 || scalar[0] > 126) throw ("non displayable used as input");
    _charNum = scalar[0];
    _intNum = static_cast<int>(_charNum);
    _floatNum = static_cast<float>(_charNum);
    _doubleNum = static_cast<double>(_charNum);
}

void Convert::printResult() const
{
    std::cout << "char: ";
    if (_charPossible)
    {
        if (_charNum < 32 || _charNum > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << _charNum << "'" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (_intPossible)
        std::cout << _intNum << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << std::setprecision(1);
    std::cout << std::fixed;
    std::cout << "float: ";
    if (_floatPossible)
        std::cout << _floatNum << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "double: " << _doubleNum << std::endl;
}



