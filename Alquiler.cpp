#include "Alquiler.h"

Alquiler :: Alquiler(float p,Inmobiliaria* &i,Propiedad* &prop) {
    this->precio=p;
    this->inmobiliaria=i;
    this->propiedad=prop;
}

float Alquiler :: getPrecio(){
    return this->precio;
}

Inmobiliaria Alquiler :: getInmobiliaria(){
    return this->inmobiliaria;
}

Propiedad Alquiler :: getPropiedad(){
    return this->propiedad;
}

int Alquiler :: getCodigoPropiedad(){
    return this->propiedad->getCodigo();
}

/*DataReportePropiedad Alquiler :: getDataReportePropiedad(){
    
}*/

Alquiler::~Alquiler() {
}

