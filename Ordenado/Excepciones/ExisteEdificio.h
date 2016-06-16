#ifndef EXISTEEDIFICIO_H
#define	EXISTEEDIFICIO_H

#include<exception>
#include<iostream>

using namespace std;

class ExisteEdificio : public exception{
	public:
		ExisteEdificio();
		virtual const char* what()const throw();

};

#endif	/* EXISTEEDIFICIO_H */
