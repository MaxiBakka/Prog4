#include "Apartamento.h"
#include "Edificio.h"
#include "Zona.h"
#include "DataApartamento.h"

Apartamento::Apartamento(int cod, int cda, int dormi, int banios, bool garaje, string dir, float m2t, Zona* z,Oferta*of,float m2e,Edificio* e)
:Propiedad(cod,cda,dormi,banios,garaje,dir,m2t,z,of) {
    this->m2edificados=m2e;
    this->edificio=e;
    z->AgregarPropiedad(this);
    e->agregarApartamento(this);
}


DataPropiedad* Apartamento::getDataPropiedad() {
  float alquiler=0;
  float venta=0;

  if(getOferta()->ExisteVenta()){
   venta = getOferta()->getVenta()->getPrecio();
  }
  if(getOferta()->ExisteAlquier()){
  alquiler=getOferta()->getAlquiler()->getPrecio();
  }

return new DataApartamento(this->getCodigo(),this->getCantDeAmbientes(),
getDormitorios(),getBanios(),getDireccion(),getGaraje(),alquiler,venta,getM2Totales(),m2edificados);


}

float Apartamento::getM2Edificados() {
    return this->m2edificados;
}

Edificio* Apartamento::getEdificio() {
    return this->edificio;
}

void Apartamento::setM2edificados(float m2e){
  this->m2edificados=m2e;
}

void Apartamento::modificarPropiedad(DataPropiedad*dp){
  DataApartamento*da= dynamic_cast<DataApartamento*>(&dp);
  this->setCantDeAmbientes(da->getCantAmbientes());
  this->setDormitorios(da->getDormitorios());
  this->setBanios(da->getBanios());
  this->setGaraje(da->getGaraje());
  this->setDireccion(da->getDireccion());
  this->setM2Totales(da->getM2totales());
  this->setAlquiler(da->getAlquiler());
  this->setVenta(da->getVenta());

  this->setM2edificados(da->getM2edificados());

}


Apartamento::~Apartamento() {
  //elimino el apartamento de el edificio
    edificio->RemoverApartamento(getCodigo());
}
