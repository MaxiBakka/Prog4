#ifndef NOHAYCHATENMEMORIA_H
#define	NOHAYCHATENMEMORIA_H

#include<exception>
#include<iostream>

using namespace std;

class NoHayChatEnMemoria : public exception{
	public:
		NoHayChatEnMemoria();
		~NoHayChatEnMemoria();
		virtual const char* what()const throw();

};

#endif	/* NOHAYCHATENMEMORIA_H */
