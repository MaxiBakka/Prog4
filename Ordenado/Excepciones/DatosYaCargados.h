#ifndef DATOSYACARGADOS_H
#define DATOSYACARGADOS_H

#include<exception>
#include<iostream>

using namespace std;

class DatosYaCargados:public excepcion {
    public:
    DatosYaCargados();
    virtual const char* what()const throw();
};

#endif // DATOSYACARGADOS_H
