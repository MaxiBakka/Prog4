
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
    Inmobiliaria(string email,string contrasenia,string nombre,string dir);
    string getNombre();
    string getDireccion();
    set<Chat*>* getChats();
    set<Alquiler*>* getAlquileres();
    set<Venta*>* getVentas();
    void crearAlquiler(DataAlquiler* &da,Propiedad p);
    void crearVenta(DataVenta* &dv,Propiedad p);
    void eliminarChat(Chat* &c);
    void borrarVenta(Venta* &v);
    void borrarAlquiler(Alquiler* a);
    void agregarChat(Chat* &c);
    DataInfoInmobiliaria getDataInfoInmobiliaria();
    DataInmobiliaria getDataInmobiliaria();
};

#endif	/* INMOBILIARIA_H */

