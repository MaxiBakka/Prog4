#ifndef ExPropiedadNoExistente_H
#define	ExPropiedadNoExistente_H


#include<exception>
#include<iostream>


using namespace std;


class ExPropiedadNoExistente : public exception{
public:
		virtual const char* what()const throw();
		ExPropiedadNoExistente();
};

#endif
