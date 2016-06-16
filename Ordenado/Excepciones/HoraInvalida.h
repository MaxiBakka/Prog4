#ifndef HORAINVALIDA_H
#define	HORAINVALIDA_H

#include<exception>
#include<iostream>

using namespace std;

class HoraInvalida : public exception{
	public:
		HoraInvalida();
		virtual const char* what()const throw();

};

#endif	/* HORAINVALIDA_H */
