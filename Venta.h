#ifndef VENTA_H
#define	VENTA_H

#include "Inmobiliaria.h"
#include "Propiedad.h"
#include "DataReportePropiedad"

class Venta {
private:
    float precio;
    Inmobiliaria* inmobiliaria;
    Propiedad* propiedad;
public:
    Venta(float p,Inmobiliaria* &i,Propiedad* &prop);
    float getPrecio();
    Inmobiliaria getInmobiliaria();
    Propiedad getPropiedad();
    int getCodigoPropiedad();
    DataReportePropiedad getDataReportePropiedad();
    ~Venta();


};

#endif	/* VENTA_H */

