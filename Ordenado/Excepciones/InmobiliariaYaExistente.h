#ifndef INMOBILIARIAYAEXISTENTE_H
#define	INMOBILIARIAYAEXISTENTE_H

#include<exception>
#include<iostream>

using namespace std;

class InmobiliariaYaExistente : public exception{
	public:
		InmobiliariaYaExistente();
		~InmobiliariaYaExistente();
		virtual const char* what()const throw();

};

#endif	/* INMOBILIARIAYAEXISTENTE_H */
