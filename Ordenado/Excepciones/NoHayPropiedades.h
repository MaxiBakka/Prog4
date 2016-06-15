#ifndef NOHAYPROPIEDADES_H
#define	NOHAYPROPIEDADES_H

#include<exception>
#include<iostream>

using namespace std;

class NoHayPropiedades : public exception{
	public:
		NoHayPropiedades();
		~NoHayPropiedades();
		virtual const char* what()const throw();

};

#endif	/* NOHAYPROPIEDADES_H */
