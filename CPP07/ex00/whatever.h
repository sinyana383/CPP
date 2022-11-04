//
// Created by Darcel Durrandon on 10/29/22.
//

#ifndef CPP07_WHATEVER_H
#define CPP07_WHATEVER_H

template<typename T>
void swap (T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const &max (T const &a, T const &b)
{
	return (a > b ? a : b);
}

template<typename T>
T const &min (T const &a, T const &b)
{
	return (a < b ? a : b);
}

#endif //CPP07_WHATEVER_H
