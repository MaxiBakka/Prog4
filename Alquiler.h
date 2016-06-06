/* 
 * File:   Alquiler.h
 * Author: gianni.testa
 *
 * Created on 6 de junio de 2016, 09:44 AM
 */

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

