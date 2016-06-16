#ifndef FECHAINVALIDA_H
#define	FECHAINVALIDA_H

#include<exception>
#include<iostream>

using namespace std;

class FechaInvalida : public exception{
	public:
		FechaInvalida();
		virtual const char* what()const throw();

};

#endif	/* FECHAINVALIDA_H */
