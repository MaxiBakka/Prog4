#ifndef NOEXISTEZONA_H
#define	NOEXISTEZONA_H

#include<exception>
#include<iostream>

using namespace std;

class NoExisteZona : public exception{
	public:
		NoExisteZona();
		virtual const char* what()const throw();

};


#endif	/* NOEXISTEZONA_H */
