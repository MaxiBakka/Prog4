#include "Inmobiliaria.h"
#include "DataAlquiler.h"

Inmobiliaria::Inmobiliaria(string& email, string& contrasenia, string& nombre, string& dir):Usuario(email,contrasenia) {
    this->nombre=nombre;
    this->direccion=dir;
    this->alquileres = new set<Alquiler*>();
    this->chats = new set<Chat*>();
    this->ventas = new set<Venta*>();
}

string Inmobiliaria::getNombre() {
    return this->nombre;
}

string Inmobiliaria::getDireccion() {
    return this->direccion;
}

void Inmobiliaria::agregarChat(Chat*& c) {
    this->chats->insert(c);
}

void Inmobiliaria::borrarAlquiler(Alquiler* &a) {
    this->alquileres->erase(a);
}

void Inmobiliaria::borrarVenta(Venta*& v) {
    this->ventas->erase(v);
}

void Inmobiliaria::crearAlquiler(DataAlquiler*& da, Propiedad* &p) {
    this->alquileres->insert(new Alquiler(da->get_precio(),this,p));
}

void Inmobiliaria::crearVenta(DataVenta*& dv, Propiedad p) {
    this->ventas->insert(new Venta(dv->get_precio(),this,p));
}

void Inmobiliaria::eliminarChat(Chat*& c) {
    this->chats->erase(c);
}

set<Alquiler*>* Inmobiliaria::getAlquileres() {
    new set<Alquiler*>* res (this->alquileres); //Contructor por copia
    return res;
}

set<Chat*>* Inmobiliaria::getChats() {
    new set<Chat*>* res (this->chats); //Contructor por copia
    return res;
}

DataInfoInmobiliaria Inmobiliaria::getDataInfoInmobiliaria() {
    set<Alquiler*>::iterator ita;
    set<Venta*>::iterator itv;
    DataInfoInmobiliaria* res = new DataInfoInmobiliaria(this->nombre,this->direccion,this->get_email());
    for(ita=this->alquileres->begin();ita!=this->alquileres->end();++ita){
        res->agregarDataReportePropiedad(ita->getDataReportePropiedad());
    }
    for(itv=this->ventas->begin();itv!=this->ventas->end();++itv){
        res->agregarDataReportePropiedad(itv->getDataReportePropiedad());
    }
    return res;
}

DataInmobiliaria Inmobiliaria::getDataInmobiliaria() {
    return new DataInmobiliaria(this->nombre,this->get_email(),this->direccion);
}

set<Venta*>* Inmobiliaria::getVentas() {
    new set<Venta*>* res (this->ventas);//constructor por copia
    return res;
}
