#ifndef EXVALORESNOPOSITIVOS_H
#define	EXVALORESNOPOSITIVOS_H

#include<exception>
#include<iostream>

using namespace std;

class ExvaloresNoPositivos : public exception{
	public:
		virtual const char* what()const throw();

};

#endif	/* EXVALORESNOPOSITIVOS_H */

