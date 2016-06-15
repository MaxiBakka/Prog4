#ifndef YAEXISTEPROPIEDAD_H
#define	YAEXISTEPROPIEDAD_H

#include<exception>
#include<iostream>

using namespace std;

class YaExistePropiedad : public exception{
	public:
		virtual const char* what()const throw();

};


#endif	/* YAEXISTEPROPIEDAD_H */

