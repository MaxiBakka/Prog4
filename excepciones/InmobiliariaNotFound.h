#ifndef InmobiliariaNotFound_h
#define InmobiliariaNotFound_h

#include<exception>
#include<iostream>

using namespace std;

class InmobiliariaNotFound : public exception{
	public:
		virtual const char* what()const throw();
		InmobiliariaNotFound();
		~InmobiliariaNotFound();
};


#endif
