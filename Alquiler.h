
#ifndef ALQUILER_H
#define	ALQUILER_H

#include "DataReportePropiedad.h"
#include "DataAlquiler.h"
#include "Propiedad.h"

class Alquiler {
private:
    float precio;
    Inmobiliaria* inmobiliaria;
    Propiedad* propiedad;
public:
    Alquiler(float p,Inmobiliaria* i,Propiedad* p);
    float getPrecio();
    Inmobiliaria getInmobiliaria();
    Propiedad getPropiedad();
    int getCodigoPropiedad();
    DataReportePropiedad getDataReportePropiedad();
    DataAlquiler* getDataAlquiler();
    virtual ~Alquiler();
};

#endif	/* ALQUILER_H */

