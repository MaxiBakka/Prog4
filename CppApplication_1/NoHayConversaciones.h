#ifndef NOHAYCONVERSACIONES_H
#define	NOHAYCONVERSACIONES_H

#include<exception>
#include<iostream>

using namespace std;

class NoHayConversaciones : public exception{
	public:
		virtual const char* what()const throw();

};

#endif	/* NOHAYCONVERSACIONES_H */

