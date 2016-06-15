#ifndef ExDptoNoExistente_h
#define ExDptoNoExistente_h

#include<exception>
#include<iostream>

using namespace std;

class ExDptoNoExistente : public exception{
	public:
		ExDptoNoExistente();
		virtual ~ExDptoNoExistente();
		virtual const char* what()const throw();

};


#endif
