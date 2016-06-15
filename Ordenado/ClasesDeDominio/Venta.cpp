#include "Venta.h"

Venta :: Venta(float p) {
    this->precio=p;
}

float Venta :: getPrecio(){
    return this->precio;
}

void Venta::setPrecio(float precio){

  this->precio=precio;
}

DataVenta* Venta::getDataVenta() {
    return new DataVenta(this->precio);
}

Venta::~Venta() {

}
