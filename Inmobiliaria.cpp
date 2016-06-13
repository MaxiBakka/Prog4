#include "Inmobiliaria.h"
#include "DataReportePropiedad.h"
#include "NoExisteChat.h"

Inmobiliaria::Inmobiliaria(string& email, string& contrasenia, string& nombre, string& dir):Usuario(email,contrasenia) {
    this->nombre=nombre;
    this->direccion=dir;
    this->ofertas = new set<Oferta*>();
    this->chats = new set<Chat*>();

}

Inmobiliaria::~Inmobiliaria{

  for (set<Oferta*>::iterator it=ofertas->begin() ;it!=ofertas->end(); ++it) {
      Oferta*of= *it;
      delete of;
  }
  ofertas->clear();
  delete ofertas;

  for (set<Chat*>::iterator it=chats->begin() ;it!=chats->end(); ++it) {
      Chat*chat= *it;
      delete chat;
  }
  chats->clear();
  delete chats;

}

string Inmobiliaria::getNombre() {
    return this->nombre;
}

string Inmobiliaria::getDireccion() {
    return this->direccion;
}

/*
void Inmobiliaria::crearAlquiler(DataAlquiler*& da, Propiedad* &p) {
    this->alquileres->insert(new Alquiler(da->get_precio(),this,p));
}

void Inmobiliaria::crearVenta(DataVenta*& dv, Propiedad p) {
    this->ventas->insert(new Venta(dv->get_precio(),this,p));
}
*/

//operaciones sobre oferta
void Inmobiliaria::AgregarOferta(Oferta* oferta){

  this->ofertas->insert(oferta);
}

void Inmobiliaria::borrarOferta(Oferta* &oferta){

  this->ofertas->erase(oferta);

}



set<Chat*>* Inmobiliaria::getChats() {

  return this->chats;
}

bool Inmobiliaria::ExisteChat(Chat* &chat){

  return chats->find(chat)!= chats->end();
}

void Inmobiliaria::agregarChat(Chat*& c) {
    this->chats->insert(c);
}

void Inmobiliaria::eliminarChat(Chat*& c) {
    this->chats->erase(c);
}

Chat* ElegirChat(DataChat* &dc){
  Chat* c=NULL;
  for ( set<Chat*>::iterator it=chats->begin(); it!=chats->end(); ++it) {
      if((dc->getEmailInteresado()==*it->getEmailInteresado()) && (dc->getCodigo()== *it->getPropiedad()->getCodigo())){
        c=*it;
      }
  }
  if(c==NULL) throw NoExisteChat();
  return c;
}

DataInfoInmobiliaria* Inmobiliaria::getDataInfoInmobiliaria(){

  set<DataReportePropiedad*>*reportes= new set<DataReportePropiedad*>();
  for (set<Oferta*>::iterator it= ofertas->begin(); it!=ofertas->end(); ++it) {
    reportes->insert(*it->getDataReportePropiedad());
  }
  return DataInfoInmobiliaria(nombre,direccion,this->get_email(),reportes);



}

DataInmobiliaria* Inmobiliaria::getDataInmobiliaria() {
    return new DataInmobiliaria(this->nombre,this->get_email(),this->direccion);
}
