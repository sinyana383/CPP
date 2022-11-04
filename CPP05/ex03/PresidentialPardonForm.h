#ifndef CPP05_PRESIDENTIALPARDONFORM_H
#define CPP05_PRESIDENTIALPARDONFORM_H
#include "Form.h"

class PresidentialPardonForm : public Form
{
private:
	std::string _target;

	void executeForm() const;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &otherPresidentialPardonForm);

	const std::string &getTarget() const;

};


#endif
