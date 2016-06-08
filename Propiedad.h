#ifndef PROPIEDAD_H
#define	PROPIEDAD_H

#include<string>
#include<map>
#include "Chat.h"
#include "Venta.h"
#include "Alquiler.h"
#include "DataMensaje.h"
#include "DataInfoPropiedad.h"
#include "DataReportePropiedad.h"

class Zona; //fwd declaration

class Propiedad {
private:
    int codigo;
    int cantDeAmbientes;
    int dormitorios;
    int Banios;
    bool garaje;
    string direccion;
    float m2Totales;
    Zona* zona;
    Venta* venta;
    Alquiler* alquiler;
public:
    Propiedad();
    virtual ~Propiedad();
};

#endif	/* PROPIEDAD_H */

