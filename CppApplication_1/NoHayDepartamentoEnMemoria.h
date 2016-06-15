#ifndef NOHAYDEPARTAMENTOENMEMORIA_H
#define	NOHAYDEPARTAMENTOENMEMORIA_H

#include<exception>
#include<iostream>

using namespace std;

class NoHayDepartamentoEnMemoria : public exception{
	public:
		virtual const char* what()const throw();

};

#endif	/* NOHAYDEPARTAMENTOENMEMORIA_H */

