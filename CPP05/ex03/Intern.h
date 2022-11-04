#ifndef CPP05_INTERN_H
#define CPP05_INTERN_H
#include <string>
#include "Form.h"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern &operator=(const Intern &otherIntern);

	Form *makeForm(const std::string &name, const std::string &target);
};


#endif //CPP05_INTERN_H
