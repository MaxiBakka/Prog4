
#ifndef EXISTEINTERESADO_H
#define	EXISTEINTERESADO_H

#include<exception>
#include<iostream>

using namespace std;

class ExisteInteresado : public exception{
	public:
		virtual const char* what()const throw();

};

#endif	/* EXISTEINTERESADO_H */

