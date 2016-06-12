#ifndef VENTA_H
#define	VENTA_H

#include "Oferta.h"
#include "DataVenta.h"

class Venta {
private:
    float precio;
public:
    Venta(float p);
    float getPrecio();
    void setPrecio(float precio);

    DataVenta* getDataVenta();
    virtual ~Venta();
};

#endif	/* VENTA_H */
