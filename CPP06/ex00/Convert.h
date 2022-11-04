#ifndef CPP06_CONVERT_H
#define CPP06_CONVERT_H
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iostream>
#include <iomanip>

class Convert {
private:
    char _type;

    char _charNum;
    int _intNum;
    float _floatNum;
    double _doubleNum;

    bool _charPossible;
    bool _intPossible;
    bool _floatPossible;
public:
    Convert();
    Convert(const Convert& copy);
    ~Convert();
    Convert &operator=(const Convert& otherInstance);

    char getType() const;
    char getCharNum() const;
    int getIntNum() const;
    float getFloatNum() const;
    double getDoubleNum() const;

    void setType(char type);

    void convertFromFloating(std::string &scalar);
    void convertFromInt(std::string &scalar);
    void convertFromChar(const char *scalar);

    void printResult() const;
};

#endif //CPP06_CONVERT_H
