#ifndef VALORESINVALIDOS_H
#define	VALORESINVALIDOS_H

#include<exception>
#include<iostream>

using namespace std;

class ValoresInvalidos : public exception{
	public:
		virtual const char* what()const throw();

};

#endif	/* VALORESINVALIDOS_H */

