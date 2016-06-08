
#include "Casa.h"

Casa::Casa(int cod, int cda, int dormi, int banios, bool garaje, string dir, float m2t,Zona* z, int ev, float m2e):Propiedad(cod,cda,dormi,banios,garaje,dir,ev+m2e,z) {
    this->espacioVerde=ev;
    this->m2Edificados=m2e;
}

int Casa::getEspacioVerde() {
    return this->espacioVerde;
}

float Casa::getM2Edificados() {
    return this->m2Edificados;
}

DataCasa* Casa::getDataCasa() {
    return new DataCasa(this->getCantDeAmbientes(),this->getDormitorios(),this->getBanios(),this->getDireccion(),this->getAlquiler()->getDataAlquiler(),this->getVenta()->getDataVenta(),this->getM2Totales(),this->espacioVerde);
}


Casa::~Casa() {

}
