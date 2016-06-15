#ifndef NoHayDepartamentos_h
#define NoHayDepartamentos_h

#include<exception>
#include<iostream>

using namespace std;

class NoHayDepartamentos : public exception{
	public:
		virtual const char* what()const throw();

};


#endif

