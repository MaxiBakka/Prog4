#ifndef VENTA_H
#define	VENTA_H

#include "Propiedad.h"
#include "DataReportePropiedad.h"
#include "DataVenta.h"

class Inmobiliaria; //fwd declaration

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
    DataVenta* getDataVenta();
    ~Venta();


};

#endif	/* VENTA_H */

