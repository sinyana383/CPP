#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
//	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
	_target = "void";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137)
{
//	std::cout << "ShrubberyCreationForm parameters constructor" << std::endl;
	_target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy)
{
//	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	*this = copy;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &otherShrubberyCreationForm)
{
	if (this == &otherShrubberyCreationForm) return *this;


	this->_target = otherShrubberyCreationForm.getTarget();
	Form *p1 = this;
	const Form *p2 = &otherShrubberyCreationForm;
	*p1 = *p2;
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
//	std::cout << "ShrubberyCreationForm deconstruct" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return _target;
}

const char *ShrubberyCreationForm::unableToOpenFile::what() const throw()
{
	return ("unable to open/create file");
}

void ShrubberyCreationForm::executeForm() const
{
	std::ofstream fout;

	fout.open(getTarget() + "_shrubbery", std::ios::out | std::ios::trunc);
	if (!fout.is_open()) throw unableToOpenFile();
  	fout
        <<"           ; ; ;\n"
		  <<"       ;        ;  ;     ;;    ;\n"
		  <<"   ;                 ;         ;  ;\n"
          <<"                   ;\n"
          <<"                  ;                ;;\n"
          <<"  ;          ;            ;              ;\n"
          <<"  ;            ';,        ;               ;\n"
          <<"  ;              'b      *\n"
          <<"   ;              '$    ;;                ;;\n"
          <<"  ;    ;           $:   ;:               ;\n"
          <<";;      ;  ;;      *;  @):        ;   ; ;\n"
          <<"             ;     :@,@):   ,;**:'   ;\n"
          <<" ;      ;,         :@@*: ;;**'      ;   ;\n"
          <<"          ';o;    ;:(@';@*\"'  ;\n"
          <<"  ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n"
          <<"             ,p$q8,:@)'  ;p*'      ;\n"
          <<"      ;     '  ; '@@Pp@@*'    ;  ;\n"
          <<"       ;  ; ;;    Y7'.'     ;  ;\n"
          <<"                 :@):.\n"
          <<"                .:@:'.\n"
          <<"              .::(@:.";
  	fout.close();
}