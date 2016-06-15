#ifndef YAEXISTEPROPIEDAD_H
#define	YAEXISTEPROPIEDAD_H

#include<exception>
#include<iostream>

using namespace std;

class YaExistePropiedad : public exception{
	public:
		YaExistePropiedad();
		~YaExistePropiedad();
		virtual const char* what()const throw();

};


#endif	/* YAEXISTEPROPIEDAD_H */
