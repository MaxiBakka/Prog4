#include "Apartamento.h"

Apartamento::Apartamento(int cod, int cda, int dormi, int banios, bool garaje, string dir, float m2t, Zona* z):Propiedad(cod,cda,dormi,banios,garaje,dir,m2t,z) {

}

bool Apartamento::estaEnZona(int cod) {
    return (this->getZona()->getCodigo()==cod);
}

DataApartamento* Apartamento::getDataApartamento() {
    return new DataApartamento(this->getCantDeAmbientes(),this->getDormitorios(),this->getBanios(),this->getDireccion(),this->getAlquiler()->getDataAlquiler(),this->getVenta()->getDataVenta(),this->getM2Totales());
}

