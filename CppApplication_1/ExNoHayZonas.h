#ifndef EXNOHAYZONAS_H
#define	EXNOHAYZONAS_H

#include<exception>
#include<iostream>

using namespace std;

class ExNoHayZonas : public exception{
	public:
		ExNoHayZonas();
		~ExNoHayZonas();
		virtual const char* what()const throw();

};


#endif	/* EXNOHAYZONAS_H */
