
#include "Casa.h"

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


DataCasa* Casa::getDataCasa() {
  //Me falta modificarlo,maxi.
    return new DataCasa(this->getCantDeAmbientes(),this->getDormitorios(),this->getBanios(),this->getDireccion(),this->getAlquiler()->getDataAlquiler(),this->getVenta()->getDataVenta(),this->getM2Totales(),this->espacioVerde);
}


Casa::~Casa() {
//me falta terminarlo
}
