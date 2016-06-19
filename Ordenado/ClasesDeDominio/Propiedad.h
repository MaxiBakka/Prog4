#ifndef PROPIEDAD_H
#define	PROPIEDAD_H

#include <string>
#include <map>
#include <set>

#include "Chat.h"
#include "Venta.h"
#include "Alquiler.h"
#include "../DataTypes/DataMensaje.h"
#include "../DataTypes/DataInfoPropiedad.h"
#include "../DataTypes/DataReportePropiedad.h"
#include "../DataTypes/DataPropiedad.h"
#include "../DataTypes/DataDetallePropiedad.h"

class Zona; //fwd declaration
class Oferta;

using namespace std;

class Propiedad {
protected:
    int codigo;
    int cantDeAmbientes;
    int dormitorios;
    int Banios;
    bool garaje;
    string direccion;
    float m2Totales;
    Zona* zona;
    Oferta* oferta;
    set<Chat*>* chats;
public:
    Propiedad(int cod,int cda,int dormi,int banios,bool garaje,string& dir,float m2t,Zona* z,Oferta*of);
    virtual int getCodigo();
    virtual int getCantDeAmbientes();
    virtual int getDormitorios();
    virtual int getBanios();
    virtual bool getGaraje();
    virtual string& getDireccion();
    virtual float getM2Totales();
    virtual Zona* getZona();
    virtual Oferta* getOferta();

    //setters
    virtual void setCodigo(int codigo);
    virtual void setCantDeAmbientes(int cantambientes);
    virtual void setDormitorios(int dorm);
    virtual void setBanios(int banio);
    virtual void setGaraje(bool garaje);
    virtual void setDireccion(string &direccion);
    virtual void setM2Totales(float m2tot);
    virtual void setVenta(float precio);
    virtual void setAlquiler(float precio);

    virtual ~Propiedad();

    //obtencion datatypes
    virtual DataReportePropiedad* getDataReportePropiedad()=0;
    virtual DataInfoPropiedad* getDataInfoPropiedad(string &email);
    virtual DataDetallePropiedad * getDataDetallePropiedad();
    virtual DataPropiedad * getDataPropiedad()=0;

    virtual void modificarPropiedad(DataPropiedad*dp)=0;
    virtual void ingresarMensaje(DataMensaje* mensaje,string &email);
    virtual void AgregarChat(Chat*c);
    virtual void eliminarChat(Chat * chat);
    virtual bool ExisteChat(string &email);
};

#endif	/* PROPIEDAD_H */
