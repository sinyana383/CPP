#ifndef CPP04_BRAIN_H
#define CPP04_BRAIN_H
#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain( const Brain& copy );
	~Brain();
	Brain& operator=( const Brain& variable );

	const std::string *getIdeas() const;
	void setIdea(unsigned int index, const std::string &idea);
};


#endif //CPP04_BRAIN_H
