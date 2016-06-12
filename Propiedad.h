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
#include "DataPropiedad.h"

class Zona; //fwd declaration
class Oferta;

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
    Oferta* oferta;
public:
    Propiedad(int cod,int cda,int dormi,int banios,bool garaje,string dir,float m2t,Zona* z,Oferta*of);
    virtual int getCodigo();
    virtual int getCantDeAmbientes();
    virtual int getDormitorios();
    virtual int getBanios();
    virtual bool getGaraje();
    virtual string getDireccion();
    virtual float getM2Totales();
    virtual Zona* getZona();
    virtual Oferta* getOferta();

    virtual ~Propiedad();

    //obtencion datatypes
    virtual DataReportePropiedad* getDataReportePropiedad();
    virtual DataInfoPropiedad* getDataInfoPropiedad();
    virtual DataDetallePropiedad * getDataDetallePropiedad();
    virtual DataPropiedad * getDataPropiedad();
    //Faltan operaciones del DSD

    virtual void ingresarMensaje(string &email,DataMensaje* mensaje);
};

#endif	/* PROPIEDAD_H */
