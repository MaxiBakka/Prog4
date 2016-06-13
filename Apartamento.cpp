#include "Apartamento.h"

Apartamento::Apartamento(int cod, int cda, int dormi, int banios, bool garaje, string dir, float m2t, Zona* z,Oferta*of,float m2e,Edificio* e)
:Propiedad(cod,cda,dormi,banios,garaje,dir,m2t,z,of) {
    this->m2edificados=m2e;
    this->edificio=e;
    z->AgregarPropiedad(this);
    e->agregarApartamento(this);
}


DataApartamento* Apartamento::getDataApartamento() {
    return new DataApartamento(this->getCantDeAmbientes(),this->getDormitorios(),this->getBanios(),this->getDireccion(),this->getAlquiler()->getDataAlquiler(),this->getVenta()->getDataVenta(),this->getM2Totales());
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

Apartamento::~Apartamento() {
  //elimino el apartamento de el edificio
    edificio->RemoverApartamento(getCodigo());
}
