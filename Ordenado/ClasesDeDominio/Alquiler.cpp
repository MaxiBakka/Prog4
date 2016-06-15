#include "Alquiler.h"

Alquiler :: Alquiler(float p) {
    this->precio=p;
}

float Alquiler :: getPrecio(){
    return this->precio;
}

void Alquiler::setPrecio(float precio){

  this->precio=precio;
}

DataAlquiler* Alquiler::getDataAlquiler() {
    return new DataAlquiler(this->precio);
}

Alquiler::~Alquiler() {

}
