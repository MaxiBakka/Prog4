#ifndef DATOSYACARGADOS_H
#define DATOSYACARGADOS_H

#include<exception>
#include<iostream>

class DatosYaCargados {
    public:
		virtual const char* what()const throw();
};

#endif // DATOSYACARGADOS_H