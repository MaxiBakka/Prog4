#include "Propiedad.h"
#include "Zona.h"
#include "Oferta.h"

Propiedad::Propiedad(int cod, int cda, int dormi, int banios, bool garaje, string dir, float m2t,Zona* z,Oferta*of) {
    this->codigo=cod;
    this->cantDeAmbientes=cda;
    this->dormitorios=dormi;
    this->Banios=banios;
    this->garaje=garaje;
    this->direccion=dir;
    this->m2Totales=m2t;
    this->zona=z;
    this->oferta=of;
    this->chats= new set<Chat*>();


}



int Propiedad::getBanios() {
    return this->Banios;
}

int Propiedad::getCantDeAmbientes() {
    return this->cantDeAmbientes;
}

int Propiedad::getCodigo() {
    return this->codigo;
}

string Propiedad::getDireccion() {
    return this->direccion;
}

int Propiedad::getDormitorios() {
    return this->dormitorios;
}

bool Propiedad::getGaraje() {
    return this->garaje;
}

float Propiedad::getM2Totales() {
    return this->m2Totales;
}



Zona* Propiedad::getZona() {
    return this->zona;
}

void Propiedad::setCodigo(int codigo){

  this->codigo=codigo;
}
void PropiedadsetCantDeAmbientes(int cantambientes){

  this->cantDeAmbientes=cantambientes;
}
void Propiedad::setDormitorios(int dorm){
  this->dormitorios=dorm;
}
void Propiedad::setBanios(int banio){

  this->Banios=banio;
}
void Propiedad::setGaraje(bool garaje){
  this->garaje=garaje;

}
void Propiedad::setDireccion(string &direccion){
  this->direccion=direccion;
}
void Propiedad::setM2Totales(float m2tot){

this->m2Totales=m2tot;
}
void Propiedad::setVenta(float precio){
  this->oferta->setVenta(precio);

}
void Propiedad::setAlquiler(float precio){

  this->oferta->setAlquiler(precio);

}

//obtencion datatypes
DataReportePropiedad* Propiedad::getDataReportePropiedad(){

//caso de uso obtener reporte de Inmobiliaria

}


DataInfoPropiedad* Propiedad::getDataInfoPropiedad(string &email){
 int cant=0;
  for (set<Chat*>::iterator it =chats->begin(); it!=chats->end(); ++it) {
    if(*it->getEmailInteresado()==email){
      cant= *it->cantidadMensajes();
      break;
    }
  }
  return new DataInfoPropiedad(this->codigo,this->direccion,cant);

}


DataDetallePropiedad *Propiedad:: getDataDetallePropiedad(){

  return new DataDetallePropiedad(codigo,direccion,oferta->ExisteVenta(),oferta->ExisteAlquier());

}


DataPropiedad * Propiedad::getDataPropiedad(){
  float alquiler=0;
  float venta=0;

  if(oferta->ExisteVenta()){
   venta = oferta->getVenta()->getPrecio();
  }
  if(oferta->ExisteAlquier()){
  alquiler=oferta->getAlquiler()->getPrecio();
  }

  return new DataPropiedad(codigo,cantDeAmbientes,dormitorios,Banios,direccion,garaje,m2Totales,alquiler,venta);
}
//Faltan operaciones del DSD
void Propiedad::modificarPropiedad(DataPropiedad*dp){
//caso de uso modificarPropiedad falta hacerlo

}
void Propiedad::ingresarMensaje(string &email,DataMensaje* mensaje){
//caso de uso enviar mensaje interesado,me falta terminar esta op

}


Propiedad::~Propiedad() {
  //elimino los chats
  for(set<Chat*>::iterator it = chats->begin(); it!=chats->end();++it){
    Chat*chat= *it;
    delete chat;
  }
  chats->clear();
  delete chats;

//elimino oferta(venta/alquiler)
  delete oferta;
//remuevo la instancia de propiedad en la zona donde la prop pertenece
  this->zona->RemoverPropiedad(codigo);

}
