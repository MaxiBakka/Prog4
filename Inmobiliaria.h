
#ifndef INMOBILIARIA_H
#define	INMOBILIARIA_H

#include <string>
#include <set>

#include "Usuario.h"
#include "Venta.h"
#include "Alquiler.h"
#include "Chat.h"
#include "Propiedad.h"
#include "DataAlquiler.h"
#include "DataVenta.h"
#include "DataInfoInmobiliaria.h"

using namespace std;

class Inmobiliaria:public Usuario {
private:
    string nombre;
    string direccion;
    set<Chat*>*chats;
    set<Alquiler*>*alquileres;
    set<Venta*>*ventas;
public:
    Inmobiliaria(string& email,string& contrasenia,string& nombre,string& dir);
    //getters
    string getNombre();
    string getDireccion();
    set<Chat*>* getChats();
    set<Alquiler*>* getAlquileres();
    set<Venta*>* getVentas();
    //operaciones sobre venta y alquiler
    void crearAlquiler(DataAlquiler* &da,Propiedad p);
    void crearVenta(DataVenta* &dv,Propiedad p);

    void borrarVenta(Venta* &v);
    void borrarAlquiler(Alquiler* a);

    //operaciones sobre chat
    bool ExisteChat(Chat&* chat);
    void agregarChat(Chat* &c);
    void eliminarChat(Chat* &c);
    //obtencion de datatypes
    DataInfoInmobiliaria* getDataInfoInmobiliaria();
    DataInmobiliaria* getDataInmobiliaria();
};

#endif	/* INMOBILIARIA_H */
