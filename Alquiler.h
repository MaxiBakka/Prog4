#ifndef ALQUILER_H
#define	ALQUILER_H

#include "DataAlquiler.h"


class Alquiler {
private:
    float precio;
public:
    Alquiler(float p);
    float getPrecio();
    void setPrecio(float precio);

    DataAlquiler* getDataAlquiler();
    virtual ~Alquiler();
};

#endif	/* ALQUILER_H */
