#ifndef CPP05_ROBOTOMYREQUESTFORM_H
#define CPP05_ROBOTOMYREQUESTFORM_H
#include "Form.h"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
private:
	std::string _target;

	void executeForm() const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &otherRobotomyRequestForm);

	const std::string &getTarget() const;
};


#endif
