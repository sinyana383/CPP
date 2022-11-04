#ifndef CPP01_HARL_H
#define CPP01_HARL_H
#include <string>

class Harl
{
private:
	void (Harl::*harl_complains[4])();
	std::string levels[4];
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	void complain( std::string level );
	void harlFilter(const std::string& level);
};

#endif //CPP01_HARL_H
