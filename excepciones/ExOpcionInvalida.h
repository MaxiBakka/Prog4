#ifndef EXOPCIONINVALIDA_H 
#define	EXOPCIONINVALIDA_H 
 
 
#include<exception> 
#include<iostream> 
 
 
using namespace std; 
 
 
class ExOpcionInvalida : public exception{ 
public: 
		virtual const char* what()const throw(); 
 
};

#endif
