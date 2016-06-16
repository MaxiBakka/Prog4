#ifndef NOEXISTENEDIFICIOS_H
#define NOEXISTENEDIFICIOS_H

#include<exception>
#include<iostream>

using namespace std;

class NoExistenEdificios:public excepcion {
    public:
    DatosYaCargados();
    virtual const char* what()const throw();
};

#endif // DATOSYACARGADOS_H
