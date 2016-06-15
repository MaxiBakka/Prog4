#ifndef EXOPCIONINVALIDA_H
#define EXOPCIONINVALIDA_H

#include<exception>
#include<iostream>

class ExOpcionInvalida {
    public:
		virtual const char* what()const throw();
};

#endif // EXOPCIONINVALIDA_H
