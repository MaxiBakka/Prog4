
#ifndef ALQUILER_H
#define	ALQUILER_H

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
    virtual ~Alquiler();
};

#endif	/* ALQUILER_H */

