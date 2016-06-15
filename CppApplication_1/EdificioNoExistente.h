#ifndef EDIFICIONOEXISTENTE_H
#define	EDIFICIONOEXISTENTE_H

#include<exception>
#include<iostream>

using namespace std;

class EdificioNoExistente : public exception{
	public:
		virtual const char* what()const throw();

};


#endif	/* EDIFICIONOEXISTENTE_H */

