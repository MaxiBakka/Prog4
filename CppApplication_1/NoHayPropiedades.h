#ifndef NOHAYPROPIEDADES_H
#define	NOHAYPROPIEDADES_H

#include<exception>
#include<iostream>

using namespace std;

class NoHayPropiedades : public exception{
	public:
		virtual const char* what()const throw();

};

#endif	/* NOHAYPROPIEDADES_H */

