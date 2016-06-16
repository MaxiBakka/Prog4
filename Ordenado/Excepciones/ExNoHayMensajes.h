#ifndef EXNOHAYMENSAJES_H
#define	EXNOHAYMENSAJES_H

#include<exception>
#include<iostream>

using namespace std;

class ExNoHayMensajes :public exception{
	public:
		ExNoHayMensajes();
		virtual const char* what()const throw();

};

#endif	/* EXNOHAYMENSAJES_H */
