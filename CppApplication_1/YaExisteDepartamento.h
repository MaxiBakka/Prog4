#ifndef YAEXISTEDEPARTAMENTO_H
#define	YAEXISTEDEPARTAMENTO_H

#include<exception>
#include<iostream>

using namespace std;

class YaExisteDepartamento : public exception{
	public:
		virtual const char* what()const throw();

};


#endif	/* YAEXISTEDEPARTAMENTO_H */

