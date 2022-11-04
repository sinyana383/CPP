#ifndef CPP08_SPAN_H
#define CPP08_SPAN_H
#include <vector>
#include <stdexcept>
#include <iostream>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _vector;
	Span();
public:
	Span(Span const &copy);
	Span& operator=(Span const &copy);
	~Span();
	Span(unsigned int N);

	void addNumber(const int &a);
	void addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);

	int  getNumber(unsigned int index) const;
	unsigned int getN() const;
	unsigned int getLength() const;

	long longestSpan();
	long shortestSpan();
};

std::ostream &operator<<(std::ostream &out, Span const &s);

#endif //CPP08_SPAN_H
