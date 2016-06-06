#include "Venta.h"

Venta :: Venta(float p,Inmobiliaria* &i,Propiedad* &prop) {
    this->precio=p;
    this->inmobiliaria=i;
    this->propiedad=prop;
}

float Venta :: getPrecio(){
    return this->precio;
}

Inmobiliaria Venta :: getInmobiliaria(){
    return this->inmobiliaria;
}

Propiedad Venta :: getPropiedad(){
    return this->propiedad;
}

int Venta :: getCodigoPropiedad(){
    return this->propiedad->getCodigo();
}

/*DataReportePropiedad Venta :: getDataReportePropiedad(){
    
}*/

Venta::~Venta() {
}

