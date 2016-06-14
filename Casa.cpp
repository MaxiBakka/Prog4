
#include "Casa.h"
#include "DataCasa.h"

Casa::Casa(int cod, int cda, int dormi, int banios, bool garaje, string dir, float m2t,Zona* z,Oferta* of, int ev, float m2e)
:Propiedad(cod,cda,dormi,banios,garaje,dir,m2t,z,of) {

    this->espacioVerde=ev;
    this->m2Edificados=m2e;
    z->AgregarPropiedad(this);
    e->agregarApartamento(this);
}

int Casa::getEspacioVerde() {
    return this->espacioVerde;
}

float Casa::getM2Edificados() {
    return this->m2Edificados;
}

void Casa::setEspacioVerde(int espverde){

  this->espacioVerde=espverde;
}
void Casa::setM2edificados(float m2edificados){
  this->m2Edificados=m2edificados;
}


DataPropiedad* Casa::getDatapropiedad() {
  float alquiler=0;
  float venta=0;

  if(getOferta()->ExisteVenta()){
   venta = getOferta()->getVenta()->getPrecio();
  }
  if(getOferta()->ExisteAlquier()){
  alquiler=getOferta()->getAlquiler()->getPrecio();
  }

  return new DataCasa(this->getCodigo(),this->getCantDeAmbientes(),
  getDormitorios(),getBanios(),getDireccion(),getGaraje(),alquiler,venta,getM2Totales(),m2Edificados,espacioVerde);
}

void Casa::modificarPropiedad(DataPropiedad*dp){

  this->setCantDeAmbientes(dp->getCantAmbientes());
  this->setDormitorios(dp->getDormitorios());
  this->setBanios(dp->getBanios());
  this->setGaraje(dp->getGaraje());
  this->setDireccion(dp->getDireccion());
  this->setM2Totales(dp->getM2totales());
  this->setAlquiler(dp->getAlquiler());
  this->setVenta(dp->getVenta());

  this->setM2edificados(dp->getM2edificados());
  this->espacioVerde=dp->getEspacioVerde();
}



Casa::~Casa() {

}
