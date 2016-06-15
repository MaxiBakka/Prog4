#ifndef INTERESADONOTFOUND_H
#define	INTERESADONOTFOUND_H

#include<exception>
#include<iostream>

using namespace std;

class InteresadoNotFound : public exception{
	public:
		InteresadoNotFound();
		~InteresadoNotFound();
		virtual const char* what()const throw();

};

#endif	/* INTERESADONOTFOUND_H */
