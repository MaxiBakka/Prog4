#ifndef INMOBILIARIA_H
#define	INMOBILIARIA_H

#include <string>
#include <set>

#include "Usuario.h"
#include "Chat.h"
#include "../DataTypes/DataInfoInmobiliaria.h"

#include "../DataTypes/DataInmobiliaria.h"

#include <set>

class Oferta;


using namespace std;

class Inmobiliaria:public Usuario {
private:
    string nombre;
    string direccion;
    set<Chat*>* chats;
    set<Oferta*>* ofertas;
public:
    Inmobiliaria(string& email,string contrasenia,string& nombre,string& dir);
    virtual ~Inmobiliaria();
    //getters
    string getNombre();
    string getDireccion();
    set<Chat*>* getChats();

    //operaciones sobre OFERTA(venta y alquiler)

    //void crearAlquiler(DataAlquiler* &da,Propiedad p);
    //void crearVenta(DataVenta* &dv,Propiedad p);

    void AgregarOferta(Oferta* oferta);
    void borrarOferta(Oferta* oferta);

    //operaciones sobre chat
    bool ExisteChat(Chat* &chat);
    void agregarChat(Chat* &c);
    void eliminarChat(Chat* c);
    Chat* ElegirChat(DataChat* &dc);


    //obtencion de datatypes
    DataInfoInmobiliaria* getDataInfoInmobiliaria();
    DataInmobiliaria* getDataInmobiliaria();

};

#endif	/* INMOBILIARIA_H */
