#ifndef DATAREPORTEPROPIEDAD_H
#define	DATAREPORTEPROPIEDAD_H

#include <string>
#include "DataZona.h"
#include "DataDepartamento.h"
using namespace std;

class DataReportePropiedad {
private:
    int codigo;
    int cantDeAmbientes;
    int dormitorios;
    int banios;
    bool garaje;
    string direccion;
    float infoVenta;
    float infoAlquiler;
    DataDepartamento* ddpto;
    DataZona* dzona;
public:
    DataReportePropiedad(int c,int cda, int d,int b,bool g,string &dir,float iv,float ia);
    int getCodigo();
    int getCantDeAmbientes();
    int getDormitorios();
    int getBanios();
    bool getGaraje();
    float getInfoVenta();
    float getInfoAlquiler();
    DataDepartamento* getDataDepartamento();
    DataZona* getDataZona();
    virtual ~DataReportePropiedad();

};

#endif	

