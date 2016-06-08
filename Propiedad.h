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

using namespace std;

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
    Propiedad(int cod,int cda,int dormi,int banios,bool garaje,string dir,float m2t,Zona* z);
    virtual int getCodigo();
    virtual int getCantDeAmbientes();
    virtual int getDormitorios();
    virtual int getBanios();
    virtual bool getGaraje();
    virtual string getDireccion();
    virtual float getM2Totales();
    virtual Zona* getZona();
    virtual Venta* getVenta();
    virtual Alquiler* getAlquiler();
    virtual ~Propiedad();
    
    //Faltan operaciones del DSD
};

#endif	/* PROPIEDAD_H */

