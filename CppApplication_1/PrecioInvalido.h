#ifndef PRECIOINVALIDO_H
#define	PRECIOINVALIDO_H

#include<exception>
#include<iostream>

using namespace std;

class PrecioInvalido : public exception{
	public:
		virtual const char* what()const throw();

};


#endif	/* PRECIOINVALIDO_H */

