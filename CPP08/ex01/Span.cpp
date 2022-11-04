#include "Span.h"

Span::Span() : _N(0)
{}
Span::Span(const Span &copy) : _N(0)
{
	*this = copy;
}
Span &Span::operator=(const Span &copy)
{
	if (&copy == this) return *this;

	this->_N = copy._N;
	this->_vector = copy._vector; // у вектора есть глубокое копирование
	return *this;
}
Span::~Span()
{
}

Span::Span(unsigned int N) : _N(N), _vector(std::vector<int> ())
{}

void Span::addNumber(const int &a)
{
	if (_vector.size() + 1 > this->_N) throw std::out_of_range("can't add more numbers than given size");
	_vector.push_back(a);
}
void Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	std::vector<int> vectorTmp(first, last);
	if (_vector.size() + vectorTmp.size() > this->_N)
		throw std::out_of_range("can't add more numbers than given size");

	_vector.insert(_vector.end(), vectorTmp.begin(), vectorTmp.end());
}


int Span::getNumber(unsigned int index) const
{
	if (index >= _vector.size()) throw std::out_of_range("index out of range");

	return (_vector[index]);
}
unsigned int Span::getN() const
{
	return _N;
}
unsigned int Span::getLength() const
{
	return _vector.size();
}

long Span::longestSpan()
{
	if (_vector.size() < 2) throw std::runtime_error("too few numbers stored to get longest span");

	std::vector<int>::iterator maxIt = std::max_element(_vector.begin(), _vector.end());
	std::vector<int>::iterator minIt = std::min_element(_vector.begin(), _vector.end());

	int res = *maxIt - *minIt;
	return res;
}
long Span::shortestSpan()
{
	if (_vector.size() < 2) throw std::runtime_error("too few numbers stored to get shortest span");


	std::vector<int> sorted(_vector);
	std::sort(sorted.begin(), sorted.end());
	long res = *(sorted.begin() + 1) - *sorted.begin();

	long tmp;
	for (unsigned i = 1; i < sorted.size(); ++i)
	{
		tmp = sorted[i] - sorted[i - 1];
		if (tmp < res)
			res = tmp;
	}
	return res;
}


std::ostream &operator<<(std::ostream &out, Span const &s)
{
	std::cout << "N = " << s.getN() << std::endl;

	std::cout << "array: ";
	for (unsigned int i = 0; i < s.getLength(); ++i)
		std::cout << s.getNumber(i) << " ";
	std::cout << std::endl;
	return out;
}
